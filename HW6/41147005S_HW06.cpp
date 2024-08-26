#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

// strictly diagonally dominant -> |Aii| > sum(|Aij (j!=i)|)
bool check(vector<vector<double>> A, int n){
    for(int i = 0; i < n;i++){
        double dia_num = A[i][i];
        double sum_other = 0.0;
        for(int j = 0;j<n;j++){
            if(j!=i){
                sum_other += fabs(A[i][j]);
            }
        }
        if(fabs(dia_num) < sum_other){
            return false;
        }
    }
    return true;
}

/*
    Ax = b;
    (L+D+U)x = b;
    Dx = b - (L+U)x;
    xk+1 = D^-1(b - (L+U)xk); for k = 0,1,2...
*/

vector<vector<double> > matrix_add(vector<vector<double> > &a, vector<vector<double> > &b) {
    vector<vector<double> > ans(a.size(), vector<double>(a.front().size(), 0));
    for(int i = 0; i < a.size(); i++) {
        for(int j = 0; j < a.front().size(); j++) {
            ans[i][j] = a[i][j] + b[i][j];
        }
    }
    return ans;
}

vector<vector<double> > matrix_min(vector<vector<double> > &a, vector<vector<double> > &b) {
    vector<vector<double> > ans(a.size(), vector<double>(a.front().size(), 0));
    for(int i = 0; i < a.size(); i++) {
        for(int j = 0; j < a.front().size(); j++) {
            ans[i][j] = a[i][j] - b[i][j];
        }
    }
    return ans;
}

vector<vector<double> > matrix_mul(vector<vector<double> > &a, vector<vector<double> > &b) {
    vector<vector<double> > ans(a.size(), vector<double>(a.front().size(), 0));
    for(int i = 0; i < a.size(); i++) {
        for(int j = 0; j < b.size(); j++) {
            for(int k = 0; k < a.front().size(); k++) {
                ans[i][j] += (a[i][k] * b[k][j]);
            }
        }
    }
    return ans;
}

int main(){
    int n = 0;
    // cin >> n;
    n = 6;
    
    vector<vector<double >> U(n, vector<double>(n,0));
    vector<vector<double >> L(n, vector<double>(n,0));
    vector<vector<double >> b(n, vector<double>(1,0));
    vector<vector<double >> D(n, vector<double>(n,0));

    for(int i = 0;i<n;i++){
        D[i][i] = 1.0/3;
    }
    for(int i = 0; i < n-1; i++) {
        U[i][i + 1] = -1.0;
    }
    U[0][n-1] = 0.5;
    U[1][n-2] = 0.5;
    for(int i = 1; i < n; i++) {
        L[i][i - 1] = -1.0;
    }
    L[n-1][0] = 0.5;
    L[n-2][1] = 0.5;
    b[0][0] = 2.5;
    b[1][0] = 1.5;
    b[2][0] = 1.0;
    b[3][0] = 1.0;
    b[4][0] = 1.5;
    b[5][0] = 2.5;
    vector<vector<double> > X(n, vector<double>(1, 0));
    for(int i = 0;i<1500;i++){
        vector<vector<double> > UL_plus = matrix_add(U, L);
        vector<vector<double> > UL_mult_X = matrix_mul(UL_plus,X);
        vector<vector<double> > b_sub_ULX = matrix_min(b,UL_mult_X);
        X = matrix_mul(D,b_sub_ULX);
        // for(int i = 0;i<n;i++){
        //     cout << "u" << i + 1 << "= " << X[i][0] << endl;
        // }
    }
    for(int i = 0;i<n;i++){
        printf("u%d = %lf\n",i+1,X[i][0]);
    }
}