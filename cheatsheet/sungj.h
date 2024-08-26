#pragma once

#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

int a[100];
int arr[2][100]; // 儲存原polynomial, 和一次微分後的polynomial
int n; // Max degree

double val(double x){
    return (x - cbrt(x) - 2);
}

double fval(double x, int n){ // Using Horner's
    double ans=0.0;
    for(int i=n;i>=0;i--){
        ans=(ans*x)+a[i];
    }
    return ans;
}
// 計算原方程和微分後方程的值
double cal(int type, double x){ // Horner's rule
    double ans=0.0;
    for(int i=n;i>=0;i--){
        ans=(ans*x)+arr[type][i];
    }
    return ans;
}

// bisection
double bisection(double lr, double rr){
    double mid;
    double mval;
    double lval;
    while((rr - lr) > 1e-6){
        //printf("A\n");
        mid = (lr + rr) / 2.0;
        lval = val(lr);
        mval = val(mid);

        if((lval * mval) < 0){
            rr = mid;
        }else{
            lr = mid;
        }
    }
    return mid;
    /*
    double l = 1, r = 2;
    while(r - l > 1e-7 && l < r) {
        double mid =  l + (r - l) / 2.0;
        double cur = func(mid);
        if(cur > 0) {
            r = mid;
        }
        else {
            l = mid;
        }
    }
    cout<<l<<endl;
    */
}

// fixed point iteration
/*
    f(x) = 0 -> x = g(x)
    S = |g`(r)| < 1
*/
double fixed_point(double x){
    double a = 0.0;
    double b = 0.0;
    a = cbrt((2 * x) + 2);
    while(abs(a-b) > 1e-6){
        b = a;
        a = cbrt((2 * a) + 2);
    }
    return a;
}

// Algorithm: Newton’s iteration
/*
    x1 = x0 - ( f(x)/f`(x) )
*/
double newton(double x){
    double x1 = 0.0;
    while(1){
        x1 = x - (cal(0,x) / cal(1,x));
        if(fabs(x1-x)<=0.0001) break;
        x = x1;
    }
    return x1;
}

// secant method
/*
                           (x1 - x2) 
    x2 = x1 - f(x1) * ( ----------------- )
                         f(x1) - f(x2)
*/
double cal1 (double x) {
    return (pow(x, 5.0) + x - 1);
}
double cal2 (double x) {
    return (log(x) + x * x - 3);
}
double cal3 (double x) {
    return (sin(x) - 6 * x - 5);
}

double secant(double a, double b){
    while(abs(a - b) > 0.000001) {
        b = a - (cal1(a) * (a - b)) / (cal1(a) - cal1(b));
        double temp = b;
        b = a;
        a = temp;
        // swap(b, a);
    }
    return a;
}

double fval(double x, int n);
double bisection(double lr, double rr);
double fixed_point(double x);
double newton(double x);
double secant(double a, double b);

// Gaussian method
double gaussian(int n, double **a, double **b);
/*
int main(){
    int n = 4; // can be input
    double a[4][5] = {{4.0,2.0,-1.0,3.0,16.9},{3.0,-4.0,2.0,5.0,-14.0},{-2.0,6.0,-5.0,-2.0,25.0},{5.0,1.0,6.0,-3.0,9.4}}; //equation
    vector<vector<double > > b(10, vector<double>(10,0));
    // swap
    vector<vector<double> > P(4, vector<double>(5, 0));

    for(int i = 0; i < 4; i++) {
        P[i][i] = 1;
    }

    for(int i = 0; i < 4; i++) {
        double MAX = __DBL_MIN__;// __DBL_MIN__
        int index = i;
        for(int j = i; j < 4; j++) {
            if(MAX < fabs(a[j][i])) { // row
                MAX = fabs(a[j][i]);
                index = j;
            }
        }
        for(int j = 0; j < 5; j++) {
            swap(a[i][j], a[index][j]);
            swap(P[i][j], P[index][j]);
            swap(b[i][j], b[index][j]);
        }
        // swap(b[i], b[index]);
        for(int j = i;j < n;j++){
            if(i==j){
                b[i][j] = 1;
                continue;
            }
            double t = a[j][i] / a[i][i];
            b[j][i] = t;
            for(int m = i;m <= n; m++){
                a[j][m] -= (a[i][m] * t);
            }
        }
    }

    cout<<"P:"<<endl;
    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 4; j++) {
            cout<<P[i][j]<<" ";
        }
        cout<<endl;
    }

    vector<double > ans(n,0);
    cout << "Upper:\n";
    for(int i = 0;i<n;i++){
        cout << "[";
        for(int j=0;j<n;j++){
            // cout << a[i][j] << " ";
            printf("%lf ",a[i][j]);
        }
        cout << "]";
        cout << endl;
    }
    printf("--------------------\n");
    for(int i = n - 1;i>=0;i--){
        for(int j = i + 1;j<n;j++){
            a[i][n] -= a[i][j] * ans[j];
        }
        ans[i] = a[i][n] / a[i][i];
    }
    cout << "Lower:\n";
    for(int i = 0;i<n;i++){
        cout << "[";
        for(int j = 0;j<n;j++){
            cout << b[i][j] << " ";
        }
        cout << "]";
        cout << endl;
    }
    cout << "ans:\n";
    cout << "x1 = " << ans[0] << endl;
    cout << "x2 = " << ans[1] << endl;
    cout << "x3 = " << ans[2] << endl;
    cout << "x4 = " << ans[3] << endl;
    return 0;
}
*/