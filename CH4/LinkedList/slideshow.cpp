//--------------------------------------------------------------------
//
//  Laboratory 5, Programming Exercise 1                 slideshow.cpp
//
//--------------------------------------------------------------------

// Displays a slide show.

// Uncomment the following line if running in windows
// #define WIN32

#include <iostream>
#include <fstream>
#include <ctime>
using namespace std;
#include <sstream>
#include <string>

#include "ListLinked.hpp"

//--------------------------------------------------------------------

// This is a very ugly way to wait for a specified amount of time.
// It is ugly because it runs the CPU the whole time, instead of
// just suspending the process for the required time period.
// However, it is also very portable.  This function should work on
// all platforms that support ANSI C++.  Feel free to replace this
// with something nicer (such as sleep or usleep) if you so choose.
void wait(int secs) 
{
    int start=clock();
	
    while (clock() < start + secs * CLOCKS_PER_SEC);
}

//--------------------------------------------------------------------

class Slide
	{
	public:
		static const int HEIGHT = 10,		// Slide dimensions
		WIDTH  = 36;
		
		void display () const;			// Display slide and pause
		
	private:

		char image [HEIGHT][WIDTH];  	   // Slide image
		int pause;				   // Seconds to pause after
		//  displaying slide

    friend istream& operator>> (istream& in, Slide& slide);
    friend ostream& operator<< (ostream & in, const Slide& slide);

	};

//--------------------------------------------------------------------

int main ()
{
    List<Slide> slideShow;    // Slide show
    Slide currSlide;                // Slide
    char filename[81];              // Name of slide show file
	
    // Read the slide show from the specified file.
	
    cout << endl << "Enter the name of the slide show file : ";
    cin >> filename;

    std::fstream slideFile ( filename );
	
    if ( !slideFile )
    {
		cout << "Error opening file " << filename << endl;
    }
    else
    {   int i = 0;
        while ( slideFile >> currSlide )
        {
            slideShow.insert ( currSlide );
            i++;

        }
		// Close the file.
		slideFile.close();
		
		// Display the slide show slide-by-slide.
        slideShow.gotoBeginning();
        while (i != 0){
            slideShow.getCursor().display();
            slideShow.gotoNext();
            i--;
        }

    }
	
    return 0;
}

//--------------------------------------------------------------------
//

istream& operator>> (istream& inFile, Slide& slide)
// Read a slide from inFile.
{
//    for (int i = 0; i < Slide::HEIGHT; i++)
//    {
//        inFile.getline ( slide.image[i], Slide::WIDTH + 1 );
//    }
//    inFile >> slide.pause;
//    inFile.ignore ( 1000);
//    return inFile;
//
//
//}
    string line;
    int i = 0;
    while (inFile.peek() != EOF && getline(inFile, line) && i < Slide::HEIGHT){
        if (line.length() > Slide::WIDTH){
            line = line.substr(0, Slide::WIDTH);
        }
        strcpy(slide.image[i], line.c_str());
        i++;

//
//                strcpy(slide.image[i], line.c_str());
//                i++;

//            }
        }
//        line = "";

    inFile >> slide.pause;
    return inFile;
}


//____________________________________________________

ostream& operator<< (ostream& out, const Slide& slide)
{
    out << slide.pause << endl;
    for (const auto & j : slide.image)
    {
        out << j << endl;
    }
    return out;
}

//--------------------------------------------------------------------

void Slide:: display () const
// Display the slide image, then wait for 'pause' seconds. 

{
	
    int i, j;

    for (i = 0; i < HEIGHT; i++)
    {
        for (j = 0; j < WIDTH; j++)

            if(image[i][j] == '\0')
                cout << " ";
            else
                cout << image[i][j];
        cout << endl;
    }
    cout << ". . . . . . . . . . . . . . . . . ."<<endl;
    cout << "1";

    wait ( pause );
}
