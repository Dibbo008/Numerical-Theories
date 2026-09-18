#include <bits/stdc++.h>
using namespace std;

void cofact(vector<vector<double>>&mat,vector<vector<double>>&temp,int p,int q,int n){
    int i=0,j=0;
    for(int row=0;row<n;row++){
        for(int col=0;col<n;col++){
            if(row!=p && col!=q){
                temp[i][j++]=mat[row][col];
                if(j==n-1){
                    j=0;
                    i++;
                }
            }
        }
    }
}

double deter(vector<vector<double>>&mat,int n){
     if(n==1)
        return mat[0][0];
    double det=0;
    int sign=1;
    vector<vector<double>>temp(n,vector<double>(n));
    for(int i=0;i<n;i++){
        cofact(mat,temp,0,i,n);
        det+=sign*mat[0][i]*deter(temp,n-1);
        sign=-sign;
    }
    return det;
}

vector<vector<double>>adj(vector<vector<double>>&mat){
    int n=mat.size();
    vector<vector<double>>adjj(n,vector<double>(n));
    vector<vector<double>>temp(n,vector<double>(n));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cofact(mat,temp,i,j,n);
            int sign=((i+j)%2==0)?1:-1;
            adjj[j][i]=sign*deter(temp,n-1);
        }
    }
    return adjj;
}

int main(){
    int n;
    cout<<"Enter n:";
    cin>>n;
    vector<vector<double>>mat(n,vector<double>(n));
    vector<double>b(n);

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>mat[i][j];
        }
    }
    for(int i=0;i<n;i++){
        cin>>b[i];
    }
    double det=deter(mat,n);

    if(fabs(det)<1e-9){
        cout<<"Not possible..."<<endl;
        return 0;
    }
    vector<vector<double>>adjm=adj(mat);
    vector<double>x(n,0);

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            x[i]+=adjm[j][i]*b[j]/det;
        }
    }
     cout<<"Possible..."<<endl;
     for(int i=0;i<n;i++){
         cout<<"x"<<i+1<<"="<<x[i]<<endl;
     }

}