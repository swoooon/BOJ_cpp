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

char arr[55][55];
int N, K;
void solve() {
    cin >> N >> K;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < K; j++) cin >> arr[i][j];
    }
    int ans = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < K; j++) {
            for (int k = 0; k < 50; k++) {
                if (i+k >= N || j+k >= K) break;
                if (arr[i][j] != arr[i][j+k]) continue;
                if (arr[i][j+k] != arr[i+k][j]) continue;
                if (arr[i+k][j] != arr[i+k][j+k]) continue;
                ans = max(ans, (k+1)*(k+1));
            }
        }
    }
    ct(ans);
}



int main() {
    FASTIO
    ll T=1;
    while (T--) solve();
} 