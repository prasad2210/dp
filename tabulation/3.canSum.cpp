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

int i, j, k;

bool canSum(int n, vl&num){
    vector<bool> table(n+1, false);
    table[0] = true;
    fo(i, n+1){
        if(table[i]){
            fo(j, num.size()){
                if(i+num[j] <n+1){
                    table[i+num[j]] = true;
                }
            }
        }
    }
    // itr(it, table){
    //     cout<<*it<<" ";
    // }
    // cout<<"\n";
    return table[n];
}

int main(){

    vl num{2, 4};
    ll n = 7;
    if(canSum(n, num)){
        cout<<"TRUE"<<"\n";
    }
    else{
        cout<<"FALSE"<<"\n";
    }

    return 0;
}