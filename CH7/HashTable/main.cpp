#include <iostream>
using namespace std;
#include <vector>
#include <string>

void insertInTable(const string& s, vector<string>& t){
 // Linear probing hashing function
   string alphabet = " abcdefghijklmnopqrstuvwxyz";
    unsigned long long int hash = 0;
    for (char i : s){
        hash = (hash + alphabet.find(i)) % t.size();
    } // O(n)
    // Check for collision

    while (!t[hash].empty()){
        // If collision, increment hash by 1
        cout << "Collision at " << hash << " for student " << s <<   endl;
        hash = (hash + 1) % t.size();
    } // O(n)

    cout << "Hash value for student " << s << ": " << hash << endl;
    t[hash] = s;

} // O(n)


int main() {
    vector<string> table(17);

    insertInTable("marry jhonson", table);
    insertInTable("laith bee", table);
    insertInTable("bob smith", table);
    insertInTable("ana dee", table);
    insertInTable("laith bee", table);

    int i=0;// index in vector starts at 0
    for (auto & it : table) {
        cout << i<< ") "<<it << endl;
        i++;
    } // O(n)


    cout << "All done!" << endl;
    return 0;
}

