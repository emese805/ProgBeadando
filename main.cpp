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

    const int elementIsIn(const int e) const{
        for(int i = 0; i < elements.size(); i++){
            if(elements[i].first == e) return i;
        }
        return -1;
    }

    void add(const int e){
        int eIsIn = elementIsIn(e);
        if(eIsIn >= 0){
            elements[eIsIn].second++;
        }else{
            elements.push_back(std::pair<int,int>(e,1));
        }
    }

    ~Bag(){}    // Destructor
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    Bag mybag;
    mybag.add(3);
    mybag.add(3);
    mybag.add(3);
    mybag.add(2);
    mybag.add(3);
    std::cout << mybag.elementIsIn(3) << mybag.elementIsIn(2) << std::endl;
    return 0;
}