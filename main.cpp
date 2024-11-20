#include <chrono>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

void sieveofprimeNumbers(int limit) {
    // Create a boolean array and initialize all entries as true. A value in prime[i] will finally be false if 'i' is not a prime, else true.
    vector<bool> prime(limit + 1, true);
    prime[0] = prime[1] = false;  // 0 and 1 are not prime numbers

    // Mark all multiples of primes as false
    for (int p = 2; p * p <= limit; ++p) {
        if (prime[p]) {
            // Marking multiples of p as non-prime
            for (int i = p * p; i <= limit; i += p) {
                prime[i] = false;
            }
        }
    }

    // Print all prime numbers (you can disable this part for large ranges)
    for (int i = 2; i <= limit; ++i) {
        if (prime[i]) {
            cout << i << " ";
        }
    }
}

int main() {
    int limit = 1000000;  // Defining the upper limit
    
    chrono::time_point < chrono::system_clock > start = chrono::system_clock::now();
    
    sieveofprimeNumbers(limit);  // Call the prime number generation function and screens out the unwanted numbers
    
    chrono::time_point < chrono::system_clock > end = chrono::system_clock::now();
    
    chrono::duration<float> elapsed = end - start;  // Calculates the elapsed time
    
    cout << "\n\nTime to find primes from 1 to " << limit << " is " << elapsed.count() << " seconds" << endl;
    return 0;
}
   
