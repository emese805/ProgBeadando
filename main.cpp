#include <iostream>
#include <vector>
#include "Bag/bag.h"


int main() {
    std::cout << "Hello, World!" << std::endl;
    Bag mybag;
    std::cout <<"\n"<< mybag;
    mybag.add(1);
    mybag.add(3);
    mybag.add(3);
    mybag.add(3);
    mybag.add(2);
    mybag.add(2);
    mybag.add(2);
    mybag.add(4);
    mybag.add(2);
    mybag.add(2);
    mybag.add(2);
    mybag.add(3);
    std::cout <<"\n"<< mybag;
    mybag.removeElemet(1);
    std::cout <<"\n"<< mybag;
    return 0;
}