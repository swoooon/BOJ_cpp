#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;
typedef long double ld;
#define ct(x) cout << x << '\n'

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
pii arr[10101];

ld ccw(ld x1, ld y1, ld x2, ld y2) {
    return x1*y2-x2*y1;
}

void solve() {
    cin >> N;
    for (int i=0; i < N; i++) {
        cin >> arr[i].first >> arr[i].second;
    }
    ld temp = 0;
    for (int i = 1; i < N-1; i++) {
        temp += ccw(arr[i].first-arr[0].first, arr[i].second-arr[0].second, arr[i+1].first-arr[0].first, arr[i+1].second-arr[0].second);
    }
    cout << fixed;
    cout.precision(1);
    temp /= 2;
    ct(abs(temp));
}



int main() {
    FASTIO
    ll T=1;
    while (T--) solve();
} 