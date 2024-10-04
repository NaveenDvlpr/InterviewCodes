#include<bits/stdc++.h>
using namespace std;

int main() {
	string str;
	cin >> str;
	int strLen = str.length();
	int n;
	cin >> n;
	int a_count = 0;
	for(int i = 0; i < n; i++) {
		if(str[i] == 'a') a_count++;
	}
	int ans = n/strLen*a_count;
	n %= strLen;
	for(int i = 0; i<n; i++) {
		if(str[i] == 'a') ans++;
	}
	cout << ans << endl;
	return 0;
}
