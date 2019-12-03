#include "Word.h"
#include <string.h>

namespace Prog3_1 {

	asasasasasa

	Word::Word(const Word &w) : kol(w.kol), SZ(w.SZ) // копирующий конструктор
	{
		mass = new char *[SZ];  
		for (int i = 0; i < SZ; i++) 
		{
			mass[i] = new char[SZ_h];
		}
		for (int i = 0; i < SZ; ++i)
		{
			for (int j = 0; j < SZ_h; j++)
				mass[i][j] = '\0';
		}
		for (int i = 0; i < kol; ++i)
		{
			for (int j = 0; j < SZ_h; j++)
			mass[i][j] = w.mass[i][j];
		}
		std::cout << "Copy" << std::endl;
	}

	Word::Word(Word && w) :kol(w.kol), SZ(w.SZ), mass(w.mass) // перемещающий конструктор
	{
		w.mass = nullptr;
		std::cout << "Transport" << std::endl;
	}

	Word:: ~Word()
	{
		for (int q = 0; q < SZ; ++q) 
		{
			delete [] mass[q];
		}
           delete [] mass;
	}

	Word & Word::operator =(const Word &w) // перегруженный оператор присваивания
	{
		if (this != &w) {
			kol = w.kol;
			SZ = w.SZ;

			for (int q = 0; q < SZ; ++q) {

				delete[] mass[q];
				delete[] mass;
			}

			mass = new char *[SZ];
			for (int i = 0; i < SZ; i++)
			{
				mass[i] = new char[SZ_h];
			}
			for (int i = 0; i < SZ; ++i)
			{
				for (int j = 0; j < SZ_h; j++)
					mass[i][j] = '\0';
			}
			for (int i = 0; i < kol; ++i)
			{
				for (int j = 0; j < SZ_h; j++)
					mass[i][j] = w.mass[i][j];
			}
		}
		return *this;
	}

	Word & Word::operator =(Word &&w) // перемещающий оператор присваивания
	{
		int tmp = kol;
		kol = w.kol;
		w.kol = tmp;
		tmp = SZ;
		SZ = w.SZ;
		w.SZ = tmp;
		char **ptr = mass;
		mass = w.mass;
		w.mass = ptr;
		return *this;
	}
	
	Word::Word():SZ(QUOTA)
	{
		kol = 0;
		mass = new char *[SZ];
		for (int i = 0; i < SZ; i++)
		{
			mass[i] = new char[SZ_h];
		}
		for (int i = 0; i < SZ; ++i)
		{
			for (int j = 0; j < SZ_h; j++)
				mass[i][j] = '\0';
		}
	}

	Word::Word(const char *l):SZ(QUOTA) //инициализация одним словом
	{
		int m = strlen(l);
		kol = 1;
		mass = new char *[SZ];
		for (int i = 0; i < SZ; i++)
		{
			mass[i] = new char[SZ_h];
		}
		for (int i = 0; i < SZ; ++i)
		{
			for (int j = 0; j < SZ_h; j++)
				mass[i][j] = '\0';
		}
		for (int q = 0; q < m; q++)
			mass[0][q] = l[q];
	}

	Word::Word(const char k[5][10], int n) :SZ(QUOTA) //инициализация количеством слов и словами из массива строковых констант
	{
		kol = n;
		mass = new char *[SZ];
		for (int i = 0; i < SZ; i++)
		{
			mass[i] = new char[SZ_h];
		}
		for (int i = 0; i < SZ; ++i)
		{
			for (int j = 0; j < SZ_h; j++)
				mass[i][j] = '\0';
		}
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < SZ_h; j++)
				mass[i][j] = k[i][j];
		}
	}

	std::ostream & operator <<(std::ostream &s, const Word &w) // вывод содержимого массива в поток
	{
		for (int i = 0; i < w.SZ; i++)
		{
			for (int j = 0; j < w.SZ_h; j++)
			{
				if (((w.mass[i][j] >= 'a') && (w.mass[i][j] <= 'z')) || ((w.mass[i][j] >= 'A') && (w.mass[i][j] <= 'Z')))
					s << w.mass[i][j];
			}
			s << ' ';
		}
		s << std::endl;
		return s;
	}


	char* Word::operator [](int u)
	{
		if (u < 0 || u >= SZ)
			throw std::exception("illegal i");
		if ((u + 1) > kol)
			throw std::exception("no found");

		std::cout << "k = ";
		return mass[u];
	}

	Word & Word:: operator +=(char *m)
	{
		if (kol >= SZ)
		{
			SZ += QUOTA;
			char **old = mass;
			mass = new char *[SZ];
			for (int i = 0; i < SZ; i++)
			{
				mass[i] = new char[SZ_h];
			}
			for (int i = 0; i < SZ; ++i)
			{
				for (int j = 0; j < SZ_h; j++)
					mass[i][j] = '\0';
			}
			for (int i = 0; i < kol; ++i)
			{
				for (int j = 0; j < SZ_h; j++)
					mass[i][j] = old[i][j];
			}

			for (int q = 0; q < kol; ++q) {

				delete[] old[q];
			}
				delete[] old;
		}
			kol++;
			int q = strlen(m);
			for (int j = 0; j < q; j++)
			{
				mass[kol - 1][j] = m[j];
			}
		return *this;
	}

	int Word:: operator ()(char *p)
	{
		int m = strlen(p);
		for (int i = 0; i < SZ; i++)
		{
			int a = 0, b = 0;
			for (int j = 0; j < SZ_h; j++)
			{
				if (((mass[i][j] >= 'a') && (mass[i][j] <= 'z')) || ((mass[i][j] >= 'A') && (mass[i][j] <= 'Z')))
				{
					if (mass[i][j] == p[j])
						a++;
					else
						b++;
				}
			}

			if ((a + b) == m && a == m)
				return i;
		}
		return -1;
	}

	void Word::sort()
	{
		int temp;
		for (int i = 0; i < kol - 1; i++) {
			for (int j = 0; j < kol - i - 1; j++)
			{
				if (strcmp(mass[j], mass[j + 1]) > 0)
				{
					for (int q = 0; q < SZ_h; q++)
					{
						temp = mass[j][q];
						mass[j][q] = mass[j + 1][q];
						mass[j + 1][q] = temp;
					}
				}
			}
		}
	}
}