#include<iostream>
using namespace std;
// 抽象组
class Group
{
public:
	virtual void find() = 0;
	virtual void add() = 0;
	virtual void deletes() = 0;
	virtual void change() = 0;
	virtual void plan() = 0;
};
//具体实现组
class RequirementGroup :public Group
{
public:
	void find() { cout << "找到需求组..." << endl; }
	void add() { cout << "客户要求增加一项需求..." << endl; }
	void deletes() { cout << "客户要求删除一项需求..." << endl; }
	void change() { cout << "客户要求修改一项需求..." << endl; }
	void plan() { cout << "客户要求需求变更计划..." << endl; }

};
class PageGroup :public Group
{
public:
	void find() { cout << "找到美工组..." << endl; }
	void add() { cout << "客户要求增加一个页面..." << endl; }
	void deletes() { cout << "客户要求删除一个页面..." << endl; }
	void change() { cout << "客户要求修改一个页面..." << endl; }
	void plan() { cout << "客户要求页面变更计划..." << endl; }

};
class CodeGroup :public Group
{
public:
	void find() { cout << "找到代码组..." << endl; }
	void add() { cout << "客户要求增加一个功能..." << endl; }
	void deletes() { cout << "客户要求删除一个功能..." << endl; }
	void change() { cout << "客户要求修改一个功能..." << endl; }
	void plan() { cout << "客户要求功能变更计划..." << endl; }

};
//抽象命令类
class Command {
public:
	virtual void execute() = 0;
protected:
	PageGroup* pg = new PageGroup();
	RequirementGroup* rg = new RequirementGroup();
	CodeGroup* cg = new CodeGroup();
};
//增加需求的命令
class AddRequirementCommand :public Command
{
public:
	void execute()
	{
		this->rg->find();
		this->rg->add();
		this->rg->plan();
	}
};
class DeletePageCommand :public Command
{
public:
	void execute()
	{
		this->pg->find();
		this->pg->deletes();
		this->pg->plan();
	}
};
//负责人
class Invoker
{
private:
	Command* command;
public:
	void serCommand(Command* command)
	{
		this->command = command;
	}
	void action()
	{
		this->command->execute();
	}
};
int main()
{
	//cout << "-----------------------" << endl;
	//Group* rg = new RequirementGroup();
	//rg->find();
	//rg->add();
	//rg->change();
	//rg->deletes();
	//rg->plan();
	cout << "-----------------------" << endl;
	Invoker* xiaosan = new Invoker();
	Command* command = new AddRequirementCommand();
	xiaosan->serCommand(command);
	xiaosan->action();
}