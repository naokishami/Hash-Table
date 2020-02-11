#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;


// HASH TABLE
//
// structure:
//      hash table that contains linked lists for every
//      element which in turn contain Nodes
//
// Collision Resolution: chaining (linked lists)
//
// variable Nodes will contain variable name and value
//
// print:
//      1. first, go down the hash table
//      2. as we're going down the hash table, go further by traversing
//              down a linked list should there be anything to travel down
//      3. then call the print Node function as we're hitting every
//              single node


// BORG FILE
//
// algorithm:
//      read the file line by line
//      parse the line
//      find key words
//      pass key words to appropriate function
//      execute
//      repeat by reading the next line


// EXECUTION
//
//


const int SIZE = 13;


class Node {
public:
    string name;
    int value;
    Node *next;
    Node (string name = "", int value = 0, Node *next = nullptr) {
        this->name = name;
        this->value = value;
        this->next = next;
    }
    void printNode () {
        cout << "Name: " << this->name << endl;
        cout << "Value: " << this->value << endl;
    }
    string getName () { return name; }
    int getValue () { return value; }
};


class lList {
private:
    Node *head, *tail;
public:
    lList () {
        head = NULL;
        tail = NULL;
    }
    void addNode (string name, int value) {
        Node *tmp = new Node;
        tmp->name = name;
        tmp->value = value;
        
        if (head == NULL) {
            head = tmp;
            tail = tmp;
        }
        else {
            tail->next = tmp;
            tail = tail->next;
        }
    }
    void traversePrint () {
        Node *tmp = head;
        while (tmp != NULL) {
            tmp->printNode();
            tmp = tmp->next;
        }
    }
    void searchKeyHelper (string key) {
        Node *tmp = head;
        while (tmp != nullptr) {
            if (tmp->name == key) {
                cout << key << " has the value: " << tmp->value << endl;
                break;
            }
            else {
                tmp = tmp->next;
            }
        }
        return;
    }
};


class hTable {
private:
    lList *table[SIZE];
public:
    hTable () {
        lList *objPtr;
        
        for (int i = 0; i < SIZE; i++) {
            objPtr = new lList;
            table[i] = objPtr;
        }
    }
    int hash (string input) {
        int sum = 0;
        int i = 1;
        
        for (char ch : input) {
            sum += ch * i;
            i++;
        }
        
        return sum % SIZE;
    }
    void insert (Node obj) {
        string name = obj.getName();
        int value = obj.getValue();
        int index = hash(name);
        table[index]->addNode(name, value);
    }
    void searchKey (string key) {
        for (int i = 0; i < SIZE; i++) {
            table[i]->searchKeyHelper(key);
        }
    }
    void print () {
        for (int i = 0; i < SIZE; i++) {
            cout << "\t\tBucket [" << i << "]" << endl;
            table[i]->traversePrint();
            cout << "----------------------------" << endl;
        }
    }
};  // this concludes everything needed to make the hash table work


class BORGfile {
private:
public:
    BORGfile () {
        
    }
};


int main () {
    Node a = *new Node ("Joel", 21);
    a.printNode();
    Node b = *new Node ("Fred", 22);
    b.printNode();
    Node c = *new Node ("Umi Todoroki", 21);
    c.printNode();
    
    cout << "\n-----New table-----\n\n";
    hTable table = *new hTable;
    table.insert(a);
    table.insert(b);
    table.insert(c);
    table.print();
}
