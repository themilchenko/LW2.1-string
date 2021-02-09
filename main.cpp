#include <iostream>

class String
{

    char* symbols;   /*указатель на чар*/
    size_t size;     /*разиер строки*/

public:

    /*конструктор по умолчанию*/
    void constructor()
    {
        size = 0;
        symbols = nullptr;
    }

    /*конструктор с параметрами*/
    String(const int& size_of_string, char* &symbols1)
    {
        size = size_of_string;
        symbols = symbols1;
        symbols1 = nullptr;
    }

    /* конструктор с параметром char* */
    String(char* str): symbols(str)
    { }

    /*конструктор копирования*/
    String(const String& str)
    {
        char* new_symbols = new char[str.size];
        if (str.symbols != nullptr)
            for (int i = 0; i < size; i++)
                new_symbols[i] = str.symbols[i];
    }

    /*деструктор*/
    ~String()
    {
        if (symbols != nullptr)
            delete[] symbols;
    }

    /*оператор присваивания копированием*/
    String operator=(const String& str1)
    {
        if (this == &str1)
            return *this;

        if (symbols != nullptr)
            delete symbols;

        size = str1.size;

        if (str1.symbols != nullptr)
        {
            for(int i = 0; i < size; i++)
                symbols[i] = str1.symbols[i];
        }

        return* this;
    }

    /*оператор сравнения*/
    bool operator==(const String& str1)
    {
        int counter = 0;

        for (int i = 0; i < str1.size; i++)
            if (symbols[i] == str1.symbols[i])
                counter++;

        if (counter == size)
            return true;
        else
            return false;
    }

    /*функция подсчета длины строки*/
    int get_size()
    {
        return size;
    }

    /*функция поска подстрокти*/
    int find(char a)
    {
        for (int i = 0; i < size; i++)
            if (symbols[i] = a)
                return i;

        return -1;
    }

    /*функция замены одного символа на другой*/
    void replace(char a, char b)
    {
        for (int i = 0; i < size; i++)
            if (symbols[i] = a)
                symbols[i] = b;
    }

    /*оператор [] (получение символа по индексу)*/
    char operator[](const String& str)
    {

    }

};

int main()
{

    return 0;
}
