#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;
typedef long long ll;

const int mod = 1e9+7;


ll gcd(ll a, ll b) {
    if (b) return gcd(b, a%b);
    return a;
}

ll ceil(ll a, ll b) {
    return (a-1)/b + 1;
}




void debug() {

}

int convert(char a) {
    if (a < 'a') return a - 'A';
    return a - 'a'+26;
}


vector<int> adj[55];
int cap[55][55];
int flo[55][55];
void solve() {
    int N; cin >> N;
    for (int i = 0; i < N; i++) {
        char a, b; int c; cin >> a >> b >> c;
        int u = convert(a), v = convert(b);
        cap[u][v] = cap[v][u] += c;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int total = 0, S = 0, E = 25;
    while (1) {
        int prev[55];
        memset(prev, -1, sizeof(prev));
        queue<int> que;
        que.push(S);
        while (!que.empty() && prev[E] == -1) {
            int curr = que.front();
            que.pop();
            for (auto next : adj[curr]) {
                if (cap[curr][next]-flo[curr][next] > 0 && prev[next] == -1) {
                    que.push(next);
                    prev[next] = curr;
                    if (next == E) break;
                }
            }
        }
        if (prev[E] == -1) break;
        int flow = mod;
        for (int i = E; i !=S; i = prev[i]) {
            flow = min(flow, cap[prev[i]][i]-flo[prev[i]][i]);
        }
        for (int i = E; i != S; i= prev[i]) {
            flo[prev[i]][i] += flow;
            flo[i][prev[i]] -= flow;
        }
        total += flow;
    }
    cout << total << '\n';
}



int main() {
    FASTIO
    ll T=1;
    while (T--) solve();
} 

