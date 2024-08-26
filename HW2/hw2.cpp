#include<iostream>
#include<cmath>

using namespace std;

int main(){
    double a = 0.0;
    double b = 0.0;
    double x = 0.0;
    cin >> x;
    a = cbrt((2 * x) + 2);
    while(abs(a-b) > 1e-6){
        b = a;
        a = cbrt((2 * a) + 2);
    }
    cout << "ans = " << a << endl;
}