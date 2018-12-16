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
	void Pause()
	{
		system("pause");
	}
	struct UserData
	{
		std::string passWord;
		std::string userName;
		std::string acount;
	};
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
			if (tag == line.substr(0, line.find_first_of("=")))
			{
				return line.substr(line.find_first_of("=") + 1);
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
class Scene;
class Task
{
	const unsigned int num;
	Scene* scene;
public:
	explicit Task(unsigned int num,Scene* scene)
		:num(num)
	{
		this->scene = scene;
	}
	virtual ~Task()
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
	unsigned int IsPlay(unsigned int id)
	{
		unsigned int play;
		std::cout << File::GetData(File::GetData(System::Get()->systemName, "text"), id) << std::endl;
		std::cout << File::GetData(File::GetData(System::Get()->systemName, "text"), 107);
		std::cin >> play;
		return play;
	}
	Scene* GetScene()
	{
		return this->scene;
	}
	virtual unsigned int Main() = 0;
	virtual void SetSelect() = 0;
};
class Scene
{
	std::vector<Task*> tasks;
	unsigned int now;
	unsigned int next;
	unsigned int pre;
public:
	explicit Scene(unsigned int  start)
	{
		next = start;
		now = start;
		pre = start;
	}
	virtual ~Scene()
	{
		for (int i = 0; i < this->tasks.size(); ++i)
		{
			Library::Delete<Task>(this->tasks[i]);
			this->tasks[i] = nullptr;
		}
	}
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
	template<class T> T* GetScene(unsigned int index)
	{
		return (T*)&(*this->tasks[index]);
	}
	void Main()
	{
		now = next;
		next = this->tasks[this->now]->Main();
		pre = now;
	}
	unsigned int GetNow()
	{
		return this->now;
	}
	unsigned int GetPre()
	{
		return this->pre;
	}
	unsigned int GetNext()
	{
		return this->next;
	}
	Task* GetTask(unsigned int id)
	{
		return this->tasks[id];
	}
	void Add(Task* task)
	{
		this->tasks.emplace_back(task);
	}
};
class Select : public Task
{
	std::vector<Scene::Menu> selecter;
	unsigned int Main() override
	{
		unsigned int now;
		GetScene()->GetTask(GetScene()->GetPre())->SetSelect();
		for (unsigned int i = 0; i < selecter.size(); ++i)
		{
			std::cout << i << ":" << GetScene()->GetTask(this->selecter[i])->To_String() << std::endl;
		}
		do
		{
			std::cin >> now;
		} while (now < 0 || now >= selecter.size());
		return selecter[now];
	}
	void SetSelect() override;
public:
	explicit Select(unsigned int num, Scene* scene)
		:Task(num,scene)
	{
	}
	virtual ~Select()
	{
		this->selecter.clear();
	}
	void Add(const Scene::Menu menu)
	{
		this->selecter.emplace_back(menu);
	}
	void Clear()
	{
		this->selecter.clear();
	}
};
class AddData : public Task
{
	Library::UserData data;
	void InputUserName()
	{
		std::cout << File::GetData(File::GetData(System::Get()->systemName, "text"), 102) << ":";
		std::cin >> data.userName;
	}
	void InputPassWord()
	{
		std::cout << File::GetData(File::GetData(System::Get()->systemName, "text"), 103) << ":";
		std::cin >> data.passWord;
	}
	void InputAcount()
	{
		std::cout << File::GetData(File::GetData(System::Get()->systemName, "text"), 104) << ":";
		std::cin >> data.acount;
	}
	void GetPassWord();
	void Input()
	{
		this->InputAcount();
		this->InputUserName();
		if (GetScene()->GetPre() != Scene::Menu::CREATE_PASSWORD)
		{
			this->InputPassWord();
		}
		else
		{
			this->GetPassWord();
		}
	}
	void Output()
	{
		std::string text = File::GetData(File::GetData(System::Get()->systemName, "text"), 105) + data.acount + " " + data.userName + " " + data.passWord + "\n";
		File::AddOutput(File::GetData(System::Get()->systemName, "data"), text);
	}

	unsigned int Main() override
	{
		this->Input();
		this->Output();
		return Scene::Menu::SELECT;
	}
	void SetSelect() override;
public:
	explicit AddData(unsigned int num,Scene* scene)
		:Task(num,scene)
	{
	}
};
class DeleteData : public Task
{
	unsigned int Main() override
	{
		return Scene::Menu::SELECT;
	}
	void SetSelect() override;
public:
	explicit DeleteData(unsigned int num,Scene* scene)
		:Task(num,scene)
	{

	}
};
class CreatePassword : public Task
{
	Library::UserData userData;
	unsigned int Main() override
	{
		unsigned int value;
		std::cout << File::GetData(File::GetData(System::Get()->systemName, "text"), 100);
		std::cin >> value;
		userData.passWord = Random::GetRand(File::GetData(File::GetData(System::Get()->systemName, "text"), 101), value);
		std::cout << userData.passWord << std::endl;
		return this->IsPlay(108) ? Scene::Menu::ADD_DATA : Scene::Menu::SELECT;
	}
	void SetSelect() override;
public:
	explicit CreatePassword(unsigned int num, Scene* scene)
		:Task(num,scene)
	{

	}
	std::string GetPassWord()
	{
		return this->userData.passWord;
	}
};
class AllDataBrowsing : public Task
{
	std::vector<Library::UserData> userDataList;
	unsigned int Main() override
	{
		this->Load();
		this->Draw();
		this->Reset();
		return this->IsPlay(106) ? Scene::Menu::SELECT : Scene::Menu::EXIT;
	}
	void Load()
	{
		std::ifstream ifs(File::GetData(System::Get()->systemName, "data"));
		if (!ifs)
		{
			throw std::runtime_error(ErrorCode::Get()->GetCode(2));
		}
		std::string line;
		std::string tag = File::GetData(File::GetData(System::Get()->systemName, "text"), 105);
		while (std::getline(ifs, line))
		{
			if (line.at(0) == '/')
			{
				continue;
			}
			if (tag.substr(0,tag.find("=")) == line.substr(0, line.find_first_of("=")))
			{
				std::string text = line.substr(line.find_first_of("=") + 1);
				Library::UserData userdata;
				std::istringstream iss(text);
				iss >> userdata.acount >> userdata.userName >> userdata.passWord;
				this->userDataList.push_back(userdata);
			}
		}
	}
	void Draw()
	{
		for (auto id = this->userDataList.begin(); id != this->userDataList.end(); ++id)
		{
			std::cout << File::GetData(File::GetData(System::Get()->systemName, "text"), 104) << ":" << id->acount << std::endl;
			std::cout << File::GetData(File::GetData(System::Get()->systemName, "text"), 102) << ":" << id->userName << std::endl;
			std::cout << File::GetData(File::GetData(System::Get()->systemName, "text"), 103) << ":" << id->passWord << std::endl;
			std::cout << "_________________________________________________________" << std::endl;
		}
	}
	void Reset()
	{
		this->userDataList.clear();
	}
	void SetSelect() override;
public:
	explicit AllDataBrowsing(unsigned int num, Scene* scene)
		:Task(num,scene)
	{

	}
};
class Exit : public Task
{
	unsigned int Main() override
	{
		return Scene::Menu::EXIT;
	}
	void SetSelect() override;
public:
	explicit Exit(unsigned int num, Scene* scene)
		:Task(num,scene)
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
		Library::Pause();
		return Scene::Menu::SELECT;
	}
	void SetSelect() override;
public:
	explicit ChangeSeed(unsigned int num, Scene* scene)
		:Task(num,scene)
	{

	}
};
class MainMenu : public Scene
{
	static MainMenu* mainMenu;
public:
	explicit MainMenu()
		:Scene(Menu::SELECT)
	{
		this->Add(new Select(Menu::SELECT, this));	
		this->Add(new AddData(Menu::ADD_DATA, this));
		this->Add(new DeleteData(Menu::DELETE_DATA, this));
		this->Add(new CreatePassword(Menu::CREATE_PASSWORD, this));
		this->Add(new AllDataBrowsing(Menu::ALLDATA_BROWSING, this));
		this->Add(new ChangeSeed(Menu::CHANGE_SEED, this));
		this->Add(new Exit(Menu::EXIT, this));
	}
	virtual ~MainMenu()
	{
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
	void Run()
	{

		while (GetNext() != Menu::EXIT)
		{
			this->Main();
			Library::Clear();
		}
	}
};
void Select::SetSelect() {
	MainMenu::Get()->GetScene<Select>(Scene::SELECT)->Clear();
	MainMenu::Get()->GetScene<Select>(Scene::SELECT)->Add(Scene::ADD_DATA);
	MainMenu::Get()->GetScene<Select>(Scene::SELECT)->Add(Scene::DELETE_DATA);
	MainMenu::Get()->GetScene<Select>(Scene::SELECT)->Add(Scene::CREATE_PASSWORD);
	MainMenu::Get()->GetScene<Select>(Scene::SELECT)->Add(Scene::ALLDATA_BROWSING);
	MainMenu::Get()->GetScene<Select>(Scene::SELECT)->Add(Scene::CHANGE_SEED);
	MainMenu::Get()->GetScene<Select>(Scene::SELECT)->Add(Scene::EXIT);
}
void AddData::SetSelect()
{
	MainMenu::Get()->GetScene<Select>(Scene::SELECT)->Clear();
	MainMenu::Get()->GetScene<Select>(Scene::SELECT)->Add(Scene::ADD_DATA);
	MainMenu::Get()->GetScene<Select>(Scene::SELECT)->Add(Scene::DELETE_DATA);
	MainMenu::Get()->GetScene<Select>(Scene::SELECT)->Add(Scene::CREATE_PASSWORD);
	MainMenu::Get()->GetScene<Select>(Scene::SELECT)->Add(Scene::ALLDATA_BROWSING);
	MainMenu::Get()->GetScene<Select>(Scene::SELECT)->Add(Scene::CHANGE_SEED);
	MainMenu::Get()->GetScene<Select>(Scene::SELECT)->Add(Scene::EXIT);
}
void DeleteData::SetSelect()
{
	MainMenu::Get()->GetScene<Select>(Scene::SELECT)->Clear();
	MainMenu::Get()->GetScene<Select>(Scene::SELECT)->Add(Scene::ADD_DATA);
	MainMenu::Get()->GetScene<Select>(Scene::SELECT)->Add(Scene::DELETE_DATA);
	MainMenu::Get()->GetScene<Select>(Scene::SELECT)->Add(Scene::CREATE_PASSWORD);
	MainMenu::Get()->GetScene<Select>(Scene::SELECT)->Add(Scene::ALLDATA_BROWSING);
	MainMenu::Get()->GetScene<Select>(Scene::SELECT)->Add(Scene::CHANGE_SEED);
	MainMenu::Get()->GetScene<Select>(Scene::SELECT)->Add(Scene::EXIT);
}
void CreatePassword::SetSelect()
{
	MainMenu::Get()->GetScene<Select>(Scene::SELECT)->Clear();
	MainMenu::Get()->GetScene<Select>(Scene::SELECT)->Add(Scene::ADD_DATA);
	MainMenu::Get()->GetScene<Select>(Scene::SELECT)->Add(Scene::DELETE_DATA);
	MainMenu::Get()->GetScene<Select>(Scene::SELECT)->Add(Scene::CREATE_PASSWORD);
	MainMenu::Get()->GetScene<Select>(Scene::SELECT)->Add(Scene::ALLDATA_BROWSING);
	MainMenu::Get()->GetScene<Select>(Scene::SELECT)->Add(Scene::CHANGE_SEED);
	MainMenu::Get()->GetScene<Select>(Scene::SELECT)->Add(Scene::EXIT);
}
void AllDataBrowsing::SetSelect()
{
	MainMenu::Get()->GetScene<Select>(Scene::SELECT)->Clear();
	MainMenu::Get()->GetScene<Select>(Scene::SELECT)->Add(Scene::ADD_DATA);
	MainMenu::Get()->GetScene<Select>(Scene::SELECT)->Add(Scene::DELETE_DATA);
	MainMenu::Get()->GetScene<Select>(Scene::SELECT)->Add(Scene::CREATE_PASSWORD);
	MainMenu::Get()->GetScene<Select>(Scene::SELECT)->Add(Scene::ALLDATA_BROWSING);
	MainMenu::Get()->GetScene<Select>(Scene::SELECT)->Add(Scene::CHANGE_SEED);
	MainMenu::Get()->GetScene<Select>(Scene::SELECT)->Add(Scene::EXIT);
}
void Exit::SetSelect()
{
	MainMenu::Get()->GetScene<Select>(Scene::SELECT)->Clear();
	MainMenu::Get()->GetScene<Select>(Scene::SELECT)->Add(Scene::ADD_DATA);
	MainMenu::Get()->GetScene<Select>(Scene::SELECT)->Add(Scene::DELETE_DATA);
	MainMenu::Get()->GetScene<Select>(Scene::SELECT)->Add(Scene::CREATE_PASSWORD);
	MainMenu::Get()->GetScene<Select>(Scene::SELECT)->Add(Scene::ALLDATA_BROWSING);
	MainMenu::Get()->GetScene<Select>(Scene::SELECT)->Add(Scene::CHANGE_SEED);
	MainMenu::Get()->GetScene<Select>(Scene::SELECT)->Add(Scene::EXIT);
}
void ChangeSeed::SetSelect()
{
	MainMenu::Get()->GetScene<Select>(Scene::SELECT)->Clear();
	MainMenu::Get()->GetScene<Select>(Scene::SELECT)->Add(Scene::ADD_DATA);
	MainMenu::Get()->GetScene<Select>(Scene::SELECT)->Add(Scene::DELETE_DATA);
	MainMenu::Get()->GetScene<Select>(Scene::SELECT)->Add(Scene::CREATE_PASSWORD);
	MainMenu::Get()->GetScene<Select>(Scene::SELECT)->Add(Scene::ALLDATA_BROWSING);
	MainMenu::Get()->GetScene<Select>(Scene::SELECT)->Add(Scene::CHANGE_SEED);
	MainMenu::Get()->GetScene<Select>(Scene::SELECT)->Add(Scene::EXIT);
}
void AddData::GetPassWord() 
{
	data.passWord = GetScene()->GetScene<CreatePassword>(Scene::Menu::CREATE_PASSWORD)->GetPassWord();
}
System* System::mainSystem = nullptr;
ErrorCode* ErrorCode::error = nullptr;
MainMenu* MainMenu::mainMenu = nullptr;
int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	//_CrtSetBreakAlloc(174);
	try
	{
		ErrorCode::Create();
		Random::Init();
		System::Create("PMSystem.ini");
		MainMenu::Create();
		MainMenu::Get()->Run();
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