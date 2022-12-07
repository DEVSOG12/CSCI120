#include <iostream>
#include <memory>
using namespace std;
// activity adapted from U. of Colorado


void demo_shared_ptr(){
    cout << "** shared_ptr example **\n"<<
         "- shared_ptr is a counting pointer, it keeps track of how many shared owners this object has, via a counter.\n"<<
         "- new owner (via assignment) increments the counter.\n"<<
         "- when any owner is destroyed, the counter decrements.\n"<<
         "- when the counter goes to zero, there are no more owners, so the object itself is destroyed.\n"<<
         "- you can assign a shared_ptr. It just increments the use_count.\n";

    shared_ptr<int> p(new int(-7));
    cout << "p use_count: "<< p.use_count() << '\n';
    {
        cout << "p use_count: "<< p.use_count() << '\n';
        auto q=p;
        cout << "p use_count: "<< p.use_count() << '\n';
        cout << "q use_count: "<< q.use_count() << '\n';
        // checkpoint 1
    }
    cout << "p use_count: "<< p.use_count() << '\n';
    // checkpoint 2

    // Q1: show output
    // Q2: at chekpoint 1 how many pointers point at object -7?
    // Q3: at chekpoint 2 how many pointers point at object -7?
}


void demo_weak_ptr()
{
    cout << "** weak_ptr example **\n"<<
         "- A weak pointer holds a 'non-owning' reference to an object.\n";

    auto sharedPtr1 = make_shared<int>(99);
    auto sharedPtr2 = sharedPtr1;
    auto sharedPtr3 = sharedPtr1;
    cout << "sharedPtr1 use_count: "<< sharedPtr1.use_count() << '\n';
    weak_ptr<int> weakPtr1 = sharedPtr1;
    cout << "sharedPtr1 use_count: "<< sharedPtr1.use_count() << '\n';
    cout << "weakPtr1 use_count: "<< weakPtr1.use_count() << '\n';

// Q4: This code creates 3 shared pointers and 1 week pointer. All 4
//  pointer point to the same int object. What is the code above printing?
}

void demo_unique_ptr(){
    cout << "** unique_ptr example **\n"<<
         "- A unique_ptr â€œownsâ€ the pointed-to object.\n"<<
         "- When the unique_ptr is destroyed (usually, by falling out of scope) then the pointed-to objected is destroyed, as well.\n"<<
         "- You cannot copy a unique_ptr. Which one would be the unique owner?\n";

    unique_ptr<int> p(new int(-13));
    cout << "p: "<< *p << '\n'; // dereferencing: prints out the int object that p points to
    //auto q = move(p);
    //cout << "q: "<< *q << '\n';
    // checkpoint 1
    unique_ptr<int> q = std::move(p);
    // Q5: at chekpoint 1, write "unique_ptr<int> q = p;" Is it compiling? If not, why not?
    // A5: No, because unique_ptr is not copyable.
    // Q6: at chekpoint 1, write "auto q = move(p);" Is it compiling? Who is pointing now to the int object -13, p or q?
    // A6: Yes, it is compiling. Now q is pointing to the int object -13.

}
auto dev(){
    // How does auto know what type to use?
    // It looks at the return type of the function.
    // If the return type is a pointer, then auto will be a pointer.
    // If the return type is a reference, then auto will be a reference.
    // If the return type is a value, then auto will be a value.
    // If the return type is a const, then auto will be a const.
    // If the return type is a volatile, then auto will be a volatile.
    // If the return type is a const volatile, then auto will be a const volatile.
    return true;
}

 volatile int x = 0; // volatile means that the value of x can change at any time, without the compiler knowing about it.
 auto me = {}; // auto is a map, because the return type of the initializer list is a map.
int main() {
    cout << "** There are three kinds of smart pointers: **\n"<<
         "1) unique_ptr if the object has one owner\n"<<
         "2) shared_ptr if the object has several owners\n"<<
         "3) weak_ptr is a 'non-owning' reference to an object \n"<<
         "4) auto_ptr - this is faulty and is deprecated in C++ 2011 and is removed from C++ 2017 - do not use it!\n\n";

    // To students: one by one uncheck the function calls from below to be able to
    // run various examples and to answer the questions Q1- Q6 from above.
    int n;
    cin >> n;

    switch (n) {
    case 1:
        demo_unique_ptr();
        break;
    case 2:
        demo_shared_ptr();
        break;
    case 3:
        demo_weak_ptr();
        break;
    default:
        cout << "Invalid input";
        break;
    }
    return 0;

    //demo_shared_ptr();
    //demo_weak_ptr();
    //demo_unique_ptr();

}