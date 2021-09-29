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
const ll NMAX = 101010;
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


class MergesortTree {
public:
	vector<vector<int>> seg;
	int n;
	MergesortTree(int n) {
		seg.resize(4 * 2 * n + 5);
		this->n = n;
	}

    void do_sort() {
        for (int i = 0; i < 2*n; i++) sort(all(seg[i]));}

	void upd_(int node, int l, int r, int target, ll x) {
		if (target < l || target > r) return;
        seg[node].push_back(x);
		if (target == l && target == r) return;
		int mid = (l + r) / 2;
		upd_(node * 2, l, mid, target, x);
		upd_(node * 2 + 1, mid + 1, r, target, x);
	}

	ll calc_(int node, int l, int r, int tl, int tr, int x) {
		if (l > tr || r < tl) return 0;
		if (tl <= l && r <= tr) return upper_bound(all(seg[node]), x) - seg[node].begin();
		int mid = (l + r) / 2;
		return (
			calc_(node * 2, l, mid, tl, tr, x) +
			calc_(node * 2 + 1, mid + 1, r, tl, tr, x)
			);
	}


	void upd(int target, ll val) {
		upd_(1, 0, n-1, target, val);
	}
	ll calc(int l, int r, int x) {
		return calc_(1, 0, n-1, l, r, x);
	}
};




void solve() {
	int N, Q; cin >> N >> Q;
    MergesortTree seg(N);
    for (int i = 0; i < N; i++) {
        int a; cin>> a;
        seg.upd(i, a);
    }

    seg.do_sort();

    while (Q--) {
        int a, b, c; cin >> a >> b >> c;
        int l = -1e9, r = 1e9;
        int ans = 0;
        while (l <= r) {
            int mid = (l+r)/2;
            if (seg.calc(a-1, b-1, mid) < c) l = mid+1;
            else ans = mid, r = mid-1;
        }
        ct(ans);
    }

}



int main() {
    FASTIO
    ll T=1;
    while (T--) solve();
} 