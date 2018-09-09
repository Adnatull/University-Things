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

private:
    token *head;

    token *newToken(string tokenname, string value) {
        token* temp = new token();
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
            cout << "The token " << tokenname << " and value " << value << " do not exist in the binary search tree." << endl;
            return;
        }
        else if (tree->value==value && tree->tokenname == tokenname) {
            cout << "The token " << tokenname << " and value " << value << " do exist in the binary search tree." << endl;
            return;
        }
        else searchToken (tree->next, tokenname, value);
        return ;
    }

    token* deleteToken(token *tree, string tokenname, string value) {
        if(tree==NULL) {
            cout << "The token " << tokenname << " and value " << value << " do not exist in the binary search tree." << endl;
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
        token* temp = head;
        int cnt = 0;
        while(temp!=NULL) {
            cout <<  temp->tokenname << "," << temp->value ;
            cnt++;
            if (temp->next != NULL) {
                cout << " => ";
            }
            temp = temp->next;
        }
        if(cnt)
            cout << endl;
        else {
            cout << "This list is empty" << endl;
        }
    }

    public:

        linkedList() {
            head = NULL;
        }

        void addTOKEN(string a, string b) {
            token *temp = head;
            head = addToken(temp, a, b);
        }

        void searchTOKEN (string tokenname, string value) {
            token *temp = head;
            searchToken (temp,tokenname, value);
        }

        void deleteTOKEN( string tokenname, string value) {
            token *temp = head;
            head = deleteToken(temp, tokenname, value);
        }

        void DISPLAY() {
            display();
        }
};

int main() {

    cout << "Insert 5 to input token 6 to delete, 7 to search, 8 to print to whole token list and any other key to exit" << endl;
    linkedList Table[5];
    string p, q;
    int n;
    while (cin >> n) {
        cin.ignore();
        if ( n== 5) {
            cout << "Input token and value to insert, give space between them " << endl;
            cin >> p >> q;
            if (p=="DT") Table[0].addTOKEN( p, q);
            else if (p == "VAR") Table[1].addTOKEN (p, q);
            else if (p == "NUM") Table[2].addTOKEN( p, q);
        } else if ( n == 6) {
            cout << "Input token and value to delete, give space between them" << endl;
            cin >> p >> q;
            if (p=="DT") Table[0].deleteTOKEN( p, q);
            else if (p == "VAR") Table[1].deleteTOKEN(p, q);
            else if (p == "NUM") Table[2].deleteTOKEN(p, q);
        } else if ( n == 7) {
            cout << "Input token and value to search, give space between them" << endl;
            cin >> p >> q;
            if (p=="DT") Table[0].searchTOKEN( p, q);
            else if (p == "VAR") Table[1].searchTOKEN(p, q);
            else if (p == "NUM") Table[2].searchTOKEN( p, q);
        } else if (n == 8) {
            for (int i=0; i<3; i++) {
                Table[i].DISPLAY();
            }
        } else {
            break;
        }
        cout << "Insert 5 to input token 6 to delete, 7 to search, 8 to print to whole token list and any other key to exit" << endl;
    }

    return 0;
}
