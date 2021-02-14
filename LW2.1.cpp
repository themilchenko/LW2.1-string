#include <iostream>
#include "String.h"

/*конструктор с параметром char*/
String::String(const char* str1)
{
    int size = get_size((char*)(str1));     /*определяем размер сроки, которую присваиваем*/

    symbols = new char[size + 1];  /*определяем новый массив с новой размерностью*/

    for (int i = 0; i < size; i++) /*производим копирование*/
        symbols[i] = str1[i];

    symbols[size] = '\0';          /*в конце ставим нулевой терминатор, как конец строки*/
    this->length = size;
}

/*конструктор копирования*/
String::String(const String& str)
{
    size_t size = get_size(str.symbols);

    symbols = new char[size + 1];

    for (int i = 0; i < size; i++)
        symbols[i] = str.symbols[i];

    symbols[size] = '\0';
    this->length = size;
}

/*деструктор*/
String::~String()
{
    delete[] this->symbols;
}

/*оператор присваивания копированием*/
String& String::operator=(const String& string)
{
    if (this->symbols != nullptr)
        delete [] symbols;

    size_t size = get_size(string.symbols);

    symbols = new char[size + 1];

    if (string.symbols != nullptr)
        for (int i = 0; i < size; i++)
            symbols[i] = string.symbols[i];

    symbols[size] = '\0';
    this->length = size;

    return *this;
}

/*оператор сравнения*/
bool String::operator==(const String& string)
{
    int counter = 0;
    size_t size = get_size(string.symbols);

    for (int i = 0; i < size; i++)
        if (symbols[i] == string.symbols[i])
            counter++;

    if (counter == size)
        return true;
    else
        return false;
}

/*функция подсчета длины строки*/
int String::get_size(char* string)
{
    int i = 0;

    while (string[i] != '\0')
        i++;

    return i;
}

int String::get_length()
{
    return this->length;
}

/*функция поиска подстроки*/
int String::find(char a)
{
    size_t size = get_size(symbols);

    for (int i = 0; i < size; i++)
        if (symbols[i] == a)
            return i;

    return -1;
}

/*функция замены одного символа на другой*/
void String::replace(char a, char b)
{
    size_t size = get_size(symbols);

    for (int i = 0; i < size; i++)
        if (symbols[i] == a)
            symbols[i] = b;
}

/*оператор [] (получение символа по индексу)*/
char String::operator[](int index)
{
    return symbols[index];
}

/*оператор + (конкатенация строк)*/
String& String::operator+(const String& str)
{
    int size1 = get_size(symbols);
    int size2 = get_size(str.symbols);

    String* result = new String;
    result->symbols = new char[size1 + size2 + 1];

    for (int i = 0; i < size1; i++)
        result->symbols[i] = symbols[i];

    for (int i = 0; i < size2; i++)
        result->symbols[size1 + i] = str.symbols[i];

    result->symbols[size1 + size2] = '\0';
    result->length = size1 + size2;

    return *result;
}

/*оператор вывода <<*/
std::ostream& operator<<(std::ostream& output, String& str)
{
    for (int i = 0; i < str.get_length(); i++)
        output << str[i];

    return output;
}

/*оператор ввода >>*/
std::istream& operator>>(std::istream& input, String& str)
{
    int size = 32727;
    char* current = new char[size + 1];
    int begin = 0;
    char a;

    while (current[begin - 1] != '\n')
    {
        input.get(a);
        current[begin] = a;
        begin++;
    }

    current[begin - 1] = '\0';

    str = current;

    delete[] current;

    return input;
}