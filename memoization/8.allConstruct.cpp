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

vector<vector<string>> allConstruct(string str, vector<string>&bank, unordered_map<string, vector<vector<string>>>&mpp){
    auto it = mpp.find(str);
    if(it != mpp.end()){
        return it->second;
    }
    if(str == ""){
        //cout<<"abc";
        return vector<vector<string>> {{}};
    }
    vector<vector<string>> ans;
    int counter = 0;
    itr(it, bank){
        if(*it == str.substr(0, it->size())){
           vector<vector<string>>result = allConstruct(str.substr(it->size(), str.size()), bank, mpp);
           vector<vector<string>>allresult;
           itr(it1, result){
               it1->push_back(*it);
               allresult.push_back(*it1);
           }
           itr(it1, allresult){
               ans.push_back(*it1);
           }
        }
    }
    mpp[str] = ans;
    return ans;
}

int main(){
    string str = "purple";
    vector<string> bank{"purp", "p", "ur", "le", "purpl"};
    
    unordered_map<string, vector<vector<string>>> mpp;
    unordered_map<string, vector<vector<string>>> mpp1;
    unordered_map<string, vector<vector<string>>> mpp2;
    unordered_map<string, vector<vector<string>>> mpp3;

    string str1 = "abcdef";
    vector<string> bank1{"ab", "abc", "cd", "def", "abcd", "ef", "c"};

    string str2 = "skateboard";
    vector<string> bank2{"bo", "rd", "ate", "t", "ska", "sk", "boar"};

    string str3 = "eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeef";
    vector<string> bank3{"e", "ee", "eee", "eeee", "eeeee"};

    int j =0;
    vector<vector<string>> ans = allConstruct(str, bank, mpp);
    fo(i, ans.size()){
        fo(j, ans[i].size()){
            cout<<ans[i][j]<< " ";
        }
        cout<<"\n";
    }
    ans = allConstruct(str1, bank1, mpp1);
    if(!ans.size()){
        cout<<"NULL"<<"\n";
    }
    fo(i, ans.size()){
        fo(j, ans[i].size()){
            cout<<ans[i][j]<< " ";
        }
        cout<<"\n";
    }
    ans = allConstruct(str2, bank2, mpp2);
    if(!ans.size()){
        cout<<"NULL"<<"\n";
    }
    fo(i, ans.size()){
        fo(j, ans[i].size()){
            cout<<ans[i][j]<< " ";
        }
        cout<<"\n";
    }
    ans = allConstruct(str3, bank3, mpp3);
    if(!ans.size()){
        cout<<"NULL"<<"\n";
    }
    fo(i, ans.size()){
        fo(j, ans[i].size()){
            cout<<ans[i][j]<< " ";
        }
        cout<<"\n";
    }

    return 0;
}