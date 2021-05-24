#include <stdio.h>
#include <bits/stdc++.h>
#include <cmath>
#include <string.h>

using namespace std;

typedef long long int ll;
#define fo(i, n) for (i = 0; i < n; i++)
#define Fo(i, k, n) for (i = k; k < n ? i < n : i > n; k < n ? i += 1 : i -= 1)
#define itr(it, a) for (auto it = a.begin(); it != a.end(); it++)
#define all(x) x.begin(), x.end()
#define sortall(x) sort(all(x))

typedef pair<int, int> pii;
typedef pair<ll, ll> pl;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vpii;
typedef vector<pl> vpl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;

const int mod = 1'000'000'007;

int i, k;

int countConstruct(string str, vector<string> &bank, unordered_map<string, int> &mpp)
{
    // auto it = mpp.find(str);
    // if (it != mpp.end())
    // {
    //     return it->second;
    // }
    auto it = mpp.find(str);
    if(it != mpp.end()){
        return it->second;
    }
    if (str == "")
    {
        return 1;
    }
    int counter = 0;
    for (int i = 0; i < bank.size(); i++)
    {
        if (bank[i] == str.substr(0, bank[i].size()))
        {
            string reminder = str.substr(bank[i].size(), str.size());
            int numways = countConstruct(reminder, bank, mpp);
            if (numways)
            {
                counter += numways;
            }
        }
    }
     //cout << counter << " "<<str;

    //  cout << "\n";
    mpp[str] = counter;
    return counter;
}

int main()
{
    string str = "purple";
    vector<string> bank{"purp", "p", "ur", "le", "purpl"};
    unordered_map<string, int> mpp;
    unordered_map<string, int> mpp1;
    unordered_map<string, int> mpp2;
    unordered_map<string, int> mpp3;


    string str1 = "abcdef";
    vector<string> bank1{"ab", "abc", "cd", "def", "abcd"};

    string str2 = "enterapotentpot";
    vector<string> bank2{"a", "p", "ent", "enter", "ot", "o", "t"};

    string str3 = "eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeef";
    vector<string> bank3{"e", "ee", "eee", "eeee", "eeeee"};

     cout << countConstruct(str, bank, mpp) << "\n";        //2
     cout << countConstruct(str1, bank1, mpp1) << "\n";     //1
    cout << countConstruct(str2, bank2, mpp2) << "\n";      //4
    cout << countConstruct(str3, bank3, mpp3) << "\n";      //0


    return 0;
}