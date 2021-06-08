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

int N, M, T;
int arr[1010][1010];
int visit[1010][1010];

void DFS(int y, int x) {
    for (int i = 0; i < 4; i++) {
        int ry = y + dy[i], rx = x + dx[i];
        if (0 <= ry && ry < N && 0 <= rx && rx < M && !visit[ry][rx] && arr[ry][rx] >= 3*T) {
            visit[ry][rx] = 1;
            DFS(ry, rx);
        }
    }
}

void solve() {
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            int temp=0;
            for (int k = 0; k < 3; k++) {
                int a; cin >> a;
                temp += a;
            }
            arr[i][j] = temp;
        }
    }
    cin >> T;
    int ans = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (!visit[i][j] && arr[i][j] >= 3*T) {
                ans++;
                DFS(i, j);
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