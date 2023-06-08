#include <iostream>
#include <string>
using namespace std;
class Node {
public:
    int rollNumber;
    string name;
    Node* next;
};

class CircularLinkedList {
private:
    Node* LAST;
public:
    CircularLinkedList() {
        LAST = NULL;
    }
    void addNode();
    bool search(int rollno, Node** previous, Node** windya);
    bool listEmpty();
    bool delNode();
    void traverse();
};

void CircularLinkedList::addNode() { 
    //write your answer here
    //Beginning of the list
    int number;                 
    string nm;
    cout << "\nEnter the roll number of the student: ";
    cin >> number;
    cout << "\nEnter the name of the student: ";
    cin.ignore();
    getline(cin, nm);

    Node* newNode = new Node();     //Allocate memory for the new node
    newNode->rollNumber = number;   //Assign value to the data field of the new node
    newNode->name = nm;

    newNode->next = LAST;           //Make the next field of the new node point to the succesfor of LAST
    LAST->next = newNode;           //Make the next field of LAST point to the new node

    //Between two nodes in the list
}

bool CircularLinkedList::search(int rollno, Node** putri, Node** windya) {
    *putri = LAST->next;
    *windya = LAST->next;
    while (*windya != LAST) {
        if (rollno == (*windya)->rollNumber) {
            return true;
        }
        *putri = *windya;
        *windya = (*windya)->next;
    }
    if (rollno == LAST->rollNumber) {
        return true;
    }
    else {
        return false;
    }
}

bool CircularLinkedList::listEmpty() {
    return LAST == NULL;
}

bool CircularLinkedList::delNode() { 
    //write your answer here
    if (listEmpty() == true) {
        cout << "\nList is empty" << endl;

    }

}

void CircularLinkedList::traverse() {
    if (listEmpty()) {
        cout << "\nList is empty\n";
    }
    else {
        cout << "\nRecords in the list are:\n";
        Node* windyaNode = LAST->next;
        while (windyaNode != LAST) {
            cout << windyaNode->rollNumber << " " << windyaNode->name << endl;
            windyaNode = windyaNode->next;
        }
        cout << LAST->rollNumber << " " << LAST->name << endl;
    }
}

int main() {
    CircularLinkedList obj;
    while (true) {
        try {
            cout << "\nMenu" << endl;
            cout << "1. Add a record to the list" << endl;
            cout << "2. Delete a record from the list" << endl;
            cout << "3. View all the records in the list" << endl;
            cout << "4. Exit" << endl;
            cout << "\nEnter your choice (1-5): ";
            char ch;
            cin >> ch;
            switch (ch) {
            case '1': {
                obj.addNode();
                break;
            }
            case '2': {
                obj.delNode();
                break;
            }
            case '3': {
                obj.traverse();
                break;
            }
            case '4': {
                return 0;
            }
            default: {
                cout << "Invalid option" << endl;
                break;
            }
            }
        }
        catch (exception& e) {
            cout << e.what() << endl;
        }
    }
    return 0;
