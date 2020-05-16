#include<iostream>
#include<list>
using namespace std;

class AdvTemplate
{
private:
	string advSubject = "XX银行国庆信用卡抽奖活动";
	string advContext = "国庆抽奖活动通知：只要刷卡就送你一百万";
public:
	string getAdvSubject()
	{
		return this->advSubject;
	};
	string getadvContext()
	{
		return advContext;
	};
};

class CPrototype
{
public:
	virtual CPrototype* Clone() = 0;
};

class Mail//:public CPrototype
{
private:
	string receiver;
	string subject;
	string appellation;
	string context;
	string tail;
public:
	list<string> test;
	Mail(AdvTemplate advTemplate)
	{
		cout << "-------------------------" << endl;
		this->subject = advTemplate.getAdvSubject();
		this->context = advTemplate.getadvContext();
		test = { "0","1","1" };
	}
	virtual Mail* Clone() {
		return this;
	}
	string getRecriver() {
		return this->receiver;
	}
	string getSubject() {
		return this->subject;
	}
	string getAppellation() {
		return this->appellation;
	}
	string getContext() {
		return this->context;
	}
	string getTail() {
		return this->tail;
	}
	void setRecriver(string receriver) {
		this->receiver = receriver;
	}
	void setSubject(string subject) {
		this->subject = subject;
	}
	void setAppellation(string appellation) {
		this->appellation = appellation;
	}
	void setContext(string context) {
		this->context = context;
	}
	void setTail(string tail) {
		this->tail = tail;
	}
};

int MAX_COUNT = 6;
void sendMail(Mail* mail)
{
	cout << "标题：" + mail->getSubject() + "\t收件人：" + mail->getRecriver() + "\t...发送成功"<<endl;
}
string getRandString(int maxLength)
{
	string soure = "zxcvbnmasdfghjklqwertyuiop1234567890ZXCVBNMASDFGHJKLQWERTYUIOP";
	string res = "";
	for (int i = 0; i < maxLength; i++)
	{
		res += soure[rand() % soure.size()];
	}
	return res;
}
int main()
{
	int i = 0;
	Mail* mail = new Mail(AdvTemplate());
	mail->setRecriver("XX银行版权所有");
	while (i < MAX_COUNT)
	{
		Mail* cloneMail = mail->Clone();
		cloneMail->test.push_back("asss");
		cloneMail->setAppellation(getRandString(5) + "先生（女士）");
		cloneMail->setRecriver(getRandString(5) + "@" + getRandString(8) + ".com");
		sendMail(cloneMail );
		//这里 主对象是深拷贝 其他的引用对象 数组等  是浅拷贝 
		for (auto x : cloneMail->test)
		{
			cout << x;
		}
		cout << endl;
		for (auto x : mail->test)
		{
			cout << x;
		}
		cout << endl;
		i++;
	}
}
