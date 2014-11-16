#ifndef SEA_H_
#define SEA_H_
#include "Robot.h"

class Sea:public Robot
{
	public:
			Sea();
			virtual ~Sea();
			void Reset(string num);
			void setProp(string setProp);
			void setSonar(bool sonarSet);
			void setSub(bool setSub);
			string getProp();
			bool getSonar();
			bool getSub();
			virtual void Display(ostream &file);
			virtual void DisplayUpgrades(ostream &file);


	private:
			string propellerType;
			bool sonar;
			bool subMarine;

};

void CustomizeSea(int response, Sea &seaBot);

#endif /* SEA_H_ */
