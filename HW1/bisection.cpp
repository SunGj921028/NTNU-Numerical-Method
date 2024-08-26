/**
 * \file
 * \brief Solve the equation \f$f(x)=0\f$ using [bisection
 * method](https://en.wikipedia.org/wiki/Bisection_method)
 *
 * Given two points \f$a\f$ and \f$b\f$ such that \f$f(a)<0\f$ and
 * \f$f(b)>0\f$, then the \f$(i+1)^\text{th}\f$ approximation is given by: \f[
 * x_{i+1} = \frac{a_i+b_i}{2}
 * \f]
 * For the next iteration, the interval is selected
 * as: \f$[a,x]\f$ if \f$x>0\f$ or \f$[x,b]\f$ if \f$x<0\f$. The Process is
 * continued till a close enough approximation is achieved.
 *
 * \see newton_raphson_method.cpp, false_position.cpp, secant_method.cpp
 */

#include<cmath>
#include<iostream>
#include<limits>

using namespace std;

#define EPSILON \
    1e-6  // std::numeric_limits<double>::epsilon()  ///< system accuracy limit
#define MAX_ITERATIONS 50000  ///< Maximum number of iterations to check

// define f(x) to find root for
// f(x) = (x^3 - 4x - 9) for example
static double eq(double i){
    return (pow(i,3) - (4 * i) - 9);
}

/** get the sign(+.1 or -.-1 =.0) of any given number */
template <typename T>
int sgn(T val){
    return (T(0) < val) - (val < T(0));
}

double bisection(double lpos,double rpos){
    double mid;
    double mval;
    while(rpos - lpos > EPSILON && lpos < rpos){
        mid = (lpos + rpos) / 2;
        mval = eq(mid);
        std::cout << "\n\nz: " << mval << "\t[" << lpos << " , " << rpos
                  << " | Bisect: " << mid << "]";
        if(mval < 0){
            lpos = mid;
        }else{
            rpos = mid;
        }
    }
    return mid;
}

int main(){
    double a = -2, b = 2, x, z;
    // int i;

    for(int i = 0;i<MAX_ITERATIONS;i++){
        z = eq(a);
        x = eq(b);
        if(sgn(z) == sgn(x)){ // same signs, increase interval
            b++;
            a--;
        }else{
            break;
        }
    }

    cout << "First initial: " << a;
    cout << "Second initial: " << b;
    
    cout << "Roots: " << bisection(a,b) << endl;
    return 0;
}