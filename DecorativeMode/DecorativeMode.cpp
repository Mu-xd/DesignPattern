#include<iostream>

using namespace std;

class SchoolReport {
public:
	virtual void report() = 0;
	virtual void sign(string) = 0;
};
class Decorator :public SchoolReport
{
private:
	SchoolReport* _sr;
public:
	Decorator(SchoolReport* sr)
	{
		this->_sr = sr;
	}
	void report()
	{
		this->_sr->report();
	}
	void sign(string name)
	{
		this->_sr->sign(name);
	}
};
class HighScoreDecorator :public Decorator
{
public:
	HighScoreDecorator(SchoolReport* sr) :Decorator(sr)
	{
	}
private:
	void reportHighScore()
	{
		cout << "这次考试语文是75，数学是78，自然是80" << endl;
	}
public:
	void report() {
		this->reportHighScore();
		Decorator::report();//访问基类的方法
	}
};
class SortDecorator :public Decorator
{
public: 
	SortDecorator(SchoolReport* sr) :Decorator(sr)
	{}
	void report()
	{
		this->reportSort();
		Decorator::report();
	}
private:
	void reportSort()
	{
		cout << "我的排名是32名" << endl;
	}
};
class FouthGradeSchoolReport : public SchoolReport
{
public:
	void report()
	{
		cout << "尊敬的xxx家长：" << endl;
		cout << "......" << endl;
		cout << "语文 62 数学 65 体育 98 自然 63" << endl;
		cout << "......" << endl;
		cout << "				家长签名：" << endl;
	}
	void sign(string name)
	{
		cout << "家长签名为：" << name << endl;
	}
};
int main()
{
	SchoolReport* sr = new FouthGradeSchoolReport();
	sr = new HighScoreDecorator(sr);
	sr = new SortDecorator(sr);
	sr->report();
	sr->sign("小三");
}