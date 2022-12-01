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
			std::cout << "[—v‘f‚Ì‘€ì]" << std::endl;
			std::cout << "1.—v‘f‚Ìˆê——•\Ž¦" << std::endl;
			std::cout << "2,—v‘f‚Ì‘}“ü" << std::endl;
			std::cout << "3,—v‘f‚Ì•ÒW" << std::endl;
			std::cout << "4,—v‘f‚Ìíœ" << std::endl;
			std::cout << "5,—v‘f‚Ì•À‚Ñ‘Ö‚¦(ƒIƒvƒVƒ‡ƒ“)" << std::endl;

			std::cout << std::endl;
			std::cout << "--------------------------" << std::endl;
			std::cout << "‘€ì‚ð‘I‘ð‚µ‚Ä‚­‚¾‚³‚¢" << std::endl;
			//—v‘f‚Ì‘I‘ð
			scanf_s("%d", &select);
			break;
		case 1:
			system("cls");
			//ƒŠƒXƒg‚Ìˆê——‚Ì•\Ž¦
			index(&head, select);
			break;
		case 2:
			system("cls");
			std::cout << "[—v‘f‚Ì‘}“ü]" << std::endl;
			//ƒŠƒXƒg‚Ì‘}“ü
			std::cout << "—v‘f‚ð’Ç‰Á‚·‚éêŠ‚ð‘I‘ð‚µ‚Ä‚­‚¾‚³‚¢" << std::endl;
			scanf_s("%d",&iterator);

			std::cout << "’Ç‰Á‚·‚é—v‘f‚Ì’l‚ð“ü—Í‚µ‚Ä‚­‚¾‚³‚¢" << std::endl;
			scanf_s("%d", &inputValue);

			//”CˆÓ‚ÌƒZƒ‹‚ÌŒã‚ë‚É’Ç‰Á
			insertCell = getInsertCellAddress(&head,iterator);
			create(insertCell, inputValue);

			std::cout << "—v‘f"<< inputValue<< "‚ª" << iterator<< "‚É’Ç‰Á‚³‚ê‚Ü‚µ‚½" << std::endl;

			std::cout << "—v‘f‚Ì‘€ì‚É–ß‚é‚É‚Í0‚ð“ü—Í‚µ‚Ä‚­‚¾‚³‚¢" << std::endl;
			scanf_s("%d", &select);
			break;
		case 3:

			break;
		case 4:

			break;
		default:
			std::cout << "’l‚ª–³Œø‚Å‚·" << std::endl;
			std::cout << "1,2,3,4,5 ‚©‚ç‘I‘ð‚µ‚Ä‚­‚¾‚³‚¢" << std::endl;
			//—v‘f‚Ì‘I‘ð
			scanf_s("%d", &select);
			break;
		}


		////—v‘f‚Ì‘I‘ð
		//scanf_s("%d", &iterator);

		//printf("‰½”Ô–Ú‚ÌƒZƒ‹‚ÌŒã‚ë‚É‘}“ü‚µ‚Ü‚·‚©H\n");
		//scanf_s("%d",&iterator);

		//printf("‘}“ü‚·‚é’l‚ð“ü—Í‚µ‚Ä‚­‚¾‚³‚¢\n");
		//scanf_s("%d", &inputValue);

		////”CˆÓ‚ÌƒZƒ‹‚ÌŒã‚ë‚É’Ç‰Á
		//insertCell = getInsertCellAddress(&head,iterator);
		//create(insertCell, inputValue);

		////ƒŠƒXƒg‚Ìˆê——‚Ì•\Ž¦
		//index(&head);
	}
	return 0;
}


void index(CELL* endCell, int& select) {
	int no = 1;
	std::cout << "[—v‘f‚Ì•\Ž¦]" << std::endl;
	std::cout << "1.—v‘f‚Ìˆê——•\Ž¦" << std::endl;
	std::cout << "2.‡”Ô‚ðŽw’è‚µ‚Ä—v‘f‚ð•\Ž¦" << std::endl;
	std::cout << "9.—v‘f‘€ì‚É–ß‚é" << std::endl;
	std::cout << std::endl;
	std::cout << "‘€ì‚ð‘I‘ð‚µ‚Ä‚­‚¾‚³‚¢" << std::endl;
	int sceneSelect;
	scanf_s("%d", &sceneSelect);
	system("cls");

	switch (sceneSelect){
	case 1:
		while (endCell->next != nullptr) {
			std::cout << "[—v‘f‚Ìˆê——•\Ž¦]" << std::endl;
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
