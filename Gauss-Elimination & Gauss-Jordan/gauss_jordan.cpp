#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cout<<"Enter n : ";
    cin>>n;

    cout<<"Enter your Augmented matrix : "<<endl;

    vector<vector<double>>a(n,vector<double>(n+1));

    for(int i=0;i<n;i++)
        for(int j=0;j<=n;j++)
            cin>>a[i][j];

    for(int i=0;i<n;i++){
        int row=i;

        for(int j=i+1;j<n;j++){
            if(fabs(a[j][i])>fabs(a[row][i]))
                row=j;
        }

        swap(a[i],a[row]);

        if(fabs(a[i][i])<1e-10)
            continue;

        double div=a[i][i];

        for(int j=0;j<=n;j++)
            a[i][j]/=div;

        for(int j=0;j<n;j++){
            if(j==i)
                continue;

            double f=a[j][i];

            for(int k=0;k<=n;k++)
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

        if(!zero)
            rab++;
        else if(fabs(a[i][n])>1e-10)
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

    cout<<"RREF :"<<endl;

    for(int i=0;i<n;i++){
        for(int j=0;j<=n;j++)
            cout<<a[i][j]<<" ";
        cout<<endl;
    }

    cout<<"Solution possible"<<endl;

    for(int i=0;i<n;i++)
        cout<<"x"<<i+1<<" = "<<a[i][n]<<endl;

    return 0;
}