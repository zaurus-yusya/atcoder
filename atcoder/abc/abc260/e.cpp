#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
typedef long long ll;
typedef long double ld;
#define rep(i,n) for(ll i=0;i<(n);i++)
#define repr(i,n) for(ll i=(n-1);i>=0;i--)
#define all(x) x.begin(),x.end()
#define br cout << '\n';
using namespace std;
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

using S = long long;
using F = long long;

const S INF = 8e18;

S op(S a, S b){ return std::min(a, b); }
S e(){ return INF; }
S mapping(F f, S x){ return f+x; }
F composition(F f, F g){ return f+g; }
F id(){ return 0; }

//宣言
//lazy_segtree<S, op, e, F, mapping, composition, id> seg(n); //e()で初期化
//lazy_segtree<S, op, e, F, mapping, composition, id> seg(vec); //vecの値で初期化
//seg.set(i, x); //i番目の値をxに更新
//seg.get(i); //i番目の要素を取得
//seg.prod(l, r); //[l, r)の区間のopを計算
//seg.all_prod(); //[0, n)の区間のopを計算
//seg.apply(l, r, f) //[l, r)に対してmappingを実施
//単位元 e()
//min: INF, max: -INF, 和: 0, 積: 1, xor: 0, gcd: 0, lcm: 1
//1点取得のとき、getじゃなくてprod(x, x+1)した方がいいかも
//区間和求める時は宣言方法が違うので「acl segtree チートシートでググる」


int main() {
    std::cout << std::fixed << std::setprecision(15);
    ll n, m; cin >> n >> m;
    vector<ll> a(n);
    vector<ll> b(n);
    lazy_segtree<S, op, e, F, mapping, composition, id> seg(m+10);
    rep(i, m+10){
        seg.set(i, 0);
    }

    map<ll, ll> mpa;
    map<ll, ll> mpb;
    rep(i, n){
        cin >> a[i] >> b[i];
        mpa[a[i]]++;
        mpb[b[i]]++;
    }


    ll right = 1;
    ll sum = 0;

    sum += mpa[1];
    sum += mpb[1];
    for(ll left = 1; left <= m; left++){
        cerr << "start " << left << " " << right << " " << sum << endl;

        while(right < m && sum < n){
            right++;
            sum += mpa[right];
            sum += mpb[right];
        }

        ll l = right - left + 1;
        ll r = m - left + 1;

        cerr << "left = " << left << " right = " << right << endl;
        cerr << "l = " << l << " r = " << r << endl;
        if(sum >= n){
            cerr << "ok" << endl;
            seg.apply(l, r+1, 1);
        }


        if(right == left){
            right++;
        }else{
            cerr << "minus" << endl;
            sum -= mpa[left];
            sum -= mpb[left];
        }

        
    }
    for(ll i = 1; i <= m; i++){
        cout << seg.get(i) << ' ';
    }br;

}