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



const ld eps = 1e-9;
inline int diff(ld lhs, ld rhs) {
    if (lhs - eps < rhs && rhs < lhs + eps) return 0;
    return (lhs < rhs) ? -1:1;
}

inline bool is_between(ld check, ld a, ld b) {
    if (a < b) return (a - eps < check && check < b + eps);
    return (b - eps < check && check < a + eps);
}

struct Point {
    ld x, y;
    bool operator==(const Point& rhs) const {
        return diff(x, rhs.x) == 0 && diff(y, rhs.y) == 0;
    }
    Point operator+(const Point& rhs) const {
        return Point{x+rhs.x, y+rhs.y};
    }
    Point operator-(const Point& rhs) const {
        return Point{x-rhs.x, y-rhs.y};
    }
    Point operator*(ld t) const {
        return Point{x*t, y*t};
    }
};

struct Line {
    Point pos, dir;
};

inline ld inner(const Point&a, const Point& b) {
    return a.x*b.x+a.y*b.y;
}

inline ld outer(const Point&a, const Point& b) {
    return a.x*b.y-a.y*b.x;
}

inline int ccw_line(const Line& line, const Point& point) {
    return diff(outer(line.dir, point - line.pos),0);
}

inline int ccw(const Point& a, const Point& b, const Point& c) {
    return diff(outer(b-a, c-a), 0);
}

inline ld dist(const Point &a, const Point& b) {
    return sqrt(inner(a-b, a-b));
}

inline ld dist(const Line& line, const Point& point) {
    return abs((line.pos.x - line.dir.x) * (point.y - line.pos.y) - (point.x - line.pos.x) * (line.pos.y - line.dir.y)) / dist(line.pos, line.dir);
}


vector<Point> convex_hull(vector<Point>& dat) {
	if (dat.size() <= 2) return dat;
	vector<Point> upper, lower;
	sort(dat.begin(), dat.end(), [](const Point& a, const Point& b) {
		return (a.x == b.x) ? a.y < b.y : a.x < b.x;
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
    vector<Point> ps;
    for (int i = 0; i < N; i++) {
        int a, b; cin >> a >> b;
        Point c;
        c.x = a, c.y=b;
        ps.push_back(c);
    }
    auto cv = convex_hull(ps);
    ld ans = -1.;
    for (int i = 0; i < cv.size(); i++) {
        Line now;
        now.dir = cv[i];
        now.pos = cv[(i+1)%cv.size()];
        ld a = 0;
        for (int j = 0; j < N; j++) {
            ld b = dist(now, ps[j]);
            a = max(a, dist(now, ps[j]));
        }


        if (ans < 0) ans = a;
        ans = min(a, ans);
    }
    cout << fixed;
    cout.precision(2);
    ans -= eps;
    ans = ceil(ans*100)/100;
    ct(ans);
}


int main() {
    FASTIO
    ll T=1;
    while (1) {
        cin >> N;
        if (N == 0) return 0;
        cout << "Case " << T++ << ": ";
        solve();
    }
} 