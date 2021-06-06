#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;
typedef long double ld;
#define ct(x) cout << x << '\n'
#define ct2(x, y) cout << x << ' ' << y << '\n'
#define ct3(x, y, z) cout << x << ' ' << y << ' ' << z << '\n'
#define ct4(x, y, z, w) cout << x << ' ' << y << ' ' << z << ' ' << w << '\n'

const ll mod = 1e9+7;
int dy[4] = {1, 0, -1, 0}, dx[4] = {0, 1, 0, -1};


ll gcd(ll a, ll b) {
    if (b) return gcd(b, a%b);
    return a;
}

ll ceil(ll a, ll b) {
    return (a-1)/b + 1;
}

void debug() {

}



vector<int> adj[12];


void solve() {
    for (int i = 0; i < 12; i++) {
        int a, b; cin >> a>> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for (int i = 1; i <= 12; i++) {
        if (adj[i].size() == 3) {
            int cnt = 0;
            for (auto a: adj[i]) {
                cnt += adj[a].size();
            }
            if (cnt == 6) {
                ct(i);
                return;
                
            }
        }
    }
}



int main() {
    FASTIO
    ll T=1;
    while (T--) solve();
} 