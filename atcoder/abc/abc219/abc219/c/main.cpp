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

string x;
map<char, ll> mp;
//return a.first > b.first;
bool cmp(string a, string b){
    ll mi = min(a.size(), b.size());

    rep(i, mi){
        if(mp[a[i]] < mp[b[i]]){
            return true;
        }else if(mp[a[i]] > mp[b[i]]){
            return false;
        }
    }

    if(a.size() < b.size()){
        return true;
    }else{
        return false;
    }


}

int main() {
    std::cout << std::fixed << std::setprecision(15);
    cin >> x;
    ll n; cin >> n;
    vector<string> s(n);
    for(long long i = 0; i < n; i ++){
        cin >> s[i];
    }

    rep(i, x.size()){
        mp[x[i]] = i;
    }

    sort(all(s), cmp);

    rep(i, n){
        cout << s[i] << '\n';
    }
    /*
    for(auto i: mp){
        cout << i.first << " " << i.second << endl;
    }
    */

}