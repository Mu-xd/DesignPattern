//---------------------------------------------------------
//设计模式练习：状态模式
//
//作者：Mxd--
//时间：2020/05/29
//----------------------------------------------------------
#include<iostream>

using namespace std;

class Context;
//电梯状态
class LiftState {
public:
	//环境角色、封装状态的变化引起的功能变化
	Context* _context;
public:
	void setContext(Context* context);
	virtual void open() = 0;
	virtual void close() = 0;
	virtual void run() = 0;
	virtual void stop() = 0;
};
//敞门状态
class OpenningState :public LiftState
{
public:
	void open() {
		cout << "电梯门已开启" << endl;
	};
	void close();
	void run() {

	}
	void stop() {

	};
};
//关闭状态
class ClosingState :public LiftState
{
public:
	void open() ;
	void close() {
		cout << "电梯门已经关闭" << endl;
	};
	void run();
	void stop();
};
//运行状态
class RunningSate :public LiftState
{
public:
	void open() {
	};
	void close() {

	};
	void run() {
		cout << "电梯上下运行" << endl;
	}
	void stop() ;
};
class StoppingState :public LiftState
{
public:
	void open();
	void close() {
	};
	void run();
	void stop() {
		cout << "电梯已经关闭" << endl;
	};
};
//上下文类//利用这个上下文类 来记录状态 运行的时候运行的是上下文类中注册的状态对应的函数
class Context {
private:
	LiftState* _lifeState;
public:
	OpenningState* openningState = new OpenningState();
	ClosingState* closingState = new ClosingState();
	RunningSate* runningSate = new RunningSate();
	StoppingState* stoppingState = new StoppingState();
	Context() {
		openningState->setContext(this);
		closingState->setContext(this);
		runningSate->setContext(this);
		stoppingState->setContext(this);
	}
	LiftState* getLiftState() {
		return this->_lifeState;
	}
	void setLiftState(LiftState* lifeState) {
		this->_lifeState = lifeState;
	}
	void close() {
		this->_lifeState->close();
	}
	void open() {
		this->_lifeState->open();
	}
	void run() {
		this->_lifeState->run();
	}
	void stop() {
		this->_lifeState->stop();
	}
};
void LiftState::setContext(Context* context)
{
	this->_context = context;
}
void OpenningState::close() {
	this->_context->setLiftState(this->_context->closingState);
	this->_context->getLiftState()->close();

};
void ClosingState::open() {
	//改变状态
	this->_context->setLiftState(this->_context->openningState);
	//执行状态的open函数
	this->_context->getLiftState()->open();
};
void ClosingState::run() {
	this->_context->setLiftState(this->_context->runningSate);
	this->_context->getLiftState()->run();
}
void ClosingState::stop() {
	this->_context->setLiftState(this->_context->stoppingState);
	this->_context->getLiftState()->stop();

};

void RunningSate::stop() {
	this->_context->setLiftState(this->_context->stoppingState);
	this->_context->getLiftState()->stop();

}
void StoppingState::open() {
	this->_context->setLiftState(this->_context->openningState);
	this->_context->getLiftState()->open();
};
void StoppingState::run() {
	this->_context->setLiftState(this->_context->runningSate);
	this->_context->getLiftState()->run();
}
int main()
{
	Context context = Context();
	context.setLiftState(context.closingState);//这里如果给一个新的话需要记得传参
	context.open();
	context.close();
	context.run();
	context.stop();
}