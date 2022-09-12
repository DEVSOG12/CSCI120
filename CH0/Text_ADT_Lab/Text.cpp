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

Text:: Text ( const Text &valueText )
{
    bufferSize = valueText.getLength();
    buffer = new char[bufferSize];
    for(int i = 0; i <= bufferSize; i++){
        buffer[i] = valueText[i];
    }

}

//--------------------------------------------------------------------
void Text:: operator = ( const Text& other )
{

    if (this != &other){
        delete [] buffer;
        bufferSize = other.getLength();
        buffer = new char[bufferSize];
        for (int i = 0; i < bufferSize; i++){
            buffer[i] = other[i];
        }
    }

}

//--------------------------------------------------------------------
Text:: ~Text ()
{
    delete [] buffer;


}

//--------------------------------------------------------------------
int Text:: getLength () const
{
    return bufferSize - 1;
}

//--------------------------------------------------------------------
char Text:: operator [] ( int n ) const
{

    if(n > 0 && n < bufferSize){
        return buffer[n];
    }else{

        return '\0';

    }

}

//--------------------------------------------------------------------
void Text:: clear ()
{

    delete [] buffer;
    buffer = new char[bufferSize];
    for(int i=0; i < bufferSize;i++){
        buffer[i] = ' ';
    }

}

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
istream & operator >> ( istream &input, Text &inputText )
{
    input >> inputText.buffer;
    return input;
}

//--------------------------------------------------------------------
ostream & operator << ( ostream &output, const Text &outputText )
{
    output << outputText.buffer;
    return output;
}


//--------------------------------------------------------------------
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

