
//--------------------------------
//データの読み込みと暗号化と複合化
//--------------------------------
//必要ファイルのインクルード
#include<iostream>
#include<fstream>
#include<string>
#include <sstream>
#include<vector>
#include "randmais.h"
using namespace std;
//------------------------------
//バイナリデータの表示
//------------------------------
void LoadBinaryData() {
	//ファイルをバイナリデータで読み込みます
	printf("ファイル名を入力\n");
	string Name;
		cin >> Name;
		ifstream ifs(Name + ".dat", ios::in | ios::binary);
		//ファイルが読み込めなかった時のエラー処理
		if (!ifs) {
			printf("ファイルが存在しません\n");
			return;
		}
		string a;
		while (getline(ifs, a)) {
			cout << a;
		}
		ifs.close();
		printf("\n");
}
//------------------------------
//テキストデータの表示
//------------------------------
void LoadTextData() {
	printf("ファイル名を入力\n");
	string Name;
	cin >> Name;
	ifstream ifs(Name + ".txt", ios::in | ios::binary);
	//ファイルが読み込めなかった時のエラー処理
	if (!ifs) {
		printf("ファイルが存在しません\n");
		return;
	}
	string a;
	while (getline(ifs, a)) {
		cout << a << endl;
	}
	printf("\n");
	ifs.close();
}
//------------------------------
//バイナリデータを複合化表示	
//------------------------------
void CompositeData() {
	printf("ファイル名を入力\n");
	string Name;
	cin >> Name;
	ifstream ifs(Name + ".dat", ios::in | ios::binary);
	//ファイルが読み込めなかった時のエラー処理
	if (!ifs) {
		printf("ファイルが存在しません\n");
		return;
	}
	char c;
	int i = 0;
	while (ifs.get(c)) {
		c = c ^ randomCipher[i];//データcの内容を暗号化
		cout << c;
		++i;
		if (i >= 40) {
			i = 0;
		}
	}
	printf("\n");
	ifs.close();
}
//-------------------------------
//テキストをバイナリデータで暗号化
//-------------------------------
void TextCipher() {
	printf("ファイル名を入力してください\n");
	//ファイルをバイナリデータで読み込みます
	string Name;
	cin >> Name;
	ifstream ifs(Name + ".txt", ios::in | ios::binary);
	//ファイルが読み込めなかった時のエラー処理
	while (!ifs) {
		printf("ファイルが存在しません\n");
		return;
	}
	//書き込み用としてファイルを読み込みます
	ofstream ofs(Name + ".dat", ios::out | ios::binary);
	//ファイルが読み込めなかった時のエラー処理
	if (!ofs) {
		return;
	}
	char c;
	int i = 0;
	while (ifs.get(c)) {//ifsの値を１つcに入れる(何もない場合falseになりループ終了)
		c = c ^ randomCipher[i];//データcの内容を暗号化
		ofs.put(c);//ofsに書き込む
		++i;
		if (i >= 40) {
			i = 0;
		}
	}
	ifs.close();
	ofs.close();
	printf("暗号化成功\n");
}
//-------------------------------
//ファイルの中の指定要素を抜き出す
//-------------------------------
void TextWithdraw() {
	printf("ファイル名を入力してください\n");
	string Name;
	cin >> Name;
	ifstream ifs(Name , ios::in);
	//ファイルが読み込めなかった時のエラー処理
	while (!ifs) {
		printf("ファイルが存在しません\n");
		return;
	}
	string s;
	int max = 0, min = 0;
	int count = 0;
	string text;
	int q = 0;
	do {
		printf("max:");
		cin >> max;
		printf("min:");
		cin >> min;
		printf("項目:");
		cin >> text;
		text = text + " ";
		printf("取り出す要素の数:");
		cin >> count;
		printf("\n");
		while (getline(ifs, s)) {
			if (s.substr(min, max) == text) {
				string t;
				t.resize(count);
				istringstream is(s.substr(max));
				for (int i = 0; i < count; ++i) {
					
					is >> t[i];
					cout << t[i] << " ";
				}
				printf("\n");
			}
		}
		
		printf("1：続ける\n0：終了する\n");
		cin >> q;
	} while (q == 1);
	ifs.close();
}
void TextMapWithdraw() {
	printf("ファイル名を入力してください\n");
	string Name;
	cin >> Name;
	ifstream ifs(Name, ios::in);
	//ファイルが読み込めなかった時のエラー処理
	while (!ifs) {
		printf("ファイルが存在しません\n");
		return;
	}
	string m;
	int x = 0, y = 0;	
	int count = 0;
	int a[8][15];
	while (getline(ifs, m)) {
		if (m.substr(0, 2) == "X ") {
			istringstream is(m.substr(2));
			is >> x;
			cout << "X " << x << endl;
		}
		if (m.substr(0, 2) == "Y ") {
			istringstream is(m.substr(2));
			is >> y;
			cout << "Y " << y << endl;
		}
		if (m.substr(0, 8) == "MapChip ") {
			istringstream is(m.substr(8));
			for (int i = 0; i < x; ++i) {
				is >> a[count][i];
				cout << a[count][i] << " ";
			}
			printf("\n");
			count++;
		}
	}
	ifs.close();
}
//-------------------------------
//終了しますって出すだけ
//-------------------------------
void Finarize() {
	printf("アプリケーションを終了します\n");
}
//-------------------------------
//メイン処理
//-------------------------------
void main() {
	int i = 1;
	while (i) {
		printf("_____________________________________\n");
		printf("|使用する機能を選択してください      |\n"
			   "|1:バイナリデータの中身の確認        |\n"
			   "|2:バイナリデータを複合化して表示する|\n"
			   "|3:テキストをバイナリに暗号化        |\n"
			   "|4:テキストデータの中身の確認        |\n"
			   "|0:アプリケーションを終了する        |\n"
			   "|____________________________________|\n");
		cin >> i;
		switch (i)
		{
		case 1:
			LoadBinaryData();
			break;
		case 2:
			CompositeData();
			break;
		case 3:
			TextCipher();
			break;
		case 4:
			LoadTextData();
			break;
		case 5:
			TextWithdraw();
			break;
		case 6:
			TextMapWithdraw();
			break;
		case 0:
			Finarize();
			return;
			break;
		default:
			Finarize();
			return;
			break;
		}
	}
}