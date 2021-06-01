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
const long long INF = 1e18;
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
    ll n; cin >> n; // <= 500
    vector<long long> p(n);
    for(long long i = 0; i < n; i ++){
        cin >> p[i];
    }

    vector<vector<ll>> ans(n, vector<ll>(n, 0));

    rep(i, n){
        ll x = p[i];
        ans[i][i] = x;
        ll now_y = i, now_x = i;
        bool flag = true;
        
        //cout << "x = " << x << endl;

        for(ll j = 0; j < x-1; j++){
            //左行けるなら左
            if(now_x > 0  && ans[now_y][now_x - 1] == 0){
                ans[now_y][now_x - 1] = x;
                now_x -= 1;
                
                //cout << "left" << endl;
                continue;
            }else if(now_y < n  && ans[now_y + 1][now_x] == 0){
                //下行けるなら下
                ans[now_y + 1][now_x] = x;
                now_y += 1;
                
                //cout << "down" << endl;
                continue;
            }else{
                flag = false;
                break;
            }
        }

        if(!flag){
            cout << -1 << endl; return 0;
        }

    }

    rep(i, n){
        rep(j, i+1){
            if(j == 0){
                cout << ans[i][j];
            }else{
                cout << " " << ans[i][j];
            }
        }br;
    }



}