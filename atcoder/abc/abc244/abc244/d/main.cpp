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

int main() {
    std::cout << std::fixed << std::setprecision(15);
    vector<char> s(3);
    vector<char> t(3);
    string S = "";
    string T = "";
    rep(i, 3){
        cin >> s[i];
        S += s[i];
    }
    rep(i, 3){
        cin >> t[i];
        T += t[i];
    }

    // cerr << S << endl;
    // cerr << T << endl;

    map<string, ll> mp;

    mp[S] = 0;
    queue<string> que;
    que.push(S);

    while(!que.empty()){
        string now = que.front();
        que.pop();

        string next = now;
        swap(next[0], next[1]);
        if(mp.count(next) == 0){
            mp[next] = mp[now] + 1;
            que.push(next);
        }

        next = now;
        swap(next[1], next[2]);
        if(mp.count(next) == 0){
            mp[next] = mp[now] + 1;
            que.push(next);
        }

        next = now;
        swap(next[0], next[2]);
        if(mp.count(next) == 0){
            mp[next] = mp[now] + 1;
            que.push(next);
        }

    } 

    // for(auto&i : mp ){
    //     cout << i.first << " " << i.second << endl;
    // }

    if((mp[T] % 2) == 0){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }





}