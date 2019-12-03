#ifndef WORD_H
#define WORD_H

#include <iostream>

namespace Prog3_1 {

	class Word {
	private:
		static const int SZ_h = 10; // максимальное количество букв в слове
		static const int QUOTA = 5; // размер квоты для выделния памяти
		int SZ; // максимальное количество слов в массиве
		char **mass; // массив слов
		int kol; // количество слов в массиве

	public:
		Word();
		Word(const char *l);
		Word(const char k[5][10], int n);
		Word(const Word&); // копирующий конструктор
		Word(Word&&); // перемещающий конструктор
		~Word(); // деструктор
		Word & operator =(const Word &); // перегруженый оператор присваивания
		Word & operator =(Word &&); // перемещающий оператор присваивания
		friend std::ostream & operator <<(std::ostream &, const Word &);
		Word & operator +=(char *m);
		char* operator[](int u);
		int operator ()(char *p);
		void sort();
	};
}
#endif 
