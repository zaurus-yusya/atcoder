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
    ll test; cin >> test;
    rep(T, test){
        ll n; cin >> n;
        vector<string> a(n);
        for(long long i = 0; i < n; i ++){
            cin >> a[i];
        }

        ll ans = 0;
        string now = a[0];
        for(ll i = 1; i < n; i++){
            //cout << now << endl;

            if(now.size() < a[i].size()){
                now = a[i];
                continue;
            }else if(now.size() == a[i].size()){
                //桁数同じ
                bool f = true;
                for(ll j = 0; j < now.size(); j++){
                    if(now[j] < a[i][j]){
                        f = false; break;
                    }
                    if(now[j] > a[i][j]){
                        f = true; break;
                    }
                }
                if(f){
                    a[i] = a[i] + '0';
                    ans++;
                }
                now = a[i];
                continue;
            }else{
                //桁数a[i]の方が短い

                //接頭辞で比較して、a[i]の方が大きい場合、桁数分0を追加
                bool f = true;
                ll cnt = 0;
                for(ll j = 0; j < a[i].size(); j++){
                    if(now[j] < a[i][j]){
                        f = false; break;
                    }
                    if(now[j] > a[i][j]){
                        f = true; break;
                    }
                    cnt++;
                }

                if(!f){
                    ll x = now.size() - a[i].size();
                    for(ll j = 0; j < x; j++){
                        a[i] += '0';
                        ans++;
                    }
                    now = a[i];
                    continue;
                }

                
                if(cnt == a[i].size()){
                    //同じ場合
                    f = true;
                    string s;
                    for(ll j = 0; j < now.size() - a[i].size(); j++){
                        if(now[j + a[i].size()] != '9') f = false;
                        s += now[j + a[i].size()];
                    }

                    //残りの桁部分が全て9なら0をnow+1桁になるまで追加
                    if(f){
                        ll x = now.size() - a[i].size();
                        for(ll j = 0; j < x + 1; j++){
                            a[i] += '0';
                            ans++;
                        }
                        now = a[i];
                        continue;
                    }
                    //残りの桁部分が全て9ではないなら、残りの桁数分の数に+1した数をa[i]に付与
                    string t = s;
                    reverse(all(t));
                    ll add = 1;
                    for(ll j = 0; j < t.size(); j++){
                        ll num = t[j] - '0';
                        num += add;
                        if(num == 10){
                            t[j] = 0 + '0';
                            add = 1;
                        }else{
                            t[j] = num + '0';
                            add = 0;
                        }
                    }
                    reverse(all(t));
                    for(ll j = 0; j < t.size(); j++){
                        a[i] += t[j];
                        ans++;
                    }
                    now = a[i];
                    continue;
                }

                ll x = now.size() - a[i].size();
                for(ll j = 0; j < x + 1; j++){
                    a[i] += '0';
                    ans++;
                }
                now = a[i];
                continue;
            }


        }

        cout << "Case #" << (T+1) << ": " << ans << endl;
    }

}