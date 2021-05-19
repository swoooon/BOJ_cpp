#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;

const ll mod = 1e9+7;


ll gcd(ll a, ll b) {
    if (b) return gcd(b, a%b);
    return a;
}

ll ceil(ll a, ll b) {
    return (a-1)/b + 1;
}

void debug() {

}




int N, M, a, b;
int arr[200];
int dp[200];
void solve() {
    cin >> N >> M;
    memset(dp, -1, sizeof(dp));
    for (int i = 1; i < 200; i++) arr[i] = i;
    for (int i = 0; i < N+M; i++) {
        cin >> a >> b;
        arr[a] = b;
    }
    queue<pair<int, int>> que;
    int ans = 0;
    que.push({1, 0});
    while (!que.empty()) {
        tie(a, b) = que.front();
        dp[a] = b;
        if (a == 100) {
            ans = b;
            break;
        }
        que.pop();
        for (int i = 1; i < 7; i++) {
            if (arr[a + i] <= 100 && (dp[a]+1 < dp[arr[a+i]] || dp[arr[a+i]] == -1)) que.push({arr[a+i], b+1});
        }
    }
    cout << ans << '\n';
}



int main() {
    FASTIO
    ll T=1;
    while (T--) solve();
} 