//
// Created by Oreofe Solarin on 9/12/22.
//



#include <stdio.h>
#include <iostream>
#include <iomanip>
#include <cassert>
#include <cstring>
#include "Text.h"

//--------------------------------------------------------------------
// Creates a string containing the delimited sequence of characters
// charSeq. Allocates enough memory for this string.
// Pre: none
// Post: creates a Text object containing the array pointed to by charSeq
Text:: Text ( const char *charSeq )
{
        bufferSize = strlen(charSeq) + 1;   // Account for null

    try
    {
        buffer = new char [ bufferSize ];   // Allocate memory
        for(int i = 0; i <= bufferSize; i++){
            buffer[i] = charSeq[i];
        }

    }
    catch ( bad_alloc &e )
    {
        cerr << "Text::Text(const char): bad_alloc: buffer == 0\n";
        throw bad_alloc();
    }

    strcpy(buffer,charSeq);             // Copy the string
}

// Creates a string containing the delimited sequence of characters
// charSeq. Allocates enough memory for this string.
// Pre: none
// Post: creates a Text object containing the Text Object pointed to by valueText
Text:: Text ( const Text &valueText )
{
    bufferSize = valueText.getLength();
    buffer = new char[bufferSize];
    for(int i = 0; i <= bufferSize; i++){
        buffer[i] = valueText[i];
    }

}

//--------------------------------------------------------------------
// Assigns a value of Text Object to a Text Obj.
// charSeq. Allocates enough memory for this string.
// Pre: none
// Post: assignment of Text from a Text Object
void Text:: operator = ( const Text& other )
{

    if (this != &other){
//        delete [] buffer;
//        bufferSize = other.getLength();
//        buffer = new char[bufferSize];

        for (int i=0; i < other.getLength(); i++){
            cout << other[0] << "  ";
        }
//        for (int i = 0; i < bufferSize; i++){
//            cout << other[i];
//        }
    }

}

//--------------------------------------------------------------------
// Deletes the content of Text Object
// Pre: none
// Post: creates a Text object containing the Text Object pointed to by valueText
Text:: ~Text ()
{
    delete [] buffer;


}

// Returns the length of characters in Text Object
// Pre: none
// Post: returns an int value of length of bufferSize - 1;
//--------------------------------------------------------------------
int Text:: getLength () const
{
    return bufferSize - 1;
}


// Returns the char at position n in the Text Object
// int n  is the index to be referenced.
// Pre: none
// Post: Returns the char of buffer[n]
//--------------------------------------------------------------------
char Text:: operator [] ( int n ) const
{

    if(n > 0 && n < bufferSize){
        return buffer[n];
    }else{

        return '\0';

    }

}


// Clears all chars in Text Object.
// Pre: none
// Post: returns void amd carries out the operation of removing each char in the Text Object
//--------------------------------------------------------------------
void Text:: clear ()
{

    delete [] buffer;
    buffer = new char[bufferSize];
    for(int i=0; i < bufferSize;i++){
        buffer[i] = ' ';

    }

}


// Displays structure of Text each char at a time
// Pre: none
// Post: Cout  << each element;
//--------------------------------------------------------------------
void Text:: showStructure () const
{
    for (int i=0; i < bufferSize;i++){
        cout << i << "  ";
    }
cout << endl;
    for (int i=0;i < bufferSize;i++){
        cout << buffer[i] << "  ";
    }


    cout << endl;
    cout << endl;


}

//--------------------------------------------------------------------
//
//                        In-lab operations
//
//--------------------------------------------------------------------
// Input Text object
// istream is the input with an object Text
// Pre: Requires an argument of istream and Text object
// Post: returns istream instance and takes input into the buffer.
istream & operator >> ( istream &input, Text &inputText )
{
    input >> inputText.buffer;
    return input;
}

//--------------------------------------------------------------------
// Input Text object
// ostream is the input with an object Text
// Pre: Requires an argument of ostream and Text object
// Post: returns ostream instance and gives an output into the buffer.
ostream & operator << ( ostream &output, const Text &outputText )
{
    output << outputText.buffer;
    return output;
}


//--------------------------------------------------------------------
// Returns an object Text which each char upper Case
// Pre:
// Post: returns a Text Object by switch each character in the buffer to upper case.

Text Text:: toUpper ( ) const
{
    Text temp(buffer);
    for(int i=0; i < bufferSize; i++){
        if((buffer[i] > 96) && (buffer[i] < 123)){
            temp.buffer[i] = char(buffer[i] - 32);
        }
    }
    return temp;
}

//--------------------------------------------------------------------
// Returns an object Text which each char to Lower
// Pre:
// Post: returns a Text Object by switch each character in the buffer to lower case.
Text Text:: toLower ( ) const
{
    Text temp(buffer);
    for(int i=0; i < temp.getLength(); i++){
        if((buffer[i] > 64) && (buffer[i] < 91)){
            temp.buffer[i] = char(buffer[i] + 32);
        }
    }
    return temp;
}


//--------------------------------------------------------------------
// Returns a boolean value if each char the buffer matches with input &other.
// Pre: Requires a input other Text Object
// other is an object Text
// Post: return a boolean value based if the comparison is of the buffer and the other Text Object
bool Text::operator == ( const Text &other ) const
{
    if(bufferSize == other.getLength()){
        if(bufferSize == 0){
            return true;
        }
        else{
            for(int i = 0; i < bufferSize; i++){
                if(buffer[i] != other.buffer[i]){
                    return false;
                }
            }
            return true;
        }
    }
    else{
        return false;
    }
}

//--------------------------------------------------------------------
// Returns a boolean value based the buffer length of the buffer and the Text other size
// Pre: Requires a input other Text Object
// other is an object Text
// Post: return a boolean value based if the length of buffer is less or greater than the  other Text object size
bool Text::operator < ( const Text &other ) const
{
    if (other.getLength()){
        if(bufferSize){
            for(int i = 0; i < bufferSize; i++){
                if (buffer[i] > other.buffer[i]){
                    return false;
                }
            }
            if((other.getLength() < bufferSize) || (other.getLength() == bufferSize)){
                return false;
            }
            else{
                return true;
            }
        }
        else{
            return true;
        }
    }
    return false;
}

//--------------------------------------------------------------------files for students
bool Text::operator > ( const Text &other ) const
{
    if(bufferSize){
        if(other.getLength()){
            for(int i = 0; i < other.getLength(); i++){
                if (buffer[i] < other.buffer[i]){
                    return false;
                }
            }
            if((other.getLength() > bufferSize) || (other.getLength() == bufferSize)){
                return false;
            }
            else{
                return true;
            }
        }
        else{
            return true;
        }
    }
    return false;
}

