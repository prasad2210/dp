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

    int i, k;

bool canSum(ll n, vl&num, unordered_map<ll, bool>&mpp){
    auto it = mpp.find(n);
    if(it != mpp.end()){
        return it->second;
    }
    if(n == 0) return true;
    if(n<0) return false;

    itr(it, num){
        ll rem = n - *it;
        if(canSum(rem, num, mpp)){
            mpp[n] = true; 
            return mpp[n];
        }
    }
    mpp[n]= false;
    return mpp[n];
}

int main(){
    vl num{7, 14};
    unordered_map<ll, bool> mpp;
    ll n = 300;
    if(canSum(n, num, mpp)){
        cout<<"YES\n";
    }
    else{
        cout<<"NO\n";
    }
    return 0;
}