#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#define new ::new(_NORMAL_BLOCK, __FILE__, __LINE__)

#include <iostream>
#include <time.h>

#include <vector>

#define OUTPUT_CONSTRUCTOR 0
/**
#if OUTPUT_CONSTRUCTOR

#endif //OUTPUT_CONSTRUCTOR
*/

/**
*@file FunctionReturnTest.cpp
*@brief 関数の戻り値によるコンストラクタの呼ばれる回数とコピーサイズによる負荷の確認
*@author kanekona
*@data 2019/03/11
*@details
*/

class Vector3
{
public:
	float x, y, z;
	std::string s;
	std::string s1;
	std::string s2;
	std::string s3;
	std::string s4;
	std::string s5;
	/**
	* @constructor
	*/
	Vector3()
	{
#if OUTPUT_CONSTRUCTOR
		std::cout << "Vector3::constructor\n";
#endif
	}
	~Vector3()
	{
#if OUTPUT_CONSTRUCTOR
		std::cout << "Vector3::destructor\n";
#endif //OUTPUT_CONSTRUCTOR
	}
	Vector3(const float vx, const float vy, const float vz)
	{
#if OUTPUT_CONSTRUCTOR
		std::cout << "Vector3::constructor\n";
#endif //OUTPUT_CONSTRUCTOR
		x = vx;
		y = vy;
		z = vz;
	}
	//Vector3(Vector& v)
	//{
	//	std::cout << "Vector3::constructor\n";
	//	x = v.x;
	//	y = v.y;
	//	z = v.z;
	//}
	//Vector3(Vector3 v)
	//{
	//	std::cout << "Vector3::constructor\n";
	//	x = v.x;
	//	y = v.y;
	//	z = v.z;
	//}

	void Output()
	{
		std::cout << x << " " << y << " " << z << std::endl;
	}
	void OutputConst() const
	{
		std::cout << x << " " << y << " " << z << std::endl;
	}
	/**
	* @operator
	*/
	void operator+=(Vector3& v)
	{
		x += v.x;
		y += v.y;
		z += v.z;
	}
	const Vector3& operator+(Vector3& v)
	{
		return Vector3(x + v.x, y + v.y, z + v.z);
	}

};

class Test
{
	Vector3 vector3;
public:
	Test()
	{
#if OUTPUT_CONSTRUCTOR
		std::cout << "Test::constructor\n";
#endif //OUTPUT_CONSTRUCTOR
	}
	~Test()
	{
#if OUTPUT_CONSTRUCTOR
		std::cout << "Test::destructor\n";
#endif //OUTPUT_CONSTRUCTOR
	}
	const Vector3& GetVector() const
	{
		return vector3;
	}
	Vector3 GetVectorCopy() const
	{
		return vector3;
	}
	const void GetVector(Vector3* vector) const
	{
		*vector = vector3;
	}
	void SetVector(const Vector3& vec)
	{
		vector3 = vec;
	}
	void Output()
	{
		std::cout << vector3.x << " " << vector3.y << " " << vector3.z << std::endl;
	}
};

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	const unsigned long int ARRAY_NUMBER = 10000000 / 2 / 2;
	static Test TestArray[ARRAY_NUMBER];
	Vector3 defaultVector(10.0f, 2.0f, 300.0f);

	{
		time_t beginTime = time(NULL);
		for (int i = 0; i < ARRAY_NUMBER; ++i)
		{
			TestArray[i].SetVector(defaultVector);
			Vector3 Get;
			Get = TestArray[i].GetVector();
		}
		printf("%f\n", difftime(time(NULL), beginTime));
	}

	{
		time_t beginTime = time(NULL);
		for (int i = 0; i < ARRAY_NUMBER; ++i)
		{
			TestArray[i].SetVector(defaultVector);
			Vector3 Get;
			Get = TestArray[i].GetVectorCopy();
		}
		printf("%f\n", difftime(time(NULL), beginTime));
	}

	{
		time_t beginTime = time(NULL);
		for (int i = 0; i < ARRAY_NUMBER; ++i)
		{
			TestArray[i].SetVector(defaultVector);
			Vector3 Get;
			TestArray[i].GetVector(&Get);
		}
		printf("%f\n", difftime(time(NULL), beginTime));
	}

	system("pause");
	return 0;
}