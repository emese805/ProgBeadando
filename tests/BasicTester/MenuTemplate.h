//
// Created by Duba on 2018. 03. 19..
// sanyikarcsi@gmail.com
//

#ifndef MENUTEMPLATE_H
#define MENUTEMPLATE_H

#include <iostream>
#include <vector>
#include <cmath>

class Menu{
private:
    bool isLeaf(){
        return menuPoints.size() == 0;
    }
    int readInt(int from, int to){
        int tmp;
        std::cin >> tmp;
        while (std::cin.fail() || tmp < from || tmp > to){
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
    const int recursiveMenu(int child = 0){
        std::cout << "---------------------------------" << std::endl;
        std::cout << title << std::endl;
        std::cout << "---------------------------------" << std::endl;
        for(int i = 0; i <menuPoints.size(); i++){
            std::cout << i+1 << " - " << menuPoints[i].title << std::endl;
        }
        std::cout << 0 << " - " << "Exit" << std::endl;
        std::cout << "---------------------------------" << std::endl;
        std::cout << "Your Choice: " << std::endl;
        int sw = readInt(0,menuPoints.size());
        if(sw == 0){
            return -1;
        }else if(menuPoints[sw-1].isLeaf()){
            return sw*((int)pow(10,child));
        }
        return (sw)*((int)pow(10,child))+menuPoints[sw-1].recursiveMenu(child+1);
    }
public:
    std::string title;
    std::vector<Menu> menuPoints;
    Menu(const std::string& title) : title(title) {}
    Menu(const Menu& m){
        this->title = m.title;
        for(int i = 0; i < m.menuPoints.size(); i++){
            this->menuPoints.push_back(m.menuPoints[i]);
        }
    }
    Menu& operator=(const Menu& m){
        this->title = m.title;
        for(int i = 0; i < m.menuPoints.size(); i++){
            this->menuPoints.push_back(m.menuPoints[i]);
        }
    }
    void addNewMenuPoint(const Menu &menu){
        menuPoints.push_back(menu);
    }
    Menu& lastMenuPoint(){
        return menuPoints[menuPoints.size()-1];
    }
    const int switchMenu(){
        recursiveMenu();
    }
};

#endif //MENUTEMPLATE_H
