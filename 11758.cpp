#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;
#define ct(x) cout << x << '\n'

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



int ccw(int x1, int y1, int x2, int y2) {
    return x1*y2-x2*y1;
}

void solve() {
    int a1, a2, b1, b2, c1, c2;
    cin >> a1 >> a2 >> b1 >> b2 >> c1 >> c2;
    if (ccw(b1-a1, b2-a2, c1-a1, c2-a2) > 0) ct(1);
    else if (ccw(b1-a1, b2-a2, c1-a1, c2-a2) < 0) ct(-1);
    else ct(0);

}



int main() {
    FASTIO
    ll T=1;
    while (T--) solve();
} 