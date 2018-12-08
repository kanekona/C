#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <iosfwd>
#include <xstring>
#include <sstream>
struct Map
{
	std::vector<std::vector<int>> _arr;
	int mapx, mapy;
};

void main()
{
	//map����
	Map map;
	//�t�@�C���p�X�w��
	std::string file = "./data/map/test.csv";
	//�t�@�C���̓ǂݍ���
	std::ifstream ifs(file, std::ios::in | std::ios::binary);
	//�ǂݍ��߂Ȃ��������̃G���[����
	if (!ifs) { return; }
	//�ǂݍ��񂾃f�[�^�����Ă����ϐ�
	std::string line;
	//���ǂݍ���
	std::getline(ifs, line);
	//��؂�œǂݍ���
	std::istringstream _is(line);
	/*std::string text;
	std::getline(_is, text, ',');
	(std::stringstream)text >> map.mapx;*/
	_is >> map.mapx;
	_is >> map.mapy;
	map._arr.resize(map.mapy);
	for (int i = 0; i < map.mapy; ++i)
	{
		map._arr[i].resize(map.mapx);
	}
	for (int y = 0; y < map.mapy; ++y) {
		std::string lineText;
		std::getline(ifs, lineText);
		std::istringstream  ss_lt(lineText);
		for (int x = 0; x < map.mapx; ++x) {
			std::string  text;
			std::getline(ss_lt, text, ',');
			(std::stringstream)text >> map._arr[y][x];
		}
	}
	ifs.close();

	std::cout << "X:" << map.mapx << "Y:" << map.mapy << std::endl;
	for (int y = 0; y < map.mapy; ++y)
	{
		for (int x = 0; x < map.mapx; ++x)
		{
			std::cout << map._arr[y][x];
		}
		std::cout << std::endl;
	}

	map._arr.clear();
}