#include <bits/stdc++.h>
using namespace std;

double func(double x){
    return x*x+-4*x+1;
}

void bisec(double a,double b,double tol){
    double c;
    while(abs(b-a)>tol){
        c=(a+b)/2.0;
        if(abs(func(c))<tol){
            cout<<"Root : "<<c<<endl;
            return;
        }
        else if(func(a)*func(c)<0){
            b=c;
        }
        else{
            a=c;
        }
    }
    c=(a+b)/2.0;
    cout<<"Root : "<<c<<endl;
}

void falsep(double a,double b,double tol){
    double c;
    while(abs(b-a)>tol){
        c=(b*func(a)-a*func(b))/(func(a)-func(b));
        if(abs(func(c))<tol){
            cout<<"Root : "<<c<<endl;
            return;
        }
        else if(func(a)*func(c)<0){
            b=c;
        }
        else{
            a=c;
        }
    }
}

int main(){
    double tol=0.0001;
    cout<<"Coefficients are 1 and -4"<<endl;
    for(int i=-10;i<10;i++){
        double a=i;
        double b=i+01;
        if(abs(func(a))<tol){
            cout<<"Root : "<<a<<endl;
        }
        else if(func(a)*func(b)<0){
            cout<<"Bisection : "<<endl;
            bisec(a,b,tol);
            cout<<"False position : "<<endl;
            falsep(a,b,tol);
        }
    }
}