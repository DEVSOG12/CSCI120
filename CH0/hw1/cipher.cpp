//
// Created by Oreofe Solarin on 9/2/22.
//
#include <iostream>

#include <regex>

using namespace std;

string rot13(string &plainText){
// student code goes here

    // We have the plainText as to be ciphered
    for (char & i : plainText) { // CPP Advices that the ranged based loop is inside. More Readable
        if(i >= 'a' && i <= 'm'){
            // This if statement checks if the char [plainText[i]] is between a and m. Basically forming a switch pattern
            // If so we can switch it. Based on adding 13 to the ASCII code
            i = i + 13;
        } else if (i >= 'n' && i <= 'z') {
            // This if statement checks if the char [plainText[i]] is between n and z. If so we can switch it.
            // Based on removing 13 to the ASCII code
            i = i - 13;

        }
    }
    // Return the ciphered || enciphered plain text.
    //
    return plainText;
}

int main() {
    string plainText, cipherText;

    cout << "Enter text: ";
    getline(cin, plainText);

    assert(regex_match(plainText, regex("^(.*)[A-Za-z]+|\\s$"))); // Make sure it's only alphabets
    // transforms all lower case
    for(char & i : plainText) // CPP Advices that the ranged based loop is inside. More Readable
        i = tolower(i);


    cipherText = rot13(plainText);
    cout<<"Cipher text: " << cipherText<<endl;
    cout << "Plain text:  "<< rot13( cipherText) << endl;
}


