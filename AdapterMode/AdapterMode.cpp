//---------------------------------------------------------
//设计模式练习：适配器模式
//类适配器：需要适配的类作为基类
//作者：Mxd--
//时间：2020/05/23
//----------------------------------------------------------
#include<iostream>
#include<map>
using namespace std;
//员工信息接口+原接口
class IUserInfo
{
public:
	virtual string getUserName() = 0;
	virtual string getHomeAddress() = 0;
	virtual string getMoblieNumber() = 0;
	virtual string getOfficeTelNumber() = 0;
	virtual string getJobPosition() = 0;
	virtual string getHomeTelNumber() = 0;
};
class UserInfo :public IUserInfo
{
public:
	string getUserName() {
		cout << "员工姓名......" << endl;
		return "";
	};
	string getHomeAddress() {
		cout << "员工家庭地址......" << endl;
		return "";
	};
	string getMoblieNumber() {
		cout << "员工移动电话......" << endl;
		return "";
	};
	string getOfficeTelNumber() {
		cout << "员工工作电话......" << endl;
		return "";
	};
	string getJobPosition() {
		cout << "工作职位是Boss......" << endl;
		return "";
	};
	string getHomeTelNumber() {
		cout << "员工家庭电话......" << endl;
		return "";
	};
};
//劳务公司人员接口 //目标接口
class IOuterUser {
public:
	virtual map<string, string> getUserBaseInfo() = 0;
	virtual map<string, string> getUserHomeInfo() = 0;
	virtual map<string, string> getUserOfficeInfo() = 0;
};
class OuterUser :public IOuterUser
{
public:
	map<string, string> getUserBaseInfo() {
		map<string, string> baseInfoMap;
		baseInfoMap["userName"] = "这个员工叫混世魔王";
		baseInfoMap["mobileNumber"] = "这个员工电话是......";
		return baseInfoMap;
	}
	map<string, string> getUserHomeInfo() {
		map<string, string> homeInfoMap;
		homeInfoMap["homeTelNumber"] = "员工的家庭电话是......";
		homeInfoMap["homeAddress"] = "员工的家庭地址是......";
		return homeInfoMap;
	}
	map<string, string> getUserOfficeInfo() {
		map<string, string> officeInfoMap;
		officeInfoMap["jobPosition"] = "这个人的职位是Boss......";
		officeInfoMap["officeTelNumber"] = "员工的办公电话是......";
		return officeInfoMap;
	}
};
//适配器 适配器接口
class OuterUserInfo :public OuterUser,public IUserInfo
{
private:
	map<string, string> baseInfoMap = OuterUser::getUserBaseInfo();
	map<string, string> homeInfoMap = OuterUser::getUserHomeInfo();
	map<string, string> officeInfoMap = OuterUser::getUserOfficeInfo();
public:
	string getUserName() {
		string userName = (string)this->baseInfoMap["userName"];
		cout << userName << endl;
		return userName;
	};
	string getHomeAddress() {
		string homeAddress = (string)this->homeInfoMap["homeAddress"];
		cout << homeAddress << endl;
		return homeAddress;
	};
	string getMoblieNumber() {
		string mobileNumber = (string)this->baseInfoMap["mobileNumber"];
		cout << mobileNumber << endl;
		return mobileNumber;
	};
	string getOfficeTelNumber() {
		string officeTelNumber = (string)this->officeInfoMap["officeTelNumber"];
		cout << officeTelNumber << endl;
		return officeTelNumber;
	};
	string getJobPosition() {
		string officeTelNumber = (string)this->officeInfoMap["officeTelNumber"];
		cout << officeTelNumber << endl;
		return officeTelNumber;
	};
	string getHomeTelNumber() {
		string jobPosition = (string)this->homeInfoMap["jobPosition"];
		cout << jobPosition << endl;
		return jobPosition;
	};
};
int main()
{
	//IUserInfo* youngGirl = new UserInfo(); //没有适配器 只调用自己的
	IUserInfo* youngGirl = new OuterUserInfo();//使用适配器
	for (int i = 0; i < 10; i++) {
		auto s = youngGirl->getMoblieNumber();
	}
}