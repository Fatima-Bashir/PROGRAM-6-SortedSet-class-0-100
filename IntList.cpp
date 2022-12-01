#include <iostream>
using namespace std;
#include "IntList.h"

IntList::IntList() {
    head = nullptr; 
    tail = nullptr; 
}

IntList::~IntList(){
// while (empty() != false){
//     pop_front(); 
// }
// head = nullptr; 
// tail = nullptr; 

if(head == nullptr && tail == nullptr) {
    head = tail; 
}
else if (head == tail){
    delete[] head; 
    head = tail = nullptr; 
}
else {
    while (head != tail){
        IntNode* t = head; 
        head = head ->next; 
        delete[] t; 
    }
}
}

void IntList::push_front(int value){
    IntNode* newNode = new IntNode(value);
    
    if(head == nullptr){
        head = newNode; 
        tail = newNode; 
    }
    else if (head == tail){
        newNode -> next = head; 
        head = newNode; 
        // tail = head->next; 
    }
    else {
        IntNode* temp = head; 
        head = newNode; 
        head->next = temp; 
        //temp = nullptr; 
    }

}
 
//removes value at front end of list
void IntList::pop_front(){
    if (head == nullptr){
        tail = nullptr; 
    }

    else if (head == tail){
        head = nullptr; 
        delete [] tail; 
        tail = nullptr; 
    }

    else {
        IntNode* tempVal; 
        tempVal = head; 
        head = head ->next;
        delete [] tempVal; 
        tempVal = nullptr; 
    }
}

// returns true if no data values
bool IntList::empty() const{
    if (head == nullptr){
        return true; 
    }
    else {
        return false; 
    }
}

//return reference to first value in list
const int & IntList::front() const{
    return head->value ; 
}

// returns reference to last value in list
const int & IntList::back() const{
    return tail->value; 
}

ostream & operator<<(ostream & cout, const IntList & ilist){
    IntNode* currNode; 
    currNode = ilist.head; 

    while (currNode != nullptr) {
        cout << currNode->value; 
        currNode = currNode->next; 
        if(currNode != nullptr){
            cout << " "; 
        }
    }

    return cout; 
}

//start of new functions


IntList::IntList(const IntList &cpy){
    head = nullptr; 
    tail = nullptr; 
    IntNode* currNode = cpy.head; 

    while (currNode != nullptr){
        push_back(currNode->value);
        currNode = currNode->next; 
    }
}

IntList & IntList::operator=(const IntList &rhs){
        if (this == &rhs){
            return *this; 
        }
        else {
            clear();
            IntNode* currNode = rhs.head; 

            while (currNode != nullptr){
                push_back(currNode->value);
                 currNode = currNode->next; 
    }
            return *this; 
        }
}

void IntList::push_back(int value){
    if (head == nullptr){
        push_front(value);
    }
    else {
        IntNode* newNode = new IntNode(value); 
        tail->next = newNode; 
        tail = newNode; 
    }
}


void IntList::clear(){
    while (!empty()){
        IntNode* temp = head; 
        head = head->next;
        //check if head is null and if so set tail == nullptr
        if (head == nullptr){
            tail = nullptr; 
        }
        delete temp;  
    }
 

}

//Sorts the integers in the list into ascending order. 
//Do NOT move the nodes, just the integers.
void IntList::selection_sort(){
    IntNode* currNode = head;  
    IntNode* min;
    IntNode* j = head;
    int temp;  

    while (j != nullptr) {
        min = j; 
        currNode = j; 
        while (currNode != nullptr){
            if(currNode->value < min->value){
                min = currNode; 
            }
            currNode = currNode->next;
        }
        temp = j-> value; 
        j->value = min->value;
        min->value = temp; 
        j = j->next; 
    }
}

//still do
void IntList::insert_ordered(int value){
   
    if(head == nullptr){
        push_front(value);
    }


    else if(head->value > value){
        push_front(value);
    }

    else if(tail->value <= value){
        push_back(value);
    }

    else {
        IntNode* currNode = head->next; 
        IntNode* previousNode = head; 
        IntNode* newNode = new IntNode(value);

        while(previousNode->value <= value){
            if (currNode->value > value){
                previousNode->next = newNode; 
                newNode->next = currNode; 
            }
            previousNode = currNode; 
            currNode = currNode->next; 
        }
    }
    
}
void IntList::remove_duplicates(){
    IntNode* currNode;  
    IntNode* previousNode;
    IntNode* outerLoop = head;  
    IntNode* temp; 

    while (outerLoop != nullptr) {
        previousNode = outerLoop; 
        currNode = outerLoop->next;  
        while (currNode != nullptr){
            if(currNode->value == outerLoop->value){
                temp = currNode; 
                currNode = currNode->next; 
                if(currNode == nullptr){
                    tail = previousNode; 
                }
                previousNode->next = currNode; 
                delete[] temp; 
            }
            else{
                currNode = currNode->next;
                previousNode = previousNode->next;
            }
        }
        outerLoop = outerLoop->next; 
    }
}
