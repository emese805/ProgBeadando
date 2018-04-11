#include <iostream>
#include <fstream>

struct Student{
    std::string neptun;
    int gradue;
    int points;
};

enum Status{abnorm, norm};

class SeqInFile
{
public:
    SeqInFile(const std::string &fname): x(fname.c_str()){}
    void first() { x.seekg(0); read();}
    void next()  { read();}
    Student current() const { return e; }
    bool end() const { return abnorm==st; }
private:
    std::ifstream x;
    Student e;
    Status st;

    void read(){
        x >> e.neptun;
        if(x.fail()){
            st=abnorm;
        }
        for(int i=0;i<6;i++) {
            int tmp;
            x >> tmp;
            if(!x.fail()) {
                e.points+=tmp;
            }
        }
        if(e.points<20){
            e.gradue=1;
        }else if(e.points<30){
            e.gradue=2;
        }else if(e.points<40){
            e.gradue=3;
        }else if(e.points<50){
            e.gradue=4;
        }else{
            e.gradue=5;
        }
    };



};

int main() {
    std::string filename;
    SeqInFile t("text1.txt");
    int gradues[5];
    for(int i=0; i<5;i++){
        gradues[i]=0;
    }
    for(t.first();!t.end();t.next()){
        std::cout << t.current().neptun;
        std::cout << " " << t.current().points << std::endl;
        gradues[t.current().gradue-1]++;
    }
    for(int i=0;i<5;i++) {
        std::cout<< i+1 << ": " << gradues[i] << "db" << std::endl;
    }
    return 0;
}