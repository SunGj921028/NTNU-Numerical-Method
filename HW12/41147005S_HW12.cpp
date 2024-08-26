#include<iostream>
#include<vector>
#include<cmath>
#include<iomanip>

using namespace std;

vector<vector<double> > transpose(vector<vector<double>> A) {
    vector<vector<double> > out(A.front().size(), vector<double>(A.size(), 0.0));
    for(int i = 0; i < A.front().size(); i++) {
        for(int j = 0; j < A.size(); j++) {
            out[i][j] = A[j][i];
        }
    }
    return out;
}

vector<vector<double> > mul_matrix(vector<vector<double> > &a, vector<vector<double> > &b) {
    vector<vector<double> > ans(a.size(), vector<double>(b.front().size(), 0));
    for(int i = 0; i < a.size(); i++) {
        for(int j = 0; j < b.size(); j++) {
            for(int k = 0; k < a.front().size(); k++) {
                ans[i][j] += (a[i][k] * b[k][j]);
            }
        }
    }
    return ans;
}

// result is a vector
vector<double> mul_vector(vector<vector<double> > &a, vector<double> &b) {
    vector<double> ans(a.size(), 0);
    for(int i = 0; i < a.size(); i++) {
        for(int j = 0; j < a.front().size(); j++) {
            ans[i] += a[i][j] * b[j];
        }
    }
    return ans;
}

vector<double> gass(vector<vector<double> > &a, vector<double> &b){
    int n = a.size();
    vector<double> ans(n, 0);
    vector<vector<double> > B(n, vector<double>(n , 0));
    vector<vector<double> > P(n, vector<double>(n , 0));

    for(int i = 0; i < n; i++) {
        P[i][i] = 1;
    }

    for(int i = 0 ; i < n ;i++){
        double MAX = __DBL_MIN__;
        int index = i;
        for(int j = i; j < n; j++) {
            if(MAX < abs(a[j][i])) {
                MAX = abs(a[j][i]);
                index = j;
            }
        }

        for(int j = 0; j < n; j++) {
            swap(a[i][j], a[index][j]);
            swap(P[i][j], P[index][j]);
            swap(B[i][j], B[index][j]);
        }
        swap(b[i], b[index]);

        for(int j = i;j < n;j++){
            if(i==j){
                B[i][j] = 1;
                continue;
            }
            double t = a[j][i] / a[i][i];
            B[j][i] = t;
            for(int m = i;m < n; m++){
                a[j][m] -= a[i][m] * t;
            }
            b[j] -= b[i] * t;
        }
    }

    // calculate the answer
    for(int i = n - 1;i>=0;i--){
        for(int j = i + 1;j<n;j++){
            // a[i][n] -> b[i]
            b[i] -= a[i][j] * ans[j];
        }
        // no solution
        if(a[i][i] == 0) {
            cout << "No solution" << endl;
            exit(0);
        }
        ans[i] = b[i] / a[i][i];
    }
    return ans;
}

void show_matrix(vector<vector<double> > A) {
    for(int i = 0; i < A.size(); i++) {
        for(int j = 0; j < A.front().size(); j++) {
            // cout << setw(10) << to_string(A[i][j]) << " ";
            printf("%10.4f ", A[i][j]);
        }
        cout << endl;
    }
    return;
}

int main(){
    // matrix A -> m * n
    int m = 0;
    int n = 0;
    // cin >> m >> n;
    // vector<vector<double> > A(m, vector<double>(n, 0));
    vector<vector<double> > A{
        {0.0,1.0},
        {1.0,1.0},
        {0.0,-1.0},
    };
    m = A.size();
    n = A.front().size();
    
    vector<vector<double>> Dr(m, vector<double>(n, 0));
    vector<double > r = {1,1,1};
    // the size of ans if n * 1
    vector<double> ans = {0, 0};
    for(int t = 0; t < 1000; t++){
        vector<double> rx(m, 0);
        for(int i = 0;i < m ; i++){
            Dr[i][0] = (ans[0] - A[i][0]) / sqrt( pow(ans[0] - A[i][0], 2) + pow(ans[1] - A[i][1], 2) );
            Dr[i][1] = (ans[1] - A[i][1]) / sqrt( pow(ans[0] - A[i][0], 2) + pow(ans[1] - A[i][1], 2) );
            // Dr[i][2] = -1;
            // rx[i] = (-1) * (sqrt( pow(ans[0] - A[i][0], 2) + pow(ans[1] - A[i][1], 2) ) - (A[i][2] + ans[2]));
            rx[i] = (-1) * (sqrt( pow(ans[0] - A[i][0], 2) + pow(ans[1] - A[i][1], 2) ) - r[i]);
        }
        vector<vector<double> > DrT = transpose(Dr);
        vector<vector<double> > DrT_Dr = mul_matrix(DrT, Dr);
        vector<double> DrT_rx = mul_vector(DrT, rx);
        vector<double> v = gass(DrT_Dr, DrT_rx);
        for(int i = 0; i < n; i++) {
            ans[i] += v[i];
        }
    }

    cout << "ans:\n";
    for(int i = 0; i < ans.size(); i++) {
        // cout << ans[i] << " ";
        if(i == 0){printf("x = ");}
        else{ printf("y = ");}
        printf("%2.4f\n", ans[i]);
    }
    return 0;
}
