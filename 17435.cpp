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
int m, q, n, x;
int nex[202020][20];


void solve() {
    cin >> m;
    for (int i = 1; i <= m; i++) cin >> nex[i][0];
    for (int j = 1; j < 20; j++) {
        for (int i = 1; i <= m; i++) {
            nex[i][j] = nex[nex[i][j-1]][j-1];
        }
    }

    cin >> q;
    while (q--) {
        cin >> n >> x;
        for (int j = 0; j < 20; j++) {
            if (n & (1<<j)) {
                n -= 1<<j;
                x = nex[x][j];
            }
        }
        ct(x);
    }
}



int main() {
    FASTIO
    ll T=1;
    while (T--) solve();
} 