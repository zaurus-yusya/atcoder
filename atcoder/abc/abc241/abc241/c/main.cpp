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
// for(auto& i: mp) &&&&&&&&&&&&&

vector<ll> dy = {1, -1, 0, 0, -1, -1, 1, 1};
vector<ll> dx = {0, 0, 1, -1, -1, 1, -1, 1};

int main() {
    std::cout << std::fixed << std::setprecision(15);
    ll n; cin >> n;
    vector<vector<char>> vec(n, vector<char>(n));
    rep(i, n){
        rep(j, n){
            cin >> vec[i][j];
        }
    }

    for(ll i = 0; i < n; i++){
        for(ll j = 0; j < n; j++){
            
            for(ll k = 0; k < 8; k++){
                ll y = dy[k];
                ll x = dx[k];
                ll cnt = 0;
                bool f = true;

                for(ll l = 0; l < 6; l++){
                    //cout << i+y*l << " " << j + 
                    if((i + y * l) < 0 || (i + y * l) >= n){
                        f = false; break;
                    }
                    if((j + x * l) < 0 || (j + x * l) >= n){
                        f = false; break;
                    }
                    if(vec[i + y * l][j + x * l] == '#'){
                        cnt++;
                    }
                }

                if(f && cnt >= 4){
                    cerr << i << " " << j << " " << k << " " << cnt << endl;
                    cout << "Yes" << endl; return 0;
                }

            }

        }
    }

    cout << "No" << endl;

}