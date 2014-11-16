#include "Robot.h"
#include "Earth.h"
#include "Air.h"
#include "Sea.h"
#include "Accounts.h"
#include "header.h"

void MainMenu();
int main()
{
	Accounts masterAccounts;

	// LOGIN MENU
	LogIn(masterAccounts);

	// INPUT & OUTPUT - Main Menu
	MainMenu();

	masterAccounts.CloseAccounts();
	return 0;
}
