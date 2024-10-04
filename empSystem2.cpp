#include<bits/stdc++.h>
using namespace std;

struct Details {
	string mngr_id;
	int yoj;
	vector<string> juniors;
	int level;
};

takeInput(int n, unordered_map<string, Details> &emps) {
	while(n--) {
		string emp_id, mngr_id;
		int yoj;
		cin >> emp_id >> mngr_id >> yoj;
		Details details;
		details.mngr_id = mngr_id;
		details.yoj = yoj;
		if(mngr_id == "X") {
			details.level = 1;	
		}
		else {
			details.level = emps[mngr_id].level+1;
			emps[mngr_id].juniors.push_back(emp_id);	
		}
		emps[emp_id] = details;
	}
}

bool sameManager(string emp1, string emp2, unordered_map<string, Details> &emps) {
	return emps[emp1].mngr_id == emps[emp2].mngr_id;
}

int maximumReports(unordered_map<string, Details> &emps) {
	int ans = 0;
	for(auto details : emps) {
		int s = details.second.juniors.size();
		ans = max(s, ans);
	}
	return ans;
}

void fire(string emp, unordered_map<string, Details> &emps) {
	vector<string> &juniors = emps[emp].juniors;
	int  yoj = INT_MAX;
	string senior_junior;
	for(auto junior : juniors) {
		if(emps[junior].yoj < yoj) {
			senior_junior = junior;
			yoj = emps[junior].yoj;
		}
	}
	emps[senior_junior].mngr_id = emps[emp].mngr_id;
	for(auto junior: juniors) {
		if(junior == senior_junior) continue;
		else {
			emps[junior].mngr_id = senior_junior;
			emps[senior_junior].juniors.push_back(junior);	
		}
	}
	auto it = emps.find(emp);
	emps.erase(it);
	emps[senior_junior].level--;
	for(auto junior : emps[senior_junior].juniors) {
		emps[junior].level--;
	}
}

int minimumGrps(unordered_map<string, Details> &emps) {
	int ans = 0;
	for(auto details : emps) {
		ans = max(ans, details.second.level);
	}
	return ans;
}

int main() {	
	int n;
	cin >> n;
	unordered_map<string, Details> emps;
	takeInput(n, emps);
	cout << sameManager("zh101","zh102", emps) << endl;
	cout << maximumReports(emps) << endl;
	cout << minimumGrps(emps) << endl;
	fire("zh100", emps);	
	cout << sameManager("zh102", "zh103", emps) << endl;
	cout << maximumReports(emps) << endl;
	cout << minimumGrps(emps) << endl;
	return 0;
}
