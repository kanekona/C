//--------------------------------
//�f�[�^�̓ǂݍ��݂ƈÍ����ƕ�����
//--------------------------------
//�K�v�t�@�C���̃C���N���[�h
#include<iostream>
#include<fstream>
#include<string>
#include "randmais.h"
using namespace std;
void main() {
	printf("�t�@�C��������͂��Ă�������\n");
	//�t�@�C�����o�C�i���f�[�^�œǂݍ��݂܂�
	string Name;
	cin >> Name;
	ifstream ifs(Name + ".txt", ios::in | ios::binary);
	//�t�@�C�����ǂݍ��߂Ȃ��������̃G���[����
	while(!ifs) {
		printf("�t�@�C�������݂��܂���\n");
		printf("�A�v���P�[�V�������I�����܂�\n");
		system("pause");
		return;
	}
	//�������ݗp�Ƃ��ăt�@�C����ǂݍ��݂܂�
	ofstream ofs( Name+".dat", ios::out | ios::binary);
	//�t�@�C�����ǂݍ��߂Ȃ��������̃G���[����
	if (!ofs) {
		return;
	}
	char c;
	int i = 0;
	while (ifs.get(c)) {//ifs�̒l���P��c�ɓ����(�����Ȃ��ꍇfalse�ɂȂ胋�[�v�I��)
		if (c != ','&&c != '\n' && c != ' ') {//��؂�p��,�Ɖ��s�����O
			c = c ^ randomCipher[i];//�f�[�^c�̓��e���Í���
		}
		ofs.put(c);//ofs�ɏ�������
		++i;
	}
	ifs.close();
	ofs.close();
	printf("�Í�������\n");
	system("pause");
}