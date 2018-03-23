#ifndef PROGBEADANDO_MANUALTESTER_H
#define PROGBEADANDO_MANUALTESTER_H

#include <iostream>
#include <vector>
#include "../Bag/Bag.h"

class ManualTester{
private:
    Bag A;
    Bag B;
    bool exit;

    std::vector<std::string> menu;
    const std::string subMenuQuestion = "Which Bag do you want to run the test?";
    const std::string subMenuAnswer1 = "Bag A";
    const std::string subMenuAnswer2 = "Bag B";

public:
    ManualTester(){
        this->exit = false;
        menu.push_back("Add element to Bag");
        menu.push_back("Remove an element from Bag");
        menu.push_back("Remove all elements from Bag");
        menu.push_back("Bag is empty?");
        menu.push_back("Element is in the Bag?");
        menu.push_back("Count of element is in the bag");
        menu.push_back("2 Bag union");
        menu.push_back("Write Bag to console");
        menu.push_back("Exit");
    }
    int mainMenu(){
        std::cout << "Navigation" << std::endl;
        std::cout << "------------" << std::endl;
        for(int i = 0; i<menu.size();i++){
            std::cout << i+1 << " - " << menu[i] << std::endl;
        }
        std::cout << "Choose one of this menu points:" <<std::endl;

        std::string tmp;
        int sw;
        bool hiba;
        do{
            std::cin >> tmp;
            hiba=tmp!="1" && tmp!="2" && tmp!="3" && tmp!="4" && tmp!="5" && tmp!="6" && tmp!="7" && tmp!="8" && tmp!="9";
            if(hiba){
                std::cout<<"Nincs ilyen menupont. Probald ujra: ";
            }
        }while(hiba);
        sw=atoi(tmp.c_str());
        std::cout<<std::endl;
        return sw;
    }
    void main(){
        do{
            int sw = mainMenu();
            switch (sw){
                case 1:

                    break;
            }
        }while(!this->exit);
    }
    bool getExit (){
        return this->exit;
    }
    ~ManualTester(){}
};

#endif //PROGBEADANDO_MANUALTESTER_H
