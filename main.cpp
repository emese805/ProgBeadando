#include <iostream>
#include "tests.h"

int main() {
    BagTester bt;
    std::cout << "Test1 " << (bt.test1() ? "passed" : "failed") << std::endl;
    std::cout << "Test2 " << (bt.test2() ? "passed" : "failed") << std::endl;
    std::cout << "Test3 " << (bt.test3() ? "passed" : "failed") << std::endl;
    std::cout << "Test4 " << (bt.test4() ? "passed" : "failed") << std::endl;
    std::cout << "Test5 " << (bt.test5() ? "passed" : "failed") << std::endl;
    std::cout << "Test6 " << (bt.test6() ? "passed" : "failed") << std::endl;
    bt.logBagToConsole();
    return 0;
}