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

struct UnionFind
{
    vector<long long> d;
    UnionFind(long long n = 0) : d(n, -1)
    {
    }

    //root : -size, not root: root
    long long root(long long x){
        if(d[x] < 0){
            return x; 
        }
        return d[x] = root(d[x]);
    }

    bool unite(long long x, long long y){
        x = root(x);
        y = root(y);
        if(x == y){
            return false;
        }
        if(d[x] > d[y]){
            swap(x, y);
        }
        d[x] += d[y];
        d[y] = x;
        return true;
    }

    long long size(long long x){
        return -d[root(x)];
    }

    bool issame(long long a, long long b){
        return root(a) == root(b);
    }
};

struct Edge
{
  int a, b, cost;

  // コストの大小で順序定義
  bool operator<(const Edge& o) const {
    return cost < o.cost;
  }
};


ll calc(vector<Edge> & vec, ll x){
    UnionFind uf(x);
    sort(all(vec));

    ll res = 0;
    rep(i, vec.size()){
        ll a = vec[i].a;
        ll b = vec[i].b;
        ll cost = vec[i].cost;

        if(uf.issame(a, b)){

        }else{
            uf.unite(a, b);
            res += cost;
        }
    }

    if(uf.size(0) == x){
        return res;
    }else{
        return INF;
    }

}   


int main() {
    std::cout << std::fixed << std::setprecision(15);
    ll n, m; cin >> n >> m;
    vector<ll> x(n);
    vector<ll> y(n);

    rep(i, n){
        cin >> x[i];
    }
    rep(i, n){
        cin >> y[i];
    }


    vector<Edge> vec;
    rep(i, m){
        Edge e;
        ll a, b, z; cin >> a >> b >> z;
        a--; b--;
        e.a = a; e.b = b; e.cost = z;
        vec.push_back(e);
    }

    ll ans = INF;

    // 道路だけ
    sort(all(vec));
    ll tmp = calc(vec, n);
    cerr << "road " << tmp << endl;
    ans = min(ans, tmp);

    
    vector<Edge> vec2;
    vec2 = vec;
    // 道路と港
    // 港n
    rep(i, n){
        Edge e;
        e.a = i; e.b = n; e.cost = y[i];
        vec2.push_back(e);
    }
    tmp = calc(vec2, n+1);
    cerr << "sail " << tmp << endl;
    ans = min(ans, tmp);



    // 道路と空港
    // 空港n
    rep(i, n){
        Edge e;
        e.a = i; e.b = n; e.cost = x[i];
        vec.push_back(e);
    }
    tmp = calc(vec, n+1);
    cerr << "air " << tmp << endl;
    ans = min(ans, tmp);



    // 道路と港と空港
    rep(i, n){
        Edge e;
        e.a = i; e.b = n+1; e.cost = y[i];
        vec.push_back(e);
    }
    tmp = calc(vec, n+2);
    cerr << "all " << tmp << endl;
    ans = min(ans, tmp);

    cout << ans << endl;

}