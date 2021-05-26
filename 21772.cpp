#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;

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
char arr[101][101];
int visited[101][101];
int ans = 0;



void dfs(int y, int x, int time, int cnt) {
    ans = max(ans, cnt);
    if (time == T) return;
    for (int i = 0; i < 4; i++) {
        int ry = y + dy[i], rx = x + dx[i];
        if (0 <= ry && ry < N && 0 <= rx && rx < M && !visited[ry][rx] && arr[ry][rx] != '#') {
            visited[ry][rx] = 1;
            if (arr[ry][rx] == 'S') dfs(ry, rx, time+1, cnt+1);
            else dfs(ry, rx, time+1, cnt);
            visited[ry][rx] = 0;
        }
    }
}

void solve() {
    cin >> N >> M >> T;
    for (int i = 0; i < N; i++) {
        for (int j = 0 ; j < M; j++) {
            cin >> arr[i][j];
        }
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0 ; j < M; j++) {
            if (arr[i][j] == 'G') {
                visited[i][j] = 1;
                dfs(i, j, 0, 0);
            }
        }
    }
    cout << ans << '\n';
}



int main() {
    FASTIO
    ll T=1;
    while (T--) solve();
} 