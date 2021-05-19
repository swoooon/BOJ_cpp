#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;

const ll mod = 1e9+7;
int dy[4] = {1 , 0, -1, 0}, dx[4]={0, 1, 0, -1}, ddy[8] = {1 ,0 ,-1 ,0, 1, 1, -1, -1}, ddx[8] = {0, 1, 0, -1, 1, -1, 1, -1};


ll gcd(ll a, ll b) {
    if (b) return gcd(b, a%b);
    return a;
}

ll ceil(ll a, ll b) {
    return (a-1)/b + 1;
}

void debug() {

}



ll N, L, R;
ll arr[20];

void solve() {
    cin >> N >> L >> R;
    for (ll i = 0; i < N; i++) cin >> arr[i];
    ll ans = 0;
    for (ll bit = 1; bit < (1<<N); bit++) {
        ll temp = 1, flag = 1, cnt = 0;
        for (ll i = 0; i < N; i++) {
            if ((1<<i) & bit) {
                temp = temp*arr[i]/gcd(arr[i], temp);
                cnt++;
                if (temp > R) {
                    flag = 0; 
                    break;
                }
            }
        }
        if (!flag) continue;
        if (cnt & 1) ans += R/temp - (L-1)/temp;
        else ans -= R/temp - (L-1)/temp;
    }
    cout << ans << '\n';
}



int main() {
    FASTIO
    ll T=1;
    while (T--) solve();
} 

/*

10 1 1000000000
999999999 999999998 999999997 999999996 999999995 999999994 999999993 999999992 999999991 999999990

*/