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


ll dp[310][310][310];

int main() {
    std::cout << std::fixed << std::setprecision(15);
    ll n; cin >> n;
    ll x, y; cin >> x >> y;
    vector<long long> a(n); int asum = 0; 
    vector<long long> b(n); int bsum = 0;
    for(long long i = 0; i < n; i ++){
        cin >> a[i] >> b[i]; 
        asum += a[i]; bsum += b[i];
    }

    rep(i, 310){
        rep(j, 310){
            rep(k, 310){
                dp[i][j][k] = INF;
            }
        }
    }

    dp[0][0][0] = 0;
    rep(i, n){
        for(ll j = 0; j <= 300; j++){
            for(ll k = 0; k <= 300; k++){
                ll l = min((ll)300, j + a[i]);
                ll r = min((ll)300, k + b[i]);
                
                dp[i+1][l][r] = min(dp[i+1][l][r], dp[i][j][k] + 1);
                dp[i+1][j][k] = min(dp[i+1][j][k], dp[i][j][k]);
            }
        }
    }

    ll ans = INF;

    for(ll i = x; i <= 300; i++){
        for(ll j = y; j <= 300; j++){
            ans = min(ans, dp[n][i][j]);
        }
    }

    if(ans == INF){
        cout << -1 << endl; return 0;
    }

    cout << ans << endl;



}