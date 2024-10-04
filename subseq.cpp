#include<bits/stdc++.h>
using namespace std;

bool subseq(string str1, string str2) {
	int l1 = str1.length(), l2 = str2.length();
	int req = 0;
	for(int i = 0; i < l2; i++) {
		if(str2[i] == str1[req]) req++;
 	}
 	if(req == l1) return true;
 	else return false;
}


int main() {
	string str1, str2;
	cin >> str1 >> str2;
	if(subseq(str1, str2)) cout << "YES" << endl;
	else cout << "NO" << endl;
}
