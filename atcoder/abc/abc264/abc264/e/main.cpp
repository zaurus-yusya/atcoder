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

//dijkstra
struct Edge
{
    ll u, v, id;
    Edge(ll u = 0, ll v = 0, ll id = 0) : u(u), v(v), id(id) {}
    //g[a].emplace_back(x, y) : x = to, y = cost
};

int main() {
    std::cout << std::fixed << std::setprecision(15);
    ll n, m, e; cin >> n >> m >> e;
    vector<vector<ll>> g(n+m);
    // [0, n): 都市, [n, n+m): 発電所

    vector<Edge> edge;
    rep(i, e){
        ll u, v; cin >> u >> v; u--; v--;
        // g[u].push_back(v);
        // g[v].push_back(u);
        edge.emplace_back(u, v, i);
    }

    ll q; cin >> q;
    map<ll, ll> mp;
    vector<ll> query(q);
    rep(i, q){
        ll x; cin >> x; x--;
        query[i] = x;
        mp[query[i]]++;
    }


    UnionFind uf(n+1);
    // nに繋がってるのが答え
    rep(i, e){
        if(mp[i] == 0){
            ll u = edge[i].u;
            ll v = edge[i].v;
            // cerr << u << " " << v << endl;
            if(u >= n) u = n;
            if(v >= n) v = n;
            uf.unite(u, v);
        }
    }

    vector<ll> ans;
    ans.push_back(uf.size(n));

    for(ll i = 0; i < q; i++){
        ll x = query[q-1-i];
        ll u = edge[x].u;
        ll v = edge[x].v;
        if(u >= n) u = n;
        if(v >= n) v = n;
        uf.unite(u, v);
        
        ans.push_back(uf.size(n));
    }

    reverse(all(ans));
    // vecdbg(ans);
    for(ll i = 0; i < ans.size(); i++){
        if(i == 0) continue;
        cout << ans[i]-1 << '\n';
    }
    // cout << uf.size(n) << endl;








}