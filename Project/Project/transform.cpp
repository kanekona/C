#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#define new ::new(_NORMAL_BLOCK, __FILE__, __LINE__)

//std::transform
#include <algorithm>
//std::tolower
#include <cctype>
#include <iostream>
#include <string>

/**
*@brief transform�֐����g�p���A�w��z��̒��g���w��ϊ����g���ăR�s�[����
*������ �R�s�[�J�n�ʒu
*������ �R�s�[�I���ʒu
*��O���� �R�s�[��擪�ʒu��������ƃ������������Ă���,�������Ɠ����̏ꍇ�㏑�����Ă����
*��l���� �ϊ�����
*/
int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	std::string text = "abcABChUrkDjgW0842#('%";
	std::string copytext;
	//�����Ń��T�C�Y���ă��������m�ۂ��Ă����Ȃ��Ɨ�O�ɂȂ�܂�
	copytext.resize(text.size());
	std::transform(text.begin(), text.end(), copytext.begin(), std::tolower);
	std::cout << "text[" << text << "]\ncopy[" << copytext << "]\n";
	system("pause");
}