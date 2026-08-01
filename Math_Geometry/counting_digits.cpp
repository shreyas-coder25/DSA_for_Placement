// Counting digits using log

#include <bits/stdc++.h>
using namespace std;

int count_digits(int n) {
    // Method-1
    int c = n, count = 0;
    while (c>0) {
        count++;
        c /= 10;
    }

    //method-2 : Short-cut
    return (int)log10(n)+1;
}

int main() {
    int n;
    cout << "Enter a number: " << "\n";
    cin >> n;
    cout << "Number of digits in " << n << " is: " << count_digits(n) << endl;
    return 0;
}