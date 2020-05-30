//---------------------------------------------------------
//设计模式练习：享元模式
//引入池的概念
//作者：Mxd--
//时间：2020/05/30
//----------------------------------------------------------
#include<iostream>
#include<unordered_map>
#include <string>
using namespace std;

class SignInfo
{
private:
	string _location;
	string _id;
	string _subject;
	string _postAddress;
public:
	string getId()
	{
		return this->_id;
	}
	string getLocation()
	{
		return this->_location;
	}
	string getSubject() {
		return this->_subject;
	}
	string getPostAdress()
	{
		return this->_postAddress;
	}
	void setId(string id)
	{
		this->_id = id;
	}
	void setLocation(string location)
	{
		this->_location = location;
	}
	void setSubject(string subject)
	{
		this->_subject = subject;
	}
	void setPostAdress(string postAdress)
	{
		this->_postAddress = postAdress;
	}
};
class SignInfo4Pool :public SignInfo
{
private:
	string _key;
public:
	SignInfo4Pool(string key)
	{
		this->_key = key;
	}
	void setKey(string key)
	{
		this->_key = key;
	}
	string getKey()
	{
		return this->_key;
	}
};
class SignInfoFactory
{
public:
	//static的成员需要在外部重新定义一下 初始化
	static unordered_map<string, SignInfo*> pool;
public:
	//static SignInfo()
	//{
	//	return new SignInfo();
	//}
	static SignInfo* getSignInfo(string key)
	{
		SignInfo* result = nullptr;

		if (pool.find( key) == pool.end())
		{
			cout << key << "----建立对象，并放置到线程池当中" << endl;
			//result = new SignInfo4Pool(key);
			pool[key] = result;
		}
		else
		{
			cout << key << "----从线程池当中获取" << endl;
			result = SignInfoFactory::pool[key];
		}
		return result;
	}
};
unordered_map<string, SignInfo*> SignInfoFactory::pool;

int main()
{
	for (int i = 0; i < 4; i++)
	{
		string subject = "科目" + to_string(i);
		for (int j = 0; j < 1; j++)
		{
			string key = subject + "考试地点" + to_string(j);
			SignInfoFactory().getSignInfo(key);
		}
	}
	SignInfo* signInfo = SignInfoFactory().getSignInfo("科目1考试地点1");
	signInfo = SignInfoFactory().getSignInfo("科目5考试地点1");
}