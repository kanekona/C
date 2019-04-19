#include <vector>
#include <iostream>
#include <string>
class Object
{
public:
	Object()
	{
		this->name = "";
		this->id = 0;
	}
	Object(const std::string& s, const int i)
	{
		this->name = s;
		this->id = i;
	}
	std::string name;
	int id;
};
int main()
{
	std::vector<Object> data;
	data.push_back(Object());
	if(1)
	{
		std::string name = "aaa";
		Object a = Object(name, 10);
		data.push_back(a);
	}
	for (auto id = data.begin(); id != data.end(); ++id)
	{
		std::cout << id->id << ":" << id->name << std::endl;
	}
	system("pause");
}