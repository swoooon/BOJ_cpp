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

int N, M, Q;
int arr[1010][1010];

void solve() {
    cin >> N >> M;
    memset(arr, 10000, sizeof(arr));
    for (int i = 0; i < M; i++) {
        int a, b; cin >> a >> b;
        arr[a][b] = 1;
        arr[b][a] = 1;
    }
    for (int i = 1; i <= N; i++) arr[i][i] = 0;
    for(int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            for (int k = 1; k <= N; k++) {
                arr[j][k] = min(arr[j][k], arr[j][i] + arr[i][k]);
            }
        }
    }
    cin >> Q;
    while (Q--) {
        int a, b; cin >> a>> b;
        arr[a][b] = 1;
        arr[b][a] = 1;
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                arr[i][j] = min(arr[i][j], arr[i][a] + arr[a][b] + arr[b][j]);
                arr[i][j] = min(arr[i][j], arr[i][b] + arr[b][a] + arr[a][j]);
            }
        }
        for (int i = 1; i <= N; i++) {
            if (arr[i][1] < 1000000) cout << arr[i][1] << " ";
            else cout << -1 << " ";
        }
        cout << '\n';
    }
}



int main() {
    FASTIO
    ll T=1;
    while (T--) solve();
} 