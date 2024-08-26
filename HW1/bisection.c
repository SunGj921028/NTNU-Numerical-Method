#include<stdio.h>
#include<math.h>
#include<stdlib.h>

double val(double x){
    return (x - cbrt(x) - 2);
}

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
}

int main(){
    double x;
    int lr;
    int rr;
    printf("Input the left region: ");
    scanf("%d",&lr);
    printf("Input the right region: ");
    scanf("%d",&rr);
    
    printf("x = %lf\n",bisection(lr,rr));
    return 0;
}