#include <iostream>
#include <cstdio>
#include <stack>
#include <algorithm>
#include <string>
#include <cmath>
#include <iomanip>

using namespace std;

struct matrix {
    double  ax,ay,az,ak,
            bx,by,bz,bk,
            cx,cy,cz,ck,
            dx,dy,dz,dk;
};

class transformation {

private:
    stack < matrix > pile;
    int cnt  = 0;
    bool pushh = false;
    void multiply(matrix a, matrix b) {

        matrix init;
        init.ax = a.ax*b.ax+a.ay*b.bx+a.az*b.cx+a.ak*b.dx;
        init.ay = a.ax*b.ay+a.ay*b.by+a.az*b.cy+a.ak*b.dy;
        init.az = a.ax*b.az+a.ay*b.bz+a.az*b.cz+a.ak*b.dz;
        init.ak = a.ax*b.ak+a.ay*b.bk+a.az*b.ck+a.ak*b.dk;

        init.bx = a.bx*b.ax+a.by*b.bx+a.bz*b.cx+a.bk*b.dx;
        init.by = a.bx*b.ay+a.by*b.by+a.bz*b.cy+a.bk*b.dy;
        init.bz = a.bx*b.az+a.by*b.bz+a.bz*b.cz+a.bk*b.dz;
        init.bk = a.bx*b.ak+a.by*b.bk+a.bz*b.ck+a.bk*b.dk;

        init.cx = a.cx*b.ax+a.cy*b.bx+a.cz*b.cx+a.ck*b.dx;
        init.cy = a.cx*b.ay+a.cy*b.by+a.cz*b.cy+a.ck*b.dy;
        init.cz = a.cx*b.az+a.cy*b.bz+a.cz*b.cz+a.ck*b.dz;
        init.ck = a.cx*b.ak+a.cy*b.bk+a.cz*b.ck+a.ck*b.dk;

        init.dx = a.dx*b.ax+a.dy*b.bx+a.dz*b.cx+a.dk*b.dx;
        init.dy = a.dx*b.ay+a.dy*b.by+a.dz*b.cy+a.dk*b.dy;
        init.dz = a.dx*b.az+a.dy*b.bz+a.dz*b.cz+a.dk*b.dz;
        init.dk = a.dx*b.ak+a.dy*b.bk+a.dz*b.ck+a.dk*b.dk;
        pile.push(init);
    }

public:
    transformation(){

        matrix init;
        init.ax = 1;
        init.ay = 0;
        init.az = 0;
        init.ak = 0;

        init.bx = 0;
        init.by = 1;
        init.bz = 0;
        init.bk = 0;

        init.cx = 0;
        init.cy = 0;
        init.cz = 1;
        init.ck = 0;

        init.dx = 0;
        init.dy = 0;
        init.dz = 0;
        init.dk = 1;

        pile.push(init);
    }

    void scale(double x, double y, double z) {
        cnt++;
        matrix init;
        init.ax = x;
        init.ay = 0;
        init.az = 0;
        init.ak = 0;

        init.bx = 0;
        init.by = y;
        init.bz = 0;
        init.bk = 0;

        init.cx = 0;
        init.cy = 0;
        init.cz = z;
        init.ck = 0;

        init.dx = 0;
        init.dy = 0;
        init.dz = 0;
        init.dk = 1;

        matrix xx = pile.top();
        multiply(init, xx);
    }

    void translate(double x, double y, double z) {
        cnt++;
        matrix init;
        init.ax = 1;
        init.ay = 0;
        init.az = 0;
        init.ak = x;

        init.bx = 0;
        init.by = 1;
        init.bz = 0;
        init.bk = y;

        init.cx = 0;
        init.cy = 0;
        init.cz = 1;
        init.ck = z;

        init.dx = 0;
        init.dy = 0;
        init.dz = 0;
        init.dk = 1;

        matrix xx = pile.top();
        multiply(init, xx);
    }

    void rotation(double tita, double x, double y, double z) {
        cnt++;
        matrix init;
        init.ax = x*x*(1-cos(tita))+cos(tita);
        init.ay = y*x*(1-cos(tita))-z*sin(tita);
        init.az = x*z*(1-cos(tita))+y*sin(tita);
        init.ak = 0;

        init.bx = y*x*(1-cos(tita))+z*sin(tita);
        init.by = y*y*(1-cos(tita))+cos(tita);
        init.bz = y*z*(1-cos(tita))-x*sin(tita);
        init.bk = 0;

        init.cx = z*x*(1-cos(tita))-y*sin(tita);
        init.cy = z*y*(1-cos(tita))+x*sin(tita);
        init.cz = z*z*(1-cos(tita))+cos(tita);
        init.ck = 0;

        init.dx = 0;
        init.dy = 0;
        init.dz = 0;
        init.dk = 1;

        matrix xx = pile.top();
        multiply(init, xx);
    }

    void triangle() {
        cnt++;

        double ax,ay,az,bx,by,bz,cx,cy,cz;
        cin >> ax >> ay >> az >> bx >> by >> bz >> cx >> cy >> cz;

        matrix init;
        init.ax = ax;
        init.ay = ay;
        init.az = az;
        init.ak = 0;

        init.bx = bx;
        init.by = by;
        init.bz = bz;
        init.bk = 0;

        init.cx = cx;
        init.cy = cy;
        init.cz = cz;
        init.ck = 0;

        init.dx = 0;
        init.dy = 0;
        init.dz = 0;
        init.dk = 1;

        matrix xx = pile.top();
        multiply(init, xx);
        xx = pile.top();
        cout << fixed << setprecision(7) ;
        cout << xx.ax << " ";
        cout << xx.ay << " ";
        cout << xx.az << endl;
        cout << xx.bx << " ";
        cout << xx.by << " ";
        cout << xx.bz << endl;
        cout << xx.cx << " ";
        cout << xx.cy << " ";
        cout << xx.cz << endl;
    }

    void togglePush() {
        if ( pushh = false) {
            pushh = true;
            cnt = 0;
        } else {
            pushh = false;
        }
    }
    void startPop() {
        while(cnt != 0) {
            pile.pop();
        }
    }

};


int main() {

    freopen ("in.txt", "r", stdin);

    transformation assignment;

    string s;
    getline(cin, s);
    getline(cin, s);
    getline(cin, s);
    getline(cin, s);
    while (getline(cin, s)) {
        double x, y, z;
        if (s == "scale") {
            cin >> x >> y >> z;
            assignment.scale(x,y,z);
        } else if (s == "translate") {
            cin >> x >> y >> z;
            assignment.translate(x,y,z);
        } else if (s == "rotate") {
            double zz;
            cin >> x >> y >> z >> zz;
            assignment.rotation(x, y, z, zz);
        } else if (s == "triangle") {
            assignment.triangle();

        } else if (s == "push") {
            assignment.togglePush();
        } else if (s == "pop") {
            assignment.startPop();
        } else if (s == "end") {
            break;
        }
    }



}
