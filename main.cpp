#include <iostream>
#include"MakeMyList.h"
#include<string>

template<typename T>
void Display(MakeMylist<T>& list, int& sceneSelect, int& displayScene);

template<typename T>
void Insert(MakeMylist<T>& list, int& sceneSelect);

template<typename T>
void Edit(MakeMylist<T>& list, int& sceneSelect);

template<typename T>
void Delete(MakeMylist<T>& list, int& sceneSelect);

template<typename T>
void SortBy(MakeMylist<T>& list, int& sceneSelect);

template<typename T>
void Change(MakeMylist<T>& list, int& sceneSelect);

int main()
{
	//要素の操作の操作番号
	int sceneSelect = 0;

	//要素の表示の操作番号
	int displayScene = 0;

	MakeMylist<std::string> list;
	while (true)
	{
		std::cout << "[要素の操作]" << std::endl;
		std::cout << "1.要素の表示" << std::endl;
		std::cout << "2.要素の挿入" << std::endl;

		if (list.Size() > 0)
		{
			std::cout << "3.要素の編集" << std::endl;
			std::cout << "4.要素の削除" << std::endl;
		}

		std::cout << "5.要素の並び替え(オプション)" << std::endl;
		std::cout << std::endl;
		std::cout << "-------------------------------------" << std::endl;
		std::cout << "操作を選択してください" << std::endl;

		std::cout << std::endl;

		if (sceneSelect == 0)
		{
			//操作番号を取得
			std::cin >> sceneSelect;
		}
		system("cls");

		switch (sceneSelect)
		{
		case 1://要素の表示
			Display(list, sceneSelect, displayScene);
			break;

		case 2://最後尾に要素を追加
			Insert(list, sceneSelect);
			break;

		case 3://任意の場所の値を変更
			Edit(list, sceneSelect);
			break;
		case 4://任意の場所の削除
			Delete(list, sceneSelect);
			break;
		case 5://任意の場所と任意の場所を入れ替え
			Change(list, sceneSelect);
			break;
		}
	}

	return 0;
}

template<typename T>
void Display(MakeMylist<T>& list, int& sceneSelect, int& displayScene)
{
	std::cout << "[要素の表示]" << std::endl;
	std::cout << "1.要素の一覧表示" << std::endl;
	std::cout << "2.順番を指定して要素を表示" << std::endl;
	std::cout << "9.要素操作に戻る" << std::endl;
	std::cout << std::endl;
	std::cout << "操作を選択してください" << std::endl;

	//操作番号を取得
	std::cin >> displayScene;
	system("cls");

	switch (displayScene)
	{
	case 1:
		std::cout << "[要素の一覧表示]" << std::endl;

		//一覧表示
		list.Dump();

		std::cout << "要素数:" << list.Size() << std::endl;

		break;
	case 2:
		std::cout << "[順番を指定して要素を表示]" << std::endl;
		std::cout << "表示したい要素の順番を指定してください。" << std::endl;

		//指定する番号を取得
		int designatedNumber;
		std::cin >> designatedNumber;
		std::cout << std::endl;

		//指定して表示
		list.DesignatedElement(designatedNumber);

		break;

	case 9:
		sceneSelect = 0;
		break;
	}

	//要素操作に戻らなかったら
	if (displayScene == 1 || displayScene == 2)
	{
		std::cout << std::endl;
		std::cout << "----------------------------------" << std::endl;
		std::cout << "1.要素の表示に戻る" << std::endl;
		std::cout << "2.要素の操作に戻る" << std::endl;

		//操作番号を取得
		std::cin >> displayScene;

		system("cls");
		switch (displayScene)
		{
		case 1:
			sceneSelect = 1;
			break;
		case 2:
			sceneSelect = 0;
			break;
		default:
			break;
		}
	}
}

template<typename T>
void Insert(MakeMylist<T>& list, int& sceneSelect)
{
	std::cout << "[リスト要素の挿入]" << std::endl;
	std::cout << std::endl;
	std::cout << "要素を追加場所を指定してください。最後尾に追加する場合は何も入力しないでください。" << std::endl;

	std::string insertNum;
	while (std::getchar() != '\n');

	std::getline(std::cin, insertNum);

	if (insertNum == "")
	{
		std::cout << "追加する要素の値を入力してください" << std::endl;
		T element{};

		std::cin >> element;

		list.Push_Back(element);

		std::cout << "要素" << element << "が" << "最後尾に挿入されました" << std::endl;
	}
	else
	{
		int index = std::atoi(insertNum.c_str());

		std::cout << "追加する要素の値を入力してください" << std::endl;
		T element{};

		std::cin >> element;

		list.Insert(element, index);

		std::cout << "要素" << element << "が" << index << "番目に挿入されました" << std::endl;
	}

	std::cout << std::endl;
	std::cout << "----------------------------------" << std::endl;
	std::cout << "9.要素操作に戻る" << std::endl;

	std::cin >> sceneSelect;
	system("cls");

	if (sceneSelect == 9)
	{
		sceneSelect = 0;
	}
	else
	{
		sceneSelect = 2;
	}
}

template<typename T>
void Edit(MakeMylist<T>& list, int& sceneSelect)
{
	std::cout << "[要素の編集]" << std::endl;
	std::cout << std::endl;
	std::cout << "編集したい要素の番号を入力してください" << std::endl;

	int elementNum;
	std::cin >> elementNum;
	std::cout << std::endl;

	if (list.Search(elementNum))
	{
		std::cout << elementNum << "番目の要素の変更する値を入力してください。" << std::endl;

		T changeElement{};
		std::cin >> changeElement;

		list.ChangeValue(changeElement, elementNum);
		std::cout << std::endl;

		std::cout << elementNum << "番目の要素の値が" << '"' << changeElement << '"' << "に変更されました" << std::endl;
	}
	else
	{
		std::cout << elementNum << "番目の要素のが見つかりませんでした。" << std::endl;
	}


	std::cout << std::endl;
	std::cout << "----------------------------------" << std::endl;
	std::cout << "9.要素操作に戻る" << std::endl;

	std::cin >> sceneSelect;
	system("cls");

	if (sceneSelect == 9)
	{
		sceneSelect = 0;
	}
	else
	{
		sceneSelect = 3;
	}

}

template<typename T>
void Delete(MakeMylist<T>& list, int& sceneSelect)
{
	std::cout << "[要素の削除]" << std::endl;
	std::cout << std::endl;
	std::cout << "削除したい要素の番号を指定してください" << std::endl;

	int elementNum;
	std::cin >> elementNum;
	std::cout << std::endl;

	if (list.Search(elementNum))
	{
		std::cout << elementNum << "番目の要素" << '"' << list.GetElement(elementNum) << '"' << "削除しました" << std::endl;

		list.Delete(elementNum);

		std::cout << std::endl;
	}
	else
	{
		std::cout << elementNum << "番目の要素のが見つかりませんでした。" << std::endl;
	}

	std::cout << std::endl;
	std::cout << "----------------------------------" << std::endl;
	std::cout << "9.要素操作に戻る" << std::endl;

	std::cin >> sceneSelect;
	system("cls");

	if (sceneSelect == 9)
	{
		sceneSelect = 0;
	}
	else
	{
		sceneSelect = 4;
	}
}

template<typename T>
void Change(MakeMylist<T>& list, int& sceneSelect)
{
	std::cout << "[要素の並び替え]" << std::endl;
	std::cout << std::endl;
	std::cout << "並び替え方法を選択してください" << std::endl;
	std::cout << "1.昇順で並び替える" << std::endl;
	std::cout << "2.降順で並び替える" << std::endl;

	int changeScene;

	std::cin >> changeScene;

	switch (changeScene)
	{
	case 1:
	{

		list.Sort();
		std::cout << "リストの要素を昇順で並び替えました" << std::endl;
	}
	break;
	case 2:
		list.Sort(false);
		std::cout << "リストの要素を降順で並び替えました" << std::endl;

		break;
	default:
		break;
	}

	std::cout << std::endl;
	std::cout << "----------------------------------" << std::endl;
	std::cout << "9.要素操作に戻る" << std::endl;

	std::cin >> sceneSelect;
	system("cls");

	if (sceneSelect == 9)
	{
		sceneSelect = 0;
	}
	else
	{
		sceneSelect = 5;
	}
}