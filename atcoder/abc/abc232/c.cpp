#include <bits/stdc++.h>
// #include <atcoder/all>
// using namespace atcoder;
typedef long long ll;
typedef long double ld;
#define rep(i,n) for(ll i=0;i<(n);i++)
#define repr(i,n) for(ll i=(n-1);i>=0;i--)
#define all(x) x.begin(),x.end()
#define br cout << '\n';
using namespace std;
const long long INF = 8e18;
const long long MOD = 1e9+7;
using Graph = vector<vector<ll>>;
template<class T> inline bool chmin(T &a, T b) { if(a > b){ a = b; return true;} return false;}
template<class T> inline bool chmax(T &a, T b) { if(a < b){ a = b; return true;} return false;}
ll ceilll(ll a, ll b) {return (a + b-1) / b;} // if(a%b != 0) (a/b) + 1
ll get_digit(ll a) {ll digit = 0; while(a != 0){a /= 10; digit++;} return digit;} // a != 0
template<typename T> void vecdbg(vector<T>& v){ rep(i, v.size()){cerr << v[i] << ' ';} cerr << '\n';}
template<typename T> void vecvecdbg(vector<vector<T>>& v){ rep(i, v.size()){rep(j, v[i].size()){cerr << v[i][j] << ' ';} cerr << '\n';}}
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
// for(auto& i: mp) &&&&&&&&&&&&&

int main() {
    std::cout << std::fixed << std::setprecision(15);
    ll n, m; cin >> n >> m;
    vector<vector<ll>> g(n);
    vector<vector<ll>> g2(n);

    map<P, ll> mp;

    rep(i, m){
        ll a, b; cin >> a >> b; a--; b--;
        g[a].push_back(b); g[b].push_back(a);
        mp[{a, b}]++; mp[{b, a}]++;
    }

    map<P, ll> mp2;
    rep(i, m){
        ll c, d; cin >> c >> d; c--; d--;
        g2[c].push_back(d); g2[d].push_back(c);
        mp2[{c, d}]++; mp2[{d, c}]++;
    }

    vector<ll> p(n);
    rep(i, n){
        p[i] = i;
    }

    if(m == 0){
        cout << "Yes" << endl; return 0;
    }

    do{
        bool f = true;
        for(auto&i : mp){
            ll l = i.first.first, r = i.first.second;
            if(mp2.count({p[l], p[r]}) == 0 && mp2.count({p[r], p[l]}) == 0){
                f = false;
            }
        }
        if(f){
            cout << "Yes" << endl; return 0;
        }

    }while(next_permutation(p.begin(), p.end()));

    cout << "No" << endl;

}