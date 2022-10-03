//
// Created by Oreofe Solarin on 9/19/22.
//

#include "BlogEntry.h"
#include "Text.h"


// Initializer of class
// Post: TBH just a constructor
BlogEntry::BlogEntry()  {
   author = Text("Author");
   contents = Text("Content");
   created = Date();
   modified = Date();

}

// Initializer of class
// Pre: req. parameter type Text --:> initial Author Name, and Text --:> Initial Contents
// Post: TBH just a constructor
BlogEntry::BlogEntry(const Text &initAuthor, const Text &initContents) {
    author = initAuthor;
    created = Date();
    contents = initContents;
}

// getter of [Text] Author Name
// Pre: Nothing tbh
// Post: Return the private value author. [Text]
Text BlogEntry::getAuthor() const {
    return author;
}

// getter of [Text] Contents
// Pre: Nothing tbh
// Post: Return the private value contents. [Text]
Text BlogEntry::getContents() const {
    return contents;
}

// getter of [Date] Created Date
// Pre: Nothing tbh
// Post: Return the private value created. [Date]
Date BlogEntry::getCreateDate() const {
    return created;
}

// getter of [Date] Modified Date
// Pre: Nothing tbh
// Post: Return the private value modified. [Date]
Date BlogEntry::getModifyDate() const {
    return modified;
}

// Setter of [Text] Author Name
// Pre: Req. [Text] newAuthor
// Post: Nothing, just nothing. That's why it's a void func
void BlogEntry::setAuthor(const Text &newAuthor) {
    author = newAuthor;
    modified = Date(); // It's sensible to modify the modify cuz it's every time a setter is called
}

// Setter of [Text] Contents
// Pre: Req. [Text] newContents
// Post: Nothing, just nothing. That's why it's a void func
void BlogEntry::setContents(const Text &newContents) {
    contents = newContents;
    modified = Date(); // It's sensible to modify the modify cuz it's every time a setter is called
}



// Print cout the Structure of the Type of BlogEntry,
// Pre: Nothing tbh
// Post: std::cout each value: [Text] Author, Contents; [Date] created, modified
void BlogEntry::showStructure() const {
    std::cout << "Author Name: " << author << std::endl;
    std::cout << "Date Created: " << created << std::endl;
    std::cout << "Date Modified: " << modified << std::endl;
    std::cout << "Content: " << std::endl << contents << std::endl;

}

// Pre: Req. std::ostream. It's actually wrong to use "using namespace std"
// Post: it prints to the console
void BlogEntry::printHTML(ostream &out) const {
    out  << "<html>" << endl;
    out << "<body> "<< endl;
    out << "<h1>" << author << "</h1>" << endl;
  out<<"<p>" <<contents<<"</p>" << endl;
   out<< "<p>" << endl;
    out << "Created:" << created << endl;
    out <<    "</p>"  <<endl;
    out << "<p>" << endl;
    out << "Last modified:" << modified << endl;
    out <<    "</p>"  <<endl;
    out << "<p>" << endl;
    out << "</body>" << endl;
    out << "</html>";
}
