
//--------------------------------
//�f�[�^�̓ǂݍ��݂ƈÍ����ƕ�����
//--------------------------------
//�K�v�t�@�C���̃C���N���[�h
#include<iostream>
#include<fstream>
#include<string>
#include <sstream>
#include<vector>
#include "randmais.h"
using namespace std;
//------------------------------
//�o�C�i���f�[�^�̕\��
//------------------------------
void LoadBinaryData() {
	//�t�@�C�����o�C�i���f�[�^�œǂݍ��݂܂�
	printf("�t�@�C���������\n");
	string Name;
		cin >> Name;
		ifstream ifs(Name + ".dat", ios::in | ios::binary);
		//�t�@�C�����ǂݍ��߂Ȃ��������̃G���[����
		if (!ifs) {
			printf("�t�@�C�������݂��܂���\n");
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
//�e�L�X�g�f�[�^�̕\��
//------------------------------
void LoadTextData() {
	printf("�t�@�C���������\n");
	string Name;
	cin >> Name;
	ifstream ifs(Name + ".txt", ios::in | ios::binary);
	//�t�@�C�����ǂݍ��߂Ȃ��������̃G���[����
	if (!ifs) {
		printf("�t�@�C�������݂��܂���\n");
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
//�o�C�i���f�[�^�𕡍����\��	
//------------------------------
void CompositeData() {
	printf("�t�@�C���������\n");
	string Name;
	cin >> Name;
	ifstream ifs(Name + ".dat", ios::in | ios::binary);
	//�t�@�C�����ǂݍ��߂Ȃ��������̃G���[����
	if (!ifs) {
		printf("�t�@�C�������݂��܂���\n");
		return;
	}
	char c;
	int i = 0;
	while (ifs.get(c)) {
		c = c ^ randomCipher[i];//�f�[�^c�̓��e���Í���
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
//�e�L�X�g���o�C�i���f�[�^�ňÍ���
//-------------------------------
void TextCipher() {
	printf("�t�@�C��������͂��Ă�������\n");
	//�t�@�C�����o�C�i���f�[�^�œǂݍ��݂܂�
	string Name;
	cin >> Name;
	ifstream ifs(Name + ".txt", ios::in | ios::binary);
	//�t�@�C�����ǂݍ��߂Ȃ��������̃G���[����
	while (!ifs) {
		printf("�t�@�C�������݂��܂���\n");
		return;
	}
	//�������ݗp�Ƃ��ăt�@�C����ǂݍ��݂܂�
	ofstream ofs(Name + ".dat", ios::out | ios::binary);
	//�t�@�C�����ǂݍ��߂Ȃ��������̃G���[����
	if (!ofs) {
		return;
	}
	char c;
	int i = 0;
	while (ifs.get(c)) {//ifs�̒l���P��c�ɓ����(�����Ȃ��ꍇfalse�ɂȂ胋�[�v�I��)
		c = c ^ randomCipher[i];//�f�[�^c�̓��e���Í���
		ofs.put(c);//ofs�ɏ�������
		++i;
		if (i >= 40) {
			i = 0;
		}
	}
	ifs.close();
	ofs.close();
	printf("�Í�������\n");
}
//-------------------------------
//�t�@�C���̒��̎w��v�f�𔲂��o��
//-------------------------------
void TextWithdraw() {
	printf("�t�@�C��������͂��Ă�������\n");
	string Name;
	cin >> Name;
	ifstream ifs(Name , ios::in);
	//�t�@�C�����ǂݍ��߂Ȃ��������̃G���[����
	while (!ifs) {
		printf("�t�@�C�������݂��܂���\n");
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
		printf("����:");
		cin >> text;
		text = text + " ";
		printf("���o���v�f�̐�:");
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
		
		printf("1�F������\n0�F�I������\n");
		cin >> q;
	} while (q == 1);
	ifs.close();
}
void TextMapWithdraw() {
	printf("�t�@�C��������͂��Ă�������\n");
	string Name;
	cin >> Name;
	ifstream ifs(Name, ios::in);
	//�t�@�C�����ǂݍ��߂Ȃ��������̃G���[����
	while (!ifs) {
		printf("�t�@�C�������݂��܂���\n");
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
//�I�����܂����ďo������
//-------------------------------
void Finarize() {
	printf("�A�v���P�[�V�������I�����܂�\n");
}
//-------------------------------
//���C������
//-------------------------------
void main() {
	int i = 1;
	while (i) {
		printf("_____________________________________\n");
		printf("|�g�p����@�\��I�����Ă�������      |\n"
			   "|1:�o�C�i���f�[�^�̒��g�̊m�F        |\n"
			   "|2:�o�C�i���f�[�^�𕡍������ĕ\������|\n"
			   "|3:�e�L�X�g���o�C�i���ɈÍ���        |\n"
			   "|4:�e�L�X�g�f�[�^�̒��g�̊m�F        |\n"
			   "|0:�A�v���P�[�V�������I������        |\n"
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