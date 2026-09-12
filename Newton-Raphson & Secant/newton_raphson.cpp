#include<bits/stdc++.h>
using namespace std;

double f(const vector<double>&a,double x){
    double res=0;
    for(auto p:a){
        res=res*x+p;
    }
    return res;
}

double df(const vector<double>&a,double x){
    double res=0;
    int n=a.size()-1;
    for(int i=0;i<n;i++){
        res=res*x+a[i]*(n-i);
    }
    return res;
}

void newton(const vector<double>&a,double x0,double tol){
    for(int i=0;i<1000;i++){
        double f0=f(a,x0);
        double d=df(a,x0);
        if(abs(d)<1e-9){return;}
        double x1=x0-f0/d;
        if(abs(x1-x0)<tol || abs(f(a,x1))<tol){
            cout<<"Root : "<<x1<<endl;
            cout<<"Iteration : "<<i+1<<endl;
            return;
        }

        x0=x1;
    }
}

int main(){
    int n;
    cout<<"Enter coeffficient : ";
    cin>>n;

    vector<double>a(n+1);

    for(int i=0;i<=n;i++){
        cin>>a[i];
    }

    double mxv=0;

    for(int i=1;i<=n;i++){
        mxv=max(mxv,abs(a[i]/a[0]));
    }

    double high=1+mxv;
    double low=-high;

    cout<<"Range : "<<low<<" to "<<high<<endl;

    double step=0.45;
    double tol=0.001;
    double x0=low;
    double f0=f(a,x0);

    while(x0<high){
        double x1=min(x0+step,high);
        double f1=f(a,x1);

        if(abs(f0)<tol){
            cout<<"Root : "<<x0<<endl;
            cout<<"Iteration : 0"<<endl;
        }
        else if(f0*f1<0){
            newton(a,(x0+x1)/2,tol);
        }

        x0=x1;
        f0=f1;
    }
}