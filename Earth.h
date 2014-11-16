#ifndef EARTH_H_
#define EARTH_H_
#include "Robot.h"

class Earth:public Robot
{
	public:
			Earth();
			virtual ~Earth();
			void Reset(string num);
			void setWheelType(string setWheel);
			void setFour(bool setFour);
			void setSC(bool setSC);
			string getWheel();
			bool getFour();
			bool getSC();
			virtual void Display(ostream &file);
			virtual void DisplayUpgrades(ostream &file);

	private:
			 string wheelType;
			 bool fourXfour;
			 bool superCharged;


};
void CustomizeEarth(int response, Earth &earthBot);
#endif /* EARTH_H_ */
