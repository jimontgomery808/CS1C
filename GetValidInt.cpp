#include "header.h"

int GetValidInt(int upper, int lower)
{
	int response;
	bool invalid;
	do
	{
		invalid = false;
		cin >> response;
		if(cin.fail())
		{
			cin.clear();
			cin.ignore();
			cout << "Please enter a number: ";
			invalid = true;
		}
		else if(response < lower || response > upper)
		{
			cout << "Please enter a number between " << lower << " and "
				 << upper;
			invalid = true;
		}
	}while(invalid);


	return response;
}
