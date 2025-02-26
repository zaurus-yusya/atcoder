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

void rotate(vector<vector<char>> &vec){
    vector<vector<char>> tmp;
    tmp = vec;
    rep(j, tmp.size()){
        rep(i, tmp.size()){
            vec[i][j] = tmp[j][tmp.size() - 1 - i];
        }
    }
}

bool calc(vector<vector<char>> &s, vector<vector<char>> &t, ll x){
    ll cnt = 0;
    rep(i, x){
        rep(j, x){
            if(t[i][j] == '#') cnt += 1;
        }
    }
    /*
    vecvecdbg(t);
    cerr << "cnt = " << cnt << endl;
    */

    for(ll sh = -x+1; sh <= 2*x-1; sh++){
        for(ll sw = -x+1; sw <= 2*x-1; sw++){
            
            ll res = 0;
            rep(i, x){
                rep(j, x){

                    if(i + sh < 0 || i + sh >= x || j + sw < 0 || j + sw >= x) continue;
                    if(s[i][j] == '.' && t[i + sh][j + sw] == '#') res += 1;

                }
            }
            if(res == cnt) return true;

        }
    }

    return false;
}

int main() {
    std::cout << std::fixed << std::setprecision(15);
    ll h, w; cin >> h >> w;
    ll x = max(h, w);
    vector<vector<char>> s(x, vector<char>(x, '#'));
    vector<vector<char>> t(x, vector<char>(x, '.'));
    rep(i, h)rep(j, w) cin >> s[i][j];
    rep(i, h)rep(j, w) cin >> t[i][j];


    rep(i, 4){
        if(calc(s, t, x)){
            cout << "Yes" << endl; return 0;
        }
        rotate(t);
    }
    cout << "No" << endl;
    /*
    vecvecdbg(t);
    rotate(t);
    vecvecdbg(t);
    rotate(t);
    vecvecdbg(t);
    rotate(t);
    */


}