#include <iostream>
#include "Array.h"

int main()
{
    int arr[] = { 12, 6, 10, 9 , 4 };
    Array a(arr, 5);
    std::cout << a << std::endl;
    long c = 4;
    a[c] = 199;
    Array a_copy(a);
    std::cout << a_copy << std::endl;
    a.sort();
    std::cout << a << std::endl;
    a.shift(3, 0, Array::RIGHT);
    std::cout << a << std::endl;
}