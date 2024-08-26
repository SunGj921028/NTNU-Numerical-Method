#include<iostream>
#include<cmath>
#include<vector>

using namespace std;

/*
    x* = argmin f(x)
    x' = x - learning_rate * f'(x)
*/

double gradient_descent(double x) {
    // the polynomial is after first derivative to get the slope
    // return ( 4 * pow(x, 3) - ( 6 * pow(x, 2) ) );
    return (4 * pow(x,3) + 9 * pow(x - 2, 2) - (30 * x));
}

int main() {
    double x = -10;
    double learning_rate = 0.00001;
    // int count = 0;

    // gradient descent
    // find closest local minimum
    while(fabs(gradient_descent(x)) > 1e-6) {
        // count++;
        x -= (learning_rate * gradient_descent(x));
    }

    printf("x = %.4lf\n", x);
    // cout << count << endl;
    return 0;
}