#ifndef PROGBEADANDO_MANUALTESTER_H
#define PROGBEADANDO_MANUALTESTER_H

#include <iostream>
#include <vector>
#include "../Bag/Bag.h"
#include "BasicTester/MenuTemplate.h"

class ManualTester{
private:
    Bag A;
    Bag B;
    Menu myMenu;
    bool exit;
    int readInt(){
        int tmp;
        std::cin >> tmp;
        while (std::cin.fail()){
            if(std::cin.fail()){
                std::cin.clear();
                std::string ignoreLine;             //read the invalid input into it
                std::getline(std::cin, ignoreLine); //read the line till next space
            }
            std::cout << "---------------------------------" << std::endl;
            std::cout <<"Try again: ";
            std::cin >> tmp;
        }
        return tmp;
    }
public:
    ManualTester() : myMenu(Menu("Manual Bag Tester")) {
        //Add menu points for myMenu
        myMenu.addNewMenuPoint(Menu("Add element for one Bag"));                            //  1
        myMenu.lastMenuPoint().addNewMenuPoint(Menu("Add element for A bag"));              // 11   - Leaf
        myMenu.lastMenuPoint().addNewMenuPoint(Menu("Add element for B bag"));              // 21   - Leaf
        myMenu.addNewMenuPoint(Menu("Remove element from one Bag"));                        //  2
        myMenu.lastMenuPoint().addNewMenuPoint(Menu("Remove element from A bag"));          // 12   - Leaf
        myMenu.lastMenuPoint().addNewMenuPoint(Menu("Remove element from B bag"));          // 22   - Leaf
        myMenu.addNewMenuPoint(Menu("Remove all element from one Bag"));                    //  3
        myMenu.lastMenuPoint().addNewMenuPoint(Menu("Remove all element from A bag"));      // 13   - Leaf
        myMenu.lastMenuPoint().addNewMenuPoint(Menu("Remove all element from B bag"));      // 23   - Leaf
        myMenu.addNewMenuPoint(Menu("Element is in the Bag function test"));                //  4
        myMenu.lastMenuPoint().addNewMenuPoint(Menu("Check Element is in the A bag"));      // 14   - Leaf
        myMenu.lastMenuPoint().addNewMenuPoint(Menu("Check Element is in the B bag"));      // 24   - Leaf
        myMenu.addNewMenuPoint(Menu("Count of element in one Bag"));                        //  5
        myMenu.lastMenuPoint().addNewMenuPoint(Menu("Count of element in one A bag"));      // 15   - Leaf
        myMenu.lastMenuPoint().addNewMenuPoint(Menu("Count of element in one B bag"));      // 25   - Leaf
        myMenu.addNewMenuPoint(Menu("Bag is Empty?"));                                      //  6
        myMenu.lastMenuPoint().addNewMenuPoint(Menu("Check A bag is empty?"));              // 16   - Leaf
        myMenu.lastMenuPoint().addNewMenuPoint(Menu("Check B bag is empty?"));              // 26   - Leaf
        myMenu.addNewMenuPoint(Menu("A + B bags Union"));                                   //  7   - Leaf
        myMenu.addNewMenuPoint(Menu("Write Bag to the console"));                           //  8
        myMenu.lastMenuPoint().addNewMenuPoint(Menu("Write A bag to the console"));         // 18   - Leaf
        myMenu.lastMenuPoint().addNewMenuPoint(Menu("Write B bag to the console"));         // 28   - Leaf
    }
    void runManualTest(){
        bool end = false;
        int tmp;
        do {
            //Switch Menu
            switch (myMenu.switchMenu()) {
                case 11:
                    tmp = readInt();
                    A.add(tmp);
                    std::cout << tmp << " added to the A bag\n";
                    break;
                case 21:
                    tmp = readInt();
                    B.add(tmp);
                    std::cout << tmp << " added to the B bag\n";
                    break;
                case 12:
                    tmp = readInt();
                    A.removeElement(tmp);
                    std::cout << tmp << " deleted from the A bag\n";
                    break;
                case 22:
                    tmp = readInt();
                    B.removeElement(tmp);
                    std::cout << tmp << " deleted from the B bag\n";
                    break;
                case 13:
                    A.removeAll();
                    std::cout << "All element from the A bag deleted\n";
                    break;
                case 23:
                    B.removeAll();
                    std::cout << "All element from the B bag deleted\n";
                    break;
                case 14:
                    tmp = readInt();
                    std::cout << tmp << (A.elementIsIn(tmp) >= 0 ? " is" : " is not") << " in the A bag\n";
                    break;
                case 24:
                    tmp = readInt();
                    std::cout << tmp << " is "<< (B.elementIsIn(tmp) >= 0 ? "" : "not") << " in the B bag\n";
                    break;
                case 15:
                    tmp = readInt();
                    std::cout << tmp << " number count in the A bag is " << A.countOf(tmp) << std::endl;
                    break;
                case 25:
                    tmp = readInt();
                    std::cout << tmp << " number count in the B bag is " << B.countOf(tmp) << std::endl;
                    break;
                case 16:
                    std::cout << "A bag is " << (A.isEmpty()? "":"not") << " empty\n";
                    break;
                case 26:
                    std::cout << "B bag is " << (B.isEmpty()? "":"not") << " empty\n";
                    break;
                case 7:
                    std::cout << "The A + B = \n" << A+B;
                    break;
                case 18:
                    std::cout << A;
                    break;
                case 28:
                    std::cout << B;
                    break;
                case -1:
                    std::cout << "Exit\n";
                    end = true;
                    break;
                default:
                    std::cout << "Menu Error" << std::endl;
                    break;
            }
        }while (!end);
    }
    ~ManualTester(){}
};

#endif //PROGBEADANDO_MANUALTESTER_H
