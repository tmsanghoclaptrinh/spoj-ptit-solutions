# include <bits/stdc++.h>
# define fi first
# define se second
# define all(a) a.begin() , e.end()
# define ms(a , n) memset(a , n , sizeof(a))
# define endl "\n"
using namespace std;

using ll = long long;
using ld = long double;

typedef pair <ll , ll> pi;
typedef vector <pi> vii;

const ll mod = 1e9 + 7;
const ll base = 31;
const ll maxn = 1e2 + 5;

ll sum = 0 , n;
string s;
stack <ll> st;
map <char , ll> mp;

int main()
{
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> s;
    n = s.size();
    s = " " + s;
    mp['O'] = 16 , mp['H'] = 1 , mp['C'] = 12;
    for (ll i = 1 ; i <= n ; i++)
    {
        if (s[i] == '(') st.push(-1);
        if (s[i] == 'O' || s[i] == 'H' || s[i] == 'C') st.push(mp[s[i]]);
        if (s[i] >= '1' && s[i] <= '9')
        {
            if (!st.empty())
            {
                ll te = st.top(); st.pop();
                te *= (s[i] - '0');
                st.push(te);
            }
        }
        if (s[i] == ')')
        {
            ll te = 0;
            while(!st.empty() && st.top() != -1)
            {
                ll top = st.top(); st.pop();
                te += top;
            }
            if (!st.empty() && st.top() == -1)
            {
                st.pop();
                st.push(te);
            }
        }
    }
    while(!st.empty())
    {
        ll te = st.top(); st.pop();
        if (te != -1) sum += te;
    }
    cout << sum;
}
