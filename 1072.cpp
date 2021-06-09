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

ll N, M;

void solve() {
    cin >> N >> M;
    ll ori = (M*100)/N;
    ll ans = 0;
    if (ori >= 100) {
        ct(-1);
        return;
    }
    ll l = 1, r = 10101010101;
    while (l <= r) {
        ll mid = (l+r)/2;
        ll k = (M + mid)*100/(N+mid);
        if (ori <= k) r = mid -1, ans = mid;
        else l = mid + 1;
    }
    ct(ans);
}



int main() {
    FASTIO
    ll T=1;
    while (T--) solve();
} 