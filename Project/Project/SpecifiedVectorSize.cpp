#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#define new ::new(_NORMAL_BLOCK, __FILE__, __LINE__)

#include <iostream>
#include <vector>
#include <string>
/**
*�z��̎w��L�[�܂ł̃T�C�Y�����擾����
*/

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	{
		//�T�C�Y�̂��߁Asizeof�Ōv�Z���s��
		std::string texts[1000];
		std::cout << sizeof(texts) << ":" << sizeof(texts[0]) << std::endl;
		std::cout << sizeof(texts) - (sizeof(texts[0]) * 500) << std::endl;
	}

	{
		//�v�f���̂��߁A1�𒼓n���v�Z�ł悢
		std::vector<std::string> texts;
		texts.resize(1000);
		std::cout << texts.size() << ":" << 1 << std::endl;
		std::cout << texts.size() - (500) << std::endl;
	}
	system("pause");
}