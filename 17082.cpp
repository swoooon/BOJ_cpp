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
		return seg[idx] = max(
			upd_(idx * 2, l, mid, pos, val),
			upd_(idx * 2 + 1, mid + 1, r, pos, val)
			);
	}
	ll calc_(int idx, int l, int r, int tl, int tr) {
		if (tl > tr) return 0;
		if (tl == l && tr == r) return seg[idx];
		int mid = (l + r) / 2;
		return max(
			calc_(idx * 2, l, mid, tl, min(tr, mid)),
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


ll arr[202020];
ll l[202020];
ll r[202020];
ll convert[202020];
map<ll, ll> m;

void solve() {
    ll N, M, Q; cin >> N >> M >> Q;
    for (ll i = 1; i <= N; i++) cin >> arr[i];
    for (ll i = 1; i <= M; i++) cin >> l[i];
    for (ll i = 1; i <= M; i++) cin >> r[i];
    sort(l+1, l+M+1);
    sort(r+1, r+M+1);
    ll flag = 0;
    for (ll i = 1; i <= M; i++) {
        if (l[i] <= r[i]) {
            m[l[i]]++, m[r[i]+1]--;
        }
        else {
            flag = 1;
        }
    }
    if (flag) {
        while (Q--) cout << 1000000000 << "\n";
        return;
    }
    ll tmp = 0;
    ll idx = 0;
    for (ll i = 1; i <= N; i++) {
        tmp += m[i];
        if (tmp) {
            convert[i] = ++idx;
        }
    }

    SegmentTree seg(idx);

    for (ll i = 1; i <= N; i++) {
        if (convert[i]) seg.upd(convert[i], arr[i]);
    }

    while (Q--) {
        ll a, b; 
        cin >> a >> b;
        if (convert[a] && convert[b]) {
            ll temp = arr[a];
            seg.upd(convert[a], arr[b]);
            arr[a] = arr[b];
            seg.upd(convert[b], temp);
            arr[b] = temp;
        }
        else if (convert[a]) {
            ll temp = arr[a];
            seg.upd(convert[a], arr[b]);
            arr[a] = arr[b];
            arr[b] = temp;
        }
        else if (convert[b]) {
            ll temp = arr[a];
            arr[a] = arr[b];
            seg.upd(convert[b], temp);
            arr[b] = temp;
        }
        else {
            ll temp = arr[a];
            arr[a] = arr[b];
            arr[b] = temp;
        }
        ct(seg.calc(1, idx));
    }
    

}



int main() {
    FASTIO
    ll T=1;
    while (T--) solve();
} 