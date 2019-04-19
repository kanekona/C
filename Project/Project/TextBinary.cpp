//--------------------------------
//データの読み込みと暗号化と複合化
//--------------------------------
//必要ファイルのインクルード
#include<iostream>
#include<fstream>
#include<string>
#include "randmais.h"
using namespace std;
void main() {
	printf("ファイル名を入力してください\n");
	//ファイルをバイナリデータで読み込みます
	string Name;
	cin >> Name;
	ifstream ifs(Name + ".txt", ios::in | ios::binary);
	//ファイルが読み込めなかった時のエラー処理
	while(!ifs) {
		printf("ファイルが存在しません\n");
		printf("アプリケーションを終了します\n");
		system("pause");
		return;
	}
	//書き込み用としてファイルを読み込みます
	ofstream ofs( Name+".dat", ios::out | ios::binary);
	//ファイルが読み込めなかった時のエラー処理
	if (!ofs) {
		return;
	}
	char c;
	int i = 0;
	while (ifs.get(c)) {//ifsの値を１つcに入れる(何もない場合falseになりループ終了)
		if (c != ','&&c != '\n' && c != ' ') {//区切り用の,と改行を除外
			c = c ^ randomCipher[i];//データcの内容を暗号化
		}
		ofs.put(c);//ofsに書き込む
		++i;
	}
	ifs.close();
	ofs.close();
	printf("暗号化成功\n");
	system("pause");
}