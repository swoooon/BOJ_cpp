#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;
typedef long long ll;

ll gcd(ll a, ll b) {
    if (b) return gcd(b, a%b);
    return a;
}

ll ceil(ll a, ll b) {
    return (a-1)/b + 1;
}

void debug() {

}

ll N;

void solve() {
    cin >> N;
    ll temp = N;
    ll ans = 0;
    vector<ll> prime;
    for (int i = 2; i < int(sqrt(N)+1); i++) {
        if (temp % i == 0) {
            prime.push_back(i);
            while (temp % i == 0) temp /= i;
        }
    }
    
    
    if (temp != 1) prime.push_back(temp);
    ll size = prime.size();
    for (ll bit = 1; bit < (1<<size); bit++) {
        ll intersect = 0, fac = 1;
        for (ll j = 0; j < size; j++) {
            if (bit & (1<<j)) intersect++, fac*=prime[j];
        }
        if (intersect % 2) ans += (N/fac);
        else ans -= (N/fac);
    }
    cout << N - ans << '\n';
}




int main() {
    FASTIO
    ll T=1;
    while (T--) solve();
} 