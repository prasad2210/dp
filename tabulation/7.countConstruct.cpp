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
ll countConstruct(string str, vector<string>&bank){
    vl table(str.length()+1, 0);
    table[0] = 1;
    fo(i, table.size()){
            // cout<<i<<" a";
        if(table[i]){
             //cout<<i<<" ";
            fo(j, bank.size()){
               //  cout<<bank[j]<<" "<<str.substr(i, bank[j].size())<<" || ";
                if(bank[j] == str.substr(i, bank[j].size())){
                    if(i + bank[j].size() < table.size()){
                        table[i + bank[j].size()] += table[i];
                    }
                }
            }
        }
        // itr(it, table){
        //     cout<<*it<<" ";
        // }
        // cout<<"\n";
    }
    return table[str.length()];
}

int main(){
    string str = "purple";
    vector<string> bank{"purp", "p", "ur", "le", "purpl"};

    string str1 = "abcdef";
    vector<string> bank1{"ab", "abc", "cd", "def", "abcd"};

    string str2 = "enterapotentpot";
    vector<string> bank2{"a", "p", "ent", "enter", "ot", "o", "t"};

    string str3 = "eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeef";
    vector<string> bank3{"e", "ee", "eee", "eeee", "eeeee"};

     cout << countConstruct(str, bank) << "\n";
     cout << countConstruct(str1, bank1) << "\n";
    cout << countConstruct(str2, bank2) << "\n";
    cout << countConstruct(str3, bank3) << "\n";




    return 0;
}