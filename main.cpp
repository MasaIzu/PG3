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
			std::cout << "[要素の操作]" << std::endl;
			std::cout << "1.要素の一覧表示" << std::endl;
			std::cout << "2,要素の挿入" << std::endl;
			std::cout << "3,要素の編集" << std::endl;
			std::cout << "4,要素の削除" << std::endl;
			std::cout << "5,要素の並び替え(オプション)" << std::endl;

			std::cout << std::endl;
			std::cout << "--------------------------" << std::endl;
			std::cout << "操作を選択してください" << std::endl;
			//要素の選択
			scanf_s("%d", &select);
			break;
		case 1:
			system("cls");
			//リストの一覧の表示
			index(&head, select);
			break;
		case 2:
			system("cls");
			std::cout << "[要素の挿入]" << std::endl;
			//リストの挿入
			std::cout << "要素を追加する場所を選択してください" << std::endl;
			scanf_s("%d",&iterator);

			std::cout << "追加する要素の値を入力してください" << std::endl;
			scanf_s("%d", &inputValue);

			//任意のセルの後ろに追加
			insertCell = getInsertCellAddress(&head,iterator);
			create(insertCell, inputValue);

			std::cout << "要素"<< inputValue<< "が" << iterator<< "に追加されました" << std::endl;

			std::cout << "要素の操作に戻るには0を入力してください" << std::endl;
			scanf_s("%d", &select);
			break;
		case 3:

			break;
		case 4:

			break;
		default:
			std::cout << "値が無効です" << std::endl;
			std::cout << "1,2,3,4,5 から選択してください" << std::endl;
			//要素の選択
			scanf_s("%d", &select);
			break;
		}


		////要素の選択
		//scanf_s("%d", &iterator);

		//printf("何番目のセルの後ろに挿入しますか？\n");
		//scanf_s("%d",&iterator);

		//printf("挿入する値を入力してください\n");
		//scanf_s("%d", &inputValue);

		////任意のセルの後ろに追加
		//insertCell = getInsertCellAddress(&head,iterator);
		//create(insertCell, inputValue);

		////リストの一覧の表示
		//index(&head);
	}
	return 0;
}


void index(CELL* endCell, int& select) {
	int no = 1;
	std::cout << "[要素の表示]" << std::endl;
	std::cout << "1.要素の一覧表示" << std::endl;
	std::cout << "2.順番を指定して要素を表示" << std::endl;
	std::cout << "9.要素操作に戻る" << std::endl;
	std::cout << std::endl;
	std::cout << "操作を選択してください" << std::endl;
	int sceneSelect;
	scanf_s("%d", &sceneSelect);
	system("cls");

	switch (sceneSelect){
	case 1:
		while (endCell->next != nullptr) {
			std::cout << "[要素の一覧表示]" << std::endl;
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
