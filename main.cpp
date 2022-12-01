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
			index(&list, select);
			break;
		case 2:
			system("cls");
			std::cout << "[要素の挿入]" << std::endl;
			//リストの挿入
			std::cout << "要素を追加する場所を選択してください。最後尾に追加する場合は何も入力しないでください。" << std::endl;

			std::string insertNum;
			while (std::getchar() != '\n');

			std::getline(std::cin, insertNum);

			if (insertNum == "") {

				std::cout << "追加する要素の値を入力してください" << std::endl;
				int element;
				std::cin >> element;

				list.PushBack(element);

				std::cout << "要素" << element << "が" << "最後尾に挿入されました" << std::endl;
			}

			scanf_s("%d",&iterator);

			std::cout << "追加する要素の値を入力してください" << std::endl;
			scanf_s("%d", &inputValue);

			//任意のセルの後ろに追加
			insertCell = list.getInsertCellAddress(&head,iterator);
			create(insertCell, inputValue);

			std::cout << "要素"<< inputValue<< "が" << iterator<< "番目に挿入されました" << std::endl;

			std::cout << std::endl;
			std::cout << "----------------------------------" << std::endl;
			std::cout << "9.要素操作に戻る" << std::endl;
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
			std::cout << "値が無効です" << std::endl;
			std::cout << "1,2,3,4,5 から選択してください" << std::endl;
			//要素の選択
			scanf_s("%d", &select);
			break;
		}
	}
	return 0;
}


void index(MakeMyList& endCell, int& select) {
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
		std::cout << "[要素の一覧表示]" << std::endl;
		//一覧表示
		endCell.Dump();

		std::cout << "要素数:" << endCell.Size() << std::endl;
		break;

	case 2:

		std::cout << "[順番を指定して要素を表示]" << std::endl;
		std::cout << "表示したい要素の順番を指定してください。" << std::endl;

		//指定する番号を取得
		int specifyNum;
		std::cin >> specifyNum;
		std::cout << std::endl;

		//指定して表示
		endCell.SpecifyElement(specifyNum);

	case 9:
		select = sceneSelect;

	default:
		break;
	}

	//要素操作に戻らなかったら
	if (sceneSelect == 1 || sceneSelect == 2)
	{
		std::cout << std::endl;
		std::cout << "----------------------------------" << std::endl;
		std::cout << "1.要素の表示に戻る" << std::endl;
		std::cout << "2.要素の操作に戻る" << std::endl;

		//操作番号を取得
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

