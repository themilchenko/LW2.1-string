#include <iostream>
#include "String.h"

/*конструктор с параметром char*/
String::String(const char* str1)
{
    int size = get_size(const_cast<char*>(str1));     /*определяем размер сроки, которую присваиваем*/

    symbols = new char[size + 1];                     /*определяем новый массив с новой размерностью*/

    for (int i = 0; i < size; i++)                    /*производим копирование*/
        symbols[i] = str1[i];

    symbols[size] = '\0';                             /*в конце ставим нулевой терминатор, как конец строки*/
    this->length = size;
}

/*конструктор копирования*/
String::String(const String& str)
{
    this->length = str.length;

    symbols = new char[str.length + 1];

    for (int i = 0; i < this->length; i++)
        symbols[i] = str.symbols[i];

    symbols[str.length] = '\0';
}

/*деструктор*/
String::~String()
{
    delete[] this->symbols;
    this->length = 0;
}

/*оператор присваивания копированием*/
String& String::operator=(const String& string)
{
    if (this->length == string.length)
    {
        size_t counter = 0;
        for (int i = 0; i < string.length; i++)
            if (string.symbols[i] == this->symbols[i])
                counter++;
        if (counter == this->length)
            return *this;
    }

    if (this->symbols != nullptr)
        delete [] symbols;

    this->symbols = new char[string.length + 1];

    if (string.symbols != nullptr)
        for (int i = 0; i < string.length; i++)
            this->symbols[i] = string.symbols[i];

    this->symbols[string.length] = '\0';
    this->length = string.length;

    return *this;
}

/*оператор сравнения*/
bool String::operator==(const String& string)
{
    int counter = 0;

    if (string.length == this->length)
    {
        for (int i = 0; i < string.length; i++)
            if (this->symbols[i] == string.symbols[i])
                counter++;

        if (counter == string.length)
            return true;
        else
            return false;
    }
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
int String::find(const String& string)
{
    if (string.length > this->length)
        return -1;
    else
    {
        size_t counter = 0;
        size_t pos = 0;
        size_t i = 0;

        for (int j = 0; j < this->length; j++)    
        {    
            if (this->symbols[j] == string.symbols[i] && i == 0)
            {
                pos = j;
                i++;

                if (string.length == 1)
                    return pos;
                else
                    continue;
            }    

            if (this->symbols[j] == string.symbols[i])
                i++;
            else   
                i = 0;

            if (i == string.length)    
                return pos;    
        }    
        return -1;
    }
}

/*функция замены одного символа на другой*/
void String::replace(char a, char b)
{
    for (int i = 0; i < this->length; i++)
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

    String* result = new String;
    result->symbols = new char[this->length + str.length + 1];

    for (int i = 0; i < this->length; i++)
        result->symbols[i] = symbols[i];

    for (int i = 0; i < str.length; i++)
        result->symbols[this->length + i] = str.symbols[i];

    result->symbols[this->length + str.length] = '\0';
    result->length = this->length + str.length;

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
