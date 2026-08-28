#include <bits/stdc++.h>
using namespace std;

double func(double x){
    return x*x*x*x-10*x*x+9;
}

double deriv(double x){
    return 4*x*x*x-20*x;
}

double newton(double x){

    for(int i=0;i<100;i++){

        double x1=x-func(x)/deriv(x);

        if(abs(x1-x)<0.0001){
            return x1;
        }

        x=x1;
    }
}

double secant(double a,double b){

    for(int i=0;i<100;i++){

        double c=(b*func(a)-a*func(b))/(func(a)-func(b));

        if(abs(c-b)<0.0001){
            return c;
        }

        a=b;
        b=c;
    }
}

int main(){

    vector<double> newtonRoots;
    vector<double> secantRoots;

    cout<<"Newton Raphson Method : "<<endl;

    for(double x=-10;x<=10;x+=0.1){

        double root=newton(x);
        bool found=false;

        for(double r:newtonRoots){

            if(abs(r-root)<0.001){
                found=true;
            }
        }

        if(found==false){
            newtonRoots.push_back(root);
        }
    }

    for(double root:newtonRoots){
        cout<<"Root : "<<root<<endl;
    }


    cout<<"\nSecant Method : "<<endl;

    for(double a=-10;a<10;a+=0.1){

        double root=secant(a,a+0.1);
        bool found=false;

        for(double r:secantRoots){

            if(abs(r-root)<0.001){
                found=true;
            }
        }

        if(found==false){
            secantRoots.push_back(root);
        }
    }

    for(double root:secantRoots){
        cout<<"Root : "<<root<<endl;
    }

    return 0;
}