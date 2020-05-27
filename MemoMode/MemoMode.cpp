//---------------------------------------------------------
//设计模式练习：备忘录模式
//备忘录管理者的引入是为了满足迪米特法则 只和朋友类交流
//作者：Mxd--
//时间：2020/05/27
//----------------------------------------------------------
#include<iostream>
using namespace std;
//备忘录类
class Memento {
private:
	string _state = "";
public:
	Memento(string state) {
		this->_state = state;
	}
	string getState()
	{
		return this->_state;
	}
	void setState(string state)
	{
		this->_state = state;
	}
};
class Boy {
private:
	string _state = "";
public:
	void changeState() {
		this->_state = "心情可能很不好~";
	}
	string getState()
	{
		return this->_state;
	}
	void setState(string state)
	{
		this->_state = state;
	}
	Memento createMemento() {
		return Memento(this->getState());
	}
	void readMemento(Memento _memento) {
		this->setState(_memento.getState());
	}
};

class Caretaker {
private:
	Memento _memento = Memento("");
public:
	Memento getMemento() {
		return this->_memento;
	}
	void setMemento(Memento memento) {
		this->_memento = memento;
	}
};
int main()
{
	Boy boy;
	Caretaker caretaker;
	boy.setState("心情很棒");
	cout << boy.getState() << endl;
	cout << "-----------------设置标记---------------" << endl;
	caretaker.setMemento(boy.createMemento());
	//Memento memento = Memento(boy.getState());
	cout << "去追女孩子了，失败了" << endl;
	boy.changeState();
	cout << boy.getState() << endl;
	cout << "-----------------恢复心情---------------" << endl;
	boy.readMemento(caretaker.getMemento());
	//boy.setState(memento.getState());
	cout << boy.getState() << endl;
}