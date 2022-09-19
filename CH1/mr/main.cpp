#include <iostream>
#include <vector>
//using namespace std;

int main ()
{
    std::vector<int> myVect;
    for (int i=1; i<=5; i++)
        myVect.push_back(i);

    std::cout << " myVect contains:";
    for (int i = 0 ; i < myVect.size() ; ++i) {
        auto fa =  myVect.begin() + i;
        std::cout << *fa;
//        std::cout << ' ' << myVect[i];
    }

    std::cout << '\n';

    return 0;
}
