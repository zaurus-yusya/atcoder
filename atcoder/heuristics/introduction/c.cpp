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
    ll d; cin >> d;
    vector<long long> c(26);
    for(long long i = 0; i < 26; i ++){
        cin >> c[i];
    }
    vector<vector<ll>> s(d, vector<ll>(26));
    rep(i, d){
        rep(j, 26){
            cin >> s[i][j];
        }
    }
    vector<long long> t(d);
    for(long long i = 0; i < d; i ++){
        cin >> t[i]; t[i]--;
    }
    ll m; cin >> m;
    vector<ll> dd(m);
    vector<ll> qq(m);
    rep(i, m){
        cin >> dd[i] >> qq[i]; dd[i]--; qq[i]--;
    }


    vector<ll> score(d+1);
    vector<vector<ll>> last(d+1, vector<ll>(26));
    rep(i, d){
        rep(j, 26){
            last[i+1][j] = last[i][j];
        }

        score[i+1] = score[i] + s[i][t[i]];
        last[i+1][t[i]] = i+1;
        
        ll down = 0;
        rep(j, 26){
            down += c[j] * ((i+1) - last[i+1][j]);
        }

        score[i+1] = score[i+1] - down;

    }
    
    rep(i, m){
        t[dd[i]] = qq[i];
        for(ll j = dd[i]; j < d; j++){
            rep(k, 26){
                last[j+1][k] = last[j][k];
            }

            score[j+1] = score[j] + s[j][t[j]];
            last[j+1][t[j]] = j+1;
            
            ll down = 0;
            rep(k, 26){
                down += c[k] * ((j+1) - last[j+1][k]);
            }

            score[j+1] = score[j+1] - down;

        }
        cout << score[d] << endl;
    }


}