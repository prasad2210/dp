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
ll  path(int x, int y, vvl &memo){
    if(x == 0 && y ==0){
        return 1;
    }
    if(memo[x][y]){
        return memo[x][y];
    }
    else{
        ll a = 0, b = 0;
        if((x-1)>=0){
            a = path(x-1, y, memo);
        }
        if((y-1)>=0){
            b = path(x, y-1, memo);
        }
        memo[x][y] = a + b;
        memo[y][x] = memo[x][y];
        return memo[x][y];
    }
}

int main(){
    int A, B;
    cin>>A>>B;
    vvl memo(A, vl(B, 0));
    
    // if(memo[0][0]){
    //     cout<<"prasad";
    // }
    // else{
    //     cout<<"prachi";
    // }
    // cout<<A<<" aef";
     int ans = path(A-1, B-1, memo);
     cout<<ans<<"\n";
    return 0;
}