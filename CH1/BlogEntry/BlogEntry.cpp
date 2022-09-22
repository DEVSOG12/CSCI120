//
// Created by Oreofe Solarin on 9/19/22.
//

#include "BlogEntry.h"
#include "Text.h"

BlogEntry::BlogEntry()  {
   author = Text("Author");
   contents = Text("Content");
   created = Date();
   modified = Date();

}

BlogEntry::BlogEntry(const Text &initAuthor, const Text &initContents) {
    author = initAuthor;
    created = Date();
    contents = initContents;
}

Text BlogEntry::getAuthor() const {
    return author;
}

Text BlogEntry::getContents() const {
    return contents;
}

Date BlogEntry::getCreateDate() const {
    return created;
}

Date BlogEntry::getModifyDate() const {
    return modified;
}

void BlogEntry::setAuthor(const Text &newAuthor) {
    author = newAuthor;
    modified = Date();
}

void BlogEntry::setContents(const Text &newContents) {
    contents = newContents;
    modified = Date();
}

void BlogEntry::showStructure() const {
    std::cout << "Author Name: " << author << std::endl;
    std::cout << "Date Created: " << created << std::endl;
    std::cout << "Date Modified: " << modified << std::endl;
    std::cout << "Content: " << std::endl << contents << std::endl;

}

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
