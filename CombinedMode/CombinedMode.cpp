//---------------------------------------------------------
//设计模式练习：组合模式
//
//作者：Mxd--
//时间：2020/05/25
//----------------------------------------------------------
#include<iostream>
#include <string>
#include <vector>
using namespace std;

//抽象公司职员类
class Corp
{
public:
	Corp(string name, string position, int salary)
	{
		this->_name = name;
		this->_position = position;
		this->_salary = salary;
	}
	string getInfo()
	{
		string info = "";
		info = "姓名：" + this->_name;
		info += "\t职位：" + this->_position;
		info += "\t薪水：" + to_string(this->_salary);
		return info;
	}
private:
	string _name = "";
	string _position = "";
	int _salary = 0;
public:
	bool flag;
};
//树叶结点
class Leaf : public Corp
{
public:
	Leaf(string name, string position, int salary) :Corp(name, position, salary)
	{
		this->flag = true;
	}
};
class Branch :public Corp
{
private:
	vector<Corp *> subordinateList;
public:
	Branch(string name, string position, int salary) :Corp(name, position, salary)
	{
		this->flag = false;
	}
	void addSubordinate(Corp* corp)
	{
		this->subordinateList.push_back(corp);
	}
	vector<Corp*> getSubordinate()
	{
		return subordinateList;
	}
};
//组装树
Branch* compositeCorpTree()
{
	Branch* root = new Branch("王大麻子", "总经理",10000);
	Branch* developDep = new  Branch("刘大瘸子", "研发部门经理", 8000);
	Leaf* salesDep = new Leaf("马二拐子", "销售部门经理", 8000);
	Leaf* financeDep = new Leaf("赵三坨子", "财务部门经理", 8000);
	Branch* fristDevGrop = new Branch("asdsss", "研发一组", 5000);
	Branch* secondDevGrop = new Branch("assss", "研发二组", 5000);
	Leaf* a = new Leaf("a", "研发人员", 3000);
	Leaf* b = new Leaf("b", "研发人员", 3000);
	Leaf* c = new Leaf("c", "研发人员", 3000);
	Leaf* d = new Leaf("d", "研发人员", 3000);
	Leaf* e = new Leaf("e", "研发人员", 3000);
	Leaf* f = new Leaf("f", "研发人员", 3000);
	Leaf* g = new Leaf("g", "研发人员", 3000);
	Leaf* h = new Leaf("h", "研发人员", 3000);
	Leaf* k = new Leaf("倩倩", "ceo秘书", 8000);
	root->addSubordinate(k);
	root->addSubordinate(developDep);
	root->addSubordinate(salesDep);
	root->addSubordinate(financeDep);
	developDep->addSubordinate(fristDevGrop);
	developDep->addSubordinate(secondDevGrop);
	fristDevGrop->addSubordinate(a);
	fristDevGrop->addSubordinate(b);
	fristDevGrop->addSubordinate(c);
	fristDevGrop->addSubordinate(d);
	secondDevGrop->addSubordinate(e);
	secondDevGrop->addSubordinate(f);
	secondDevGrop->addSubordinate(g);
	secondDevGrop->addSubordinate(h);
	return root;
}
string getTreeInfo(Branch* root)
{
	vector<Corp*> subordinateList = root->getSubordinate();
	string Info = "";
	for (Corp* s : subordinateList)
	{
		if (s->flag)
		{
			Info += ((Leaf *)s)->getInfo() + "\n";
		}
		else
		{
			Info += s->getInfo() + "\n" + getTreeInfo((Branch *)s);
		}
	}
	return Info;
}
int main()
{
	Branch* ceo = compositeCorpTree();
	cout << ceo->getInfo() << endl;
	cout << getTreeInfo(ceo) << endl;
}