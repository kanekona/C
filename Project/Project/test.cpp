//--------------------------------
//�f�[�^�̓ǂݍ��݂ƈÍ����ƕ�����
//--------------------------------
//�K�v�t�@�C���̃C���N���[�h
#include<iostream>
#include<fstream>
#include<string>

#define _RPTN
//std�ȗ��p
using namespace std;
void main() {
	//�t�@�C�����o�C�i���f�[�^�œǂݍ��݂܂�
	ifstream ifs("test.txt", ios::in | ios::binary);
	//�t�@�C�����ǂݍ��߂Ȃ��������̃G���[����
	if (!ifs) {
		_RPTN(_CRT_WARN, ("�t�@�C�������݂��܂���"));
		return;
	}
	//�������ݗp�Ƃ��ăt�@�C����ǂݍ��݂܂�
	ofstream ofs("test.dat", ios::out | ios::binary);
	//�t�@�C�����ǂݍ��߂Ȃ��������̃G���[����
	if (!ofs) {
		_RPTN(_CRT_WARN, ("�t�@�C�������݂��܂���"));
	}
	//�i�[�p�̕ϐ�
	char c;
	while (ifs.get(c)) {//ifs�̒l���P��c�ɓ����(�����Ȃ��ꍇfalse�ɂȂ胋�[�v�I��)
		if (c != ','&&c != '\n' && c != ' ') {//��؂�p��,�Ɖ��s�����O
			c = c ^ 0x53;//�f�[�^c�̓��e���Í���
		}
		ofs.put(c);//ofs�ɏ�������
	}

	//�N���[�Y����
	ifs.close();
	ofs.close();

	//�t�@�C�����o�C�i���f�[�^�œǂݍ��݂܂�
	ifstream ifs2("test.dat", ios::in | ios::binary);
	//�t�@�C�����ǂݍ��߂Ȃ��������̃G���[����
	if (!ifs2) {
		_RPTN(_CRT_WARN, ("�t�@�C�������݂��܂���"));
		return;
	}

	//�������ݗp�Ƃ��ăt�@�C����ǂݍ��݂܂�
	ofstream ofs2("test2.csv", ios::in | ios::binary);
	//�t�@�C�����ǂݍ��߂Ȃ��������̃G���[����
	if (!ofs2) {
		_RPTN(_CRT_WARN, ("�t�@�C�������݂��܂���"));
		return;
	}
	//�i�[�p�̕ϐ�
	char c2;
	int a[15];
	string word;
	
	while (ifs2.get(c2)) {//ifs�̒l���P��c�ɓ����(�����Ȃ��ꍇfalse�ɂȂ胋�[�v�I��)
		if (c2 != ','&&c2 != '\n' && c2!= ' ') {//��؂�p��,�Ɖ��s�����O
			c2 = c2 ^ 0x53;//�Í������ꂽ�f�[�^c�̓��e�𕡍���
		}
		ofs2.put(c2);//ofs�ɏ�������
	}

	//�t�@�C�����o�C�i���f�[�^�œǂݍ��݂܂�
	ifstream ifs3("test.txt", ios::in|ios::binary);
	//�t�@�C�����ǂݍ��߂Ȃ��������̃G���[����
	if (!ifs3) {
		_RPTN(_CRT_WARN, ("�t�@�C�������݂��܂���"));
		return;
	}
	
	for (int i = 0; i < 15; ++i) {
		ifs3 >> a[i];
		
		printf("%d\n", a[i]);
	}

	//�N���[�Y����
	ifs2.close();
	ifs3.close();
	ofs2.close();
	system("Pause");
}