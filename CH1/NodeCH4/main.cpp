#include <iostream>
using namespace std;
#include "Node.hpp";

//void display(Node<int> k) {
////     Node ptr;
//    k = head;
//    while (k != NULL) {
//        cout<< k->data <<" ";
//        ptr = ptr->next;
//    }
//}

int main() {

    // create a node n1 using the no args constructor
    Node<int> n1;

    // create a node n2 using the one arg constructor
    Node<int> n2(1);
    Node<int> *npr;
    npr = new Node<int>(-222);


    // display content of n2
    std::cout << "Node n2 has item: " << n2.getItem() << std::endl;


    std::cout << "Node npr has item: " << npr->getItem() << std::endl;

//    delete npr;

//    std::cout << "Node npr has item: " << npr->getItem()  << std::endl;



    // create two more nodes n3 and n4 using the one arg constructor

    Node<int> n3(2), n4(3), n5(4);

    // link the four nodes together n1->n2->n3->n4->n5

    n1.setNext(&n2);
    n2.setNext(&n3);
    n3.setNext(&n4);
    n4.setNext(&n5);
//    n4.setNext(&n1);





    // create a pointer to n1; name it visitor_ptr
    Node<int>* head;
   
   
   

    // visitor_ptr should point to node n1
    head = &n1;
   
   
   
    // write awhile loop that visits all nodes
    // and displays their content
    cout << "Content of my nodes linked together is: \n";

    while (head != nullptr){
        std::cout << head->getItem() << "    " ;
        head = head->getNext();
    }

//    while (){
//
//    }


   

    return 0;
}