#include<stdio.h>
#include<stdlib.h>
#include"MakeMyList.h"
#include <iostream>

void create(CELL* currentCell, int val); //�v���g�^�C�v�錾
void index(CELL* endCell, int& select);
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

		case 3:

		case 4:

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


void index(CELL* endCell, int& select) {
	int no = 1;
	std::cout << "[�v�f�̕\��]" << std::endl;
	std::cout << "1.�v�f�̈ꗗ�\��" << std::endl;
	std::cout << "2.���Ԃ��w�肵�ėv�f��\��" << std::endl;
	std::cout << "9.�v�f����ɖ߂�" << std::endl;
	int sceneSelect;
	scanf_s("%d", &sceneSelect);
	while (endCell->next != nullptr) {
		endCell = endCell->next;
		printf("%d ", no);
		printf("%p ", endCell->prev);
		printf("%5d ", endCell->val);
		printf("(%p) ", endCell);
		printf("%p\n ", endCell->next);
		no++;
	}
	printf("�߂�Ȃ�0�����\n");
	int sceneSelect;
	scanf_s("%d", &sceneSelect);
	select = sceneSelect;



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
