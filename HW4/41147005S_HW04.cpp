#include<iostream>
#include<cmath>
#include<vector>

using namespace std;

// double **gaussian_change(double a[4][5]){
//     vector<vector<double> > P(4, vector<double>(5, 0));

//     for(int i = 0; i < 4; i++) {
//         P[i][i] = 1;
//     }

//     for(int i = 0; i < 4; i++) {
//         double MAX = __DBL_MIN__;
//         int index = i;
//         for(int j = i; j < 4; j++) {
//             if(MAX < abs(a[j][i])) {
//                 MAX = abs(a[j][i]);
//                 index = j;
//             }
//         }
//         for(int j = 0; j < 5; j++) {
//             swap(a[i][j], a[index][j]);
//             swap(P[i][j], P[index][j]);
//         }
//         // swap(b[i], b[index]);
//     }

//     cout << "A\n";
//     for(int i = 0;i<4;i++){
//         for(int j = 0;j<5;j++){
//             cout << a[i][j] << " ";
//         }
//         cout << endl;
//     }

//     cout<<"P:"<<endl;
//     for(int i = 0; i < 4; i++) {
//         for(int j = 0; j < 5; j++) {
//             cout<<P[i][j]<<" ";
//         }
//         cout<<endl;
//     }
    
//     return (double**)a;
// }

int main(){
    int n = 4; // can be input
    double a[4][5] = {{1.19,2.11,-100,1,1.12},{14.2,-0.122,12.2,-1,3.44},{0,100,-99.9,1,2.15},{15.3,0.11,-13.1,-1,4.16}}; //equation
    double b[10][10] = {{0}};

    // swap
    vector<vector<double> > P(4, vector<double>(5, 0));

    for(int i = 0; i < 4; i++) {
        P[i][i] = 1;
    }

    for(int i = 0; i < 4; i++) {
        double MAX = __DBL_MIN__;
        int index = i;
        for(int j = i; j < 4; j++) {
            if(MAX < abs(a[j][i])) {
                MAX = abs(a[j][i]);
                index = j;
            }
        }
        for(int j = 0; j < 5; j++) {
            swap(a[i][j], a[index][j]);
            swap(P[i][j], P[index][j]);
        }
        // swap(b[i], b[index]);
    }

    cout<<"P:"<<endl;
    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 5; j++) {
            cout<<P[i][j]<<" ";
        }
        cout<<endl;
    }
    // cout << "AC\n";
    // for(int i = 0;i<4;i++){
    //     for(int j = 0;j<5;j++){
    //         cout << a[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    vector<double > ans(n,0);
    for(int i = 0;i<n;i++){
        for(int j = i;j<n;j++){
            if(i==j){
                b[i][j] = 1;
                continue;
            }
            double t = a[j][i] / a[i][i];
            b[j][i] = t;
            for(int m = i;m <= n; m++){
                a[j][m] -= a[i][m] * t;
            }
        }
    }
    cout << "A\n";
    for(int i = 0;i<n;i++){
        cout << "[";
        for(int j=0;j<n + 1;j++){
            cout << a[i][j] << " ";
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
    cout << "Upper:\n";
    for(int i = 0;i<n;i++){
        cout << "[";
        for(int j=0;j<n;j++){
            cout << a[i][j] << " ";
        }
        cout << "]";
        cout << endl;
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