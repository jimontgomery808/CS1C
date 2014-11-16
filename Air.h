#ifndef AIR_H_
#define AIR_H_
#include "Robot.h"

class Air:public Robot
{
	public:
			 Air();
			 virtual ~Air();
			 void Reset(string num);
			 void setRotor(string setRotor);
			 void setAlt(bool setAlt);
			 void setAuto(bool setAuto);
			 string getRotor();
			 bool getAlt();
			 bool getAuto();
			 virtual void Display(ostream &file);
			 virtual void DisplayUpgrades(ostream &file);
	private:
			 string rotorType;
			 bool highAltitude;
			 bool autoPilot;

};
void CustomizeAir(int response, Air &airBot);

#endif /* AIR_H_ */
