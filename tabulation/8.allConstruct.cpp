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

vector<vector<string>> allConsturct(string str, vector<string> &bank){
    cout<<"1";
    vector<vector<vector<string>>> table(str.length()+1, {{}});
    cout<<"2";

    table[0][0] = {{1}};
    cout<<"3";

    cout<<table[0][0].size()<<" q";

    fo(i, table.size()){
        if(table[i][0].size()){
            cout<<i<<" ";
            fo(j, bank.size()){
                if(bank[j] == str.substr(i, bank[j].size())){
                    if(i + bank[j].size() < table.size()){
                        itr(it, table[i]){
                            it->push_back(bank[j]);
                            table[i+bank[j].size()].push_back(*it);
                        }
                    }
                }
            }
        }
    }
    return table[str.length()];
}

int main(){
    string str = "purple";
    vector<string> bank{"purp", "p", "ur", "le", "purpl"};

    string str1 = "abcdef";
    vector<string> bank1{"ab", "abc", "cd", "def", "abcd", "ef", "c"};

    string str2 = "skateboard";
    vector<string> bank2{"bo", "rd", "ate", "t", "ska", "sk", "boar"};

    string str3 = "eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeef";
    vector<string> bank3{"e", "ee", "eee", "eeee", "eeeee"};

    vector<vector<string>> ans;
    
    ans = allConsturct(str, bank);

    fo(i, ans.size()){
        fo(j, ans[i].size()){
            cout<<ans[i][j]<< " ";
        }
        cout<<"\n";
    }
    return 0;
}