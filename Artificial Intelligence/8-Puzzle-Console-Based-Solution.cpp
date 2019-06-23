#include <iostream>
#include <string>
#include <map>
#include <queue>
#include <sstream>
#include <vector>
#include <algorithm>
#include <cstdio>

using namespace std;

string initialState = "", finalState = "123456780";

queue < string > Q;
map < string, string > parent;
vector < string > childNodes;

void printResult(string intialState, string v) {
    vector < string > lst;

    while(parent[v]!=v) {
        lst.push_back(v);
        v = parent[v];
    }
    lst.push_back(intialState);
    reverse(lst.begin(), lst.end());
    string u;
    for(int i=0; i<lst.size(); i++) {
        u = lst[i];
        cout << "Step No: " << i << endl;
        for(int k=0; k<u.size(); k++) {
            if(k%3==0 && k!=0) cout << endl;
            cout << u[k] << " ";
        }
        cout << endl << endl;
    }

}

vector < string > findChilds(string s) {
    int indexOfZero;
    for(indexOfZero=0; indexOfZero < s.size(); indexOfZero++ ) {
        if(s[indexOfZero] == '0') {
            break;
        }
    }
    vector < string > lst;
    string v;
    if(indexOfZero == 0) {
        v = s;
        swap(v[0], v[1]);
        lst.push_back(v);
        v = s;
        swap(v[0], v[3]);
        lst.push_back(v);
    } else if(indexOfZero == 1) {
        v = s;
        swap(v[0], v[1]);
        lst.push_back(v);
        v = s;
        swap(v[1], v[2]);
        lst.push_back(v);
        v = s;
        swap(v[1], v[4]);
        lst.push_back(v);
    } else if(indexOfZero == 2) {
        v = s;
        swap(v[2], v[1]);
        lst.push_back(v);
        v = s;
        swap(v[5], v[2]);
        lst.push_back(v);
    } else if(indexOfZero == 3) {
        v = s;
        swap(v[0], v[3]);
        lst.push_back(v);
        v = s;
        swap(v[4], v[3]);
        lst.push_back(v);
        v = s;
        swap(v[6], v[3]);
        lst.push_back(v);
    } else if(indexOfZero == 4) {
        v = s;
        swap(v[1], v[4]);
        lst.push_back(v);

        v = s;
        swap(v[4], v[3]);
        lst.push_back(v);

        v = s;
        swap(v[5], v[4]);
        lst.push_back(v);

        v = s;
        swap(v[7], v[4]);
        lst.push_back(v);
    } else if(indexOfZero == 5) {
        v = s;
        swap(v[2], v[5]);
        lst.push_back(v);

        v = s;
        swap(v[4], v[5]);
        lst.push_back(v);

        v = s;
        swap(v[5], v[8]);
        lst.push_back(v);

    } else if(indexOfZero == 6) {
        v = s;
        swap(v[3], v[6]);
        lst.push_back(v);

        v = s;
        swap(v[7], v[6]);
        lst.push_back(v);
    } else if(indexOfZero == 7) {
        v = s;
        swap(v[7], v[4]);
        lst.push_back(v);

        v = s;
        swap(v[6], v[7]);
        lst.push_back(v);

        v = s;
        swap(v[8], v[7]);
        lst.push_back(v);
    } else if(indexOfZero == 8) {
        v = s;
        swap(v[5], v[8]);
        lst.push_back(v);

        v = s;
        swap(v[7], v[8]);
        lst.push_back(v);

    }

    return lst;
    }

void solvePuzzle(string initialState, string finalState) {

    Q.push(initialState);
    parent[initialState] = initialState;
    string u,v;
    while(!Q.empty()) {
        u = Q.front();
        Q.pop();
        if(u == finalState) {
            break;
        }
        childNodes = findChilds(u);
        for(int i=0; i<childNodes.size(); i++) {
            v = childNodes[i];
            if(parent.find(v) == parent.end()) {
                parent[v] = u;
                Q.push(v);

            }
        }
    }

    printResult(initialState, finalState);
}

int main() {

   // freopen("in.txt", "r", stdin);

	int x;

	for(int i=1; i<=9; i++) {
		cin >> x;
		initialState += (x+48);
	}

	solvePuzzle(initialState, finalState);

	return 0;
}
