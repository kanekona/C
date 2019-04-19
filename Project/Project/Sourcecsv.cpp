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
	//map生成
	Map map;
	//ファイルパス指定
	std::string file = "./data/map/test.csv";
	//ファイルの読み込み
	std::ifstream ifs(file, std::ios::in | std::ios::binary);
	//読み込めなかった時のエラー処理
	if (!ifs) { return; }
	//読み込んだデータを入れておく変数
	std::string line;
	//一列読み込み
	std::getline(ifs, line);
	//区切りで読み込む
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