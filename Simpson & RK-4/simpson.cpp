#include <bits/stdc++.h>
using namespace std;

double f(double x){
    return x*x+1;
}

int main(){
    double a,b,h,sum=0;
    int n;

    cin>>a>>b>>n;

    h=(b-a)/n;
    sum=f(a)+f(b);

    for(int i=1;i<n;i++){
        double x=a+i*h;

        if(i%2==0)
            sum+=2*f(x);
        else
            sum+=4*f(x);
    }
    cout<<"Integral = "<<(h/3)*sum<<endl;

    return 0;
}