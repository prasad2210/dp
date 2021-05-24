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
vl howSum(ll n, vl &num, unordered_map<ll, vl>&mpp){
    auto it = mpp.find(n);
    if(it != mpp.end()){
        return it->second;
    }
    if(n == 0) return vl(1, 1);
    if(n < 0 ) return vl(1,0);
    itr(it, num){
        ll rem = n - *it;
        vl result = howSum(rem, num, mpp);
        if(result[0]){
            result.push_back(*it);
            mpp[n] = result;
            return mpp[n];
        }
    }
    mpp[n] = vl(1,0);
    return mpp[n];
}

int main(){

    vl num{7, 25};
    unordered_map<ll, vl>mpp;
    ll n = 300;
    vl resultFinal = howSum(n, num, mpp);
    if(resultFinal[0]){
        resultFinal.erase(resultFinal.begin());

        itr(it, resultFinal){
            cout<<*it<<" ";
        }
    }
    else{
        cout<<"NULL";
    }
    return 0;
}