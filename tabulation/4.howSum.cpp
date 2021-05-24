#include <stdio.h>
#include <bits/stdc++.h>
#include <cmath>

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

int i, j, k;

vl howSum(ll n, vl &num)
{
    vvl table(n + 1, vl(1, 0));
    table[0] = {1};
    fo(i, n + 1)
    {
        if (table[i][0])
        {
            fo(j, num.size())
            {
                if (i + num[j] <= n)
                {
                    table[i + num[j]] = table[i];
                    table[i + num[j]].push_back(num[j]);
                }
            }
        }
    }
    return table[n];
}

int main()
{

    vl num = {1, 4, 5};
    ll n = 8;

    vl ans = howSum(n, num);
    ans.erase(ans.begin());
    if (ans.size())
    {
        fo(i, ans.size())
        {
            cout << ans[i] << " ";
        }
        cout << "\n";
    }
    else
    {
        cout << "NULL"
             << "\n";
    }

    return 0;
}