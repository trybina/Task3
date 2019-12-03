#include "Word.h"
#include <string>

using namespace Prog3_1;

int main()
{
	const char l[6] = "world";
	const char k[5][10] = { "Dog", "door", "Dkd", "dsdf", "dfaf" };
	Word W(l);
	std::cout << "1.This" << std::endl << W << std::endl;
	std::cout << "2.Add el" << std::endl;
	int fl2 = 1;
	while (fl2) {
		std::cout << "Enter word or ctrl+Z to quit:" << std::endl;
		char x[20];
		std::cin >> x;
		fl2 = std::cin.good();
		if (!fl2)
			continue;
		try {
			int q = strlen(x);
			if (q > 10) {
				throw std::exception("too many leters");
			}
			int y = W(x);
			if (y != -1) {
				throw std::exception("duplication");
			}
			W += x;
		}
		catch (std::exception &ex) {
			std::cout << ex.what() << std::endl;
		}
	}
	std::cin.clear();
	std::cout << "In new mass: \n" << std::endl << W << std::endl;
	std::cout << "3.Copy: " << std::endl;
	Word Q(W);
	std::cout << "Copy mass:" << std::endl << Q << std::endl;
	std::cout << "4.Search: " << std::endl;
	int fl3 = 1;
	while (fl3) {
		std::cout << "Enter word or ctrl+Z to quit:" << std::endl;
		char vb[20];
		std::cin >> vb;
		fl3 = std::cin.good();
		if (!fl3)
			continue;
		try {
			int q = strlen(vb);
			if (q > 10) {
				throw std::exception("too many leters");
			}
			std::cout << W(vb) << std::endl;;
		}
		catch (std::exception &ex) {
			std::cout << ex.what() << std::endl;
		}
	}
	std::cin.clear();
	std::cout << "5. Get word: " << std::endl;
	int fl0 = 1;
	while (fl0) {
		std::cout << "Enter index:" << std::endl;
		int i;
		char *k;
		std::cin >> i;
		fl0 = std::cin.good();
		if (!fl0)
			continue;
		try {
			k = W[i];
			std::cout << std::string(k, 10) << std::endl;
		}
		catch (std::exception &ex) {
			std::cout << ex.what() << std::endl;
		}
	}
	std::cin.clear();
	std::cout << "6.Sort" << std::endl;
	W.sort();
	std::cout << "Sort mass" << std::endl << W << std::endl;
	std::cout << "7. New " << std::endl;
	Word V(k, 5);
	std::cout << "New mass" << std::endl << V << std::endl;
	Word Y = W;
	std::cout << "Y:" << std::endl << Y << std::endl;
	system("pause");
	return 0;
}
