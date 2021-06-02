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

int N, Q;
int dist[101010];
int parent[101010][20];
int check[101010];
int depth[101010];
vector<int> adj[101010];
int candy[101010];
int dp[101010][6];


void DFS(int curr) {
    for (auto next: adj[curr]) {
        if (!check[next]) {
            depth[next] = depth[curr] + 1;
            dist[next] = dist[curr] + 1;
            check[next] = 1;
            parent[next][0] = curr;
            for (int i = 1; i <= 5; i++) {
                dp[next][i] = dp[curr][i];
            }
            dp[next][candy[next]]++;
            DFS(next);
        }
    }
}

int LCA(int u, int v) {
    if (depth[u] < depth[v]) swap(u, v);
    int diff = depth[u] - depth[v];
    for (int i = 0; diff; i++, diff >>=1) {
        if (diff % 2) u = parent[u][i];
    }
    if (u == v) return u;
    for (int j = 19; j >= 0; j--) {
        if (parent[u][j] != parent[v][j]) {
            u = parent[u][j];
            v = parent[v][j];
        }
    }
    return parent[u][0];
}

int judge(int u, int v, int c) {
    int cen = parent[LCA(u, v)][0];
    if (dp[u][c] + dp[v][c] > 2*dp[cen][c]) return 1;
    else return 0;
}


void solve() {
    cin >> N;
    for (int i = 1; i <= N; i++){
        cin >> candy[i];
    } 

    for (int i = 0; i < N-1; i++) {
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dp[1][candy[1]]++;
    check[1] = 1;

    DFS(1);
    for (int j = 1; j < 20; j++) {
        for (int i = 1; i <= N; i++) {
            parent[i][j] = parent[parent[i][j-1]][j-1];
        }
    }


    cin >> Q;
    Q--;
    int a, b;
    cin >> a >> b;
    int pre = a;
    int flag = 1;
    for (int i = 1; i <= N; i++) {
        if (candy[i] == b) {
            ct("PLAY");
            flag = 0;
            break;
        }
    }
    if (flag) ct("CRY");

    while (Q--) {
        cin >> a >> b;
        if (judge(pre, a, b)) ct("PLAY");
        else ct("CRY");
        pre = a;
    }

}



int main() {
    FASTIO
    ll T=1;
    while (T--) solve();
} 