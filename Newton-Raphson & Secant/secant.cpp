#include<bits/stdc++.h>
using namespace std;

double f(const vector<double>&a,double x){
    double res=0;
    for(auto p:a){
        res=res*x+p;
    }
    return res;
}

void sec(const vector<double>&a,double x0,double x1,double tol){
    for(int i=1;i<1000;i++){
        double f0=f(a,x0);
        double f1=f(a,x1);
        if(abs(f1-f0)<1e-9){return;}
        double x2=x1-f1*(x1-x0)/(f1-f0);
        if(abs(x1-x0)<tol || abs(f(a,x2))<tol){
        cout<<"Bracket : "<<x0<<" to "<<x1<<endl;
        cout<<"Root : "<<x2<<endl;
        cout<<"Iteration : "<<i<<endl;
        return;
        }
        x0=x1;
        x1=x2;
    }
}

int main(){
   int n;
   cout<<"Coefficient : ";
   cin>>n;
   vector<double>a(n+1);
   for(int i=0;i<=n;i++){
    cin>>a[i];
   }
   double mxv=0;
   for(int i=1;i<=n;i++){
    mxv=max(mxv,abs(a[i]/a[0]));
   }
   double high=mxv+1;
   double low=-high;
   cout<<"Range : "<<low<<"-"<<high<<endl;
   double step=0.45;
   double tol=0.0001;
   double x0=low;
   double f0=f(a,x0);
   while(x0<high){
    double x1=min(x0+step,high);
    double f1=f(a,x1);
    if(abs(f0)<tol){
        cout<<"Bracket : "<<x0<<" to "<<x0<<endl;
        cout<<"Root : "<<x0<<endl;
        cout<<"Iteration : 0 "<<endl;
    }
    if(f0*f1<0){
        sec(a,x0,x1,tol);
    }
    x0=x1;
    f0=f1;
   }
    return 0;
}