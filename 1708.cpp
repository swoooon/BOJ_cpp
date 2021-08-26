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
#define xx first
#define yy second

const ll mod = 1e9+7;
int dy[4] = {1, 0, -1, 0}, dx[4] = {0, 1, 0, -1};


ll gcd(ll a, ll b) {
    if (b) return gcd(b, a%b);
    return a;
}

ll ceil(ll a, ll b) {
    return (a-1)/b + 1;
}

inline ll outer(const pii a, const pii b) {
    return a.xx*b.yy-a.yy*b.xx;
}

inline ll ccw(const pii& a, const pii  &b, const pii &c) {
    auto tmp = outer({b.xx-a.xx, b.yy-a.yy}, {c.xx-a.xx, c.yy-a.yy});
    return (tmp ? (tmp < 0 ? -1:1):0);
}

vector<pii> convex_hull(vector<pii>& dat) {
	if (dat.size() <= 2) return dat;
	vector<pii> upper, lower;
	sort(dat.begin(), dat.end(), [](const pii& a, const pii& b) {
		return (a.xx == b.xx) ? a.yy < b.yy : a.xx < b.xx;
	});
	for (const auto& p : dat) {
		while (upper.size() >= 2 && ccw(*++upper.rbegin(), *upper.rbegin(), p)
			>= 0) upper.pop_back();
		while (lower.size() >= 2 && ccw(*++lower.rbegin(), *lower.rbegin(), p)
			<= 0) lower.pop_back();
		upper.emplace_back(p);
		lower.emplace_back(p);
	}
	upper.insert(upper.end(), ++lower.rbegin(), --lower.rend());
	return upper;
}


void debug() {

}

int N;
void solve() {
    vector<pii> ps;
    cin >> N;
    for (int i = 0; i < N; i++) {
        int a, b; cin >> a >> b;
        pii c;
        c.xx = a, c.yy=b;
        ps.push_back(c);
    }
    auto ans = convex_hull(ps);
    int a = 0;
    ct(ans.size());

}




int main() {
    FASTIO
    ll T=1;
    while (T--) solve();
} 


