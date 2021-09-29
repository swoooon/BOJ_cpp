#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;
#define all(x) x.begin(), x.end()
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
		if (pos == l && pos == r) return seg[idx] += val;
		int mid = (l + r) / 2;
		return seg[idx] = (
			upd_(idx * 2, l, mid, pos, val) +
			upd_(idx * 2 + 1, mid + 1, r, pos, val)
			);
	}
	ll calc_(int idx, int l, int r, int tl, int tr) {
		if (l > tr || r < tl) return 0;
		if (tl <= l && r <= tr) return seg[idx];
		int mid = (l + r) / 2;
		return (
			calc_(idx * 2, l, mid, tl, tr) +
			calc_(idx * 2 + 1, mid + 1, r, tl, tr)
			);
	}
	void upd(int pos, ll val) {
		upd_(1, 0, n-1, pos, val);
	}
	ll calc(int l, int r) {
		return calc_(1, 0, n-1, l, r);
	}
};

int cmp(pii a, pii b) {
    if (a.first == b.first) return a.second > b.second;
    return a.first < b.first;
}

vector<int> comp;

int find_idx(int a) {
    return lower_bound(all(comp), a) - comp.begin();
}

void solve() {
    int N; cin >> N;
    comp.clear();
    vector<pii> arr;

    for (int i = 0; i < N; i++) {
        int a, b; cin >> a >> b;
        comp.push_back(b);
        arr.push_back({a, b});
    }
    sort(arr.begin(), arr.end(), cmp);
    sort(comp.begin(), comp.end());
    comp.erase(unique(all(comp)), comp.end());
    int s = comp.size();
    SegmentTree seg(N);
    ll ans = 0;
    for (auto [x, y] : arr) {
        int idx = find_idx(y);

        ans += seg.calc(idx, s-1);
        seg.upd(idx, 1);
    }
    ct(ans);
}






int main() {
    FASTIO
    ll T; cin >> T;
    while (T--) solve();
} 