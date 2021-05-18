#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;
typedef long long ll;

const int mod = 1e9+7;

struct Matrix{
	int size;
	vector< vector<ll> > arr;
	Matrix(){size = 0;}
	Matrix(int n){
		size = n;
		arr = vector< vector<ll> >(n, vector<ll>(n));
	}
	Matrix operator * (const Matrix &x){
		Matrix ret(size);
		for(int i=0; i<size; i++){
			for(int j=0; j<size; j++){
				for(int k=0; k<size; k++){
					ret.arr[i][j] += arr[i][k] * x.arr[k][j];
					ret.arr[i][j] %= mod;
				}
			}
		}
		return ret;
	}
};

Matrix powmat(Matrix a, ll b){
	if(b == 1) return a;
	Matrix ret = powmat(a, b/2);
	ret = ret * ret;
	if(b & 1) ret = ret * a;
	return ret;
}