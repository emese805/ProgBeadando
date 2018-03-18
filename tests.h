#ifndef PROGBEADANDO_TESTS_H
#define PROGBEADANDO_TESTS_H

#include "Bag/Bag.h"

/*
 * Constructor Test
 * Copy Contstructor
 * elementIsIn() -------------------
 * removeAll() ---------------------
 * removeElement() -----------------
 * add() ---------------------------
 * countOf() -----------------------
 * isEmpty() -----------------------
 * operator+ -----------------------
 * ostream -------------------------
 * */


class BagTester{
private:
    Bag b1;
    Bag b2;
    void clear(){
        b1.removeAll();
        b2.removeAll();
    }
public:
    BagTester(){
        clear();
    }
    /*
     * add()
     * elementIsIn()
     * */
    bool test1(){
        clear();
        b1.add(3);
        return b1.elementIsIn(3) != -1;
    }
    /*
     * add()
     * removeElement()
     * elementIsIn()
     * */
    bool test2(){   //remove Test
        clear();
        b1.add(3);
        b1.add(5);
        b1.removeElemet(3);
        return b1.elementIsIn(3) == -1;
    }
    /*
     * add()
     * removeAll()
     * isEmpty
     * */
    bool test3(){   //removeAll and isEmpty Test
        clear();
        b1.add(3);
        b1.add(5);
        b1.removeAll();
        return b1.isEmpty();
    }
    /*
     * add()
     * countOf()
     * */
    bool test4(){   //countOf() Test
        clear();
        b1.add(3);
        b1.add(3);
        b1.add(5);
        return b1.countOf(3) == 2;
    }
    /*
     * add()
     * countOf()
     * operator+
     * */
    bool test5(){   //operator+ Test
        clear();
        b1.add(3);
        b1.add(2);
        b1.add(2);
        b1.add(2);
        b2.add(3);
        b2.add(3);
        Bag u = b1+b2;
        return u.countOf(2) == 3 && u.countOf(3) == 3;
    }
    /*
     * add()
     * countOf()
     * copy Constructor
     * */
    bool test6(){   //Copy Constructor Test
        clear();
        b1.add(3);
        b1.add(2);
        b1.add(2);
        b1.add(2);
        Bag myNewBag(b1);
        return myNewBag.countOf(3) == b1.countOf(3) && myNewBag.countOf(2) == b1.countOf(2);
    }
    void logBagToConsole(){
        clear();
        b1.add(3);
        b1.add(2);
        b1.add(3);
        b1.add(5);
        b1.add(6);
        std::cout << b1 << std::endl;
    }
};

#endif //PROGBEADANDO_TESTS_H
