#include <thread>
#include <mutex>
#include <vector>
#include <string>
#include <iostream>
#include <time.h>
#include <future>
#include <xtr1common>
const unsigned int DataNum = 1000000;
class Task
{
public:
	virtual void Init() = 0;
	virtual void Delete() = 0;
};
class Param : public std::thread
{
public:
	std::mutex mutex;
	bool flag;
	template<class _Fn,
		class... _Args,
		class = enable_if_t<!is_same_v<decay_t<_Fn>, thread>>>
	explicit Param(_Fn&& _Fx, _Args&&... _Ax)
		:thread(_Fx,_Ax)
	{
		flag = false;
	}
	
};

class Data
{
public:
	std::vector<std::string*> str_data;
	std::vector<int*> f_data;
	Data()
	{
		//this->Init();
	}
	~Data()
	{
		//this->Delete();
	}
	void Init()
	{
		for (int i = 0; i < DataNum; ++i)
		{
			this->str_data.push_back(new std::string(std::to_string(i)));
			this->f_data.push_back(new int(i));
		}
	}
	void Delete()
	{
		for (int i = 0; i < DataNum; ++i)
		{
			delete this->str_data[i];
			delete this->f_data[i];
		}
		this->str_data.clear();
		this->f_data.clear();
	}
	static void _Init(Data& data)
	{
		for (int i = 0; i < DataNum; ++i)
		{
			data.str_data.push_back(new std::string(std::to_string(i)));
			data.f_data.push_back(new int(i));
		}
	}
	static void _Delete(Data& data)
	{
		for (int i = 0; i < DataNum; ++i)
		{
			delete data.str_data[i];
			delete data.f_data[i];
		}
		data.str_data.clear();
		data.f_data.clear();
	}
	void ThreadInit()
	{
		std::thread thread(Data::_Init, std::ref(*this));
		thread.join();
		Param param(Data::_Init, std::ref(*this));
		param.join();
	}
	void ThreadDelete()
	{
	/*	std::thread thread(Data::_Delete, std::ref(*this));
		thread.join();*/
		Param param(Data::_Delete, std::ref(*this));
		param.join();
	}
	void cout()
	{
		for (int i = 0; i < DataNum; ++i)
		{
			std::cout << this->str_data[i] << ":";
		}
		std::cout << "\n";
		for (int i = 0; i < DataNum; ++i)
		{
			std::cout << this->f_data[i] << ":";
		}
		std::cout << "\n";
	}
};

int main()
{
	char date[64];
	time_t t = time(NULL);
	strftime(date, sizeof(date), "%Y/%m/%d %a %H:%M:%S", localtime(&t));
	printf("%s\n", date);
	Data data /*= new Data*/;
	data.ThreadInit();
	//data.cout();
	data.ThreadDelete();
	//delete data;
	t = time(NULL);
	strftime(date, sizeof(date), "%Y/%m/%d %a %H:%M:%S", localtime(&t));
	printf("%s\n", date);
	system("pause");
}