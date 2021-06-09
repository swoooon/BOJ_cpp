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
pii arr[22];
double ans;

void DFS(int i, int cnt, int a, int b) {
    ct4(i, cnt, a, b);
    if (i == N) {
        ans = min(ans, sqrt(a*a+b*b));
        return;
    }
    if (cnt < N/2) {
        DFS(i+1, cnt+1, a+arr[i].first, b + arr[i].second);
    }
    if (i-cnt < N/2) {
        DFS(i+1, cnt, a-arr[i].first, b-arr[i].second);
    }
    
}


void solve() {
    cin >> N;
    ans = 987654321;
    for (int i = 0; i < N; i++) {
        double a, b; cin >> a>> b;
        arr[i] = {a, b};
    }
    DFS(0, 0, 0, 0);
    ct(ans);
}



int main() {
    FASTIO
    ll T; cin >> T;
    while (T--) solve();
} 