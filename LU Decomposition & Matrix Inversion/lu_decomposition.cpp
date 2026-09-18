#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<vector<double>>a(n,vector<double>(n));
    vector<vector<double>>l(n,vector<double>(n,0));
    vector<vector<double>>u(n,vector<double>(n,0));
    vector<double>b(n),y(n),x(n);

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>a[i][j];
        }
    }
    for(int i=0;i<n;i++){
        cin>>b[i];
    }
    bool possible=true;
    for(int i=0;i<n;i++){
        for(int k=i;k<n;k++){
            double sum=0;
            for(int j=0;j<i;j++){
                sum+=l[i][j]*u[j][k];
            }
            u[i][k]=a[i][k]-sum;
        }
        if(fabs(u[i][i])<1e-9){
            possible=false;
            break;
        }
        l[i][i]=1;
        for(int k=i+1;k<n;k++){
            double sum=0;
            for(int j=0;j<i;j++){
                sum+=l[k][j]*u[j][i];
            }
            l[k][i]=(a[k][i]-sum)/u[i][i];
        }
    }
    if(!possible){
        cout<<"Solution not possible"<<endl;
        return 0;
    }

    for(int i=0;i<n;i++){
        double sum=0;
        for(int j=0;j<i;j++){
                sum+=l[i][j]*y[j];
            }
            y[i]=b[i]-sum;
    }
    for(int i=n-1;i>=0;i--){
        double sum=0;
        for(int j=i+1;j<n;j++){
                sum+=u[i][j]*x[j];
            }
            x[i]=(y[i]-sum)/u[i][i];
    }

    cout<<"Possible solution :"<<endl;
    for(int i=0;i<n;i++){
        cout<<"x"<<i+1<<"="<<x[i]<<endl;
    }
}