#include <bits/stdc++.h> 
using namespace std;

int reverse_num(int n) {
    int rev = 0;
    while (n > 0) {
        int d = n%10;
        if (rev > (INT_MAX/10) || rev < (INT_MIN/10)) {
            return 0; // Handle overflow
        }
        rev += rev*10 + d;
        n /= 10;
    }
    return rev;
}

// Imp notes
// Error handling is done for overflow cases. If the reversed number exceeds the range of int, it returns 0.
// We can also use long long int to handle larger numbers, but it is not done here as the function is designed to return an int.