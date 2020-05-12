#include<iostream>
using namespace std;

//抽象产品类
class Human {
public:
	virtual void getColor() = 0;
	virtual void talk() = 0;
};
//具体产品类
class BlackHuman :public Human
{
public:
	void getColor() {
		cout << "黑色人种的皮肤是黑色的" << endl;
	};
	void talk() {
		cout << "黑色人种说的话一般人听不懂" << endl;
	};
};
class YellowHuman :public Human
{
public:
	void getColor() {
		cout << "黄色人种的皮肤是黑色的" << endl;
	};
	void talk() {
		cout << "黄色人种说的话一般是双字节" << endl;
	};
};
class WhiteHuman :public Human
{
public:
	void getColor() {
		cout << "白色人种的皮肤是白色的" << endl;
	};
	void talk() {
		cout << "白色人种说的话一般是单字节" << endl;
	};
};
//抽象工厂类
class AbstractHumanFactory
{
public:
	virtual Human* createHuman(string s) = 0;
};
//具体工厂
class HumanFactory:public AbstractHumanFactory
{
public:
	Human* createHuman(string s) {
		if (s == "BlackHuman")
			return new BlackHuman();
		else if (s == "YellowHuman")
			return new YellowHuman();
		else if (s == "WhiteHuman")
			return new WhiteHuman();
		else
			return NULL;
	}
};
int main() {
	AbstractHumanFactory* f = new HumanFactory();
	cout << "创造黑人" << endl;
	Human* res = f->createHuman("BlackHuman");
	res->getColor();
	res->talk();
	cout << "创造黄人" << endl;
	res = f->createHuman("YellowHuman");
	res->getColor();
	res->talk();
	cout << "创造白人" << endl;
	res = f->createHuman("WhiteHuman");
	res->getColor();
	res->talk();
}