//---------------------------------------------------------
//设计模式练习：模板模式
//场景中最后调用的是基类的具体方法，但方法的步骤在子类中完成
//作者：Mxd--
//----------------------------------------------------------
#include<iostream>
using namespace std;
//模板类
class HummerModel
{
public:
	virtual void start() = 0;
	virtual void stop() = 0;
	virtual void alarm() = 0;
	virtual void engineBoom() = 0;
	void run() {
		this->start();
		this->engineBoom();
		if (this->isAlarm())
		{
			this->alarm();
		}
		this->stop();
	};
protected:
	virtual bool isAlarm() {
		return true;
	};
};
class HummerH1model :public HummerModel
{
public:
	void alarm() {
		cout << "悍马H1鸣笛" << endl;
	}
	void stop() {
		cout << "悍马H1停车" << endl;
	}
	void start() {
		cout << "悍马H1启动" << endl;
	}
	void engineBoom() {
		cout << "悍马H1引擎声音...." << endl;
	}
	void setAlarm(bool isAlarm) {
		alarFlag = isAlarm;
	}
protected:
	bool isAlarm() {
		return alarFlag;
	};
private:
	bool alarFlag = true;
};
class HummerH2model :public HummerModel
{
public:
	void alarm() {
		cout << "悍马H2鸣笛" << endl;
	}
	void stop() {
		cout << "悍马H2停车" << endl;
	}
	void start() {
		cout << "悍马H2启动" << endl;
	}
	void engineBoom() {
		cout << "悍马H2引擎声音...." << endl;
	}
protected:
	bool isAlarm() {
		return false;
	};
};
int main() {
	while (1)
	{
		cout << "悍马H1是否鸣笛？ -- 0 否 1 是		:";
		bool flag;
		cin >> flag;
		HummerModel* H1 = new HummerH1model();
		((HummerH1model*)H1)->setAlarm(flag);
		((HummerH1model*)H1)->run();
		cout << "----------------------------------------" << endl;
		HummerModel* H2 = new HummerH2model();
		((HummerH2model*)H2)->run();
	}
}