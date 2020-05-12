#include<iostream>
#include <mutex>

using namespace std;

class Emperor
{
public:
	static Emperor * getInstance() {
		//双检测锁
		if (Em == NULL)
		{
			mt.lock();
			if (Em == NULL)
				Em = new Emperor();
			mt.unlock();
		}
		return Em;
	};
	static void say() {
		cout << "我是皇上...." << endl;
	}
private:
	static mutex mt;
	static Emperor *Em;
	//禁止拷贝和复制
	Emperor(const Emperor&);
	Emperor& operator=(const Emperor&);

	Emperor() {
	};
};
Emperor* Emperor::Em = new Emperor();
mutex Emperor::mt = mutex();
void say() {
	cout << "我是皇上...." << endl;
}
int main()
{
	for (int i = 0; i < 5; i++)
	{
		auto Em = Emperor::getInstance();
		Em->say();
		cout << Em << endl;
	}
}