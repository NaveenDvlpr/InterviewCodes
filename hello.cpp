#include<bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	int arr[n];
	for(int i = 0; i < n; i++) cin >> arr[i];
	unordered_map<int, int> mp;
	int ans = INT_MAX;
	for(int i = 0; i < n; i++) {
		int key = arr[i];
		if(mp[key] == 0) mp[key] = i+1;
		else {
			ans = min(ans, i+1-mp[key]);
			mp[key] = i+1;
		}
	}
	if(ans == INT_MAX) cout << "-1" << endl;
	else cout << ans << endl;
	return 0;
}
