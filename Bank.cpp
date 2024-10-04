#include<bits/stdc++.h>
using namespace std;

class Holder{
private:
	string Name;
	string ID;
	string AccountNumber;
	int Age;
public:
	Holder() {
		
	}
	Holder(string name, string id, string accountNumber, int age) {
		Name = name;
		ID = id;
		AccountNumber = accountNumber;
		Age = age;
	}
	string getName() {
		return Name;
	}
	void setName(string name) {
		Name = name;
	}
	string getID() {
		return ID;
	}
	void setID(string id) {
		ID = id;
	}
	string getAccountNumber() {
		return AccountNumber;
	}
	void setAccountNumber(string accountNumber) {
		AccountNumber = accountNumber;
	}
	int getAge() {
		return Age;
	}
	void setAge(int age) {
		Age = age;
	}
};

class Account{
private:
	string AccountNumber;
	int Balance;
	vector<string> Transactions;
public:
	Account() {
		
	}
	Account(string accountNumber, int balance) {
		AccountNumber = accountNumber;
		Balance = balance;
		if(balance != 0) {
			string amt = to_string(balance);
			Transactions.push_back("Credit of Rupees: "+amt);
		}
	}
	string getAccountNumber() {
		return AccountNumber;
	}
	void setAccountNumber(string accountNumber) {
		AccountNumber = accountNumber;
	}
	int getBalance() {
		return Balance;
	}
	void setBalance(int balance) {
		Balance = balance;
	}
	void addAmount(int amount) {
		Balance += amount;
		Transactions.push_back("Credited Rupees: "+to_string(amount));
	}
	bool getAmount(int withdrawalRequest) {
		if(withdrawalRequest <= Balance) {
			Balance -= withdrawalRequest;
			Transactions.push_back("Debited Rupees: "+to_string(withdrawalRequest));
			return true;
		} else {
			return false;
		}
	}
	void showTransactions() {
		cout << endl;
		if(Transactions.size() == 0) cout << "NO Transactions Yet!" << endl;
		for(auto transaction : Transactions) cout << transaction << endl;
		cout << endl << "Balance: " << Balance << endl;
	}
};

class Bank{
private:
	int AccountHolders;
	string BankCode;
	unordered_map<string, pair<Holder, Account>> Accounts;
public:
	Bank() {
		AccountHolders = 0;
		BankCode = "324578";
	}
	void createAccount(string name, string id, int age, int firstDeposit = 0) {
		AccountHolders++;
		string accountNumber = BankCode;
		if(AccountHolders < 100) accountNumber += "0";
		if(AccountHolders < 10) accountNumber += "0";
		accountNumber+=(to_string(AccountHolders));
		
		Holder H(name, id, accountNumber, age);
		Account A(accountNumber, firstDeposit);
		Accounts[id] = {H, A};
	}
	void  creditAmountToAccount(string id, int amount) {
		Accounts[id].second.addAmount(amount);
	}
	bool debitAmountFromAccount(string id, int amount) {
		return Accounts[id].second.getAmount(amount);
	}
	void showAccountTransactions(string id) {
		Accounts[id].second.showTransactions();
	} 
	int getAccountHoldesCount() {
		return AccountHolders;
	}
};


int main() {
	Bank B;
	while(1) {
		cout << endl << endl << B.getAccountHoldesCount() << " Customers have account in our Bank" << endl << endl;
		cout << "1.Create Account" << endl;
		cout << "2.Add Amount" << endl;
		cout << "3.WithDraw Amount" << endl;
		cout << "4.Show Transactions" << endl;
		cout << "5.Delete Account" << endl;
		int ch;
		cin >> ch;
		cout << endl;
		if(ch == 1) {
			string name, id;
			int age, deposit;
			cout << "Enter Your Name: ";
			getline(cin, name);
			cout << "Enter Your ID: ";
			cin >> id;
			cout << "Enter Your Age: ";
			cin >> age;
			cout << "Enter Your First Deposit: ";
			cin >> deposit;
			B.createAccount(name, id, age, deposit);
		} else if(ch == 2) {
			string id;
			cout << "Enter Your ID: ";
			cin >> id;
			int amount;
			cout << "Enter Your Amount: ";
			cin >> amount;
			B.creditAmountToAccount(id, amount);
			cout << endl << "Amount of rupees " << amount << " Credited Successfully" << endl;
		} else if(ch == 3) {
			string id;
			cout << "Enter Your ID: ";
			cin >> id;
			int amount;
			cout << "Enter Your Amount: ";
			cin >> amount;
			if(B.debitAmountFromAccount(id, amount)) cout << endl << "Withdrawal Successfull" << endl;
			else cout << endl << "Insufficient Funds" << endl;
		} else if(ch == 4){
			cout << endl << "Enter Your ID: ";
			string id;
			cin >> id;
			B.showAccountTransactions(id);
		} else {
			cout << "Choose A Valid Input" << endl;
		}
	} 
	
	return 0;
}
