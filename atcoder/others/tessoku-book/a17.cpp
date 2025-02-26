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

int main() {
    std::cout << std::fixed << std::setprecision(15);
    ll n; cin >> n;
    vector<ll> a(n);
    vector<ll> b(n);
    for(ll i = 1; i < n; i++){
        cin >> a[i];
    }
    for(ll i = 2; i < n; i++){
        cin >> b[i];
    }

    vector<ll> dp(n+10, INF);
    dp[0] = 0;
    dp[1] = 0;
    for(ll i = 2; i <= n; i++){
        if(i == 2){
            dp[i] = dp[i-1] + a[i-1];
        }else{
            dp[i] = min(dp[i-1] + a[i-1], dp[i-2] + b[i-1]);
        }
    }

    ll now = n;
    ll cur = dp[n];
    vector<ll> ans;
    ans.push_back(n);

    while(now > 1){
        if(dp[now - 1] == cur - a[now - 1]){
            ans.push_back(now - 1);
            
            cur = cur - a[now - 1];
            now = now - 1;
        }else{
            ans.push_back(now - 2);
            
            cur = cur - b[now - 1];
            now = now - 2;
        }
    }
    reverse(all(ans));

    cout << ans.size() << endl;
    rep(i, ans.size()){
        cout << ans[i] << " ";
    }br;

}