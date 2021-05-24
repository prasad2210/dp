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

bool canConstruct(string str, vector<string>&bank, unordered_map<string, bool>&mpp){
    auto it = mpp.find(str);
    if(it != mpp.end()){
        return it->second;
    }
    if(str == ""){
        return true;
    }
    for(int i=0; i<bank.size(); i++){
        if(bank[i] == str.substr(0, bank[i].size()) ){
            string reminder = str.substr(bank[i].size(), str.size());
            if(canConstruct(reminder, bank, mpp) == true){
                mpp[str] = true;
                return true;
            }
        }
    }
    mpp[str] = false;
    return false;
}

int main(){
    string str = "enterapotentpot";
    vector<string> bank{"a", "p", "ent", "enter", "ot", "o", "t"};
    unordered_map<string, bool>mpp;
    unordered_map<string, bool>mpp1;

    string str1 = "eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee";
    vector<string> bank1{"e", "ee", "eee", "eeee", "eeeee"};

    cout<<canConstruct(str, bank, mpp)<<"\n";
    cout<<canConstruct(str1, bank1, mpp1)<<"\n";

    return 0;
}