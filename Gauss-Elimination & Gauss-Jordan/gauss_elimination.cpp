#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cout<<"Enter n :";
    cin>>n;

    cout<<"Enter your Augmented matrix : "<<endl;

    vector<vector<double>>a(n,vector<double>(n+1));

    for(int i=0;i<n;i++){
        for(int j=0;j<=n;j++){
            cin>>a[i][j];
        }
    }

    for(int i=0;i<n;i++){
        int row=i;

        for(int j=i+1;j<n;j++){
            if(fabs(a[j][i])>fabs(a[row][i]))
                row=j;
        }

        swap(a[i],a[row]);

        if(fabs(a[i][i])<1e-10)
            continue;

        for(int j=i+1;j<n;j++){
            double f=a[j][i]/a[i][i];

            for(int k=i;k<=n;k++)
                a[j][k]-=f*a[i][k];
        }
    }

    int ra=0,rab=0;

    for(int i=0;i<n;i++){
        bool zero=true;

        for(int j=0;j<n;j++){
            if(fabs(a[i][j])>1e-10){
                zero=false;
                break;
            }
        }

        if(!zero)
            ra++;

        if(!zero || fabs(a[i][n])>1e-10)
            rab++;
    }

    if(ra<rab){
        cout<<"No solution"<<endl;
        return 0;
    }

    if(ra<n){
        cout<<"Infinite solutions"<<endl;
        return 0;
    }

    cout<<"REF :"<<endl;

    for(int i=0;i<n;i++){
        for(int j=0;j<=n;j++)
            cout<<a[i][j]<<" ";
        cout<<endl;
    }

    vector<double>x(n);

    for(int i=n-1;i>=0;i--){
        x[i]=a[i][n];

        for(int j=i+1;j<n;j++)
            x[i]-=a[i][j]*x[j];

        x[i]/=a[i][i];
    }

    cout<<"Solution possible"<<endl;

    for(int i=0;i<n;i++)
        cout<<"x"<<i+1<<" = "<<x[i]<<endl;

    return 0;
}