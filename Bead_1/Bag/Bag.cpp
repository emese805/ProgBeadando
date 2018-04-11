#include "Bag.h"

Bag::Bag(){}     // Default Constructor
Bag::Bag(const Bag& b){
    this->elements = std::vector< std::pair<int, unsigned int> >(b.elements);
}

const int Bag::elementIsIn(int e) const{   //e elem benne van-e a zsákban
    for(int i = 0; i < elements.size(); i++){
        if(elements[i].first == e) return i;
    }
    return -1;
}

void Bag::add(const int e){                      //e elem hozzáadása a zsákhoz
    int eIsIn = elementIsIn(e);
    if(eIsIn >= 0){
        elements[eIsIn].second += 1;
    }else{
        elements.push_back(std::pair<int,unsigned int>(e,1));
    }
}

void Bag::removeElement(int e){                   //e elem törlése a zsákból
    int eIsIn = elementIsIn(e);
    if(eIsIn >= 0){
        if(elements[eIsIn].second > 1){
            elements[eIsIn].second -= 1;
        }else{
            elements.erase(elements.begin() + eIsIn);
        }
    }
}

void Bag::removeAll(){
    elements.clear();
}

const int Bag::countOf(int e) const{       //Egy e elem hányszor van a zsákban
    int eIsIn = elementIsIn(e);
    if(eIsIn>=0){
        return elements[eIsIn].second;
    }
    return 0;
}

const bool Bag::isEmpty()const{                  //Üres-e a zsák
    return elements.empty();
}

const Bag& Bag::operator+(const Bag& b){         //Unió, használata a plusz jel (+) pl.: Bag Union = Bag1 + Bag2;
    Bag *tmp = new Bag(b);
    for(int i = 0; i < this->elements.size(); i++){
        for(int j = 0; j<this->elements[i].second; j++){
            tmp->add(this->elements[i].first);
        }
    }
    return *tmp;
}