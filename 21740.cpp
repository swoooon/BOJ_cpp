#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int mod = 1e9+7;


ll gcd(ll a, ll b) {
    if (b) return gcd(b, a%b);
    return a;
}

ll ceil(ll a, ll b) {
    return (a-1)/b + 1;
}



void debug() {

}

int toint(string a) {
    int ret = 0;
    for (auto i: a) ret = ret * 10 + int(i);
    return ret;
}

bool cmp(string a, string b) {return a+b > b+a;}

string reve(string a) {
    string ret = "";
    for (auto i: a) {
        if (i == '6') ret = '9' + ret;
        else if (i == '9') ret = '6' + ret;
        else ret = i + ret;
    }
    return ret;
}

int N;
string M = "0";
string arr[101010];

void solve() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        string a; cin >> a;
        arr[i] = reve(a);
        if (toint(M) < toint(arr[i])) M = arr[i];
    }
    arr[N] = M;
    sort(arr, arr+N+1, cmp);
    string ans = "";
    for (int i = N; i >= 0; i--) {
        cout << reve(arr[i]);
    }
}



int main() {
    FASTIO
    ll T=1;
    while (T--) solve();
} 

