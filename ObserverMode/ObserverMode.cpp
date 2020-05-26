//---------------------------------------------------------
//设计模式练习：观察者模式
//一般uodate接收两个参数一个是被观察者一个DTO、多线程/缓存技术（解决卡死问题）
//
//作者：Mxd--
//时间：2020/05/26
//----------------------------------------------------------
#include<iostream>
#include<vector>
using namespace std;
//抽象观察者
class Observer
{
public:
	virtual void update(string context) = 0;
};
//抽象被观察者
class Observable
{
public:
	//添加观察者
	virtual void addObserver(Observer* observer) = 0;
	//删除观察者
	virtual void deletObserver(Observer* observer) = 0;
	//通知观察者
	virtual void notifyObservers(string context) = 0;
};
class IHanFeiZi
{
public:
	virtual void haveBreadfast() = 0;
	virtual void haveFun() = 0;
};
//具体被观察者
class HanFeiZi :public Observable, public IHanFeiZi
{
private:
	vector<Observer*> observerList;
public:
	void haveBreadfast() {
		cout << "韩非子：我要开始吃饭了..." << endl;
		cout << "----------------------------------" << endl;
		notifyObservers("韩非子开始吃饭了");
	}
	void haveFun() {
		cout << "韩非子：我要开始娱乐了...嘿嘿嘿..." << endl;
		cout << "----------------------------------" << endl;
		notifyObservers("韩非子开始娱乐了");
	}
	void addObserver(Observer* observer)
	{
		this->observerList.push_back(observer);
	}
	void deletObserver(Observer* observer)
	{
		this->observerList.erase(find(this->observerList.begin(),this->observerList.end(),observer));
	}
	void notifyObservers(string context)
	{
		int i = 1;
		for (auto item : this->observerList)
		{
			item->update(context);
			cout << "---------" << i++ << "----------------------------------" << endl;
		}
	}
};
//具体观察者
class LiSi :public Observer
{
private:
	void report(string s)
	{
		cout << "李斯：报告老板，韩非子有所行动-->" << s << endl;
	}
public:
	void update(string context)
	{
		cout << "李斯：观察到韩非子活动，马上去和老板汇报..." << endl;
		this->report(context);
		cout << "李斯：汇报完毕..." << endl;
	}
};
class LiuSi :public Observer
{
private:
	void report(string s)
	{
		cout << "刘思：报告老板，韩非子有所行动-->" << s << endl;
	}
public:
	void update(string context)
	{
		cout << "刘思：观察到韩非子活动，马上去和老板汇报..." << endl;
		this->report(context);
		cout << "刘思：汇报完毕..." << endl;
	}
};
int main()
{
	Observable* hanfeizi = new HanFeiZi();
	Observer* lisi = new LiSi();
	Observer* liusi = new LiuSi();
	hanfeizi->addObserver(lisi);
	hanfeizi->addObserver(liusi);
	((HanFeiZi*)hanfeizi)->haveBreadfast();
	((HanFeiZi*)hanfeizi)->haveFun();

}