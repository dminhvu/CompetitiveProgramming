#include<bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < int(n); i++)
#define fore(i,a,b) for (int i = int(a); i <= int(b); i++)
#define ford(i,a,b) for (int i = int(a); i >= int(b); i--)
#define ll int64_t
#define sz(x) int(x.size())

using namespace std;
template<class t, class u> bool maxi(t &a, u b){ if (a < b){ a = b; return 1;} return 0;}
template<class t, class u> bool mini(t &a, u b){ if (a > b){ a = b; return 1;} return 0;}

class SinglyLinkedList {
public:
    struct Node {
        int value;
        Node *next;
        Node(int x): value(x), next(nullptr) {}
    };

    Node *pHead, *pTail, *dummyHead;
    int list_size = 0;

    SinglyLinkedList() {
        dummyHead = new Node(0);
		pHead = pTail = dummyHead;
        cout << "Your list has been created!\n";
        cout << flush;
    }

    void get(int index) {
        if (index >= list_size) {
            cout << "Cannot perform query!\n";
            cout << flush;
            return;
        }
        Node *tmp = dummyHead->next;
        for(int i = 0; i < index; i++) {
            tmp = tmp->next;
        }
        cout << "The value of the " << index << "-th element is " << tmp->value << ".\n";
        cout << flush;
    }

    void addAtHead(int val) {
        Node *new_node = new Node(val);
        new_node->next = dummyHead->next;
        dummyHead->next = new_node;
        pHead = new_node;
        if (new_node->next == nullptr) pTail = new_node;
        list_size += 1;
        cout << "An element with the value of " << val << " was added to the head of your list!\n";
        cout << flush;
    }

    void addAtTail(int val) {
    	Node *new_node = new Node(val);
        pTail->next = new_node;
        pTail = new_node;
        list_size += 1;
        cout << "An element with the value of " << val << " was added to the tail of your list!\n";
        cout << flush;
    }

    void addAtIndex(int index, int val) {
        if (index > list_size) {
            cout << "Cannot perform query!\n";
            cout << flush;
            return;
        }
    	Node *new_node = new Node(val);
    	Node *tmp = dummyHead;
        for(int i = 0; i < index; i++) {
            tmp = tmp->next;
        }
        new_node->next = tmp->next;
        tmp->next = new_node;
        if (index == 0) pHead = new_node;
        if (index == list_size) pTail = new_node;
        list_size += 1;
        cout << "An element with the value of " << val << " was added to the " << index << "-th position of your list!\n";
        cout << flush;
    }

    void deleteAtIndex(int index) {
        if (index < 0 || index >= list_size) {
            cout << "Cannot perform query!\n";
            cout << flush;
            return;
        }
        Node *tmp = dummyHead;
        for(int i = 0; i < index; i++) {
            tmp = tmp->next;
        }
        Node *tmp2 = tmp->next;
        tmp->next = tmp->next->next;
        tmp2->next = nullptr;
        delete tmp2;
        if (index == 0) pHead = tmp->next;
        if (index == list_size - 1) pTail = tmp;
        list_size -= 1;
        cout << "The element at the " << index << "-th position has been deleted!\n";
        cout << flush;
    }

    void show() {
        Node *tmp = dummyHead->next;
        cout << "Your current list: ";
        while (tmp != nullptr) {
            cout << tmp->value << " ";
            tmp = tmp->next;
        }
        cout << '\n';
        cout << flush;
    }
};


int main() {
	// ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cout << "Welcome to SinglyLinkedList!\n";
    int query_type = -1;
    SinglyLinkedList mySinglyLinkedList;
    do {
        "Please choose the queries below:\n";
        cout << "1. Append a new element\n";
        cout << "2. Delete an element\n";
        cout << "3. Print the current list\n";
        cout << "0. Exit\n";
        cout << flush;
        cin >> query_type;
        if (query_type == 1) {
            system("cls");
            cout << "Please choose the queries below:\n";
            cout << "1. Append to the head\n";
            cout << "2. Append to the tail\n";
            cout << "3. Append to a position\n";
            cout << flush;
            int query_type_2; cin >> query_type_2;
            if (query_type_2 == 1) {
                cout << "Input the value of your element: ";
                cout << flush;
                int value; cin >> value;
                mySinglyLinkedList.addAtHead(value);
            } else if (query_type_2 == 2) {
                cout << "Input the value of your element: ";
                cout << flush;
                int value; cin >> value;
                mySinglyLinkedList.addAtTail(value);
            } else if (query_type_2 == 3) {
                cout << "Input the value of your element: ";
                cout << flush;
                int value; cin >> value;
                cout << "Input the position you want to add: ";
                cout << flush;
                int position; cin >> position;
                mySinglyLinkedList.addAtIndex(position, value);
            } else {
                cout << "Cannot perform your selection!\n";
                cout << flush;
            }
        } else if (query_type == 2) {
            cout << "Input the position you want to delete: ";
            cout << flush;
            int position; cin >> position;
            mySinglyLinkedList.deleteAtIndex(position);
        } else if (query_type == 3) {
            mySinglyLinkedList.show();
        } else if (query_type != 0) {
            cout << "Cannot perform your selection!\n";
            cout << flush;
        }
        system("cls");
    } while (query_type != 0);
	// SinglyLinkedList mySinglyLinkedList; // create a new list
    // mySinglyLinkedList.addAtHead(10); // append 10 to the head
    // mySinglyLinkedList.get(0); // get the value of the 0-th element
    // mySinglyLinkedList.addAtTail(5); // append 5 to the tail
	return 0;
}
