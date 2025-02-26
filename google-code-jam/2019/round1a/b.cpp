#include <bits/stdc++.h>
typedef long long ll;
#define rep(i,n) for(ll i=0;i<(n);i++)
#define repr(i,n) for(ll i=(n-1);i>=0;i--)
#define pb push_back
#define mp make_pair
#define all(x) x.begin(),x.end()
#define br cout << "\n";
using namespace std;
const int INF = 1e9;
const int MOD = 1e9+7;
using Graph = vector<vector<ll>>;
template<class T> inline bool chmin(T &a, T b) { if(a > b){ a = b; return true;} return false;}
template<class T> inline bool chmax(T &a, T b) { if(a < b){ a = b; return true;} return false;}

// 0 false, 1 true 
// string to int : -48
// ceil(a)  1.2->2.0
// c++17	g++ -std=c++17 a.cpp

int main() {
    std::cout << std::fixed << std::setprecision(15);
    ll t, n, m; cin >> t >> n >> m;
    vector<ll> q = {8, 3, 5, 7, 11, 13, 17};

    rep(T, t){
        vector<ll> res(7);

        rep(i, 7){
            rep(j, 18){
                cerr << q[i] << " ";
                cout << q[i] << " ";
            }br;
            cerr << endl;
            flush(std::cout);

            ll tmp = 0;
            rep(j, 18){
                ll x; cin >> x;
                tmp += x; 
                cerr << x << " ";
            }
            cerr << endl;
            res[i] = tmp % q[i];
        }

        ll ans = 1;
        for(ll i = 1; i <= m; i++){
            bool f = true;
            for(ll j = 0; j < 7; j++){
                if( (i % q[j]) != res[j]){
                    f = false; break;
                }
            }
            if(f){
                ans = i; break;
            }
        }

        cout << ans << endl;
        cerr << ans << endl;
        flush(std::cout);
        ll x; cin >> x;
        if(x == -1){
            return 0;
        }

    }

}