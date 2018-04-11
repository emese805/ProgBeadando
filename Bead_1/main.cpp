#include <iostream>
#include "tests/ManualTester.h"
#include "tests/BagTester.h"
#include "tests/BasicTester/MenuTemplate.h"


int main() {

    /* Automatic Bag Tester
     *
     *
    BagTester bt;
    std::cout << "Test1 " << (bt.test1() ? "passed" : "failed") << std::endl;
    std::cout << "Test2 " << (bt.test2() ? "passed" : "failed") << std::endl;
    std::cout << "Test3 " << (bt.test3() ? "passed" : "failed") << std::endl;
    std::cout << "Test4 " << (bt.test4() ? "passed" : "failed") << std::endl;
    std::cout << "Test5 " << (bt.test5() ? "passed" : "failed") << std::endl;
    std::cout << "Test6 " << (bt.test6() ? "passed" : "failed") << std::endl;
    bt.logBagToConsole();
    */
    Bag myNewBag;
    myNewBag.add(3);
    myNewBag.add(3);
    myNewBag.add(3);
    myNewBag.add(3);

    Bag myAnotherBag(myNewBag);
    std::cout << myAnotherBag;
/*    ManualTester mt;
    mt.runManualTest();*/
    return 0;
}