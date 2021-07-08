#include <iostream>
#include <vector>
#include <algorithm>
#define FAST ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
typedef long long ll;
using namespace std;

typedef pair<int, int> pii;
vector<pii> v;
ll fenwick[2001];
ll N, M;

void update(ll index, ll val){
    while (index <= N) {
        fenwick[index] += val;
        index += index & -index;
    }
}

ll query(ll index){
    ll s = 0;
    while (index) {
        s += fenwick[index];
        index -= index & - index;
    }
    return s;
}

int main(){
    FAST;
    cin >> N >> M;
    int a, b, answer = 0;
    for (int i = 0; i < M; i++){
        cin >> a >> b;
        v.emplace_back(a,b);
    }
    sort(v.begin(), v.end());

    for (auto [A, B] : v){
        answer += query(N) - query(B);
        update(B, 1);
    }
    cout << answer;
    return 0;
}