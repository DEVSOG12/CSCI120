#include <iostream>
#include <random>
//#include <vector>

#include "Restaurant.hpp"
#include "Time.hpp"
using namespace std;

int x();

bool isPalindrome(string& basicString);

// Print Matrix from vector of vectors
template <typename T>
void printMatrix(vector<T>& matrix) {
//   Check typename T type
if (typeid(T) == typeid(vector<int>)) {
    cout << "vector<int>" << endl;
}
//   cout <<  << endl;
    for_each(matrix.begin(), matrix.end(), [](vector<int> &row) {
        for_each(row.begin(), row.end(), [](int &x) {
            cout << x << " ";
        });
        cout << endl;
    });
}

int mains() {
//    Restaurant Restaurant;
//    Restaurant.printMenu();
    vector<int> myvector;
    for (int i=1; i<=10; i++) myvector.push_back(i);
    cout << "myvector Initially contains:";
    for (int & it : myvector)
        cout << ' ' << it;
    cout << endl;
    shuffle ( myvector.begin(), myvector.end() , std::mt19937(std::random_device()()));
    cout << "After shuffle myvector contains:";
    for (int & it : myvector)
        cout << ' ' << it;
    cout << endl;
    sort(myvector.begin(), myvector.end());
    cout << "After sort myvector contains:";
    for (int & it : myvector)
        cout << ' ' << it;
    cout << endl;


    auto it = min_element(myvector.begin(), myvector.end());
    cout << *it << endl;
//    myvector.erase(it);
    auto v = std::remove(myvector.begin(), myvector.end(), *it);
    cout << *v << endl;
    cout << "After erase myvector contains:";
    for (int & it : myvector)
        cout << ' ' << it;
    cout << endl;

        accumulate(myvector.begin(), myvector.end(), 0);
        x();
        return 0;
}

// Create a 2d array using a vector of vectors and initialize it with random numbers and print it out.

int x()
{
    vector<vector<int>> v(3, vector<int>(3));
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            v[i][j] = rand() % 2;
//            cout << "[" << v[i][j]  << "]" << " ";
        }
//        cout << endl;
    }
    printMatrix(v);


         return 0;
}

// Queues

class Queue {
    private:
        int front;
        int rear;
        int size;
        int *Q;
    public:
        Queue() {front = rear = -1; size = 10; Q = new int[size];}
        Queue(int size) {front = rear = -1; this->size = size; Q = new int[this->size];}
        void enqueue(int x);
        int dequeue();
        void Display();
    };

void Queue::enqueue(int x) {
    if (rear == size - 1)
        cout << "Queue is Full" << endl;
    else {
        rear++;
        Q[rear] = x;
    }

}

int Queue::dequeue() {
    int x = -1;
    if (front == rear)
        cout << "Queue is Empty" << endl;
    else {
        x = Q[front + 1];
        front++;
    }
    return x;
}

void Queue::Display() {
    for (int i = front + 1; i <= rear; i++)
        cout << Q[i] << " " << flush;
    cout << endl;
}

// Queues using Linked List

class Node {
    public:
        int data;
        Node *next;
};

class QueueL {
    private:
        Node *front;
        Node *rear;
    public:
        QueueL() {front = rear = nullptr;}
        void enqueue(int x);
        int dequeue();
        void Display();
    };

void QueueL::enqueue(int x) {
    Node *t = new Node;
    if (t == nullptr)
        cout << "Queue is Full" << endl;
    else {
        t->data = x;
        t->next = nullptr;
        if (front == nullptr)
            front = rear = t;
        else {
            rear->next = t;
            rear = t;
        }
    }

}

int QueueL::dequeue() {
    int x = -1;
    Node *p;
    if (front == nullptr)
        cout << "Queue is Empty" << endl;
    else {
        p = front;
        front = front->next;
        x = p->data;
        delete p;
    }
    return x;
}

void QueueL::Display() {
    Node *p = front;
    while (p) {
        cout << p->data << " " << flush;
        p = p->next;
    }
    cout << endl;

}

int mainb() {
    Queue q(5);

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.Display();

    cout << q.dequeue() << endl;
    q.Display();

    QueueL qL;
    qL.enqueue(10);
    qL.enqueue(20);
    qL.enqueue(30);
    qL.Display();

    cout << qL.dequeue() << endl;

    qL.Display();

    return 0;
}

int main() {
    Time time(22,22);

    Time time2(11,11);


    time2 = time;

//    delete time2;

   time2.display();



}
bool isPalindrome(string& basicString) {
    Queue q(int(basicString.length()));
    for (auto i: basicString) {
        q.enqueue(i);
    } // a b c b a

    for (auto i: basicString) {
        if (q.dequeue() != i) {
            return false;
        }
    }
    return true;
}

bool isPalind(string &k) {
    // Check if length is even or odd
    if(k.length() % 2 == 0) {
        // ab ba
    } else {
        // Odd
       // If the substring between 0, k.length() / 2 is not equal to the substring between k.length() / 2 + 1, k.length() - 1
        if (k.substr(0, k.length() / 2) != k.substr(k.length() / 2 + 1, k.length() - 1)) {
            return false;
        }
    }
}



