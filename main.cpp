#include <stdio.h>
#include <list>
#include <iostream>

int main()
{
	const char* yamanoteStationName[28] = {
		"Tokyo",
		"Kanda",
		"Akihabara",
		"Okachimachi",
		"Ueno",
		"Uguisudani",
		"Nippori",
		"Tabata",
		"Komagome",
		"Sugamo",
		"Otsuka",
		"Ikebukuro",
		"Mejiro",
		"Takadanobaba",
		"ShinOkubo",
		"Shinjuku",
		"Yoyogi",
		"Harajuku",
		"Shibuya",
		"Ebisu",
		"Meguro",
		"Gotanda",
		"Osaki",
		"Shinagawa",
		"Tamachi",
		"Hamamatsucho",
		"Shimbashi",
		"Yurakucho"
	};

	//���X�g�𐶐�
	std::list<const char*> lst(yamanoteStationName, std::end(yamanoteStationName));

	//�w�ꗗ
	std::cout << "1970�N�w�ꗗ" << std::endl;
	for (auto itr = lst.begin(); itr != lst.end(); ++itr)
	{
		std::cout << *itr << "\n";
	}
	//��J����
	std::cout << std::endl;

	//�w�ꗗ
	std::cout << "2019�N�w�ꗗ" << std::endl;
	std::list<const char*>::iterator itr1971 = std::next(lst.begin(), 7);
	lst.insert(itr1971, "NishiniNippori");
	for (auto itr = lst.begin(); itr != lst.end(); ++itr)
	{
		std::cout << *itr << "\n";
	}
	//��J����
	std::cout << std::endl;

	//�w�ꗗ
	std::cout << "2022�N�w�ꗗ" << std::endl;
	std::list<const char*>::iterator itr2019 = std::next(lst.begin(), 25);
	lst.insert(itr2019, "TakanawaGateway");
	for (auto itr = lst.begin(); itr != lst.end(); ++itr)
	{
		std::cout << *itr << "\n";
	}

	return 0;
}
