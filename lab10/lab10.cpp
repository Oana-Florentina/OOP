#include <iostream>
#include "vect.h"



int main(){
    Array<int> a(5);
    a.Insert(0, 4);
    a.Insert(1, 5);
    a.Insert(0, 2);
    
    Array<int> b(a);
    b.Insert(0, 55);
    b += 0;
    std::cout << b[b.GetCount() - 1] << std::endl;

    Array<int> c(10);
    c += 44;
    c += 64;
    c += 213;

    for (int i = 0; i < c.GetCount(); i++)
        std::cout << c[i] << " ";
       std::cout<<std::endl;
    c.Insert(1, a);
    
    for (int i = 0; i < c.GetCount(); i++)
        std::cout << c[i] << " ";
    std::cout<<std::endl;

    c.Delete(4);
    c.Delete(0);
    c.Insert(0, 3231);
    for (int i = 0; i < c.GetCount(); i++)
        std::cout << c[i] << " ";
    std::cout<<std::endl;
    
    c.Sort();


    for (int i = 0; i < c.GetCount(); i++)
        std::cout << c[i] << " ";
    std::cout<<std::endl;

    std::cout << c.BinarySearch(4) << " ";
}
