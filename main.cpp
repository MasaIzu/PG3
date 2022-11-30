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

	//リストを生成
	std::list<const char*> lst(yamanoteStationName, std::end(yamanoteStationName));

	//駅一覧
	printf("1970年駅一覧\n");
	for (auto itr = lst.begin(); itr != lst.end(); ++itr)
	{
		std::cout << *itr << "\n";
	}
	//一つ開ける
	printf("\n");

	//駅一覧
	printf("2019年駅一覧\n");
	std::list<const char*>::iterator itr1971 = std::next(lst.begin(), 7);
	lst.insert(itr1971, "NishiniNippori");
	for (auto itr = lst.begin(); itr != lst.end(); ++itr)
	{
		std::cout << *itr << "\n";
	}
	//一つ開ける
	printf("\n");

	//駅一覧
	printf("2022年駅一覧\n");
	std::list<const char*>::iterator itr2019 = std::next(lst.begin(), 25);
	lst.insert(itr2019, "TakanawaGateway");
	for (auto itr = lst.begin(); itr != lst.end(); ++itr)
	{
		std::cout << *itr << "\n";
	}


	return 0;
}
