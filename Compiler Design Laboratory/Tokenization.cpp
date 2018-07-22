#include <iostream>
#include <cstdio>
#include <algorithm>
#include <sstream>

using namespace std;

struct token {
    string tokenname;
    string value;
    token *next;
};

class linkedList {

public:

    token *head = NULL;

    token *newToken(string tokenname, string value) {
        token *temp = (token*) malloc(sizeof(token));
        temp->tokenname = tokenname;
        temp->value = value;
        temp->next = NULL;
        return temp;
    }

    token* addToken (token *tree, string tokenname, string value) {
        if(tree==NULL) return tree = newToken(tokenname, value);
        else  tree->next = addToken(tree->next, tokenname, value);
        return tree;
    }

    void searchToken (token *tree, string tokenname, string value) {
        if(tree==NULL) {
            cout << "The token " << tokenname << " and value " << value << "do not exist in the binary search tree." << endl;
            return;
        }
        else if (tree->value==value && tree->tokenname == tokenname) {
            cout << "The token " << tokenname << " and value " << value << "do exist in the binary search tree." << endl;
            return;
        }
        else searchToken (tree->next, tokenname, value);
        return ;
    }

    token* deleteToken(token *tree, string tokenname, string value) {
        if(tree==NULL) {
            cout << "The token " << tokenname << " and value " << value << "do not exist in the binary search tree." << endl;
        }
        else if (tree->value==value && tree->tokenname == tokenname) {
            if(tree->next==NULL) {
                free(tree);
                return NULL;
            }
            else {
                token *temp = tree->next;
                return temp;
            }
        }
        else tree->next = deleteToken(tree->next, tokenname, value);
        return tree;
    }

    void display() {
        cout << "Aschi ami ekhane" << endl;
        token *temp = head;

        while(temp!=NULL) {
            cout <<  temp->tokenname << "," << temp->value << " => ";
            temp = temp->next;
        }

    }
};

int main() {
    freopen ("input.txt", "r", stdin);
    string s;
    linkedList Table[3];
    while (getline(cin, s)) {
        for (int i=0; i<s.size(); i++) {
            if (s[i]==',') s[i] = 32;
        }
        stringstream ss(s);
        string p,q;
        ss >> p;
        //cout << p << endl;
        ss >> q;
        //cout << q << endl;

        if (p=="DT") Table[0].addToken(Table[0].head, p, q);
        else if (p == "VAR") Table[1].addToken(Table[1].head, p, q);
        else if (p == "NUM") Table[2].addToken(Table[2].head, p, q);
       // cout << "HELLO" << endl;
    }
   // Table[0].display();

}
