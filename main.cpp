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

	//ƒŠƒXƒg‚ğ¶¬
	std::list<const char*> lst(yamanoteStationName, std::end(yamanoteStationName));

	//‰wˆê——
	std::cout << "1970”N‰wˆê——" << std::endl;
	for (auto itr = lst.begin(); itr != lst.end(); ++itr)
	{
		std::cout << *itr << "\n";
	}
	//ˆê‚ÂŠJ‚¯‚é
	std::cout << std::endl;

	//‰wˆê——
	std::cout << "2019”N‰wˆê——" << std::endl;
	std::list<const char*>::iterator itr1971 = std::next(lst.begin(), 7);
	lst.insert(itr1971, "NishiniNippori");
	for (auto itr = lst.begin(); itr != lst.end(); ++itr)
	{
		std::cout << *itr << "\n";
	}
	//ˆê‚ÂŠJ‚¯‚é
	std::cout << std::endl;

	//‰wˆê——
	std::cout << "2022”N‰wˆê——" << std::endl;
	std::list<const char*>::iterator itr2019 = std::next(lst.begin(), 25);
	lst.insert(itr2019, "TakanawaGateway");
	for (auto itr = lst.begin(); itr != lst.end(); ++itr)
	{
		std::cout << *itr << "\n";
	}

	return 0;
}
