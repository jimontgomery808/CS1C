#include "Robot.h"
#include "Earth.h"
#include "Air.h"
#include "Sea.h"
/******************************************************************************
 * PROTOTYPES
 ******************************************************************************/
void DisplayCart(vector<Earth> &eBots,
				 vector<Air> &aBots,
				 vector<Sea> &sBots,
				 unsigned int &numBots);

void RemoveEarthUpgrade(vector<Earth> &eBots,
						unsigned int &index);
void AddEarthUpgrade(vector<Earth> &eBots,
					 unsigned int &index);

void AddAirUpgrade(vector<Air> &aBots,
				   unsigned int &index);
void RemoveAirUpgrades(vector<Air> &aBots,
					  unsigned int &index);

void AddSeaUpgrade(vector<Sea> &sBots, unsigned int &index);
void RemoveSeaUpgrade(vector<Sea> &sBots, unsigned int &index);

/******************************************************************************
 * FUNCTION - ShoppingCart
 * ___________________________________________________________________________
 * This function will allow the user to edit their shopping cart
 ******************************************************************************/
void ShoppingCart(vector<Earth> &eBots,
				  vector<Air> &aBots,
				  vector<Sea> &sBots,
				  unsigned int &numBots)
{
	// Variables
	unsigned int index;	// CALC  - Counter used for element of vector
	int response;	    // INPUT - Menu Option Selection
	bool found;		    // CALC  - boolean for bot searched for
	string bot;			// INPUT - model number of bot being searched for

	// Will Run Shopping cart if there is at least one Bot in Cart
	if(numBots > 0)
	{
		// OUTPUT - displays all Bots in cart
		DisplayCart(eBots, aBots, sBots, numBots);

		// INPUT - Yes or No: make changes to cart
		set: cout << endl;

		cout << MAKE_CHANGES;
		response = GetValidInt(1,0);
		while(response != 0)
		{
			switch(response)
			{

				// Set - goto place mark, used if a Bot is deleted from cart

				// User inputs yes to edit
				case 1:
				// INPUT - user selects a Bot to edit, or to view the cart
				cout <<  SHOP_CART_MENU;
				response = GetValidInt(3,0);
				cin.ignore();

				while(response != 0 && numBots > 0)
				{
					switch(response)
					{
/******************************************************************************
 *                     BEGIN - Make changes to Earth Bot
 ******************************************************************************/
						case 1:
						if(eBots.size() > 0)
						{
							cout << "\nPlease enter the model number of the "
									"bot you wish to edit: ";

							getline(cin, bot);
							for(index = 0; index < eBots.size(); index ++)
							{
								if(eBots[index].getNum() == bot)
								{
									found = true;
									cout << endl;
									eBots[index].Display(cout);
									break;
								}
							}
							if(found)
							{
								cout << EDIT_MENU;
								response = GetValidInt(3,0);
								while(response != 0)
								{
									/**********************************************
									 * START - if(eBots.size() > 0)
									 **********************************************/
									if(eBots.size() > 0)
									{
										/*******************************************
										 * START - switch(response): EDIT_MENU
										 ******************************************/
										switch(response)
										{
										/******************************************
										 * START - while(response != 0): E_CUST_SP
										 ******************************************/
										case 1:AddEarthUpgrade(eBots,index);
										break;

										case 2: RemoveEarthUpgrade(eBots,index);
										break;
										// Removes a Robot
										case 3:
										eBots.erase(eBots.begin() + index);
										cout << "\nRemoved Bot from cart\n";
										numBots --;
										goto set;
										break;
										}
										/*******************************************
										 * END - switch(response): EDIT_MENU
										 ******************************************/
									}
									/**********************************************
									 * END - if(eBots.size() > 0)
									 **********************************************/
									else
									{
										cout << "\nNo Earth Bots in cart.\n";
									}
									cout << EDIT_MENU;
									response = GetValidInt(3,0);
								}

							}
							else
							{
								cout << "Earth Bot not found or invalid model number. "
										"Please try again\n";
							}


						}// END - if(eBots.size() > 0)
						else
						{
							cout << "\nNo Earth Bots in Cart\n";
						}
						break;

/******************************************************************************
 *                    END - Make changes to Earth Bot
 ******************************************************************************/


/******************************************************************************
 *                     BEGIN - Make changes to Air Bot
 ******************************************************************************/
						case 2:
						if(aBots.size() > 0)
						{
							cout << "\nPlease enter the model number of the bot you"
									" wish to edit: ";
							getline(cin, bot);
							for(index = 0; index < aBots.size(); index ++)
							{
								if(aBots[index].getNum() == bot)
								{
									found = true;
									cout <<  endl;
									aBots[index].Display(cout);
									break;
								}
							}

							if(found)
							{
								cout << EDIT_MENU;
								response = GetValidInt(3,0);
								while(response != 0)
								{
									if(aBots.size() > 0)
									{
										switch(response)
										{
										case 1: AddAirUpgrade(aBots, index);
										break;

										case 2: RemoveAirUpgrades(aBots, index);
										break;
										// Removes a Robot
										case 3:
										aBots.erase(aBots.begin() + index);
										cout << "\nRemoved Bot from cart\n";
										numBots --;
										goto set;
										break;
									}
								}
								else
								{
									cout << "\nNo Air Bots in cart.\n";
								}
							cout << EDIT_MENU;
							response = GetValidInt(3,0);
							}// END - chose to add or remove

							}
							else
							{
								cout << "Air Bot not found or invalid model number. "
										"Please try again\n";
							}

						}
						else
						{
							cout << "\nNo Air Bots in Cart\n";
						}
						break;

/******************************************************************************
 *                    END - Make changes to Air Bot
 ******************************************************************************/



/******************************************************************************
 *                    BEGIN - Make changes to Sea Bot
 ******************************************************************************/
						case 3:
						/***********************************************************
						 * START - if(sBots.size() > 0)
						 *********************************************************/
						if(sBots.size() > 0)
						{
							cout << "\nPlease enter the model number of the bot you"
									" wish to edit: ";
							getline(cin, bot);
							for(index = 0; index < aBots.size(); index ++)
							{
								if(sBots[index].getNum() == bot)
								{
									found = true;
									cout << endl;
									sBots[index].Display(cout);
									break;
								}
							}

						   /****************************************************
							*  START - if found Sea Bots
							***************************************************/
							if(found)
							{
							   /************************************************
								* START - while(response != 0): EDIT_MENU
								***********************************************/
								cout << EDIT_MENU;
								response = GetValidInt(3,0);
								while(response != 0)
								{
									/*******************************************
									 * START - if(sBots.size() > 0)
									 ******************************************/
									if(sBots.size() > 0)
									{
										switch(response)
										{
											case 1: AddSeaUpgrade(sBots, index);
											break;

											case 2: RemoveSeaUpgrade(sBots, index);
											break;

											// INPUT - removes current Sea Bot
											case 3:
											// Bot is erased from vector
											sBots.erase(sBots.begin() + index);
											cout << "\nRemoved Bot from cart\n";
											// CALC - number of Bots is decremented
											numBots --;
											// Goes to Bot selection
											goto set;
										break;
										}
									}
									// If no Sea Bots in vector, output message
									else
									{
										cout << "\nNo Sea Bots in cart\n\n";
									}

								// Re-initialize LCV
								cout << EDIT_MENU;
								response = GetValidInt(3,0);
								}
								/***********************************************
								* END - while(response != 0): EDIT_MENU
								***********************************************/

							}
							/***************************************************
							*  END - if found Sea Bots
							***************************************************/
							else
							{
								cout << "Sea Bot not found or invalid model number. "
										"Please try again\n";
							}

						}
						/*******************************************************
						 * END - if(sBots.size() > 0)
						 ******************************************************/
						else
						{
							cout << "\nNo Sea Bots in Cart\n";
						}
						break;
/******************************************************************************
 *                    END - Make changes to Sea Bot
 ******************************************************************************/

					}
					/**********************************************************
					 * END - switch(response) - SHOP_CART_MENU
					 **********************************************************/


					if(numBots <= 0)
					{
						cout << "\nNo Bots in Cart\n";
					}
						cout <<  SHOP_CART_MENU;
						response = GetValidInt(3,0);
						cin.ignore();
				}// END - chose which robot to edit

		}// END - switch: make changes to cart

		if(numBots > 0)
		{
			DisplayCart(eBots, aBots, sBots, numBots);
		}
		else
		{
			cout << "\nCart is empty\n\n";
		}
		cout << MAKE_CHANGES;
		response = GetValidInt(1,0);

		} // END - Yes/No

	}// END - if(numBots > 0)
	else
	{
		cout << "\nCart is Empty!\n";
	}

}


