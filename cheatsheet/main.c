#include"sungj.h"

int a[100] = {0};
int arr[2][100];
int n = 0;

int main(){
    // equation(polynomial)
    printf("Enter the degree of eqn: ");
    scanf("%d",&n);
    for(int i=n;i>=0;i--){
        printf("Enter coefficient of x^%d: ",i);
        scanf("%d",&a[i]);
    }
    // bisection
    // double x1;
    int lr;
    int rr;
    printf("Input the left region: ");
    scanf("%d",&lr);
    printf("Input the right region: ");
    scanf("%d",&rr);
    printf("x = %lf\n",bisection(lr,rr));

    //fixed point iteration
    double x1;
    scanf("%lf",&x1);
    printf("ans = %lf\n",fixed_point(x1));

    // Algorithm: Newton’s iteration
    // 輸入方程式並順便儲存微分後的方程式
    printf("please input the degree of eq: ");
    scanf("%d",&n);
    arr[1][n] = 0;
    for(int i = n;i >= 0 ;i--){
        printf("Enter the cofficient of x^%d: ",i);
        scanf("%d",&arr[0][i]);
        arr[1][i-1] = arr[0][i] * i; //微分
    }
    double x2 = 0.0;
    printf("Input the value of x: ");
    scanf("%lf",&x2);
    double root = newton(x2);
    printf("Roots is %lf\n",root);

    // secant method
    double a = 5, b = 4;
    double ans = secant(a,b);
    printf("ans = %lf\n",ans);

    // gaussian method
    int size = 0;
    printf("Please input the size of matrix(n*n): ");
    scanf("%d",&size);
    int **upper;
    int **lower;
    upper = (int **)calloc(size,sizeof(int*));
    for(int i = 0; i< size + 1; i++){
        upper[i] = (int*)calloc((size + 1),sizeof(int));
    }
    lower = (int **)calloc(size,sizeof(int*));
    for(int i = 0; i< size + 1; i++){
        lower[i] = (int*)calloc((size + 1),sizeof(int));
    }
    for(int i = 0; i < size;i++){
        for(int j = 0; j< size+1;j++){
            scanf("%d",&upper[i][j]);
        }
    }
    for(int i = 0; i < size;i++){
        for(int j = 0; j< size+1;j++){
            lower[i][j] = 0;
        }
    }
    gaussian(size,upper,lower);
    return 0;
}
