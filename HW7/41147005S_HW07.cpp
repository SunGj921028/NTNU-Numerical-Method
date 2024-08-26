#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

// Df(xk)s = -F(xk)
// Ax = b
// xk+1 = xk + s

/*
    Df(x) = [偏微變數1 偏微變數2 偏微變數3]
            [偏微變數1 偏微變數2 偏微變數3]
            [偏微變數1 偏微變數2 偏微變數3]...
    
*/

// to find s
// vector<double> gass(vector<vector<double> > a, vector<double> b) {
//     int n = a.size();
//     vector<double> ans(n, 0);
//     for(int i = 0; i < n; i++) {
//         for(int j = i + 1; j < n; j++) {
//             double times = a[j][i] / a[i][i];
//             for(int k = i; k < n; k++) {
//                 a[j][k] -= a[i][k] * times;
//             }
//             b[j] -= b[i] * times;
//         }
//     }

//     for(int i = n - 1; i >= 0; i--) {
//         for(int j = i + 1; j < n; j++) {
//             b[i] -= a[i][j] * ans[j];
//         }
//         ans[i] = b[i] / a[i][i];
//     }
//     return ans;
// }

vector<double> gass(vector<vector<double> > a, vector<double> b) {
    int n = a.size();
    vector<double> ans(n, 0);
    for(int i = 0; i < n; i++) {
        double MAX = __DBL_MIN__;// __DBL_MIN__
        int index = i;
        for(int j = i; j < n; j++) {
            if(MAX < fabs(a[j][i])) { // row
                MAX = fabs(a[j][i]);
                index = j;
            }
        }
        for(int j = 0; j < n; j++) {
            swap(a[i][j], a[index][j]);
        }
        swap(b[i], b[index]);
        for(int j = i + 1;j < n;j++){
            double t = a[j][i] / a[i][i];
            for(int m = i;m < n; m++){
                a[j][m] -= (a[i][m] * t);
            }
            b[j] -= b[i] * t;
        }
    }

    for(int i = n - 1;i>=0;i--){
        for(int j = i + 1;j<n;j++){
            b[i] -= a[i][j] * ans[j];
        }
        ans[i] = b[i] / a[i][i];
    }
    return ans;
}

int main(){
    int n = 3;
    double ans[3] = {0,2,2};

    vector<vector<double> > Df(3, vector<double>(3,0));
    vector<double> f(3);

    for(int i = 0;i < 10000;i++){
        for(int j = 0;j < n;j++){
            if(j==0){
                Df[j][0] = cos(ans[0]);
                Df[j][1] = 2 * ans[1];
                Df[j][2] = 1.0 / ans[2];
                f[j] = (-1) * (sin(ans[0]) + pow(ans[1],2) + log(ans[2]) - 7);
            }else if(j==1){
                Df[j][0] = 3 *(ans[0]);
                Df[j][1] = 2 * ans[1];
                Df[j][2] = (-3) * pow(ans[2],2);
                f[j] = (-1) * ((3 * ans[0]) + (2 * ans[1]) - (pow(ans[2],3)) + 1);
            }else{
                Df[j][0] = 1;
                Df[j][1] = 1;
                Df[j][2] = 1;
                f[j] = (-1) * ((ans[0]) + (ans[1]) + (ans[2]) - 5);
            }
        }
        vector<double> s;
        s = gass(Df,f);
        for(int i = 0;i<n;i++){
            ans[i] += s[i];
        }
    }

    for(int i = 0; i < n; i++) {
        // cout<<ans[i]<<endl;
        printf("%lf\n",ans[i]);
    }
    return 0;
}