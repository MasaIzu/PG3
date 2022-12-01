#include<stdio.h>
#include<stdlib.h>
#include"MakeMyList.h"
#include <iostream>
#include<string>

void index(MakeMyList* endCell, int& select);


int main()
{
	int iterator;
	int inputValue;
	Cell* insertCell;

	Cell head;
	head.next = nullptr;

	int select = 0;

	MakeMyList list;

	while (1) {
		switch (select) {
		case 0:
			system("cls");
			std::cout << "[�v�f�̑���]" << std::endl;
			std::cout << "1.�v�f�̈ꗗ�\��" << std::endl;
			std::cout << "2,�v�f�̑}��" << std::endl;
			std::cout << "3,�v�f�̕ҏW" << std::endl;
			std::cout << "4,�v�f�̍폜" << std::endl;
			std::cout << "5,�v�f�̕��ёւ�(�I�v�V����)" << std::endl;

			std::cout << std::endl;
			std::cout << "--------------------------" << std::endl;
			std::cout << "�����I�����Ă�������" << std::endl;
			//�v�f�̑I��
			scanf_s("%d", &select);
			break;
		case 1:
			system("cls");
			//���X�g�̈ꗗ�̕\��
			index(&list, select);
			break;
		case 2:
			system("cls");
			std::cout << "[�v�f�̑}��]" << std::endl;
			//���X�g�̑}��
			std::cout << "�v�f��ǉ�����ꏊ��I�����Ă��������B�Ō���ɒǉ�����ꍇ�͉������͂��Ȃ��ł��������B" << std::endl;

			std::string insertNum;
			while (std::getchar() != '\n');

			std::getline(std::cin, insertNum);

			if (insertNum == "") {

				std::cout << "�ǉ�����v�f�̒l����͂��Ă�������" << std::endl;
				int element;
				std::cin >> element;

				list.PushBack(element);

				std::cout << "�v�f" << element << "��" << "�Ō���ɑ}������܂���" << std::endl;
			}

			scanf_s("%d",&iterator);

			std::cout << "�ǉ�����v�f�̒l����͂��Ă�������" << std::endl;
			scanf_s("%d", &inputValue);

			//�C�ӂ̃Z���̌��ɒǉ�
			insertCell = list.getInsertCellAddress(&head,iterator);
			create(insertCell, inputValue);

			std::cout << "�v�f"<< inputValue<< "��" << iterator<< "�Ԗڂɑ}������܂���" << std::endl;

			std::cout << std::endl;
			std::cout << "----------------------------------" << std::endl;
			std::cout << "9.�v�f����ɖ߂�" << std::endl;
			int seneSelect;
			scanf_s("%d", &seneSelect);
			if (seneSelect == 9) {
				select = 0;
			}

			break;
		case 3:

			break;
		case 4:

			break;
		default:
			std::cout << "�l�������ł�" << std::endl;
			std::cout << "1,2,3,4,5 ����I�����Ă�������" << std::endl;
			//�v�f�̑I��
			scanf_s("%d", &select);
			break;
		}
	}
	return 0;
}


void index(MakeMyList& endCell, int& select) {
	int no = 1;
	std::cout << "[�v�f�̕\��]" << std::endl;
	std::cout << "1.�v�f�̈ꗗ�\��" << std::endl;
	std::cout << "2.���Ԃ��w�肵�ėv�f��\��" << std::endl;
	std::cout << "9.�v�f����ɖ߂�" << std::endl;
	std::cout << std::endl;
	std::cout << "�����I�����Ă�������" << std::endl;
	int sceneSelect;
	scanf_s("%d", &sceneSelect);
	system("cls");

	switch (sceneSelect){
	case 1:
		std::cout << "[�v�f�̈ꗗ�\��]" << std::endl;
		//�ꗗ�\��
		endCell.Dump();

		std::cout << "�v�f��:" << endCell.Size() << std::endl;
		break;

	case 2:

		std::cout << "[���Ԃ��w�肵�ėv�f��\��]" << std::endl;
		std::cout << "�\���������v�f�̏��Ԃ��w�肵�Ă��������B" << std::endl;

		//�w�肷��ԍ����擾
		int specifyNum;
		std::cin >> specifyNum;
		std::cout << std::endl;

		//�w�肵�ĕ\��
		endCell.SpecifyElement(specifyNum);

	case 9:
		select = sceneSelect;

	default:
		break;
	}

	//�v�f����ɖ߂�Ȃ�������
	if (sceneSelect == 1 || sceneSelect == 2)
	{
		std::cout << std::endl;
		std::cout << "----------------------------------" << std::endl;
		std::cout << "1.�v�f�̕\���ɖ߂�" << std::endl;
		std::cout << "2.�v�f�̑���ɖ߂�" << std::endl;

		//����ԍ����擾
		std::cin >> sceneSelect;

		system("cls");
		switch (sceneSelect)
		{
		case 1:
			select = 1;
			break;
		case 2:
			select = 0;
			break;
		default:
			break;
		}
	}

}

void create(Cell* currentCell, int val) {
	Cell* newCell;
	newCell = (Cell*)malloc(sizeof(Cell));
	newCell->val = val;
	newCell->prev = currentCell;
	newCell->next = currentCell->next;

	if (currentCell->next) {
		Cell* newCell = currentCell->next;
		newCell->prev = newCell;
	}
	currentCell->next = newCell;
}

