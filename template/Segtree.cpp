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
#define all(x) x.begin(), x.end()


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
	ll upd_(int node, int l, int r, int target, ll val) {
		if (target < l || target > r) return seg[node];
		if (target == l && target == r) return seg[node] = val;
		int mid = (l + r) / 2;
		return seg[node] = (
			upd_(node * 2, l, mid, target, val) +
			upd_(node * 2 + 1, mid + 1, r, target, val)
			);
	}
	ll calc_(int node, int l, int r, int tl, int tr) {
		if (l > tr || r < tl) return 0;
		if (tl <= l && r <= tr) return seg[node];
		int mid = (l + r) / 2;
		return (
			calc_(node * 2, l, mid, tl, tr) +
			calc_(node * 2 + 1, mid + 1, r, tl, tr)
			);
	}
	void upd(int target, ll val) {
		upd_(1, 0, n-1, target, val);
	}
	ll calc(int l, int r) {
		return calc_(1, 0, n-1, l, r);
	}
};




void solve() {
	
}



int main() {
    FASTIO
    ll T=1;
    while (T--) solve();
} 