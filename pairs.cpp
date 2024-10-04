#include<bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	int arr[n];
	for(int i = 0; i < n; i++) cin >> arr[i];
	unordered_map<int, int> mp;
	for(int i = 0; i < n; i++) mp[arr[i]]++;
	int ans = 0;
	for(auto it : mp) {
		ans += (it.second)/2;
	}
	cout << ans << endl;
	return 0;
}
