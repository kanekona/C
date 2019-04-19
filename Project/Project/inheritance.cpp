#include <iostream>
#include <vector>
#include <string>
#include <typeinfo>
//メモリリーク検知
#if (_DEBUG)
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#define new ::new(_NORMAL_BLOCK, __FILE__, __LINE__)
#endif
/**
*データ型が等しいかをtypeidを使って調べる
*/

class Entity
{
public:
	explicit Entity()
	{
		tag = "Entity";
	}
	virtual void Update()
	{
		std::cout << "Entity" << num << std::endl;
	}
	size_t num;
	std::string tag;
	static size_t id;
	static std::vector<Entity*> e;
};

class Player : public Entity
{
	virtual void Update() override
	{
		std::cout << "Player" << num << std::endl;
	}
public:
	explicit Player()
	{
		tag = "Player";
	}
};
class Enemy : public Entity
{
	virtual void Update() override
	{
		std::cout << "Enemy" << num << std::endl;
	}
public:
	explicit Enemy()
	{
		tag = "Enemy";
	}
};
class Monster : public Entity
{
public:
	explicit Monster()
	{
		tag = "Monster";
	}
};

size_t NewID(Entity* add)
{
	for (auto it : Entity::e)
	{
		if (typeid(*add) == typeid(*it))
		{
			return it->num;
		}
	}
	Entity::e.emplace_back(add);
	return ++Entity::id;
}
template <class T> size_t GetId()
{
	for (auto it : Entity::e)
	{
		if (typeid(*it) == typeid(T))
		{
			return it->num;
		}
	}
	return 0;
}
std::vector<Entity*> entitys;
template <class T> T* Get()
{
	for (auto it : entitys)
	{
		if ((typeid(T) == typeid(*it)))
		{
			return static_cast<T*>(it);
		}
	}
	return nullptr;
}
template <class T> std::vector<T*> Gets()
{
	std::vector<T*> vector;
	for (auto it : entitys)
	{
		if ((typeid(T) == typeid(*it)))
		{
			vector.emplace_back(static_cast<T*>(it));
		}
	}
	return vector;
}

size_t Entity::id = 0;
std::vector<Entity*> Entity::e;

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	{
		//std::vector<Entity*> entitys;
		entitys.emplace_back(new Enemy());
		entitys.emplace_back(new Player());
		entitys.emplace_back(new Enemy());
		entitys.emplace_back(new Player());
		entitys.emplace_back(new Monster());
		//これなら成功する
		for (auto it : entitys)
		{
			it->num = NewID(it);
		}
		for (auto it : entitys)
		{
			it->Update();
		}

		delete entitys[1];
		entitys[1] = nullptr;
		for (auto it = entitys.begin(); it != entitys.end();)
		{
			if (*it == nullptr)
			{
				it = entitys.erase(it);
			}
			else
			{
				++it;
			}
		}
		for (auto it = Entity::e.begin(); it != Entity::e.end();)
		{
			if (*it == nullptr)
			{
				it = Entity::e.erase(it);
			}
			else
			{
				++it;
			}
		}
		if (Get<Player>() != nullptr)
		{
			std::cout <<  Get<Player>()->tag << Get<Player>()->num << std::endl;
		}
		std::cout << Gets<Entity>().size() << std::endl;
		for (auto it : entitys)
		{
			delete it;
		}
	}
	{
		Entity* entity = new Entity();
		Player* player = new Player();
		Enemy* enemy = new Enemy();
		Monster* monster = new Monster();
		Entity* entpla = new Player();
		Entity* entene = new Enemy();
		Entity* entmns = new Monster();

		////PlayerとPlayerは同じ認識
		//std::cout << (typeid(*entpla) == typeid(*player)) << std::endl;
		////EntityとEnemyは別物と認識
		//std::cout << (typeid(*entity) == typeid(*entene)) << std::endl;
		////ポインタじゃ同じ扱い
		//std::cout << (typeid(entpla) == typeid(entene)) << std::endl;
		////EnemyとPlayerは別物と認識
		//std::cout << (typeid(*entpla) == typeid(*entene)) << std::endl;
		////EntityとMonsterは別物
		//std::cout << (typeid(*monster) == typeid(*entity)) << std::endl;
		////これも別物と認識
		//std::cout << (typeid(*entmns) == typeid(*entity)) << std::endl;
		////型との判定
		//std::cout << (typeid(*entpla) == typeid(Player)) << std::endl;
		delete entity;
		delete player;
		delete enemy;
		delete entpla;
		delete entene;
		delete monster;
		delete entmns;
	}
	system("pause");
}