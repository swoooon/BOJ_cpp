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

ll N, arr[101010];

ll f(ll s, ll e) {
    if (s == e) return 0; 
    if (s+1 == e) return arr[s];

    ll mid = (s+e)/2;
    ll res = max(f(s, mid), f(mid, e));

    ll width = 1, hight = arr[mid], left = mid, right = mid;
    while (right - left + 1 < e - s) { //중앙부터 확장한 길이가 현재 보려고 하는 구간의 길이보다 길어지지 않는 선에서
        ll a = left > s ? min(hight, arr[left-1]): 0; //만약 left의 값이 현재 보려고 하는 부분 s보다 크다면 a에 값 대입
        ll b = right < e ? min(hight, arr[right+1]): 0; //동일
        if (a >= b) hight = a, left--; //만약 왼쪽으로 확장한 크기가 더 크다면 왼쪽으로 확장 
        else hight = b, right++;   
        res = max(res, ++width*hight);
    }
    return res;
}

void solve() {
    for (ll i = 0; i < N; i++) cin >> arr[i];
    cout << f(0, N) << '\n';
}



int main() {
    FASTIO
    while (1){
        cin >> N;
        if (!N) break;
        memset(arr, 0, sizeof(arr));
        solve();
    }
} 

