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
    ll t, w; cin >> t >> w;
    if(w == 2){
        return 0;
    }
    rep(T, t){
        vector<ll> ans(6);
        for(ll i = 5; i >= 1; i--){
            cout << i * 63 << endl;
            flush(std::cout);
            ll x; cin >> x;
            ll tmp = 0;
            for(ll j = 5; j > i; j--){
                tmp += ans[j] * POW(2, i * 63 / (j+1));
                //cerr << "ans" << j << "= " << ans[j] << " j = " << i * 63 / (j+1) << " " << POW(2, i * 63 / (j+1)) << endl;
            }
            x -= tmp;
            ans[i] = x / POW(2, i*63/(i+1));
            //cerr << i * 63 << " " << i * 63 / (i+1) << endl;
        }
        cout << 1 << endl;
        flush(std::cout);
        ll x; cin >> x;
        ans[0] = (x - ans[5] - ans[4] - ans[3] - ans[2] - ans[1]) / 2;

        rep(i, 6){
            cout << ans[i] << " ";
        }br;
        flush(std::cout);
        ll y; cin >> y;
        // 6
        // 64r1 + 8r2 + 4r3 + 2r4 + 2r5 + 2r6
        // 5
        // 32r1 + 4r2 + 2r3 + 2r4 + 2r5 + r6
        // 4
        // 16r1 + 4r2 * 2r3 + 2r4 + r5 + r6
        // 3
        // 8r1 + 2r2 + 2r3 + r4 + r5 + r6
        // 2
        // 4r1 + 2r2 + r3 + r4 + r5 + r6
        // 1
        // 2r1 + r2 + r3 + r4 + r5 + r6


    }
    // 1, 2, 3, 4, 5, 6

}