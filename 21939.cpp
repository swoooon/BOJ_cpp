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

int N, M;
map<int, int> d;
priority_queue<pii> minque;
priority_queue<pii> maxque;
priority_queue<pii> dminque;
priority_queue<pii> dmaxque;

void solve() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        int a, b; cin >> a>> b;
        d[a] = b;
        minque.push({-b, -a});
        maxque.push({b, a});
    }
    cin >> M;
    for (int i = 0; i < M; i++) {
        string s; cin >> s;
        if (s == "add") {
            int a, b; cin >> a>> b;
            if (d[a] == 0) d[a] = b;
            else {
                dminque.push({-d[a], -a});
                dmaxque.push({d[a], a});
                d[a] = b;
            }
            minque.push({-b, -a});
            maxque.push({b, a});
        }
        else if (s == "solved") {
            int a; cin >> a;
            dminque.push({-d[a], -a});
            dmaxque.push({d[a], a});
        }
        else {
            int a; cin >> a;
            if (a == 1){
                while (dmaxque.size() && maxque.top().first == dmaxque.top().first && maxque.top().second == dmaxque.top().second) {
                    maxque.pop();
                    dmaxque.pop();
                }
                ct(maxque.top().second);
            }
            else {
                while (dminque.size() && minque.top().first == dminque.top().first && minque.top().second == dminque.top().second) {
                    minque.pop();
                    dminque.pop();
                }
                ct(-minque.top().second);
            }
        }
    }
}



int main() {
    FASTIO
    ll T=1;
    while (T--) solve();
} 