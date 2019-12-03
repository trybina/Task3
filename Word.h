#ifndef WORD_H
#define WORD_H

#include <iostream>

namespace Prog3_1 {

	class Word {
	private:
		static const int SZ_h = 10; // ������������ ���������� ���� � �����
		static const int QUOTA = 5; // ������ ����� ��� �������� ������
		int SZ; // ������������ ���������� ���� � �������
		char **mass; // ������ ����
		int kol; // ���������� ���� � �������

	public:
		Word();
		Word(const char *l);
		Word(const char k[5][10], int n);
		Word(const Word&); // ���������� �����������
		Word(Word&&); // ������������ �����������
		~Word(); // ����������
		Word & operator =(const Word &); // ������������ �������� ������������
		Word & operator =(Word &&); // ������������ �������� ������������
		friend std::ostream & operator <<(std::ostream &, const Word &);
		Word & operator +=(char *m);
		char* operator[](int u);
		int operator ()(char *p);
		void sort();
	};
}
#endif 
