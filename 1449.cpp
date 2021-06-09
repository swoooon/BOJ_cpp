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

int N, M;
int arr[2020];
int num[2020];
void solve() {
    cin >> N >> M;
    int ans = 0;
    for (int i = 0; i < N; i++) {
        cin >> num[i];
    }
    sort(num, num+N);
    for (int i = 0; i < N; i++) {
        int a = num[i];
        if (arr[a] == 1) continue;
        else {
            for (int j = 0; j < M; j++) {
                arr[a+j] = 1;
            }
            ans++;
        }
    }
    ct(ans);
}



int main() {
    FASTIO
    ll T=1;
    while (T--) solve();
} 