#ifndef HEADER_H_
#define HEADER_H_

#include <iostream>
#include <iomanip>
#include <vector>
#include <fstream>
#include <ctime>
#include <cstdlib>
using namespace std;

struct Person
{
	string name;
	string address;
	string address2;
	string zip;
	string interest;
	string rating;
	Person* next;
};

void Print (Person *personPtr, fstream &file);
void ModelNumberGenerator(string list[]);
int GetValidInt(int upper, int lower);
void Inventory (ostream &file);

const string MAKE_CHANGES = "Would you like to make changes to the cart?\n"
							"0. No\n"
							"1. Yes\n\n"
							"Selection: ";

const string LOGIN = "\nLOGIN\n"
					 "-----------------------\n"
					 "1.    Register New User\n"
					 "2.    Sign in\n\n"
					 "Selection: ";

const string MAIN_MENU = "\nMAIN MENU\n"
						 "-----------------------\n"
						 "1.	About Us\n"
						 "2. 	Purchase Robot\n"
						 "3. 	Shopping Cart\n"
						 "0. 	Exit Brochure\n\n"
						 "Selection: ";

const string PURCHASE_MENU = "\nPURCHASE MENU\n"
							 "------------------------\n"
							 "1.	Earth-Bot\n"
							 "2.	Air-Bot\n"
							 "3.	Sea-Bot\n"
							 "0.	Main Menu\n\n"
							 "Selection: ";

const string SHOP_CART_MENU =   "\nSELECT A TYPE TO EDIT\n"
								"-----------------------"
								"1.	Earth-Bot\n"
								"2.	Air-Bot\n"
								"3.	Sea-Bot\n"
								"0.	View Cart\n\n"
								"Selection: ";

const string A_HEADER = "\nPURCHASE AIR-BOT\n"
						"-------------------\n";

const string E_HEADER = "\nPURCHASE EARTH-BOT\n"
						"-------------------\n";

const string S_HEADER = "\nPURCHASE SEA-BOT\n"
						"-------------------\n";

const string A_EDIT =   "\nEDIT AIR-BOT\n"
						"-------------------\n";
const string E_EDIT =   "\nEDIT EARTH-BOT\n"
						"-------------------\n";
const string S_EDIT =   "\nEDIT SEA-BOT\n"
						"-------------------\n";

const string PURCHASE_OPTIONS = "1.    Purchase Base Model\n"
								"2.    Customize\n"
								"0.    Purchase Menu\n\n"
								"Selection: ";

const string EDIT_MENU ="\nEdit Menu\n"
						"------------------\n"
						"1.    Add Upgrades\n"
						"2.    Remove Upgrades\n"
						"3.    Remove Robot\n"
						"0.    Return to previous\n\n"
						"Selection: ";

const string CONT_UPGRADE = "\nPURCASE CONTROLLER UPGRADE\n"
							"--------------------------------------\n"
							"1.    iOS compatibility ($1999.99)\n"
							"2.    Android compatibility ($1999.99)\n"
							"3.    iOS/Android ($3999.98)\n"
							"0.    Return to previous\n\n"
							"Selection: ";

const string REMOV_CONT =   "\nREMOVE CONTROLLER UPGRADE\n"
							"----------------------------\n"
							"1.    iOS compatibility (- $1999.99)\n"
							"2.    Android compatibility (- $1999.99)\n"
							"0.    Return to previous\n\n"
							"Selection: ";

const string REM_E_CUST = "1.	Remove controller upgrade\n"
						  "2.	Remove 4x4 upgrade (- $500.99)\n"
						  "3.	Remove super-charged engine (- $700.99)\n"
						  "0.	Save Changes\n\n"
						  "Selection: ";

const string REM_A_CUST = "1.	Remove controller upgrade\n"
						  "2.	Remove high-altitude capability (- $700.99)\n"
						  "3.	Remove auto-pilot (- 1200.99)\n"
						  "0.	Save Changes\n\n"
						  "Selection: ";

const string REM_S_CUST = "1.	Remove controller upgrade\n"
						  "2.	Remove sonar (- $1200.99)\n"
						  "3.	Remove submarine capability (- $1700.99)\n"
						  "0.	Save Changes\n\n"
						  "Selection: ";

const string E_CUST = "1.	Add controller upgrade\n"
					  "2.	Add 4x4 upgrade (+ $500.99)\n"
					  "3.	Add super-charged engine (+ $700.99)\n"
					  "0.	Add to Cart\n\n"
					  "Selection: ";

const string E_CUST_SP = "1.	Add controller upgrade\n"
						  "2.	Add 4x4 upgrade (+ $500.99)\n"
						  "3.	Add super-charged engine (+ $700.99)\n"
						  "0.	Save Changes\n\n"
						  "Selection: ";

const string A_CUST = "1.	Add controller upgrade\n"
					  "2.	Add high-altitude capability (+ $700.99)\n"
					  "3.	Add auto-pilot (+ 1200.99)\n"
					  "0.	Add to Cart\n\n"
					  "Selection: ";

const string A_CUST_SP = "1.	Add controller upgrade\n"
						  "2.	Add high-altitude capability (+ $700.99)\n"
						  "3.	Add auto-pilot (+ 1200.99)\n"
						  "0.	Save Changes\n\n"
						  "Selection: ";

const string S_CUST = "1.	Add controller upgrade\n"
					  "2.	Add sonar (+ $1200.99)\n"
					  "3.	Add submarine capability (+ $1700.99)\n"
					  "0.	Add to Cart\n\n"
					  "Selection: ";

const string S_CUST_SP =  "1.	Add controller upgrade\n"
						  "2.	Add sonar (+ $1200.99)\n"
						  "3.	Add submarine capability (+ $1700.99)\n"
						  "0.	Save Changes\n\n"
						  "Selection: ";
#endif /* HEADER_H_ */
