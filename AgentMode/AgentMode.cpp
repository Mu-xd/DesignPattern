#include<iostream>
#include <time.h>
using namespace std;
//游戏者接口
class IGamePlater
{
public:
	virtual void login(string user, string password) = 0;
	virtual void killBoss() = 0;
	virtual void upgrade() = 0;
};
class GamePlayer :public IGamePlater
{
public:
	GamePlayer(string _name)
	{
		this->name = _name;
	};
	void killBoss()
	{
		cout << this->name + "在打怪！" << endl;
	};
	void login(string user, string password)
	{
		cout << "登录名为 " + user + " 的用户，" + this->name + "登录成功！" << endl;
	}
	void upgrade()
	{
		cout << this->name + "升了一级" << endl;
	}
private:
	string name = "";
};
//代理类  代理GamePlayer 这个代理类需要知道代理者是谁 通过调用代理者 来实现类的代理
class GamePlayerProxy :public IGamePlater
{
public:
	GamePlayerProxy(IGamePlater* _gameplayer)
	{
		this->gameplayer = _gameplayer;
	}
	void killBoss()
	{
		((GamePlayer*)this->gameplayer)->killBoss();
	};
	void login(string user, string password) 
	{
		cout << "-------专业代练100年------" << endl;
		((GamePlayer*)this->gameplayer)->login(user,password);
	};
	void upgrade() 
	{
		cout << "-------专业代练100年------" << endl;
		((GamePlayer*)this->gameplayer)->upgrade();  
		cout << "-------专业代练100年------" << endl;
	}
private:
	IGamePlater* gameplayer = NULL;
};
int main() {

	IGamePlater* player = new GamePlayer("张三");
	IGamePlater* proxy = new GamePlayerProxy(player);
	cout << "------------------------------------------" << endl;
	proxy->login("zhangSan", "password");
	for (int i = 0; i < 50; i++)
	{
		for(int j = 0;j<i;j++)
			proxy->killBoss();
		proxy->upgrade();
	}
	cout << "------------------------------------------" << endl;
}