#include "Accounts.h"
#include "header.h"

void LogIn(Accounts &masterAccounts)
{
	int response;
	bool user;

	user = false;
	cout << LOGIN;
	response = GetValidInt(2,1);
	cin.ignore();

	while(!user)
	{
		switch(response)
		{
			case 1:
			masterAccounts.SignUp();
			cout << LOGIN;
			response = GetValidInt(2,1);
			cin.ignore();
			break;

			case 2:
			user = masterAccounts.LogIn();
			break;
		}


	}
}
