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

int V, E, cnt, dfsnode[10101], SN, sccnode[10101];
vector<int> adj[10101];
int finish[10101];
stack<int> st;
vector<vector<int>> SCC;


int DFS(int curr) {
    dfsnode[curr] = ++cnt;
    st.push(curr);

    int result = dfsnode[curr];
    for (auto next: adj[curr]) {
        if (dfsnode[next] == 0) result = min(result, DFS(next));
        else if (!finish[next]) result = min(result, dfsnode[next]); 
    }

    if (result == dfsnode[curr]) {
        vector<int> currSCC;

        while (1) {
            int t = st.top(); st.pop();
            currSCC.push_back(t);
            finish[t] = 1;
            sccnode[t] = SN;
            if (t == curr) break;
        }
        sort(currSCC.begin(), currSCC.end());
        SCC.push_back(currSCC);
        SN++;
    }
    return result;
} 

void solve() {
    cin >> V >> E;
    for (int i = 0; i < E; i++) {
        int a, b; cin >> a>> b;
        adj[a].push_back(b);
    }
    
    for (int i = 1; i <= V; i++) {
        if (dfsnode[i] == 0) DFS(i);
    }

    sort(SCC.begin(), SCC.end());
    ct(SN);
    for (auto i: SCC) {
        for (auto ans: i) cout << ans << ' ';
        ct(-1);
    }
}



int main() {
    FASTIO
    ll T=1;
    while (T--) solve();
} 