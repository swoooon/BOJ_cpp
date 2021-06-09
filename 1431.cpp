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
string arr[1010];

int cmp(string a, string b) {
    if (a.length() != b.length()) return a.length() < b.length();
    int aa = 0, bb = 0;
    for (int i = 0; i < a.length(); i++) {
        if ('0' <= a[i] && '9' >= a[i]) aa += a[i]-'0';
        if ('0' <= b[i] && '9' >= b[i]) bb += b[i]-'0';
    }
    if (aa != bb) return aa < bb;
    return a < b;
}

void solve() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    sort(arr, arr+N, cmp);
    for (int i = 0; i < N; i++) ct(arr[i]);
}



int main() {
    FASTIO
    ll T=1;
    while (T--) solve();
} 