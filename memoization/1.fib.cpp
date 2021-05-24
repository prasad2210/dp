#include<stdio.h>
#include<bits/stdc++.h>
#include<cmath>

using namespace std;

typedef long long int ll;
#define fo(i,n) for(i=0;i<n;i++)
#define Fo(i,k,n) for(i=k;k<n?i<n:i>n;k<n?i+=1:i-=1)
#define itr(it, a) for(auto it = a.begin(); it != a.end(); it++)
#define all(x) x.begin(), x.end()
#define sortall(x) sort(all(x))

typedef pair<int, int> pii;
typedef pair<ll, ll>   pl;
typedef vector<int>    vi;
typedef vector<ll>     vl;
typedef vector<pii>    vpii;
typedef vector<pl>     vpl;
typedef vector<vi>     vvi;
typedef vector<vl>     vvl;

const int mod = 1'000'000'007;



int i, m;
long long  fib(int n, vl &memo){
    if(memo[n-1]){
        return memo[n-1];
    }
    if(n<=2) return 1;
    memo[n-1] = fib(n-1, memo) + fib(n-2, memo);
    return memo[n-1];
}



int main(){

    int n;
    cin>>n;
    vl memo(n, 0);

    cout<<fib(n, memo)<<" \n";

    return 0;
}