#include <iostream>
#include <string>
#include <fstream>
#include <random>
#include <sstream>
#include <vector>
#if (_DEBUG)
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#define new ::new(_NORMAL_BLOCK, __FILE__, __LINE__)
#endif
namespace Library
{
	template<class T> bool Delete(T* t)
	{
		if (t)
		{
			delete t;
			t = nullptr;
			return true;
		}
		return false;
	}
	template<class T> bool Delete(const T* t)
	{
		if (t)
		{
			delete t;
			t = nullptr;
			return true;
		}
		return false;
	}
	void Clear()
	{
		system("cls");
	}
}
class ErrorCode
{
	const std::string errorcode[3] = {
		"String data does not exist",
		"Not exist",
		"Not exist/Failed to generate"
	};
	static ErrorCode* error;
public:
	std::string GetCode(unsigned int id)
	{
		return errorcode[id];
	}
	static void Create()
	{
		if (!ErrorCode::error)
		{
			ErrorCode::error = new ErrorCode();
		}
	}
	static void Delete()
	{
		Library::Delete<ErrorCode>(ErrorCode::error);
	}
	static ErrorCode* Get()
	{
		return ErrorCode::error;
	}
};

namespace Random
{
	static std::mt19937_64 engine;
	void Init()
	{
		std::random_device device;
		engine.seed(device());
	}
	int GetRand(const int min_, const int max_)
	{
		std::uniform_int_distribution<int> range(min_, max_);
		return range(engine);
	}
	float GetRand(const float min_, const float max_)
	{
		std::uniform_real_distribution<float> range(min_, max_);
		return range(engine);
	}
	float GetRand_Normal(const float mu, const float sig)
	{
		std::normal_distribution<float> range(mu, sig);
		return range(engine);
	}
	std::string GetRand(const std::string& text, const std::size_t size)
	{
		if (text.empty())
		{
			throw std::runtime_error(ErrorCode::Get()->GetCode(0));
		}
		std::uniform_int_distribution<std::size_t> range(0, text.size() - 1);
		std::string ReturnText;
		for (std::size_t i = 0; i < size; ++i)
		{
			std::size_t index = range(engine);
			char random_char = text[index];
			ReturnText += random_char;
		}
		return ReturnText;
	}
	bool GetProportion(const float proportion)
	{
		std::bernoulli_distribution dist((double)proportion);
		return dist(engine);
	}
}
class File final
{
public:
	// Reading files
	static std::string Load(std::ifstream& ifs)
	{
		std::istreambuf_iterator<char> begin(ifs);
		std::istreambuf_iterator<char> end;
		return std::string(begin, end);
	}
	// Reading files
	static std::string Load(const std::string path)
	{
		std::ifstream ifs(path, std::ios::in | std::ios::binary);
		if (!ifs)
		{
			throw std::runtime_error(path + ErrorCode::Get()->GetCode(1));
		}
		return File::Load(ifs);
	}
	// File Output
	static void Output(const std::string& path,const std::string& text)
	{
		std::ofstream ofs(path, std::ios::out, std::ios::binary);
		if (!ofs)
		{
			throw std::runtime_error(path + ErrorCode::Get()->GetCode(2));
		}
		ofs << text;
		ofs.close();
	}
	// File Append Output
	static void AddOutput(const std::string& path, const std::string& text)
	{
		std::ofstream ofs(path, std::ios::app, std::ios::binary);
		if (!ofs)
		{
			throw std::runtime_error(path + ErrorCode::Get()->GetCode(2));
		}
		ofs << text;
		ofs.close();
	}
	// Chenge Seed Value
	static void RandomSeedChenge(const std::string& fileName, const unsigned int seedNum)
	{
		File::DeleteContents(fileName);
		for (unsigned int i = 0; i < seedNum; ++i)
		{
			std::ostringstream ostr;
			ostr << Random::GetRand(0, 999999999) << std::endl;
			File::AddOutput(fileName, ostr.str());
		}
	}
	// Delete the contents of the file
	static void DeleteContents(const std::string& path)
	{
		std::ofstream ofs(path, std::ios::trunc);
		if (!ofs)
		{
			throw std::runtime_error(path + ErrorCode::Get()->GetCode(1));
		}
		ofs.close();
	}
	// Create file
	static void Create(const std::string& path)
	{
		std::ofstream ofs(path);
		ofs.close();
	}
	// Get the data of the specified tag
	static std::string GetData(const std::string& path, const std::string& tag)
	{
		std::ifstream ifs(path);
		if (!ifs)
		{
			throw std::runtime_error(path + ErrorCode::Get()->GetCode(1));
		}
		std::string line;
		while (std::getline(ifs, line))
		{
			if (line.at(0) == '/')
			{
				continue;
			}
			if (tag == line.substr(0, line.find("=")))
			{
				return line.substr(line.find("=") + 1);
			}
		}
		return std::string();
	}
	// Get the data of the specified tag
	static std::string GetData(const std::string& path, const unsigned int tag)
	{
		std::ostringstream oss;
		oss << tag;
		std::ifstream ifs(path);
		if (!ifs)
		{
			throw std::runtime_error(path + ErrorCode::Get()->GetCode(1));
		}
		std::string line;
		while (std::getline(ifs, line))
		{
			if (line.at(0) == '/')
			{
				continue;
			}
			if (oss.str() == line.substr(0, line.find("=")))
			{
				return line.substr(line.find("=") + 1);
			}
		}
		return std::string();
	}
};
class System
{
	static System* mainSystem;
public:
	const std::string systemName;
	explicit System(const std::string& path)
		:systemName(path)
	{

	}
	static void Create(const std::string& path)
	{
		if (!System::mainSystem)
		{
			System::mainSystem = new System(path);
		}
	}
	static void Delete()
	{
		Library::Delete<System>(System::mainSystem);
	}
	static System* Get()
	{
		return System::mainSystem;
	}
};
class Task
{
	const unsigned int num;
public:
	explicit Task(unsigned int num)
		:num(num)
	{

	}
	const unsigned int GetNum() const
	{
		return this->num;
	}
	std::string To_String()
	{
		std::ostringstream oss;
		oss << num;
		return File::GetData(File::GetData(System::Get()->systemName, "text"), oss.str());
	}
	virtual unsigned int Main() = 0;
};
class Scene
{
public:
	explicit Scene(unsigned int  start)
	{
		next = start;
		now = start;
	}
	std::vector<Task*> tasks;
	unsigned int now;
	unsigned int next;
	enum Menu : unsigned int
	{
		SELECT,
		ADD_DATA,
		DELETE_DATA,
		CREATE_PASSWORD,
		ALLDATA_BROWSING,
		CHANGE_SEED,
		EXIT,
		MENU_NUM,
	};
	void Input()
	{
		std::cin >> now;
	}
};
class Select : public Task
{
	Scene* scene;
	unsigned int Main() override
	{
		for (unsigned int i = Scene::Menu::SELECT + 1; i < Scene::Menu::MENU_NUM; ++i)
		{
			std::cout << scene->tasks[i]->GetNum() << ":" << scene->tasks[i]->To_String() << std::endl;
		}
		do
		{
			scene->Input();
		} while (scene->now <= Scene::Menu::SELECT || scene->now >= Scene::Menu::MENU_NUM);
		Library::Clear();
		return scene->now;
	}
public:
	explicit Select(unsigned int num, Scene* scene)
		:Task(num)
	{
		this->scene = scene;
	}
};
class AddData : public Task
{
	unsigned int Main() override
	{

		return GetNum();
	}
public:
	explicit AddData(unsigned int num)
		:Task(num)
	{

	}
};
class DeleteData : public Task
{
	unsigned int Main() override
	{

		return GetNum();
	}
public:
	explicit DeleteData(unsigned int num)
		:Task(num)
	{

	}
};
class CreatePassword : public Task
{
	unsigned int Main() override
	{
		unsigned int value;
		std::cout << File::GetData(File::GetData(System::Get()->systemName, "text"), 100);
		std::cin >> value;
		std::string pass = Random::GetRand(File::GetData(File::GetData(System::Get()->systemName, "text"), 101), value);
		std::cout << pass << std::endl;
		return Scene::Menu::SELECT;
	}
public:
	explicit CreatePassword(unsigned int num)
		:Task(num)
	{

	}
};
class AllDataBrowsing : public Task
{
	unsigned int Main() override
	{

		return GetNum();
	}
public:
	explicit AllDataBrowsing(unsigned int num)
		:Task(num)
	{

	}
};
class Exit : public Task
{
	unsigned int Main() override
	{
		return GetNum();
	}
public:
	explicit Exit(unsigned int num)
		:Task(num)
	{

	}
};
class ChangeSeed : public Task
{
	unsigned int Main() override
	{
		std::stringstream ss;
		ss << File::GetData(System::Get()->systemName, "seedValue");
		unsigned int value;
		ss >> value;
		File::RandomSeedChenge(File::GetData(System::Get()->systemName, "seed"), value);
		return Scene::Menu::SELECT;
	}
public:
	explicit ChangeSeed(unsigned int num)
		:Task(num)
	{

	}
};
class MainMenu : public Scene
{
	unsigned int Main()
	{
		return this->tasks[this->now]->Main();
	}
	static MainMenu* mainMenu;
	explicit MainMenu()
		:Scene(Menu::SELECT)
	{
		this->tasks.emplace_back(new Select(Menu::SELECT, this));
		this->tasks.emplace_back(new AddData(Menu::ADD_DATA));
		this->tasks.emplace_back(new DeleteData(Menu::DELETE_DATA));
		this->tasks.emplace_back(new CreatePassword(Menu::CREATE_PASSWORD));
		this->tasks.emplace_back(new AllDataBrowsing(Menu::ALLDATA_BROWSING));
		this->tasks.emplace_back(new ChangeSeed(Menu::CHANGE_SEED));
		this->tasks.emplace_back(new Exit(Menu::EXIT));
		while (next != Menu::EXIT)
		{
			now = next;
			next = this->Main();
		}
	}
public:
	virtual ~MainMenu()
	{
		for (int i = 0; i < this->tasks.size(); ++i)
		{
			delete this->tasks[i];
		}
	}
	static void Create()
	{
		if (!MainMenu::mainMenu)
		{
			MainMenu::mainMenu = new MainMenu();
		}
	}
	static void Delete()
	{
		Library::Delete<MainMenu>(MainMenu::mainMenu);
	}
	static MainMenu* Get()
	{
		return mainMenu;
	}
};
System* System::mainSystem = nullptr;
ErrorCode* ErrorCode::error = nullptr;
MainMenu* MainMenu::mainMenu = nullptr;
int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	try
	{
		ErrorCode::Create();
		Random::Init();
		System::Create("PMSystem.ini");
		MainMenu::Create();
		MainMenu::Delete();
		System::Delete();
		ErrorCode::Delete();
	}
	catch (std::exception error)
	{
		std::cout << error.what();
		system("pause");
		return -1;
	}
}