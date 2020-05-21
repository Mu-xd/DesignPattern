//-------------------------------------------------
//策略模式
//
//
//-------------------------------------------------
#include<iostream>

using namespace std;
//策略的接口
class IStrategy
{
public:
	virtual void operate() = 0;
};
//具体策略
class BackDoor :public IStrategy
{
public:
	void operate()
	{
		cout << "找乔国老帮忙，让吴国太给孙权施加压力" << endl;
	}
};
class GivenGreeLight :public IStrategy
{
public:
	void operate()
	{
		cout << "求吴国太开绿灯，放行。" << endl;
	}
};
class BlockEnemy :public IStrategy
{
public:
	void operate()
	{
		cout << "孙夫人断后，挡住追兵。" << endl;
	}
};
//策略分发类
class Context
{
private: 
	IStrategy* _straegy;
public:
	Context(IStrategy* straegy)
	{
		this->_straegy = straegy;
	}
	void operate()
	{
		this->_straegy->operate();
	}
};
int main()
{
	Context* context;
	cout << "--刚到吴国的时候，拆开第一个--" << endl;
	context = new Context(new BackDoor());
	context->operate();
	cout << "--刘备乐不思蜀了，拆开第二个--" << endl;
	context = new Context(new GivenGreeLight());
	context->operate();
	cout << "--孙权的小兵追来了，拆第三个--" << endl;
	context = new Context(new GivenGreeLight());
	context->operate();
}