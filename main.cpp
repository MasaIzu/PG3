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
			index(&list, select);
			break;
		case 2:
			system("cls");
			std::cout << "[—v‘f‚Ì‘}“ü]" << std::endl;
			//ƒŠƒXƒg‚Ì‘}“ü
			std::cout << "—v‘f‚ð’Ç‰Á‚·‚éêŠ‚ð‘I‘ð‚µ‚Ä‚­‚¾‚³‚¢BÅŒã”ö‚É’Ç‰Á‚·‚éê‡‚Í‰½‚à“ü—Í‚µ‚È‚¢‚Å‚­‚¾‚³‚¢B" << std::endl;

			std::string insertNum;
			while (std::getchar() != '\n');

			std::getline(std::cin, insertNum);

			if (insertNum == "") {

				std::cout << "’Ç‰Á‚·‚é—v‘f‚Ì’l‚ð“ü—Í‚µ‚Ä‚­‚¾‚³‚¢" << std::endl;
				int element;
				std::cin >> element;

				list.PushBack(element);

				std::cout << "—v‘f" << element << "‚ª" << "ÅŒã”ö‚É‘}“ü‚³‚ê‚Ü‚µ‚½" << std::endl;
			}

			scanf_s("%d",&iterator);

			std::cout << "’Ç‰Á‚·‚é—v‘f‚Ì’l‚ð“ü—Í‚µ‚Ä‚­‚¾‚³‚¢" << std::endl;
			scanf_s("%d", &inputValue);

			//”CˆÓ‚ÌƒZƒ‹‚ÌŒã‚ë‚É’Ç‰Á
			insertCell = list.getInsertCellAddress(&head,iterator);
			create(insertCell, inputValue);

			std::cout << "—v‘f"<< inputValue<< "‚ª" << iterator<< "”Ô–Ú‚É‘}“ü‚³‚ê‚Ü‚µ‚½" << std::endl;

			std::cout << std::endl;
			std::cout << "----------------------------------" << std::endl;
			std::cout << "9.—v‘f‘€ì‚É–ß‚é" << std::endl;
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
			std::cout << "’l‚ª–³Œø‚Å‚·" << std::endl;
			std::cout << "1,2,3,4,5 ‚©‚ç‘I‘ð‚µ‚Ä‚­‚¾‚³‚¢" << std::endl;
			//—v‘f‚Ì‘I‘ð
			scanf_s("%d", &select);
			break;
		}
	}
	return 0;
}


void index(MakeMyList& endCell, int& select) {
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
		std::cout << "[—v‘f‚Ìˆê——•\Ž¦]" << std::endl;
		//ˆê——•\Ž¦
		endCell.Dump();

		std::cout << "—v‘f”:" << endCell.Size() << std::endl;
		break;

	case 2:

		std::cout << "[‡”Ô‚ðŽw’è‚µ‚Ä—v‘f‚ð•\Ž¦]" << std::endl;
		std::cout << "•\Ž¦‚µ‚½‚¢—v‘f‚Ì‡”Ô‚ðŽw’è‚µ‚Ä‚­‚¾‚³‚¢B" << std::endl;

		//Žw’è‚·‚é”Ô†‚ðŽæ“¾
		int specifyNum;
		std::cin >> specifyNum;
		std::cout << std::endl;

		//Žw’è‚µ‚Ä•\Ž¦
		endCell.SpecifyElement(specifyNum);

	case 9:
		select = sceneSelect;

	default:
		break;
	}

	//—v‘f‘€ì‚É–ß‚ç‚È‚©‚Á‚½‚ç
	if (sceneSelect == 1 || sceneSelect == 2)
	{
		std::cout << std::endl;
		std::cout << "----------------------------------" << std::endl;
		std::cout << "1.—v‘f‚Ì•\Ž¦‚É–ß‚é" << std::endl;
		std::cout << "2.—v‘f‚Ì‘€ì‚É–ß‚é" << std::endl;

		//‘€ì”Ô†‚ðŽæ“¾
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

