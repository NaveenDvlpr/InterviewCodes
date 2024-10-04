#include<bits/stdc++.h>
using namespace std;

class Employee {
public: 
	string EmpID;
	string MngrID;
	int YOJ;
	vector<string> Juniors;
	
	Employee(string empID, string mngrID, int yoj) {
		EmpID = empID;
		MngrID = mngrID;
		YOJ = yoj;
		cout << "Employee Mapped Successfully" << endl;
	}
	void updateJuniors(string jnr_id) {
		Juniors.push_back(jnr_id);
	}
};

class EmpMngSystem {
public:
	int EmployeeCount = 0;
	vector<Employee> Employees;
	unordered_map<string, int> EmpIndex;
	
	void addEmployee() {
		cout << "Enter Employee ID: " << endl;
		string emp_id;
		cin >> emp_id;
		cout << "Enter Manager ID: " << endl;
		string mngr_id;
		cin >> mngr_id;
		int yoj; 
		cout << "Year of Joining" << endl;
		cin >> yoj;
		if(mngr_id != "X" && EmpIndex[mngr_id] == 0) {
			cout << "No Manager Found" << endl;
			mngr_id = "X";
		} else {
			Employee e(emp_id,mngr_id,yoj);
			Employees.push_back(e);
			EmployeeCount++;
			EmpIndex[emp_id]=EmployeeCount;
			if(mngr_id != "X") {
				Employee mngr = Employees[EmpIndex[mngr_id]-1];
				mngr.updateJuniors(emp_id);	
			}
		}
	}
	
	
	
	void sameManager(string id1, string id2) {
		int e1i = EmpIndex[id1], e2i = EmpIndex[id2];
		if(e1i == 0) {
			cout << "Employye id1 not Exists in Record" << endl;
			return;	
		}
		if(e2i == 0) {
			cout << "Employee id2 not exists in Record" << endl;
			return;	
		} 
		Employee e1 = Employees[e1i-1];
		Employee e2 = Employees[e2i-1];
		if(e1.MngrID == e2.MngrID) cout << "YES, Same Manager" << endl;
		else cout << "Both have Different Manager" << endl;
	}
	int maximumReports() {
		int ans = 0;
		for(int i = 0; i < EmployeeCount; i++) {
			int n = Employees[i].Juniors.size();
			ans = max(n, ans);
		}
		return ans;
	}
};


int main() {
	EmpMngSystem ems;
	while(1) {
		cout << "1.Map Employee" << endl;
		cout << "2.Same Manager" << endl;
		cout << "3.Maximum Reports" << endl;
		cout << "4.Fire Employee" << endl;
		cout << "5.Organise Fest" << endl;
		cout << "6.Exit" << endl;
		int ch;
		cin >> ch;
		if(ch == 1) {
			ems.addEmployee();
		} else if(ch == 2) {
			cout << "Employee ID1" << endl;
			string emp1_id;
			cin >> emp1_id;
			cout << "Employee ID2" << endl;
			string emp2_id;
			cin >> emp2_id;
			ems.sameManager(emp1_id, emp2_id);
		} else if(ch == 3) {
			cout << ems.maximumReports() << " are the maximum direct reports" << endl;
		} else if(ch == 4) {
			
		} else if(ch == 5) {
			
		} else if(ch == 6) {
			
		} else {
			cout << endl << "Choose a valid Choice" << endl;
		}
	}
	
	
	return 0;
}
