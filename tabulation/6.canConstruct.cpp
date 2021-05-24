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

bool canConstruct(string str, vector<string> &bank){
    vector<bool> table((str.length()+1) , false);
    table[0] = true;
    fo(i, table.size()){
        if(table[i]){
             //cout<<i<<" ";
            fo(j, bank.size()){
                    //cout<<bank[j]<<" "<<str.substr(i, bank[j].size())<<" ||";
                if(bank[j] == str.substr(i, bank[j].size())){
                    //cout<<bank[j]<<" ";
                    if(i + bank[j].size() <= table.size()){
                        table[i+bank[j].size()] = true;
                    }
                }
            }
        }
        // cout<<"\n";
        // itr(it, table){
        //     cout<<*it<<" ";
        // }
        // cout<<"\n";
    }
    return table[str.length()];
}

int main(){

    string str = "enterapotentpot";
    vector<string> bank{"a", "p", "ent", "enter", "ot", "o", "t"};
    
    string str1 = "eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeef";
    vector<string> bank1{"e", "ee", "eee", "eeee", "eeeee"};

    string str2 = "abcdef";
    vector<string> bank2{"ab", "abc", "cd", "def", "abcd"};

    cout<<canConstruct(str, bank)<<"\n";
    cout<<canConstruct(str1, bank1)<<"\n";
    cout<<canConstruct(str2, bank2)<<"\n";


    return 0;
}