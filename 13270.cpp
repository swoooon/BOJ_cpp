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

int N;
int dp[101010];
int dp1[101010];
int dp2[101010];
vector<int> fibo;

int dfs1(int n) {
    if (n == 2) return 1;
    if (n == 3) return 2;
    int &ret = dp1[n];
    if (ret) return ret;
    int a = 0;
    for (int i: fibo) {
        if (n - i > 1) a = max(a, dp[i]+dfs1(n-i));
        else if (n < i) break;
    }
    ret += a;
    return ret;
}

int dfs2(int n) {
    if (n == 2) return 1;
    if (n == 3) return 2;
    int &ret = dp2[n];
    if (ret) return ret;
    int a = 101010100;
    for (int i: fibo) {
        if (n - i > 1) a = min(a, dp[i]+dfs2(n-i));
        else if (n < i) break;
    }
    ret += a;
    return ret;
}


void solve() {
    cin >> N;
    fibo.push_back(2);
    fibo.push_back(3);
    dp[2] = 1;
    dp[3] = 2;
    for (int i = 2;;i++) {
        int a = fibo[i-1] + fibo[i-2];
        if (a > N) break;
        fibo.push_back(a);
        dp[a] = fibo[i-1];
    }
    ct2(dfs2(N),dfs1(N));
    
}



int main() {
    FASTIO
    ll T=1;
    while (T--) solve();
} 