#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#define all(v) v.begin(), v.end()

using namespace std;

int n, sum, cnt;
int main() {
	
	cin >> n;
	vector<int> v;
	v.resize(n);
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
	}
	sort(v.begin(), v.end());

	int rever = 0;
	for (int i = 0; i  + 2< v.size(); i++)
	{
		int tmp = v[i];
		sum = -tmp;
		int le = i + 1, ri = n -1;
		while (le < ri)
		{
			rever = v[le] + v[ri];
			if (rever + sum == 0) {  
				cnt++;
				if (v[le+1]-v[le] > v[ri] - v[ri-1]) ri--;
                else le++;
			}
			else if (rever + sum > 0)ri--;
			else if (rever + sum < 0)le++;
		}
	}
	cout << cnt;
	return 0;
}