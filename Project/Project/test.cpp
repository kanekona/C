//--------------------------------
//データの読み込みと暗号化と複合化
//--------------------------------
//必要ファイルのインクルード
#include<iostream>
#include<fstream>
#include<string>

#define _RPTN
//std省略用
using namespace std;
void main() {
	//ファイルをバイナリデータで読み込みます
	ifstream ifs("test.txt", ios::in | ios::binary);
	//ファイルが読み込めなかった時のエラー処理
	if (!ifs) {
		_RPTN(_CRT_WARN, ("ファイルが存在しません"));
		return;
	}
	//書き込み用としてファイルを読み込みます
	ofstream ofs("test.dat", ios::out | ios::binary);
	//ファイルが読み込めなかった時のエラー処理
	if (!ofs) {
		_RPTN(_CRT_WARN, ("ファイルが存在しません"));
	}
	//格納用の変数
	char c;
	while (ifs.get(c)) {//ifsの値を１つcに入れる(何もない場合falseになりループ終了)
		if (c != ','&&c != '\n' && c != ' ') {//区切り用の,と改行を除外
			c = c ^ 0x53;//データcの内容を暗号化
		}
		ofs.put(c);//ofsに書き込む
	}

	//クローズ処理
	ifs.close();
	ofs.close();

	//ファイルをバイナリデータで読み込みます
	ifstream ifs2("test.dat", ios::in | ios::binary);
	//ファイルが読み込めなかった時のエラー処理
	if (!ifs2) {
		_RPTN(_CRT_WARN, ("ファイルが存在しません"));
		return;
	}

	//書き込み用としてファイルを読み込みます
	ofstream ofs2("test2.csv", ios::in | ios::binary);
	//ファイルが読み込めなかった時のエラー処理
	if (!ofs2) {
		_RPTN(_CRT_WARN, ("ファイルが存在しません"));
		return;
	}
	//格納用の変数
	char c2;
	int a[15];
	string word;
	
	while (ifs2.get(c2)) {//ifsの値を１つcに入れる(何もない場合falseになりループ終了)
		if (c2 != ','&&c2 != '\n' && c2!= ' ') {//区切り用の,と改行を除外
			c2 = c2 ^ 0x53;//暗号化されたデータcの内容を複合化
		}
		ofs2.put(c2);//ofsに書き込む
	}

	//ファイルをバイナリデータで読み込みます
	ifstream ifs3("test.txt", ios::in|ios::binary);
	//ファイルが読み込めなかった時のエラー処理
	if (!ifs3) {
		_RPTN(_CRT_WARN, ("ファイルが存在しません"));
		return;
	}
	
	for (int i = 0; i < 15; ++i) {
		ifs3 >> a[i];
		
		printf("%d\n", a[i]);
	}

	//クローズ処理
	ifs2.close();
	ifs3.close();
	ofs2.close();
	system("Pause");
}