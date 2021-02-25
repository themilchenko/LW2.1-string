#pragma once

#include <iostream>

class String
{

private:

	char* symbols;     /*указатель на char*/
	int length;        /*длина строки*/

public:

	/*конструктор по умолчанию*/
	String() : symbols(nullptr), length(0) { };

	/*конструктор копирования*/
	String(const String& string);

	/*конструктор с параметрами (char*) */
	String(const char* str);

	/*деструктор*/
	~String();

	/*оператор присваивания копированием*/
	String& operator=(const String& string);

	/*оператор сравнения*/
	bool operator==(const String& string);

	/*функция подсчета длины строки*/
	int get_size(char* string);
	int get_length();

	/*функция поиска подстроки*/
	int find(const String& string);

	/*функция замены одного символа на другой*/
	void replace(char a, char b);

	/*оператор [] (получение символа по индексу)*/
	char operator[](int index);

	/*оператор + (конкатенация строк)*/
	String& operator+(const String& string);

	/*оператор вывода <<*/
	friend std::ostream& operator<<(std::ostream& output, String& str);

	/*оператор ввода >>*/
	friend std::istream& operator>>(std::istream& input, String& str);
};
