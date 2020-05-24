//----------------------------------------------------------------
//设计模式练习：迭代器模式
//作者:Mxd
//时间;2020/05/24
//----------------------------------------------------------------
#include<iostream>
#include<vector>
#include <string>
using namespace std;

//迭代器接口
class IProjectIterator
{
};

//项目接口
class IProject
{
public:
	virtual void add(string name, int num, int cost) = 0;
	virtual string getProjectInfo() = 0;
	virtual IProjectIterator* iterator() = 0;
};
class ProjectIterator :public IProjectIterator
{
private:
	vector<IProject*> _projectlist;
	int _currentItem = 0;
public:
	ProjectIterator(vector<IProject*> &projectlist)
	{
		this->_projectlist = projectlist;
	}
	bool hasNext()
	{
		bool b = true;
		if (this->_currentItem >= this->_projectlist.size())
			b = false;
		return b;
	}
	IProject* next()
	{
		return this->_projectlist[this->_currentItem++];
	}
};
class Project :public IProject
{
private:
	vector<IProject*> _projectlist;
	string _name = "";
	int _num = 0;
	int _cost = 0;
	Project(string name,int num,int cost) {
		this->_name = name;
		this->_num = num;
		this->_cost = cost;
	}
public:
	Project()
	{
	}
	void add(string name, int num, int cost)
	{
		this->_projectlist.push_back(new Project(name, num, cost));
	}
	string getProjectInfo()
	{
		string Info = "";
		Info += "项目名称:" + this->_name;
		Info += "\t项目人数：" + to_string(this->_num);
		Info += "\t项目费用：" + to_string(this->_cost);
		return Info;
	}
	IProjectIterator* iterator()
	{
		return new ProjectIterator(this->_projectlist);
	}
};

int main()
{
	IProject* project = new Project();
	project->add("星球大战项目ddddd", 10, 100000);
	project->add("扭转时空项目-----", 1000, 1000000);
	project->add("超人改造项目*****", 100, 41545);
	IProjectIterator* projectIterator = project->iterator();
	while (((ProjectIterator*)projectIterator)->hasNext())
	{
		IProject* p = ((ProjectIterator*)projectIterator)->next();
		cout << p->getProjectInfo() << endl;
	}
}