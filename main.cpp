#include <iostream>
#include"MakeMyList.h"
#include<string>

template<typename T>
void Display(MakeMylist<T>& list, int& operationNum, int& displayOperationNum);

template<typename T>
void Insert(MakeMylist<T>& list, int& operationNum);

template<typename T>
void Edit(MakeMylist<T>& list, int& operationNum);

template<typename T>
void Delete(MakeMylist<T>& list, int& operationNum);

template<typename T>
void SortBy(MakeMylist<T>& list, int& operationNum);

int main()
{
	//—v‘f‚Ì‘€ì‚Ì‘€ì”Ô†
	int sceneSelect = 0;

	//—v‘f‚Ì•\¦‚Ì‘€ì”Ô†
	int displayScene = 0;

	MakeMylist<std::string> list;
	while (true)
	{
		std::cout << "[—v‘f‚Ì‘€ì]" << std::endl;
		std::cout << "1.—v‘f‚Ì•\¦" << std::endl;
		std::cout << "2.—v‘f‚Ì‘}“ü" << std::endl;

		if (list.Size() > 0)
		{
			std::cout << "3.—v‘f‚Ì•ÒW" << std::endl;
			std::cout << "4.—v‘f‚Ìíœ" << std::endl;
		}

		std::cout << std::endl;
		std::cout << "-------------------------------------" << std::endl;
		std::cout << "‘€ì‚ğ‘I‘ğ‚µ‚Ä‚­‚¾‚³‚¢" << std::endl;

		std::cout << std::endl;

		if (sceneSelect == 0)
		{
			//‘€ì”Ô†‚ğæ“¾
			std::cin >> sceneSelect;
		}
		system("cls");

		switch (sceneSelect)
		{
		case 1://—v‘f‚Ì•\¦
			Display(list, sceneSelect, displayScene);
			break;

		case 2://ÅŒã”ö‚É—v‘f‚ğ’Ç‰Á
			Insert(list, sceneSelect);
			break;

		case 3://”CˆÓ‚ÌêŠ‚Ì’l‚ğ•ÏX
			Edit(list, sceneSelect);
			break;
		case 4://”CˆÓ‚ÌêŠ‚Ìíœ
			Delete(list, sceneSelect);
			break;

		}
	}

	return 0;
}

template<typename T>
void Display(MakeMylist<T>& list, int& sceneSelect, int& displayScene)
{
	std::cout << "[—v‘f‚Ì•\¦]" << std::endl;
	std::cout << "1.—v‘f‚Ìˆê——•\¦" << std::endl;
	std::cout << "2.‡”Ô‚ğw’è‚µ‚Ä—v‘f‚ğ•\¦" << std::endl;
	std::cout << "9.—v‘f‘€ì‚É–ß‚é" << std::endl;
	std::cout << std::endl;
	std::cout << "‘€ì‚ğ‘I‘ğ‚µ‚Ä‚­‚¾‚³‚¢" << std::endl;

	//‘€ì”Ô†‚ğæ“¾
	std::cin >> displayScene;
	system("cls");

	switch (displayScene)
	{
	case 1:
		std::cout << "[—v‘f‚Ìˆê——•\¦]" << std::endl;

		//ˆê——•\¦
		list.Dump();

		std::cout << "—v‘f”:" << list.Size() << std::endl;

		break;
	case 2:
		std::cout << "[‡”Ô‚ğw’è‚µ‚Ä—v‘f‚ğ•\¦]" << std::endl;
		std::cout << "•\¦‚µ‚½‚¢—v‘f‚Ì‡”Ô‚ğw’è‚µ‚Ä‚­‚¾‚³‚¢B" << std::endl;

		//w’è‚·‚é”Ô†‚ğæ“¾
		int designatedNumber;
		std::cin >> designatedNumber;
		std::cout << std::endl;

		//w’è‚µ‚Ä•\¦
		list.DesignatedElement(designatedNumber);

		break;

	case 9:
		sceneSelect = 0;
		break;
	}

	//—v‘f‘€ì‚É–ß‚ç‚È‚©‚Á‚½‚ç
	if (displayScene == 1 || displayScene == 2)
	{
		std::cout << std::endl;
		std::cout << "----------------------------------" << std::endl;
		std::cout << "1.—v‘f‚Ì•\¦‚É–ß‚é" << std::endl;
		std::cout << "2.—v‘f‚Ì‘€ì‚É–ß‚é" << std::endl;

		//‘€ì”Ô†‚ğæ“¾
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
	std::cout << "[ƒŠƒXƒg—v‘f‚Ì‘}“ü]" << std::endl;
	std::cout << std::endl;
	std::cout << "—v‘f‚ğ’Ç‰ÁêŠ‚ğw’è‚µ‚Ä‚­‚¾‚³‚¢BÅŒã”ö‚É’Ç‰Á‚·‚éê‡‚Í‰½‚à“ü—Í‚µ‚È‚¢‚Å‚­‚¾‚³‚¢B" << std::endl;

	std::string insertNum;
	while (std::getchar() != '\n');

	std::getline(std::cin, insertNum);

	if (insertNum == "")
	{
		std::cout << "’Ç‰Á‚·‚é—v‘f‚Ì’l‚ğ“ü—Í‚µ‚Ä‚­‚¾‚³‚¢" << std::endl;
		T element{};

		std::cin >> element;

		list.Push_Back(element);

		std::cout << "—v‘f" << element << "‚ª" << "ÅŒã”ö‚É‘}“ü‚³‚ê‚Ü‚µ‚½" << std::endl;
	}
	else
	{
		int index = std::atoi(insertNum.c_str());

		std::cout << "’Ç‰Á‚·‚é—v‘f‚Ì’l‚ğ“ü—Í‚µ‚Ä‚­‚¾‚³‚¢" << std::endl;
		T element{};

		std::cin >> element;

		list.Insert(element, index);

		std::cout << "—v‘f" << element << "‚ª" << index << "”Ô–Ú‚É‘}“ü‚³‚ê‚Ü‚µ‚½" << std::endl;
	}

	std::cout << std::endl;
	std::cout << "----------------------------------" << std::endl;
	std::cout << "9.—v‘f‘€ì‚É–ß‚é" << std::endl;

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
	std::cout << "[—v‘f‚Ì•ÒW]" << std::endl;
	std::cout << std::endl;
	std::cout << "•ÒW‚µ‚½‚¢—v‘f‚Ì”Ô†‚ğ“ü—Í‚µ‚Ä‚­‚¾‚³‚¢" << std::endl;

	int elementNum;
	std::cin >> elementNum;
	std::cout << std::endl;

	if (list.Search(elementNum))
	{
		std::cout << elementNum << "”Ô–Ú‚Ì—v‘f‚Ì•ÏX‚·‚é’l‚ğ“ü—Í‚µ‚Ä‚­‚¾‚³‚¢B" << std::endl;

		T changeElement{};
		std::cin >> changeElement;

		list.ChangeValue(changeElement, elementNum);
		std::cout << std::endl;

		std::cout << elementNum << "”Ô–Ú‚Ì—v‘f‚Ì’l‚ª" << '"' << changeElement << '"' << "‚É•ÏX‚³‚ê‚Ü‚µ‚½" << std::endl;
	}
	else
	{
		std::cout << elementNum << "”Ô–Ú‚Ì—v‘f‚Ì‚ªŒ©‚Â‚©‚è‚Ü‚¹‚ñ‚Å‚µ‚½B" << std::endl;
	}


	std::cout << std::endl;
	std::cout << "----------------------------------" << std::endl;
	std::cout << "9.—v‘f‘€ì‚É–ß‚é" << std::endl;

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
	std::cout << "[—v‘f‚Ìíœ]" << std::endl;
	std::cout << std::endl;
	std::cout << "íœ‚µ‚½‚¢—v‘f‚Ì”Ô†‚ğw’è‚µ‚Ä‚­‚¾‚³‚¢" << std::endl;

	int elementNum;
	std::cin >> elementNum;
	std::cout << std::endl;

	if (list.Search(elementNum))
	{
		std::cout << elementNum << "”Ô–Ú‚Ì—v‘f" << '"' << list.GetElement(elementNum) << '"' << "íœ‚µ‚Ü‚µ‚½" << std::endl;

		list.Delete(elementNum);

		std::cout << std::endl;
	}
	else
	{
		std::cout << elementNum << "”Ô–Ú‚Ì—v‘f‚Ì‚ªŒ©‚Â‚©‚è‚Ü‚¹‚ñ‚Å‚µ‚½B" << std::endl;
	}

	std::cout << std::endl;
	std::cout << "----------------------------------" << std::endl;
	std::cout << "9.—v‘f‘€ì‚É–ß‚é" << std::endl;

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
void SortBy(MakeMylist<T>& list, int& operationNum)
{
	
}