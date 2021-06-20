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



void solve() {
    int a, b; cin >> a >> b;
    vector<int> v;
    int ans = 0;
    while (a) {
        v.push_back(a);
        a >>= 1;
    }
    while (b) {
        v.push_back(b);
        b >>= 1;
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < v.size()-1; i++) {
        if (v[i] == v[i+1]) ans = max(ans, v[i]);
    }
    ct(10*ans);
}



int main() {
    FASTIO
    ll T; cin >> T;
    while (T--) solve();
} 