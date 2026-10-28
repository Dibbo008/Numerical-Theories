#include <bits/stdc++.h>
using namespace std;

double f(double x, double y){
    return x+y;
}

int main(){
    double x,y,h,xn;
    cin>>x>>y>>h>>xn;

    while(x<xn){
        double k1=h*f(x, y);
        double k2=h*f(x+h/2, y+k1/2);
        double k3=h*f(x+h/2, y+k2/2);
        double k4=h*f(x+h, y+k3);

        y=y+(k1+2*k2+2*k3+k4)/6;
        x=x+h;
    }
    cout<<"y = " <<y<<endl;

    return 0;
}