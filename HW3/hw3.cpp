#include<iostream>
#include<cmath>
#include<limits>

using namespace std;

int arr[2][100];
int n;

double cal(int type, double x){ // Horner's rule
    double ans=0.0;
    for(int i=n;i>=0;i--){
        ans=(ans*x)+arr[type][i];
    }
    return ans;
}

double newton(double x){
    double x1 = 0.0;
    while(1){
        x1 = x - (cal(0,x) / cal(1,x));
        if(fabs(x1-x)<=0.0001) break;
        x = x1;
    }
    return x1;
}

// x^5 + x -1 = 0

int main(){
    cout << "please input the degree of eq: ";
    cin >> n;
    arr[1][n] = 0;
    for(int i = n;i >= 0 ;i--){
        cout << "Enter the cofficient of x^" << i << ":";
        cin >> arr[0][i];
        arr[1][i-1] = arr[0][i] * i;
    }

    double x = 0.0;
    cout << "Input the value of x";
    cin >> x;
    double root = newton(x);
    cout << "Roots is " << root << endl;
    return 0;
}