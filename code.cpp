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
const ll NMAX = 2010101;
const ll mod = 1e9+7;
int dy[4] = {1, 0, -1, 0}, dx[4] = {0, 1, 0, -1};


ll gcd(ll a, ll b) {
    if (b) return gcd(b, a%b);
    return a;
}

ll ceil(ll a, ll b) {
    return (a-1)/b + 1;
}


class SegmentTree {
public:
	vector<ll> seg;
	int n;
	SegmentTree(int n) {
		seg.resize(4 * n + 5);
		this->n = n;
	}
	ll upd_(int idx, int l, int r, int pos, ll val) {
		if (pos < l || pos > r) return seg[idx];
		if (pos == l && pos == r) return seg[idx] = val;
		int mid = (l + r) / 2;
		return seg[idx] = (
			upd_(idx * 2, l, mid, pos, val) +
			upd_(idx * 2 + 1, mid + 1, r, pos, val)
			);
	}
	ll calc_(int idx, int l, int r, int tl, int tr) {
		if (tl > tr) return 0;
		if (tl == l && tr == r) return seg[idx];
		int mid = (l + r) / 2;
		return (
			calc_(idx * 2, l, mid, tl, min(tr, mid)) +
			calc_(idx * 2 + 1, mid + 1, r, max(mid + 1, tl), tr)
			);
	}
	void upd(int pos, ll val) {
		upd_(1, 1, n, pos, val);
	}
	ll calc(int l, int r) {
		return calc_(1, 1, n, l, r);
	}
};



void solve() {
    int N, Q; cin >> N >> Q;
    string s; cin >> s;

    SegmentTree odd(N+1), even(N+1);

    for (int i = 0; i < N; i++) {
        if ((i+1)%2) odd.upd(i+1, '+' == s[i] ? 1: -1);
        else even.upd(i+1, '+' == s[i] ? 1: -1);
    }

    while (Q--) {
        int a, b; cin >> a >> b;
        ll ans = abs(odd.calc(a, b) - even.calc(a, b));
        if (ans == 0) ct(0);
        else if (ans%2) ct(1);
        else ct(2);
    }
    
}



int main() {
    FASTIO
    ll T; cin >> T;
    while (T--) solve();
} 