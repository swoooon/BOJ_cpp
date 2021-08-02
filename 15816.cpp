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
#define all(x) x.begin(), x.end()

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
		upd_(1, 0, n - 1, pos, val);
	}
	ll calc(int l, int r) {
		return calc_(1, 0, n - 1, l, r);
	}
};


int N, M;
ll cmd[1010101][3];
vector<ll> com;

int l_idx(int x) {
    return lower_bound(all(com), x) - com.begin()+2;
}

int r_idx(int x) {
    return upper_bound(all(com), x) - com.begin()+1;
}

void solve() {
    cin >> N;
    vector<ll> arr(N);
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
        com.push_back(arr[i]);
    }
    cin >> M;
    for (int i = 0; i < M; i++) {
        cin >> cmd[i][0];
        if (cmd[i][0] == 1) {
            cin >> cmd[i][1];
            com.push_back(cmd[i][1]);
        }
        else {
            cin >> cmd[i][1] >> cmd[i][2];
        }
    }
    sort(all(com));
    com.erase(unique(all(com)), com.end());
    int s = com.size();
    SegmentTree seg(s+2);
    for (int i = 0; i < N; i++) {
        int idx = l_idx(arr[i]);
        seg.upd(idx, 1);
    }
    for (int i = 0; i < M; i++) {
        int idx = l_idx(cmd[i][1]);
        if (cmd[i][0] == 1) {
            seg.upd(idx, 1);
        }
        else {
            int ridx = r_idx(cmd[i][2]);
            ll ans = cmd[i][2] - cmd[i][1] + 1 + seg.calc(0, idx-1) - seg.calc(0, ridx);
            ct(ans);
        }
    }
}



int main() {
    FASTIO
    ll T=1;
    while (T--) solve();
} 