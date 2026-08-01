// Calculation of LCm using GCD

#include <iostream>
using namespace std;

int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a%b);
}
 
int lcm(int a, int b) {
    return (a*b)/gcd(a, b);
}

// Imp Notes
// Time Complexity of LCM is O(log(min(a, b))) as it uses GCD to calculate LCM
// Formula used: a*b = GCD(a, b) * LCM(a, b)