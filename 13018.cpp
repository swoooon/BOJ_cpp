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

int a, b;

void solve() {
    cin >> a>> b;
    if (a == b) {
        ct("Impossible");
        return;
    }
    for (int i = 2; i <= a-b; i++) {
        cout << i << " ";
    }
    cout << 1 << " ";
    for (int i = a-b+1; i <= a; i++) {
        cout << i << " ";
    }
}



int main() {
    FASTIO
    ll T=1;
    while (T--) solve();
} 