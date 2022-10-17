#include <iostream>
using namespace std;

class Node{
public:
    int x;
    int y;
    Node * next;

    Node(){
        x: 0;
        y: 0;
        next: NULL;
    }

    Node(int x, int y){
        this->x = x;
        this->y = y;
    }
};

class LinkedList {

    Node * head;

public:

    //LinkedList constructor
    LinkedList() { head = NULL; }

    void insertNode(int x, int y){

        Node* node = new Node(x,y);

        if(head == NULL){
            head == node;
        }

        else{
            Node * temp = head;
            while(temp->next != NULL){
                temp = temp -> next;
            }
            temp -> next = node;
        }
    }

    void printList(){
        Node * temp = head;
        while(temp->next != NULL){
            cout << "(" << temp->x << ", " << temp->y <<  "),  ";
            temp = temp -> next;
        }
    }


};

int inBound(int x, int Rs, int Rh){
    if((x < (0-Rh)) && ((x + Rs) < (0 - Rh))){
        return -1;
    }
    else{
        return 1;
    }
}

void calculateScores(int N, LinkedList red, int M, LinkedList yellow, int redScore, int yellowScore){

}

void solve(int scores []){

    int Rs, Rh = 0;
    //Set Rs and Rh values
    cin >> Rs;
    cin >> Rh;

    //Initialize the Red team's Disks in house
    int N = 0;
    cin >> N;

    LinkedList redDisks;

    for(int i = 0; i < N; i++){

        int x, y = 0;
        cin >> x;
        if(!inBound(x, Rs, Rh)){continue;}
        cin >> y;
        if(!inBound(y, Rs, Rh)){continue;}
        redDisks.insertNode(x, y);

    }

    //Initialize the Yellow team's Disks in house

    int M = 0;
    cin >> M;

    LinkedList yellowDisks;

    for(int i = 0; i < M; i++){
        int x, y = 0;
        cin >> x;
        if(!inBound(x, Rs, Rh)){continue;}
        cin >> y;
        if(!inBound(y, Rs, Rh)){continue;}
        yellowDisks.insertNode(x, y);
    }

    //Calculate scores
    int redScore, yellowScore = 0;
    calculateScores(N, redDisks, M, yellowDisks, redScore, yellowScore);

    //Set the scores
    scores[0] = redScore;
    scores[1] = yellowScore;
}

int main(){
    int cases = 0;
    cin >> cases;
    for(int i = 0; i < cases; i++){
        int scores [2] = {0,0};
        solve(scores);
        cout << "Case #" << i+1 << ": " << scores[0] << ", " << scores[1] << endl;

    }

}