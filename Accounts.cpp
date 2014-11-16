#include "Accounts.h"

//creating an account will generate a queue of account names and passwords
Accounts::Accounts()
{
	string fileUsername;
	string filePassword;
	totalAccounts = 0;

	ifstream inFile;
	inFile.open("accountInformation.txt");

	//has created a queue of account names and passwords
	while(!inFile.eof())
	{
		//incrementing the total number of accounts
		totalAccounts++;

		//taking in the username and and password from the input file
		getline(inFile, fileUsername);
		getline(inFile, filePassword);

		//pushing the username and password onto the queue
		accInfo.push(fileUsername);
		accInfo.push(filePassword);
	}//END - while(inFile)

	inFile.close();
}//END - Default Constructor

//default destructor
Accounts::~Accounts(){}

//MUTATORS/////////////////////////////////////////////////////////////////////

//Sign In method will prompt the user for a username and password, the sign
//in method will then check the validity of the username against the usernames
//already created as well as for being a valid username of over a set length
void Accounts::SignUp()
{
	string username;
	string password;
	string passwordConfirm;
	bool   validUsername = false;

	do
	{
		//prompting for username, password, and confirm password
		cout << "Please enter a username: ";
		getline(cin, username);
		cout << "Please enter a password: ";
		getline(cin, password);
		cout << "Please confirm password: ";
		getline(cin, passwordConfirm);

		try
		{
			//error checking for password confirmation
			if(password != passwordConfirm)throw 10;
			//error checking for if username is already taken
			if(SearchAccounts(username))throw 20;
			//error checking for minimum length size
			if(username.length() < 5)throw 30;
			//error checking for minimum password size
			if(password.length() < 5)throw 40;

			cout << "Account created! You may now log in\n";
			accInfo.push(username);
			accInfo.push(password);
			totalAccounts++;
			validUsername = true;

		}
		catch(int e)
		{
			switch(e)
			{
				case 10: cout << "::ATTENTION:: Passwords do not match, "
						         "please try again\n";
					break;

				case 20: cout << "::ATTENTION:: Username already taken, "
								 "please try again\n";
					break;

				case 30: cout << "::ATTENTION:: Invalid username, minimum of "
								 "five characters required, "
								 "please try again\n";
					break;

				case 40: cout << "::ATTENTION:: Invalid password, minimum of "
								 "five characters required, "
								 "please try again\n";
					break;

				default: cout << "unknown error, this is not good\n\n";
			}//switch(e)
		}//END - catch(e)
	}while(!validUsername);

}//END - SignUp

//ACCESSORS////////////////////////////////////////////////////////////////////

//The following method will allow the user to log into their account. It will
//prompt for a username and password and check them against the already-
//created queue of usernames and passwords
bool Accounts::LogIn()
{
	bool passwordOK = false;
	bool usernameOK = false;
	string username;
	string password;

	do
	{
		cout << "Enter username: ";
		getline(cin, username);
		cout << "Enter password: ";
		getline(cin, password);

		usernameOK = SearchAccounts(username);
		passwordOK = SearchAccounts(password);

		if(passwordOK && usernameOK)
		{
			cout << "Login successful! Welcome back " << username << endl;
		}
		else
		{
			cout << "::ERROR:: Invalid username or password, "
					"please try again\n";
		}
	}while(!(passwordOK && usernameOK));

	return (passwordOK && usernameOK);
}//END - LogIn

//Close accounts method will output to a file a current and comprehensive
//list of all the usernames and passwords currently in the program
void Accounts::CloseAccounts()
{
	ofstream outFile;

	//removing the old accountInformation file
	remove("accountInformation.txt");
	//creating new account information text of the same name as the input file
	outFile.open("accountInformation.txt");

	outFile << accInfo.front();
	accInfo.pop();

	//populating the output file with the contents of the queue
	while(!accInfo.empty())
	{
		outFile << endl << accInfo.front();
		accInfo.pop();
	}//END - while(!accInfo.empty())

	outFile.close();
}//END - CloseAccounts

//returns the total number of accounts
int Accounts::GetTotAccounts()
{
	return totalAccounts;
}//END - GetTotAccounts

//takes in a username and searches through the queue for any same usernames
bool Accounts::SearchAccounts(string username)
{
	bool sameUsername = false;
	queue<string> accHolder;
	accHolder = accInfo;

	while(!accHolder.empty() && !sameUsername)
	{
		//checking queue usernames against the username passed in
		if(accHolder.front() == username)sameUsername = true;

		accHolder.pop();
	}//END - while(!accHolder.empty())

	return sameUsername;
}//END - SearchAccounts

//prints the current list of all usernames and passwords. FOR DEV MODE ONLY
void Accounts::Print()
{
	queue<string> accHolder;
	accHolder = accInfo;

	while(!accHolder.empty())
	{
		cout << accHolder.front() << endl;
		accHolder.pop();
	}
}//END - Print



