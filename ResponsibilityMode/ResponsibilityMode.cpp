//--------------------------------------------------------------
//责任链模式
//
//
//
//--------------------------------------------------------------
#include<iostream>
#include <list>
using namespace std;
class IWomen
{
public:
	virtual int getType() = 0;
	virtual string getRequest() = 0;
};
class Women :public IWomen {
private:
	int type = 0;
	string request = "";
public:
	Women(int _type, string _request)
	{
		this->type = _type;
		this->request = _request;
	}
	int getType()
	{
		return this->type;
	}
	string getRequest()
	{
		return this->request;
	}
};
//抽象处理者  //责任链在抽象处理者的具体函数中处理
class Handler
{
public:
	static int FATHER_LEVEL_REQUEST;
	static int HUSBAND_LEVEL_REQUEST;
	static int SON_LEVEL_REQUEST;
	Handler(int _level)
	{
		this->level = _level;
	};
	void setNext(Handler* _handler)
	{
		this->nextHandler = _handler;
	}
	void HandleMessage(IWomen* women)
	{
		//是当前的 就直接回应 如果不是当前的就用递归的思路进行回应
		if (women->getType() == this->level)
		{
			this->response(women);
		}
		else {
			if (this->nextHandler != NULL)
				this->nextHandler->HandleMessage(women);
			else
				cout << "---------------没地方请示了，按不同意处理----------" << endl;
		}
	}
protected:
	virtual void response(IWomen* women) = 0;
private:
	int level = 0;//处理的级别
	Handler* nextHandler;


};
int Handler::FATHER_LEVEL_REQUEST = 1;
int Handler::HUSBAND_LEVEL_REQUEST = 2;
int Handler::SON_LEVEL_REQUEST = 3;
//下面是具体处理者
class Father :public Handler
{
public:
	Father() :Handler(this->FATHER_LEVEL_REQUEST)
	{
	}
protected:
	void response(IWomen* women)
	{
		cout << "--------------------女儿向父亲请示------------------" << endl;
		cout << women->getRequest() << endl;
		cout << "父亲的答复是：同意" << endl;
	}
};
class Hasband :public Handler
{
public:
	Hasband() :Handler(this->HUSBAND_LEVEL_REQUEST)
	{
	}
protected:
	void response(IWomen* women)
	{
		cout << "--------------------女儿向丈夫请示------------------" << endl;
		cout << women->getRequest() << endl;
		cout << "丈夫的答复是：同意" << endl;
	}
};
class Son :public Handler
{
public:
	Son() :Handler(this->SON_LEVEL_REQUEST)
	{
	}
protected:
	void response(IWomen* women)
	{
		cout << "--------------------女儿向儿子请示------------------" << endl;
		cout << women->getRequest() << endl;
		cout << "儿子的答复是：同意" << endl;
	}
};

int main()
{
	list<IWomen*> womenList;
	for (int i = 0; i < 5; i++)
	{
		int level = rand() % 3 + 1;
		womenList.push_back(new Women(level,"女人：我要去逛街"));
	}
	Handler* father = new Father();
	Handler* busband = new Hasband();
	Handler* son = new Son();
	father->setNext(busband);
	busband->setNext(son);
	for (IWomen* women : womenList)
	{
		//这里只要找到责任链的最顶端就可以
		father->HandleMessage(women);
	}
}