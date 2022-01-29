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

int main() {
    std::cout << std::fixed << std::setprecision(15);
    ll t; cin >> t;
    while(t--){
        ll n, k, x; cin >> n >> k >> x;
        string s; cin >> s;
        s.push_back('a');
        vector<ll> res;
        ll cnt = 0;
        rep(i, s.size()){
            if(s[i] == 'a' && cnt > 0){
                res.push_back(cnt);
                cnt = 0;
            }
            if(s[i] == '*'){
                cnt++;
            }
        }

        rep(i, res.size()){
            res[i] = res[i] * k + 1;
        }

        ll sho = x, amari = 0;
        vector<ll> b(res.size());
        for(ll i = res.size() - 1; i >= 0; i--){
            if(res[i] >= sho){
                b[i] = sho - 1; break;
            }
            amari = sho % res[i];
            sho = sho / res[i];
            b[i] = (amari -1 + res[i]) % res[i];
        }

        ll now = 0;
        bool f = true;
        rep(i, s.size() - 1){
            if(s[i] == 'a'){
                cout << 'a';
                f = true;
            }else{
                if(f && now < b.size()){
                    rep(j, b[now]){
                        cout << 'b';
                    }
                    now++;
                    f = false;
                }
            }
        }br;
        
    }

}