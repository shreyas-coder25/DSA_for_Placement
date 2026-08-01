#include <iostream>
using namespace std;

int gcd(int a, int b) { // Normal method to find gcd
    if (a == b) {
        return a;
    } else if (a == 0) {
        return b;
    } else if (b == 0) {
        return a;
    }
    int ans = 1;
    for (int i=2; i<=min(a, b); i++) {
        if (a%i==0 && b%i==0) {
            ans = max(ans, i);
        }
    }
    return ans;
}

int gcd_euclid(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd_euclid(b, a%b);
}

int main() {
    cout << gcd_euclid(12, 15);
    return 0;
}

// Imp Notes
// 1. The time complexity of the normal method is O(min(a, b))
// 2. The time complexity of the Euclid's algorithm is O(log(min(a, b)))
// Euclid's algorithm is based on the principle that the GCD of two numbers also divides their difference.
// The algorithm can eb simmarized as follows:
// 1. If b = 0, then GCD(a, b) = a
// 2. Otherwise, GCD(a, b) = GCD(b, a % b)