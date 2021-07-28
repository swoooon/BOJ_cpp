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

int arr[22];
int N, K;

void solve() {
    cin >> N >> K;
    int ans = 0;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    for (ll bit = 1; bit < (1<<N); bit++) {
        ll temp = 0;
        for (ll i = 0; i < N; i++) {
            if ((1<<i) & bit) temp += arr[i];
        }
        if (temp == K) ans++;
    } 
    ct(ans);
}



int main() {
    FASTIO
    ll T=1;
    while (T--) solve();
} 