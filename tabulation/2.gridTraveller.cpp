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

int i, k, j;

ll gridTraveller(ll n, ll m){
    vvl table(n+1, vl(m+1, 0));
    table[1][1] = 1;
    
    
    fo(i, n+1){
        fo(j, m+1){
            if(i+1 <n+1) table[i+1][j] += table[i][j];
            if(j+1 <m+1) table[i][j+1] += table[i][j];  
        }
    }
    // fo(i, n+1){
    //     fo(j, m+1){
    //         cout<<table[i][j]<<" ";
    //     }
    // cout<<"\n";
    // }
    return table[n][m];
}

int main(){
    ll n, m;
    cin>>n>>m;
    cout<<gridTraveller(n, m);
    return 0;
}