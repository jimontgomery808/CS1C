#include "Robot.h"

Robot::Robot()
{
	name = " ";
	modelNumber = " ";
	price = 0.0;
	iOS = false;
	android = false;
	reset = false;
}
Robot::Robot(string setName,
			 string setNum,
			 double setPrice,
		     bool setiOS,
			 bool setAndroid)
{
	name = setName;
	modelNumber = setNum;
	price = setPrice;
	iOS = setiOS;
	android = setAndroid;
	reset = false;
}
Robot::~Robot()
{

}
void Robot::setName(string setName)
{
	name = setName;
}
void Robot::setNum(string setNum)
{
	modelNumber = setNum;
}
void Robot::setPrice(double setPrice)
{
	price = setPrice;
}
void Robot::setiOS(bool setiOS)
{
	if(setiOS)
	{
		if(iOS)
		{
			cout << "\nThis bot already has iOS compatibility\n";
		}
		else if(!iOS)
		{
			iOS = setiOS;
			price += 1999.99;
			cout << "\nPurchased iOS compatible robot controller ($1999.99)\n";
			if(android)
			{
//				cout << "\n***** iOS and Android Package Special *****\n"
//						" You've earned $500 off your total price!\n\n";
//				price -= 500.99;
			}
		}
	}
	if(!setiOS && !getReset())
	{
		if(iOS)
		{
			iOS = setiOS;
			price -= 1999.99;
			cout << "\nRemoved iOS capabilities\n";
		}
		else if(!iOS && !reset)
		{
			cout << "\nThis Bot does not have iOS compatibilities\n";
		}
	}

}
void Robot::setAndroid(bool setA)
{
	if(setA)
	{
		if(android)
		{
			cout << "\nThis bot already has Android compatiblity\n";
		}
		else if(!android)
		{
			android = setA;
			price += 1999.99;
			cout << "\nPurchased Android compatible robot controller ($1999.99)\n";
			if(iOS)
			{
//				cout << "\n***** iOS and Android Package Special *****\n"
//						" You've earned $500 off your total price!\n\n";
//				price -= 500.99;
			}
		}
	}
	else if(!setA && !getReset())
	{
		if(android)
		{
			android = setA;
			price -= 1999.99;
			cout << "\nRemoved Android capabilities\n";
		}
		else if(!android && !reset)
		{
			cout << "\nThis Bot does not have Android compatibilities\n";
		}
	}
}
void Robot::setReset(bool setReset)
{
	reset = setReset;
}
string Robot::getName()
{
	return name;
}
string Robot::getNum()
{
	return modelNumber;
}
double Robot::getPrice()
{
	return price;
}
bool Robot::getiOS()
{
	return iOS;
}
bool Robot::getAndroid()
{
	return android;
}
bool Robot::getReset()
{
	return reset;
}
void Robot::Display(ostream &file)
{
	file << left;
	file << setw(17) << "MODEL NAME: "   << name << endl;
	file << setw(17) << "MODEL NUMBER: " << modelNumber << endl;
	file << setw(17) << "PRICE: "        << setprecision(2) << fixed << "$"
		 << price << endl;
}
void Robot::DisplayUpgrades(ostream &file)
{
	file << left;
	file << setw(17) << "UPGRADES\n"
						"--------\n";

	if(iOS || android)
	{
		if(iOS && android)
		{
			file << "iPad and Android compatibility\n";
		}

		else if(iOS && !android)
		{
			file << "iOS compatibility\n";
		}
		else if(!iOS && android)
		{
			file << "Android compatibility\n";
		}

	}
}
void Robot::DisplayToCart(ostream &file)
{

	file << left << setw(15) << name << setw(15) << modelNumber << setw(15)
		 <<price;
}
