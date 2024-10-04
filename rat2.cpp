#include<bits/stdc++.h>
using namespace std;

int main() {
	float f;
	cin >> f;
	
//	cout << f << endl;
	
	int t = f;
			
	int numr = ((int)(f*100000))%100000;
	int denom = 100000;

//	cout << numr << " " << denom << endl;
	
	while(numr%10 == 0 && denom%10 == 0) {
		numr/=10;
		denom/=10;
	}
	
	for(int i = 2; i < denom; i++) {
		while(numr%i == 0 && denom%i == 0) {
			numr /= i;
			denom /= i;
		}
	}
	if(f == (int)f) cout << f << endl;
	else cout << t << " " << numr << "/" << denom << endl;
	return 0;
}
