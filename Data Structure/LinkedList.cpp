#include<bits/stdc++.h>

using namespace std;

struct token{
    string tokenname;
    string value;
};

struct node {
    token current;
    node* next = NULL;
};

class linkedlist {
public:
    node* head;
    linkedlist() {
        head = NULL;
    }

    node* new_node(string a, string b) {
        node* temp = (node*) malloc(sizeof(node));
        temp->current.tokenname = a;
        temp->current.value = b;
        temp->next = NULL;
        return temp;
    }

    void append(string a, string b) {
        node* temp = head;
        if (temp == NULL) {
            temp = new_node(a,b);
            head = temp;
        } else {
            while(temp->next != NULL) {
                temp= temp->next;
            }
            temp->next = new_node(a,b);
        }
        return;
    }

    void searchNode(string a, string b) {
        node* temp = head;
        if (temp == NULL) {
            cout << "The list is empty!" << endl;
        } else {
            bool found = false;
            while(temp != NULL) {
                if(temp->current.tokenname == a && temp->current.value == b) {
                    cout << "Token found" << endl;
                    found = true;
                }
                temp = temp->next;
            }
            if(!found) {
                cout << "Token not found" << endl;
            }
        }
    }

    void deleteNode(string a, string b) {
        node* temp = head;
        if (temp == NULL) {
            cout << "The list is empty!" << endl;
        } else {
            bool found = false;
            while(temp != NULL) {
                if(temp->current.tokenname == a && temp->current.value == b) {
                    if(temp->next == NULL) {
                        temp = NULL;
                    } else {
                        temp->current.tokenname = temp->next->current.tokenname;
                        temp->current.value = temp->next->current.value;
                        temp->next = temp->next->next;
                    }
                    found = true;
                }
                temp = temp->next;
            }
            if(!found) {
                cout << "Token not found" << endl;
            } else {
                cout << "Token has been deleted" << endl;
            }
        }
    }

    void display() {
        node* temp = head;
        if (temp == NULL) {
            cout << "NO list" << endl;
        } else {
            while(temp != NULL) {
                cout << temp->current.tokenname << "," << temp->current.value ;
                if(temp->next != NULL) cout << " -> ";
                temp = temp->next;
            }
        }
        cout << endl;
    }
};

int main() {

    //freopen("input.txt", "r", stdin);
    string s,p;
    linkedlist L[3];
    while (cin >> s >> p) {
        if(s == "DT") L[0].append(s,p);
        else if(s == "VAR") L[1].append(s,p);
        else if(s == "NUM") L[2].append(s,p);
    }
    L[0].display();
    L[1].display();
    L[2].display();

    return 0;
}
