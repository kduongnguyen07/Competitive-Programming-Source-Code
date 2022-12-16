#include<bits/stdc++.h> 
using namespace std;
long long solve(long long n){
    long long tmp = n-1;
    long long res = tmp*(tmp+1)*2;
    res += n*4;
    return res+1;
}
int main(){
    long long n;
    cin>>n;
    cout<<solve(n);
}
