#include <iostream>
#include <vector>

class Bag{
    std::vector< std::pair<int, int> > elements;
    /*
     * Zsák Reprezentációja
     * Vectorban tárolunk párokat Szám - DB párokat.
     * Az első szám (first) az ami a zsákban van.
     * A második szám (second) pedig azt tárolja,
     * hogy mennyi van ebből a számból a zsákban.
     * */

public:
    Bag(){}     // Default Constructor
    Bag(const Bag& b){
        for(int i = 0; i < b.elements.size(); i++){
            for(int j = 0; j<b.elements[i].second; j++){
                this->add(b.elements[i].first);
            }
        }
    }
    const int elementIsIn(const int e) const{   //e elem benne van-e a zsákban
        for(int i = 0; i < elements.size(); i++){
            if(elements[i].first == e) return i;
        }
        return -1;
    }

    void add(const int e){                      //e elem hozzáadása a zsákhoz
        int eIsIn = elementIsIn(e);
        if(eIsIn >= 0){
            elements[eIsIn].second += 1;
        }else{
            elements.push_back(std::pair<int,int>(e,1));
        }
    }

    void removeElemet(const int e){                   //e elem törlése a zsákból
        int eIsIn = elementIsIn(e);
        if(eIsIn >= 0){
            if(elements[eIsIn].second > 1){
                elements[eIsIn].second-=1;
            }else{
                elements.erase(elements.begin() + eIsIn);
            }
        }
    }

    const int countOf(const int e) const{       //Egy e elem hányszor van a zsákban
        int eIsIn = elementIsIn(e);
        if(eIsIn>=0){
            return elements[eIsIn].second;
        }
        return 0;
    }

    const bool isEmpty()const{                  //Üres-e a zsák
        return elements.size() == 0;
    }

    const Bag& operator+(const Bag& b){         //Unió, használata a plusz jel (+) pl.: Bag Union = Bag1 + Bag2;
        Bag tmp(b);
        for(int i = 0; i < this->elements.size(); i++){
            for(int j = 0; j<this->elements[i].second; j++){
                tmp.add(this->elements[i].first);
            }
        }
    }

    friend std::ostream& operator<<(std::ostream& out, const Bag& b){    //Zsák kiírása
        out << "Zsak Tartalma:\n";
        for(int i = 0; i<b.elements.size();i++){
            out << b.elements[i].first << " szambol " << b.elements[i].second <<" db\n";
        }
        out << (b.isEmpty() ? "Ures.": "van a zsakban.\n");
        return out;
    }

    ~Bag(){}    // Destructor
};

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