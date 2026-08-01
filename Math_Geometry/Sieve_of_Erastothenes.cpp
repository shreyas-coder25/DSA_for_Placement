// Using the Sieve of Eratosthenes algorithm to find all prime numbers up to a given limit

#include <bits/stdc++.h> 
using namespace std;

int count_prime(int n) {
    int ans = 0;
    vector<bool> prime(n+1, true); 
    for (int i=2; i<n; i++) {
        if (prime[i]) {
            ans++;
            for (int j = i*2; j<=n; j+=i) { // every multiple of i is not prime
                prime[j] = false;
            }
        }
    }
    return ans;
}
int main() {
    int n;
    cout << "Enter a number: " << "\n";
    cin >> n;
    cout << "Number of prime numbers up to " << n << " is: " << count_prime(n) << endl;
    return 0;
}