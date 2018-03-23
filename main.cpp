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

    //create a Menu
    Menu myMenu = Menu("Main Menu Title");

    //Add menu points for myMenu
    myMenu.addNewMenuPoint(Menu("Menu point with SubMenu"));                            //  1
    myMenu.lastMenuPoint().addNewMenuPoint(Menu("Yes"));                                // 11   - Leaf
    myMenu.lastMenuPoint().addNewMenuPoint(Menu("No"));                                 // 21   - Leaf
    myMenu.addNewMenuPoint(Menu("Second Menu Point, Without SubMenu"));                 //  2   - Leaf
    myMenu.addNewMenuPoint(Menu("Third Menu Point, With 2 deep SubMenu"));              //  3
    myMenu.lastMenuPoint().addNewMenuPoint(Menu("First Sub"));                          // 13
    myMenu.lastMenuPoint().lastMenuPoint().addNewMenuPoint(Menu("First Sub Yes"));      //113   - Leaf
    myMenu.lastMenuPoint().lastMenuPoint().addNewMenuPoint(Menu("First Sub No"));       //213   - Leaf
    myMenu.lastMenuPoint().addNewMenuPoint(Menu("Second Sub"));                         // 23
    myMenu.lastMenuPoint().lastMenuPoint().addNewMenuPoint(Menu("Second Sub Yes"));     //123   - Leaf
    myMenu.lastMenuPoint().lastMenuPoint().addNewMenuPoint(Menu("Second Sub No"));      //223   - Leaf

    //Switch Menu
    switch (myMenu.switchMenu()){
        case 11:
            std::cout<<"Menu point with SubMenu --> Yes\n";
            break;
        case 21:
            std::cout<<"Menu point with SubMenu --> No\n";
            break;
        case 2:
            std::cout<<"Second Menu Point, Without SubMenu\n";
            break;
        case 113:
            std::cout<<"Third Menu Point, With 2 deep SubMenu --> First Sub --> First Sub Yes\n";
            break;
        case 213:
            std::cout<<"Third Menu Point, With 2 deep SubMenu --> First Sub --> First Sub No\n";
            break;
        case 123:
            std::cout<<"Third Menu Point, With 2 deep SubMenu --> Second Sub --> Second Sub Yes\n";
            break;
        case 223:
            std::cout<<"Third Menu Point, With 2 deep SubMenu --> Second Sub --> Second Sub No\n";
            break;
        case -1:
            std::cout<<"Exit\n";
            exit(1);
        default:
            std::cout << "Menu Error" << std::endl;
            break;
    }
    return 0;
}