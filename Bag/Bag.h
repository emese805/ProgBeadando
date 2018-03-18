#ifndef PROGBEADANDO_BAG_H
#define PROGBEADANDO_BAG_H
#include <iostream>
#include <vector>


class Bag{
    std::vector< std::pair<int, int> > elements;
public:
    Bag();
    Bag(const Bag& b);
    const int elementIsIn(const int e) const;
    void add(const int e);
    void removeElemet(const int e);
    void removeAll();
    const int countOf(const int e) const;
    const bool isEmpty()const;
    const Bag& operator+(const Bag& b);
    friend std::ostream& operator<<(std::ostream& out, const Bag& b){    //Zsák kiírása
        out << "Zsak Tartalma:\n";
        for(int i = 0; i<b.elements.size();i++){
            out << b.elements[i].first << " szambol " << b.elements[i].second <<" db\n";
        }
        out << (b.isEmpty() ? "Ures.": "van a zsakban.\n");
        return out;
    }
    ~Bag(){}
};

#endif //PROGBEADANDO_BAG_H
