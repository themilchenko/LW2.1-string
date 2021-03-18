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
    length = size;
}

/*конструктор копирования*/
String::String(const String& str)
{
    length = str.length;

    symbols = new char[str.length + 1];

    for (int i = 0; i < length; i++)
        symbols[i] = str.symbols[i];

    symbols[str.length] = '\0';
}

/*деструктор*/
String::~String()
{
    delete[] symbols;
    length = 0;
}

/*оператор присваивания копированием*/
String& String::operator=(const String& string)
{
    if (this != &string)
    {
        if (symbols != nullptr)
            delete[] symbols;

        symbols = new char[string.length + 1];

        if (string.symbols != nullptr)
            for (int i = 0; i < string.length; i++)
                symbols[i] = string.symbols[i];

        symbols[string.length] = '\0';
        length = string.length;
    }
    return *this;
}

/*оператор сравнения*/
bool String::operator==(const String& string)
{
    int counter = 0;

    if (string.length == length)
    {
        for (int i = 0; i < string.length; i++)
            if (symbols[i] == string.symbols[i])
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
    return length;
}

/*функция поиска подстроки*/
int String::find(const String& string)
{
    if (string.length > this->length)
        return -1;
    else
    {
        size_t pos = 0;
        size_t counter = 0;

        for (int j = 0; j < length; j++)    
        {

            int count = 0;
            pos = j;

            if (string.length > length - j)
                return -1;
            else
            {
                size_t count = j;
                for (int i = 0; i < string.length; i++)
                {
                    if (symbols[count] == string.symbols[i])
                        counter++;
                    count++;
                }
                    
            }

            if (counter == string.length)
                return pos;

            counter = 0;
        }    
        return -1;
    }
}

/*функция замены одного символа на другой*/
void String::replace(char a, char b)
{
    for (int i = 0; i < length; i++)
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
    result->symbols = new char[length + str.length + 1];

    for (int i = 0; i < length; i++)
        result->symbols[i] = symbols[i];

    for (int i = 0; i < str.length; i++)
        result->symbols[length + i] = str.symbols[i];

    result->symbols[length + str.length] = '\0';
    result->length = length + str.length;

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

    do
    {
        input.get(a);
        current[begin] = a;
        begin++;
    } while (current[begin - 1] != '\n');

    current[begin - 1] = '\0';

    str = current;

    delete[] current;

    return input;
}
