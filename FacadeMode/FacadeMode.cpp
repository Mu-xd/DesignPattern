//---------------------------------------------------------
//设计模式练习：门面模式
//注意：一个子系统可以有多个门面、门面不参与子系统内的业务逻辑
//作者：Mxd--
//时间：2020/05/27
//----------------------------------------------------------
#include<iostream>
using namespace std;
//信件子系统接口
class ILetterProcess
{
public:
	virtual void writeContext(string) = 0;
	virtual void fillEnvelope(string) = 0;
	virtual void letterIntoEnvelope() = 0;
	virtual void sendLetter() = 0;
};
class LetterProcessImpl :public ILetterProcess
{
public:
	void writeContext(string context) {
		cout << "写了一封信...." << context <<endl;
	};
	void fillEnvelope(string address) {
		cout << "写一些地址..."<< address << endl;
	};
	void letterIntoEnvelope() {
		cout << "把信放到信封中...." << endl;
	};
	void sendLetter() {
		cout << "邮递信件...." << endl;
	};
};
//检查子系统
class Police {
public:
	void checkLetter(ILetterProcess* letterprocess) {
		cout << &letterprocess << "检查完毕！通过" << endl;
	}
};
//门面类
class ModenPostOffice {
private:
	ILetterProcess* _letterprocess = new LetterProcessImpl();
	Police police;
public:
	void sendLetter(string context,string address) {
		_letterprocess->writeContext(context);
		_letterprocess->fillEnvelope(address);
		_letterprocess->letterIntoEnvelope();
		police.checkLetter(_letterprocess);
		_letterprocess->sendLetter();
	}
};
int main()
{
	ModenPostOffice postOffice;
	postOffice.sendLetter("----------------------------正文","d地址d");
}