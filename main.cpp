#include <iostream>
#include "String.h"

int main()
{
    String str;
    std::cout << "Enter the string: ";
    std::cin >> str;

    std::cout << "This is your string: " << str;

    String a("World");
    std::cout << a << std::endl;

    String b;
    b = "Hello";

    String c;
    c = a + b;

    std::cout << c << std::endl;

    if (a == b)
        std::cout << "The strings are equal\n";
    else
        std::cout << "The string aren't equal\n";

    std::cout << "The 2nd element of string a is " << a[2] << std::endl;

    int pos_of_a = a.find('a');
    int pos_of_l = a.find('l');

    std::cout << pos_of_l << ' ' << pos_of_a << std::endl;

    b.replace('H', 'Y');

    std::cout << str + a << std::endl;

    return 0;
}
