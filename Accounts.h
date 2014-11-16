#ifndef ACCOUNTS_H_
#define ACCOUNTS_H_

#include<queue>
#include<string>
#include<iostream>
#include<fstream>
using namespace std;

class Accounts {
public:
	Accounts();
	virtual ~Accounts();

//MUTATORS/////////////////////////////////////////////////////////////////////
	//upon successful login,
	//a new username and password will be added to the queue
	void SignUp();

//ACCESSORS////////////////////////////////////////////////////////////////////
	//returns true if login was successful
	bool LogIn();
	//updates the current account text file
	void CloseAccounts();
	//returns the current total number of accounts
	int  GetTotAccounts();
	//returns true if passed in string matched username or password in queue
	bool SearchAccounts(string username);
	//displays the current contents of the queue
	void Print();

private:
	queue<string> accInfo;
	int totalAccounts;
};
void LogIn(Accounts &masterAccounts);
#endif /* ACCOUNTS_H_ */
