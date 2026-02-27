#include<vector>
#include <cmath>

using namespace std;
/*
204. Count Primes
*/
class Solution {
public:
    int countPrimes(int n) {
        if (n <= 2) return 0;
        vector<bool> isPrime(n, true);
        isPrime[0] = isPrime[1] = false;

        for (int i =2; i*i<n; i++) {
            if(isPrime[i]) {
                for (int j=i*i; j<n; j+=i){
                    isPrime[j] = false; //把i的倍數劃掉
                }
            }
        }
        int count = 0;
        for (int i = 0; i<n; i++) {
            if(isPrime[i] == true) {
                count++;
            }
        }
        return count;
    }
};