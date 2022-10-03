#include <iostream>


struct Me {

    std::string name;
    bool hate{};

    Me();

    Me(std::string kname, bool h);

};

Me::Me() {

}

Me::Me(std::string kname, bool h) {
    name = kname;
    hate = h;
}

bool operator==(const Me& me, const Me& mee){
    if(me.name == mee.name && me.hate == mee.hate){
        return true;
    }else{
        return false;
    }
}

std::ostream &operator<<(std::ostream &os, const Me &n) {
    os <<  n.name << std::endl;
    os << n.hate;
    return  os;
}


int main() {
    int *name;
    name = new int[10];

    for(int i =0; i < 10; i++){
        name[i] = i+1;
    }
    for (int i = 0; i < 10; ++i) {
        std::cout << name[i];
    }
//    std::cout << kname;
    return 0;
}
