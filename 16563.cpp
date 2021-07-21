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
int arr[1010101];
int p[5000005];

void solve() {
    cin >> N; 
    for (int i = 1; i <= 5000001; i++) p[i] = i;
    for (int i = 2; i <= int(sqrt(5000000+1)); i++) {
        if (p[i] == i) {
            for (int j = i+i; j <= 5000000+1; j+=i) {
                if (p[j] == j) p[j] = i;
            }
        }
    }
    for (int i = 1; i <= N; i++) {
        int a; cin >> a;
        while (a != 1) {
            cout << p[a] << " ";
            a /= p[a];
        }
        cout << "\n";
    }
    
}



int main() {
    FASTIO
    ll T=1;
    while (T--) solve();
} 