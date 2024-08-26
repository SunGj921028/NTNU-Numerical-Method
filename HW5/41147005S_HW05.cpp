#include<iostream>
#include<cmath>
#include<vector>

using namespace std;

int main(){
    int n = 3; // can be input
    // double a[4][5] = {{4.0,2.0,-1.0,3.0,16.9},{3.0,-4.0,2.0,5.0,-14.0},{-2.0,6.0,-5.0,-2.0,25.0},{5.0,1.0,6.0,-3.0,9.4}}; //equation
    // double a[4][4] = 
    // {{0,0,-1,1},
    //  {1,1,-1,2},
    //  {-1,-1,2,0},
    //  {1,2,0,2}}; //equation
    double a[3][3] = 
    {{2,4,1},
     {4,-10,2},
     {1,2,4},
    };
    vector<vector<double > > b(10, vector<double>(10,0));
    // swap
    vector<vector<double> > P(3, vector<double>(3, 0));

    for(int i = 0; i < 3; i++) {
        P[i][i] = 1;
    }

    for(int i = 0; i < 3; i++) {
        double MAX = __DBL_MIN__;// __DBL_MIN__
        int index = i;
        for(int j = i; j < 3; j++) {
            if(MAX < fabs(a[j][i])) { // row
                MAX = fabs(a[j][i]);
                index = j;
            }
        }
        for(int j = 0; j < 3; j++) {
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
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
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
    // cout << "x4 = " << ans[3] << endl;
    return 0;
}