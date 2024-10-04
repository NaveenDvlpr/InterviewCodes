#include<bits/stdc++.h>
using namespace std;

bool isRational(float f) {
	if(f == (int) f) return false;	
	else return true;
}

int range(int n) {
	int tmp = n;
	int d = 1;
	while(tmp) {
		d*=10;
		tmp/=10;
	}
	return d;
}

int decimalPart(float f) {
	int ans = 0;
	while(isRational(f)) {
		int tmp = f*10;
		int point1 = tmp%10;
		cout << point1 << " -" << endl;
		ans = ans*10+point1;
		f*=10;	
	}
	return ans;
}


int main() {
 	float f;
	cin >> f;
	
	cout << f*100000 << endl;
	
	if(!isRational(f)) cout << f << " " << endl;
	else {
		int num = decimalPart(f);
		int denom = range(num);
		for(int i = 2; i < denom; i++) {
			if(denom%i==0 && num%i == 0) {
				denom/=i;
				num/=i;
			}
		}
		cout << (int)f << " " << num << "/" << denom << endl;
	}	
	return 0;
}
