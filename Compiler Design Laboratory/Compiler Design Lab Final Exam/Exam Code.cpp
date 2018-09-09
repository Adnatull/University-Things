#include <iostream>
#include <cstdio>
#include <algorithm>
#include <sstream>
#include <map>

using namespace std;

struct token {
    string tokenname;
    string value;
    int line;
    int cnt;
    token *next;
};

class linkedList {

private:
    token *head;
    map<string, int> cnt;

    token *newToken(string tokenname, string value, int line) {
        cnt[value]++;
        token* temp = new token();
        temp->tokenname = tokenname;
        temp->value = value;
        temp->line = line;
        temp->cnt = cnt[value];
        temp->next = NULL;

        return temp;
    }

    token* addToken (token *tree, string tokenname, string value, int line) {
        if(tree==NULL) return tree = newToken(tokenname, value, line);
        else  tree->next = addToken(tree->next, tokenname, value, line);
        return tree;
    }

    void display() {
        token* temp = head;

        if (temp!=NULL) cout << temp->tokenname << " -> ";
        while(temp!=NULL) {
            cout << temp->value << "(" << temp->line << "," << temp->cnt << ")";
            if (temp->next != NULL) {
                cout << " -> ";
            }
            temp = temp->next;
        }
        cout << endl;
    }

    public:

        linkedList() {
            head = NULL;
        }

        void addTOKEN(string a, string b, int c) {
            token *temp = head;
            head = addToken(temp, a, b, c);
        }

        void DISPLAY() {
            display();
        }
};

int main() {


    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    string a, b;
    int c;
    linkedList Table[7];
    while (cin >> a >> b >> c) {
        if (a == "DT") Table[0].addTOKEN(a,b,c);
         else if (a == "VAR") Table[1].addTOKEN(a,b,c);
         else if (a == "KWRD") Table[2].addTOKEN(a,b,c);
         else if (a == "OP") Table[3].addTOKEN(a,b,c);
         else if (a == "NOT") Table[4].addTOKEN(a,b,c);
         else if (a == "NUM") Table[5].addTOKEN(a,b,c);
         else if (a == "RELOP") Table[6].addTOKEN(a,b,c);
    }
    for (int i=0; i<7; i++) Table[i].DISPLAY();

    return 0;
}
