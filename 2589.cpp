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
int N, M;

int BFS(int y, int x) {
    queue<pii> q;
    q.push({y, x});
    int visit[55][55] = {0,};
    visit[y][x] = 1;
    int ans = 0;
    while (!q.empty()) {
        tie(y, x) = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            int ry = y + dy[i], rx = x + dx[i];
            if (0 <= ry && ry < N && 0 <= rx && rx < M && visit[ry][rx] == 0 && arr[ry][rx] == 'L') {
                visit[ry][rx] = visit[y][x] + 1;
                ans = max(ans, visit[ry][rx]-1);
                q.push({ry, rx});
            }
        }
    }
    return ans;
}


void solve() {
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) cin >> arr[i][j];
    }
    int ans = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (arr[i][j] == 'L') ans = max(ans, BFS(i, j));
        }
    }
    ct(ans);
}



int main() {
    FASTIO
    ll T=1;
    while (T--) solve();
} 