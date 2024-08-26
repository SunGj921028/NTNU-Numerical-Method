#include<stdio.h>
#include<stdlib.h>

double **matrix_add(double (*a)[10], double (*b)[10], int n){
    double **ans = (double **)calloc(n,sizeof(double*));
    for(int i = 0; i < n; i++){
        ans[i] = (double*)calloc(n,sizeof(double));
    }
    for(int i = 0; i<n;i++){
        for(int j = 0;j<n;j++){
            ans[i][j] = 0;
        }
    }

    printf("%lf\n",a[0][0]);
    for(int i = 0;i<n;i++){
        for(int j = 0;j<n;j++){
            ans[i][j] = (a[i][j] + b[i][j]);
        }
    }

    return ans;
}

double **matrix_sub(double **a, double **b, int n){
    double **ans = (double **)calloc(n,sizeof(double*));
    for(int i = 0; i < n; i++){
        ans[i] = (double*)calloc(n,sizeof(double));
    }
    for(int i = 0; i<n;i++){
        for(int j = 0;j<n;j++){
            ans[i][j] = 0;
        }
    }

    for(int i = 0;i<n;i++){
        for(int j = 0;j<n;j++){
            ans[i][j] = (a[i][j] - b[i][j]);
        }
    }

    return ans;
}

double **matrix_mul(double **a, double **b, int n, int b_size){
    double **ans = (double **)calloc(n,sizeof(double*));
    for(int i = 0; i < n; i++){
        ans[i] = (double*)calloc(n,sizeof(double));
    }
    for(int i = 0; i<n;i++){
        for(int j = 0;j<n;j++){
            ans[i][j] = 0;
        }
    }

    for(int i = 0;i<n;i++){
        for(int j = 0; j<b_size;j++){
            for(int m = 0;m<n;m++){
                ans[i][j] += (a[i][m] * b[m][j]);
            }
        }
    }
    return ans;
}

int main(){
    int n = 10;
    double U[10][10] = {{0}};
    double D[10][10] = {{0}};
    double L[10][10] = {{0}};
    double b[10][1] = {{0}};

    for(int i = 0; i < 10; i++) {
        D[i][i] = -1.0 / 4.0;
    }
    for(int i = 0; i < 9; i++) {
        U[i][i + 1] = 2;
    }
    for(int i = 1; i < 10; i++) {
        U[i][i - 1] = 2;
    }
    for(int i = 0; i < 10; i++) {
        b[i][0] = i + 2;
    }

    printf("D: \n");
    for(int i = 0; i < 10; i++) {
        for(int j = 0;j<10;j++){
            printf("%.2lf ",D[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    printf("U: \n");
    for(int i = 0; i < 10; i++) {
        for(int j = 0;j<10;j++){
            printf("%.2lf ",U[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    printf("b: \n");
    for(int i = 0; i < 10; i++) {
        printf("%.2lf ",b[i][0]);
    }
    printf("\n");

    double **x;
    x = (double**)calloc(10,sizeof(double*));
    for(int i = 0;i < 10;i++){
        x[i] = (double*)calloc(1,sizeof(double));
    }
    int t = 1000;
    while(t--){
        double **UL = matrix_add(U,L,n);
        double **ULX = matrix_mul(UL,x,n,1);
        double **bULX = matrix_sub(b,ULX,n);

        x = matrix_mul(D,bULX,n,1);
        for(int i = 0; i < 10; i++) {
            printf("%.1lf ",x[i][0]);
        }
        printf("\n\n");
    }
    for(int i = 0; i < 10; i++) {
        printf("%.1lf ",x[i][0]);
    }
    printf("\n");

    for(int i = 0;i<10;i++){
        free(x[i]);
    }
    free(x);
    return 0;
}