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


struct SegmentTree {
	vector<ll> seg;
	int n;
	SegmentTree(int n) {
		seg.resize(4 * n + 5);
		this->n = n;
	}
	ll upd_(int idx, int l, int r, int pos, ll val) {
		if (pos < l || pos > r) return seg[idx];
		if (pos == l && pos == r) return seg[idx] += val; // += , =
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

int q;

void solve() {
    SegmentTree seg(1000000);


    cin >> q;
    for (int i = 0; i < q; i++) {
        int a; cin >> a;
        if (a == 1) {
            int b; cin >> b;
            int l = 1, r = 1000000;
            int can = 0;
            while (l <= r) {
                int mid = (l+r)/2;
                if (seg.calc(1, mid) >= b) {
                    can = mid;
                    r = mid-1;
                }
                else l = mid+1;
            } 
            seg.upd(can, -1);
            ct(can);
        }
        else {
            int b, c; cin >> b >> c;
            seg.upd(b, c);
        }
    }
}



int main() {
    FASTIO
    ll T=1;
    while (T--) solve();
} 