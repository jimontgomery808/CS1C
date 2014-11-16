#ifndef ROBOT_H_
#define ROBOT_H_
#include "header.h"

class Robot
{
	public:
			Robot();
			virtual ~Robot();
			Robot(string setName,
				  string setNum,
				  double setPrice,
				  bool setIOS,
				  bool setAndroid);
			void setName(string setName);
			void setNum(string setNum);
			void setPrice(double setPrice);
			void setiOS(bool setiOS);
			void setAndroid(bool setA);
			void setReset(bool setReset);
			string getName();
			string getNum();
			double getPrice();
			bool getiOS();
			bool getAndroid();
			bool getReset();
			virtual void Display(ostream &file);
			virtual void DisplayUpgrades(ostream &file);
			virtual void DisplayToCart(ostream &file);
	private:
			string name;
			string modelNumber;
			double price;
			bool iOS;
			bool android;
			bool reset;

};
#endif /* ROBOT_H_ */
