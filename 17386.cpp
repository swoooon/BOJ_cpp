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


ll ccw(ll x1, ll y1, ll x2, ll y2) {
    if (x1*y2 - x2*y1 > 0) return 1;
    else if (x1*y2 == x2*y1) return 0;
    else return -1;
}

void solve() {
    ll a, b, c, d, e, f, g, h;
    cin >>a>>b>>c>>d>>e>>f>>g>>h;
    ct(((ccw(c-a, d-b, e-a, f-b)*ccw(c-a, d-b, g-a, h-b) <= 0) && (ccw(g-e, h-f, a-e, b-f)*ccw(g-e, h-f, c-e, d-f) <= 0)));
    //ct4(ccw(c-a, d-b, e-a, f-b), ccw(c-a, d-b, g-a, h-b) , ccw(g-e, h-f, a-e, b-f), ccw(g-e, h-f, c-e, d-f));


}



int main() {
    FASTIO
    ll T=1;
    while (T--) solve();
} 