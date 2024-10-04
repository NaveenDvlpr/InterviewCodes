#include<bits/stdc++.h>
using namespace std;

void getInput(vector<int> &arr, int n) {
	for(int i = 0; i < n; i++) {
		int tmp;
		cin >> tmp;
		arr.push_back(tmp);
	}
}

int getSum(vector<int> &arr, int n) {
	int sum = 0;
	for(int i = 0; i < n; i++) sum += arr[i];
	cout << sum << endl;
	return sum;
}

void makeMap(int arrSum, int n, vector<int> &arr, unordered_map<int, int> &mp) {
	for(int i = 0; i < n; i++) {
		mp[arrSum]++;
		arrSum -= arr[i];
	}
}

int main() {
	int n;
	cin >> n;
	vector<int> s(n);
	for(int i = 0; i < n; i++) cin >> s[i];
	vector<int> st[n];
	for(int i = 0; i < n; i++) getInput(st[i], s[i]);
	
	unordered_map<int, int> mp;
	vector<int> arr_sum(n);
	for(int i = 0; i < n; i++) arr_sum[i] = getSum(st[i], s[i]);
	for(int i = 0; i < n; i++) makeMap(arr_sum[i], s[i], st[i], mp);
	
	int ans = 0;
	
	for(auto it: mp) {
		if(it.second == n && it.first > ans) ans = it.first;
	}
	
	cout << ans << endl;
}
