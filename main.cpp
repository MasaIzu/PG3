#include<stdio.h>
#include<stdlib.h>
#include"MakeMyList.h"
#include <iostream>

void index(CELL* endCell, int& select);
void create(CELL* currentCell, int val);
CELL* getInsertCellAddress(CELL* endCELL, int iterator);

int main()
{
	int iterator;
	int inputValue;
	CELL* insertCell;

	CELL head;
	head.next = nullptr;

	int select = 0;



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
			index(&head, select);
			break;
		case 2:
			system("cls");
			std::cout << "[�v�f�̑}��]" << std::endl;
			//���X�g�̑}��
			std::cout << "�v�f��ǉ�����ꏊ��I�����Ă�������" << std::endl;
			scanf_s("%d",&iterator);

			std::cout << "�ǉ�����v�f�̒l����͂��Ă�������" << std::endl;
			scanf_s("%d", &inputValue);

			//�C�ӂ̃Z���̌��ɒǉ�
			insertCell = getInsertCellAddress(&head,iterator);
			create(insertCell, inputValue);

			std::cout << "�v�f"<< inputValue<< "��" << iterator<< "�ɒǉ�����܂���" << std::endl;

			std::cout << "�v�f�̑���ɖ߂�ɂ�0����͂��Ă�������" << std::endl;
			scanf_s("%d", &select);
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


		////�v�f�̑I��
		//scanf_s("%d", &iterator);

		//printf("���Ԗڂ̃Z���̌��ɑ}�����܂����H\n");
		//scanf_s("%d",&iterator);

		//printf("�}������l����͂��Ă�������\n");
		//scanf_s("%d", &inputValue);

		////�C�ӂ̃Z���̌��ɒǉ�
		//insertCell = getInsertCellAddress(&head,iterator);
		//create(insertCell, inputValue);

		////���X�g�̈ꗗ�̕\��
		//index(&head);
	}
	return 0;
}


void index(CELL* endCell, int& select) {
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
		while (endCell->next != nullptr) {
			std::cout << "[�v�f�̈ꗗ�\��]" << std::endl;
			endCell = endCell->next;
			std::cout << ' ' << no << ':' << '"' << endCell->val << '"' << ',' << std::endl;
			no++;
		}

		scanf_s("%d", &sceneSelect);
		break;

	case 2:


	case 9:
		select = sceneSelect;

	default:
		break;
	}



}

void create(CELL* currentCell, int val) {
	CELL* newCell;
	newCell = (CELL*)malloc(sizeof(CELL));
	newCell->val = val;
	newCell->prev = currentCell;
	newCell->next = currentCell->next;

	if (currentCell->next) {
		CELL* newCell = currentCell->next;
		newCell->prev = newCell;
	}
	currentCell->next = newCell;
}

CELL* getInsertCellAddress(CELL* endCELL, int iterator) {
	for (int i = 0; i < iterator; i++) {
		if (endCELL->next) {
			endCELL = endCELL->next;
		}
		else {
			break;
		}
	}
	return endCELL;
}
