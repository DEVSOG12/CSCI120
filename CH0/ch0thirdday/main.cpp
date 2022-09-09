#include <iostream>

using namespace std;

bool areAnagram(const string &str1, const string &str2)
{

        if(str1.size() == str2.size() &&
        is_permutation(begin(str1), end(str1),
                       begin(str2), std::end(str2) ))
        {
            return true;
        }
    return false;



}

int howManyOccurrences(const string &sample, const string &target) {
    if (target.length() == 0) return 0;
    int count = 0;
    for (size_t offset = sample.find(target); offset != string::npos;
         offset = sample.find(target, offset + target.length()))
    {
        ++count;
    }
    return count;

}
void isPalindrome(const string &str) {
    if( equal(str.begin(), str.begin() + str.size()/2, str.rbegin()) )
        cout << str << " is a palindrome.\n";
    else
        cout << str << " is NOT a palindrome.\n";
}

int main()

{
    // Pb.1 : 4
//    char animal[7]="bird";
//    cout << strlen(animal);

// Pb.2 Change strlen(s) to s.length()
//    string s("abc");
//    cout << strlen(s); // Wrong
//    cout << s.length();

//Pb.3 Use getline() instead of cin >> because getline() scans the entire not minding white spaces or ASCII code 32
//    string s;
//    cout << "Input your full name: ";// Bob Smith
//    getline(cin, s);
//    cout << s;



// Pb. 4: Outputs comment to the right
//    string s = "The cat in the hat";
//
//    short int wordFound1 = s.find("cat");
//    cout << wordFound1 << endl;   // 4
//
//    int wordFound2 = s.find("dog");
//    cout << wordFound2 << endl; // -1
//
//    size_t wordFound3 = s.find("dog");
//    cout << wordFound3 << endl; // 18446744073709551615
//    cout << string::npos; //18446744073709551615

//Pb.5: Checking if ASCII code length of each string is bigger
//    string str1;
//    string str2;
//
//    cout << "Enter String1: ";
//    cin >> str1;
//    cout << "Enter String2: ";
//    cin >> str2;
//
//
//
//
//    if(str1.compare(str2) ){
//        cout << str1 <<" is bigger than " << str2;
//    }else{
//        cout << str2 << " is bigger than "<<  str1;
//    }
//
//


// Pb.6: Anagrams
//    string str1 = "absbd", str2 = "bsbad";
//
//    if (areAnagram(str1, str2)) {
//        cout << "The two strings are anagram of each other";
//    }
//    else
//        cout << "The two strings are NOT anagram of each other";


// Pb.7:

//    cout << howManyOccurrences("michmichmich", "mich");

    // pb.9

//    isPalindrome("ormro");




    return 0;
}