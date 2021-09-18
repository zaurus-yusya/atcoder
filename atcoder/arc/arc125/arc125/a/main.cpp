#include <bits/stdc++.h>
// #include <atcoder/all>
// using namespace atcoder;
typedef long long ll;
typedef long double ld;
#define rep(i,n) for(ll i=0;i<(n);i++)
#define repr(i,n) for(ll i=(n-1);i>=0;i--)
#define all(x) x.begin(),x.end()
#define br cout << "\n";
using namespace std;
const long long INF = 8e18;
const long long MOD = 1e9+7;
using Graph = vector<vector<ll>>;
template<class T> inline bool chmin(T &a, T b) { if(a > b){ a = b; return true;} return false;}
template<class T> inline bool chmax(T &a, T b) { if(a < b){ a = b; return true;} return false;}
ll ceilll(ll a, ll b) {return (a + b-1) / b;} // if(a%b != 0) (a/b) + 1
ll get_digit(ll a) {ll digit = 0; while(a != 0){a /= 10; digit++;} return digit;} // a != 0
template<typename T> void vecdbg(vector<T>& v){ rep(i, v.size()){cerr << v[i] << " ";} br;}
template<typename T> void vecvecdbg(vector<vector<T>>& v){ rep(i, v.size()){rep(j, v[i].size()){cerr << v[i][j] << " ";} br;}}
ll POW(ll a, ll n){ ll res = 1; while(n > 0){ if(n & 1){ res = res * a; } a *= a; n >>= 1; } return res; }
using P = pair<ll, ll>;
const double PI = acos(-1);

// 0 false, 1 true 
// string number to int : -48 or - '0'
// a to A : -32
// ceil(a)  1.2->2.0
// c++17	g++ -std=c++17 a.cpp
// global vector -> 0 initialization
// DONT FORGET TO INTIALIZE
// The type of GRID is CHAR. DONT USE STRING
// If the result in local and judge is different, USE CODETEST!!
// (a * b)over flow?   if(a > INF / b){ /* overflow */}

int main() {
    std::cout << std::fixed << std::setprecision(15);
    ll n, m; cin >> n >> m;
    vector<long long> s(n);
    for(long long i = 0; i < n; i ++){
        cin >> s[i];
    }
    vector<long long> t(m);
    map<ll, ll> mp;
    for(long long i = 0; i < m; i ++){
        cin >> t[i];
        mp[t[i]]++;
    }

    ll x = s[0];

    if(x == 0){
        ll dis = INF;
        for(ll i = 0; i < n; i++){
            if(s[i] == 1){
                dis = min(dis, i);
            }
        }
        for(ll i = n-1; i >= 0; i--){
            if(s[i] == 1){
                dis = min(dis, n-i);
            }
        }
        if(dis == INF && mp.count(1) > 0){
            cout << -1 << endl; return 0;
        }

        bool flag = true;
        ll ans = 0;
        ll now = 0;
        rep(i, m){
            if(t[i] == 0){
                if(now == 0){
                    ans += 1;
                }else{
                    if(flag){
                        ans += dis;
                        ans++;
                        flag = false;
                    }else{
                        ans += 2;
                    }
                    now = 0;
                }
            }else{
                if(now == 0){
                    if(flag){
                        ans += dis;
                        ans++;
                        flag = false;
                    }else{
                        ans += 2;
                    }
                    now = 1;
                }else{
                    ans += 1;
                }

            }
        }
        cout << ans << endl;
    }else{
        ll dis = INF;
        for(ll i = 0; i < n; i++){
            if(s[i] == 0){
                dis = min(dis, i);
            }
        }
        for(ll i = n-1; i >= 0; i--){
            if(s[i] == 0){
                dis = min(dis, n-i);
            }
        }
        if(dis == INF && mp.count(0) > 0){
            cout << -1 << endl; return 0;
        }
        //cerr << dis << endl;
        bool flag = true;
        ll ans = 0;
        ll now = 1;
        rep(i, m){
            if(t[i] == 0){
                if(now == 0){
                    ans += 1;
                }else{
                    if(flag){
                        ans += dis;
                        ans++;
                        flag = false;
                    }else{
                        ans += 2;
                    }
                    now = 0;
                }
            }else{
                if(now == 0){
                    if(flag){
                        ans += dis;
                        ans++;
                        flag = false;
                    }else{
                        ans += 2;
                    }
                    now = 1;
                }else{
                    ans += 1;
                }

            }
        }
        cout << ans << endl;
    }
    

    


}