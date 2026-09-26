#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cout<<"Enter number of data: ";
    cin>>n;

    double x[100],y[100],d[100][100];

    cout<<"Enter x values:\n";
    for(int i=0;i<n;i++)
        cin>>x[i];

    cout<<"Enter y values:\n";
    for(int i=0;i<n;i++)
        cin >> y[i];

    for(int i=0;i<n;i++)
        d[i][0]=y[i];

    for(int j=1;j<n;j++) {
        for(int i=1;i<n;i++) {
            d[i][j]=d[i][j-1]-d[i-1][j-1];
        }
    }
    cout<<"\nBackward Difference Table:\n";
    for(int i=0;i<n;i++) {
        cout<<x[i]<<" ";
        for(int j=0;j<=i;j++)
            cout<<d[i][j]<<" ";
        cout<<endl;
    }

    double value;
    cout<<"\nEnter x to find y: ";
    cin>>value;

    double h=x[1]-x[0];
    double u=(value-x[n-1])/h;

    double ans=d[n-1][0];
    double term=1;

    for(int i=1;i<n;i++) {
        term=term*(u+(i-1))/i;
        ans+=term*d[n-1][i];
    }

    cout<<"\nNewton Backward Interpolation Equation:\n";
    cout<<"y=";

    for(int i=0;i<n;i++){
        if(i==0)
            cout<<d[n-1][i];
        else
            cout<<"+("<<d[n-1][i]<<")*u(u+1)...";
    }

    cout<<"\n\nAt x="<<value<<", y="<<ans<<endl;

    return 0;
}