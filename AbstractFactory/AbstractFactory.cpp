#include<iostream>
using namespace std;

//抽象产品类
class Human
{
	//人种接口
public:
	virtual void getColor() = 0;
	virtual void talk() = 0;
	virtual void getSex() = 0;
};
//一次成型
class AbstractWhiteHuman :public Human
{
public:
	void getColor() {
		cout << "白色人种的皮肤是白色的" << endl;
	}
	void talk() {
		cout << "白色人种说的话一般都是单字节的" << endl;
	}
};
class AbstractBlackHuman :public Human
{
public:
	void getColor() {
		cout << "黑色人种的皮肤是黑色的" << endl;
	}
	void talk() {
		cout << "黑色人种说的话一般人听不懂" << endl;
	}
};
class AbstractYellowHuman :public Human
{
public:
	void getColor() {
		cout << "黄色人种的皮肤是黄色的" << endl;
	}
	void talk() {
		cout << "黄色人种说的话一般是双字节的" << endl;
	}
};
//具体产品
class FemaleYellowHuman :public AbstractYellowHuman
{
public:
	void getSex() {
		cout << "黄色人种男性" << endl;
	}
};
class MaleYellowHuman :public AbstractYellowHuman
{
public:
	void getSex() {
		cout << "黄色人种女性" << endl;
	}
};
//抽象工厂
class HumanFactory
{
public:
	virtual Human* createYellowHuman() = 0;
	//virtual Human* createWhiteHuman() = 0;
	//virtual Human* createBlackHuman() = 0;
};
//生产线
class FemaleFactory :public HumanFactory
{
public:
	Human* createYellowHuman() {
		return new FemaleYellowHuman();
	}
};
class MaleFactory :public HumanFactory
{
public:
	Human* createYellowHuman() {
		return new MaleYellowHuman();
	}
};
int main() {
	HumanFactory* maleHuman = new MaleFactory();
	HumanFactory* FamaleHuman = new FemaleFactory();
	Human* YellowHuman = maleHuman->createYellowHuman();
	YellowHuman->getColor();
	YellowHuman->getSex();
	YellowHuman->talk();
	YellowHuman = FamaleHuman->createYellowHuman();
	YellowHuman->getColor();
	YellowHuman->getSex();
	YellowHuman->talk();
}