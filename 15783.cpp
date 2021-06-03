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
const int NMAX = 101010;

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

int N, M, cnt, dfsnode[NMAX], SN, sccnode[NMAX];
vector<int> adj[NMAX];
int finish[NMAX];
stack<int> st;
vector<vector<int>> SCC;
int indegree[NMAX];


int getSCC(int curr) {
    dfsnode[curr] = ++cnt;
    st.push(curr);

    int result = dfsnode[curr];
    for (auto next: adj[curr]) {
        if (dfsnode[next] == 0) result = min(result, getSCC(next));
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
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        int a, b; cin >> a>> b;
        a++,b++;
        adj[a].push_back(b);
    }
    cnt = SN = 0;
    for (int i = 1; i <= N; i++) {
        if (dfsnode[i] == 0) getSCC(i);
    }
    for (int i = 1; i <= N; i++) {
        for (auto j: adj[i]) {
            if (sccnode[i] != sccnode[j]) indegree[sccnode[j]]++;
        }
    }
    int ans = 0;
    for (int i = 0; i < SN; i++) {
        if (indegree[i] == 0) ans++;
    }
    ct(ans);
}



int main() {
    FASTIO
    ll T=1;
    while (T--) solve();
} 