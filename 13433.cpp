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
ld arr[9];
int p[9];
ld coord[9];
ld ans = 987654321111;

void solve() {
    cout << fixed;
    cout.precision(12);
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
    }
    for (int i =1; i <= N; i++) {
        p[i] = i;
    }
    do {
        for (int i = 2; i <= N; i++) {
            ld now = 0;
            for (int j = 1; j < i; j++) {
                now = max(now, coord[j]+sqrt(4*arr[p[j]]*arr[p[i]]));
            }
            coord[i] = now;
        }
        ans = min(ans, coord[N]);
    } while(next_permutation(p+1, p+1+N));
    ct(ans);
}



int main() {
    FASTIO
    ll T=1;
    while (T--) solve();
} 