#include <bits/stdc++.h>
using namespace std;
const int LIM = 1e6;
int cntPrime = 0;
bool isPrime[LIM + 1];
void sieve(int n)
{ 
    memset(isPrime, false, sizeof(isPrime));
    if (n < 2) return ;
    isPrime[2] = true; cntPrime = 1;
    if (n < 3) return ;
    isPrime[3] = true; cntPrime = 2;
    if (n < 4) return ;
    for (int x = 1; x * x <= n; ++x)
    { 
        int A = x * x;
        for (int y = 1; y * y <= n - A; ++y)
        {
            int B = y * y, p;
            if (p = 4 * A + B, p <= n && (p % 12 == 1 || p % 12 == 5)) isPrime[p] = !isPrime[p]; 
            if (p = 3 * A + B, p <= n && p % 12 == 7)                  isPrime[p] = !isPrime[p]; 
            if (p = 3 * A - B, p <= n && p % 12 == 11 && x > y)        isPrime[p] = !isPrime[p]; 
        } 
    } 
  
    int rn = sqrt(n);
    for (int x = 5; x <= rn; ++x) if (isPrime[x])
        for (int k = 1; k * x * x <= n; ++k)
            isPrime[k * x * x] = false;
    
    cntPrime = count(isPrime, isPrime + n + 1, 1);
}
int main()
{
    int n;
    cin >> n;

    sieve(n);
    cout << "Number of primes up to " << n << " is " << cntPrime;
    return 0;
}