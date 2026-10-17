#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;

    double x[n],y[n];

    for(int i=0;i<n;i++)
        cin>>x[i]>>y[i];

    //LINEAR MODE
    // y=a+bx

    double sx=0,sy=0,sx2=0,sxy=0;
    for(int i=0;i<n;i++){
        sx+=x[i];
        sy+=y[i];
        sx2+=x[i]*x[i];
        sxy+=x[i]*y[i];
    }

    double b=(n*sxy-sx*sy)/(n*sx2-sx*sx);
    double a=(sy-b*sx)/n;

    cout<<fixed<<setprecision(6);

    cout<<"\nLinear Model:\n";
    cout<<"a = "<<a<<endl;
    cout<<"b = "<<b<<endl;
    cout<<"Equation: y = "<<a<<" + "<<b<<"x"<<endl;


    //POWER MODEL
    //y=p*e^q

    double sxlog=0,sylog=0,sxlog2=0,sxlogsylog=0;

    for(int i=0;i<n;i++){
        double X=log(x[i]);
        double Y=log(y[i]);

        sxlog+=X;
        sylog+=Y;
        sxlog2+=X*X;
        sxlogsylog+=X*Y;
    }

    double q=(n*sxlogsylog-sxlog*sylog)/(n*sxlog2-sxlog*sxlog);
    double lnp=(sylog-q*sxlog)/n;
    double p=exp(lnp);

    cout<<"\nPower Model:\n";
    cout<<"p = "<<p<<endl;
    cout<<"q = "<<q<<endl;
    cout<<"Equation: y = "<<p<<" * e^"<<q<<endl;


    //POLYNOMIAL MODEL
    // y=A+Bx+Cx^2

    double s[5]={0};
    double ssxy=0;
    double sx2y=0;

    for(int i=0;i<n;i++){
        double temp=1;

        for(int j=0;j<=4;j++){
            s[j]+=temp;
            temp*=x[i];
        }
        ssxy+=x[i]*y[i];
        sx2y+=x[i]*x[i]*y[i];
    }

    double A[3][4]={
        {s[0],s[1],s[2],sy},
        {s[1],s[2],s[3],ssxy},
        {s[2],s[3],s[4],sx2y}
    };

    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(i!=j){
                double r=A[j][i]/A[i][i];

                for(int k=0;k<4;k++)
                    A[j][k]-=r*A[i][k];
            }
        }
    }

    double A0=A[0][3]/A[0][0];
    double B=A[1][3]/A[1][1];
    double C=A[2][3]/A[2][2];

    cout<<"\nPolynomial Model:\n";
    cout<<"A = "<<A0<<endl;
    cout<<"B = "<<B<<endl;
    cout<<"C = "<<C<<endl;
    cout<<"Equation: y = "<<A0<<" + "<<B<<"x + "<<C<<"x^2"<<endl;


    //ESTIMATION

    double x0=6;

    double yLinear=a+b*x0;
    double yPower=p*pow(x0,q);
    double yPolynomial=A0+B*x0+C*x0*x0;

    cout<<"\nEstimation at x = 6:\n";

    cout<<"Linear model:     y = "<<yLinear<<endl;
    cout<<"Power model:      y = "<<yPower<<endl;
    cout<<"Polynomial model: y = "<<yPolynomial<<endl;

    return 0;
}