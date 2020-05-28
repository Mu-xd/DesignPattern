//---------------------------------------------------------
//设计模式练习：访问者模式
//
//作者：Mxd--
//时间：2020/05/28
//----------------------------------------------------------
#include<iostream>
#include<vector>
using namespace std;

class IVisitor;//调用了后面的  先声明
class Employee
{
private:
	string _name;
	string _salary;
	int _sex;
public:
	static int MALE;
	static int FAMALE;
	string getName()
	{
		return this->_name;
	}
	string getSalary()
	{
		return this->_salary;
	}
	int getSex()
	{
		return this->_sex;
	}
	void setName(string name)
	{
		this->_name = name;
	}
	void setSalary(string salary)
	{
		this->_salary = salary;
	}
	void setSex(int sex)
	{
		this->_sex = sex;
	}
	virtual void accept(IVisitor* visitor) = 0; //这里给一个访问接口
};
int Employee::FAMALE = 0;
int Employee::MALE = 1;
class CommonEmployee : public Employee
{
private:
	string _job;
public:
	string getJob()
	{
		return this->_job;
	}
	void setJob(string job)
	{
		this->_job = job;
	}
	void accept(IVisitor* visitor);//现实时调用了后面的  先声明
};
class Manager : public Employee
{
private:
	string _performance;
public:
	string getPerformance()
	{
		return this->_performance;
	}
	void setPerformance(string performance)
	{
		this->_performance = performance;
	}
	void accept(IVisitor* visitor);//现实时调用了后面的  先声明
};
//访问者接口
class IVisitor
{
public:
	virtual void visit(CommonEmployee* commonEmployee) = 0;
	virtual void visit(Manager* manager) = 0;
};
class Visitor :public IVisitor
{
public:
	void visit(CommonEmployee* commonEmployee) {
		cout << this->getCommonEmployeeInfo(commonEmployee)<<endl;
	};
	void visit(Manager* manager) {
		cout << this->getManagerInfo(manager)<<endl;
	};
private:
	string geyBasicInfo(Employee* employee)
	{
		string info = "姓名：" + employee->getName() + "\t";
		string sex = (employee->getSex() == employee->FAMALE) ? "女" : "男";
		info += "性别：" + sex + "\t";
		info += "薪水：" + employee->getSalary() + "\t";
		return info;
	}
	string getManagerInfo(Manager* manager)
	{
		string info = this->geyBasicInfo(manager);
		info += "业绩：" + manager->getPerformance() + "\t";
		return info;
	}
	string getCommonEmployeeInfo(CommonEmployee* commonEmployee)
	{
		string info = this->geyBasicInfo(commonEmployee);
		info += "工作：" + commonEmployee->getJob() + "\t";
		return info;
	}
};
//这里注意调用顺序 由于发生了后面调用前面的 所以先声明 后实现
void Manager::accept(IVisitor* visitor)
{
	visitor->visit(this);
}
void CommonEmployee::accept(IVisitor* visitor)
{
	visitor->visit(this);
}
int main()
{
	vector<Employee*> emplist;
	CommonEmployee* zhangsan = new CommonEmployee();
	zhangsan->setName("张三");
	zhangsan->setSalary("1000");
	zhangsan->setSex(zhangsan->MALE);
	zhangsan->setJob("写程序");
	emplist.push_back(zhangsan);
	CommonEmployee* wangwu = new CommonEmployee();
	wangwu->setName("王五");
	wangwu->setSalary("10000");
	wangwu->setSex(wangwu->MALE);
	wangwu->setJob("写框架");
	emplist.push_back(wangwu);
	Manager* liliu = new Manager();
	liliu->setName("王五");
	liliu->setSalary("100000");
	liliu->setSex(wangwu->MALE);
	liliu->setPerformance("很好");
	emplist.push_back(liliu);
	for (auto item : emplist)
	{
		item->accept(new Visitor());
	}
}