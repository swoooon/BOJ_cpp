#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;
typedef long long ll;
typedef pair<double, double> pdd;
ll gcd(ll a, ll b) {
    if (b) return gcd(b, a%b);
    return a;
}

ll ceil(ll a, ll b) {
    return (a-1)/b + 1;
}

int N;
pdd arr[101];
int uf[101];

void debug() {

}

int find(int a) {
    if (uf[a] == a) return a;
    return uf[a] == find(uf[a]);
}

int merge(int a, int b) {
    a = find(a);
    b = find(b);
    if (a == b) return 0;
    uf[b] = a;
    return 1;
}

struct St{
    double s, e, v;
};

bool compare(St &a, St &b) {
    return a.v < b.v;
}

vector<St> V;

void solve() {
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> arr[i].first;
        cin >> arr[i].second;
    }
    for (int i = 1; i <= N; i++) {
        uf[i] = i;
    }
    for (int i = 1; i < N; i++) {
        for (int j = i+1; j <= N; j++) {
            St k;
            k.s = i; k.e = j;
            k.v = sqrt((arr[i].first-arr[j].first)*(arr[i].first-arr[j].first)+(arr[i].second-arr[j].second)*(arr[i].second-arr[j].second));
            V.push_back(k);
        }
    }
    sort(V.begin(), V.end(), compare);
    double ans = 0;
    for (auto t : V) {
        if (merge(t.s, t.e)) ans += t.v; 
    }
    cout << ans << '\n';
}


int main() {
    FASTIO
    int T=1;
    while (T--) solve();
} 