#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define el '\n'
#define _ << ' '<<
#define memset( a, b ) memset( a, b, sizeof a )
#define cico( A ) freopen( A".INP", "r", stdin ); freopen( A".OUT", "w", stdout );

template<typename X, typename Y> inline void amax( X &A, Y B ){ if(B>A) A=B; }
template<typename X, typename Y> inline void amin( X &A, Y B ){ if(B<A) A=B; }

const int N = 1e6+7, mod = 1e9+7;
int cnt[N];
ll gt[N];
int n, k, l, r;

ll powup( ll base, ll mu ){
    ll root = 1;
    while( mu ){
        if( mu&1 ) ( root *= base ) %= mod;
        ( base *= base ) %= mod;
        mu >>= 1;
    }
    return root;
}

ll C( int _k, int _n ){
    if( _k>_n ) return 0;
    ll res = gt[_n];
    ( res *= powup( gt[_n-_k], mod-2 ) ) %= mod;
    ( res *= powup( gt[_k], mod-2 ) ) %= mod;
    return res;
}
int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
    memset( cnt, 0 );
    cin >> n >> k >> l >> r;
    if( k==1 ){
        cout << r-l+1;
        return 0;
    }
    gt[0] = 1;
    for( int i=1; i<N; ++i )  gt[i] = ( gt[i-1] * i ) % mod;
    for( int i=l; i<=r; ++i ){
        cnt[ i%(k-1) ]++;
    }
    ll sum = 0;
    for( int i=0; i<k-1; ++i ){
        ( sum += C( 2, cnt[i] ) ) %= mod;
    }
    cout << sum;

    return 0;
}
