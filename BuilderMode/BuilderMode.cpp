//------------------------------------------------------
//设计模式联系：建造者模式
//作者：Mxd
//时间：2020/05/14
//------------------------------------------------------

#include<iostream>
#include <string>
#include <list>
using namespace std;
//模型类
class CarModel
{
private:
	list<string> sequence;
protected:
	virtual void start() = 0;
	virtual void stop() = 0;
	virtual void alarm() = 0;
	virtual void engineBoom() = 0;
public:
	void run() {
		for (string Item : this->sequence)
		{
			if (Item == "start")
				this->start();
			else if (Item == "stop")
				this->stop();
			else if (Item == "alarm")
				this->alarm();
			else if (Item == "engineBoom")
				this->engineBoom();
		}
	}
	void setSequence(list<string> sequence)
	{
		this->sequence = sequence;
	}
};
class BenzModel :public CarModel
{
protected:
	void start() {
		cout << "奔驰车启动...." << endl;
	}
	void stop() {
		cout << "奔驰车停止...." << endl;
	}
	void alarm() {
		cout << "奔驰车的喇叭声音...." << endl;
	}
	void engineBoom() {
		cout << "奔驰车的引擎声音...." << endl;
	}

};
class BWMModel :public CarModel
{
protected:
	void start() {
		cout << "宝马车启动...." << endl;
	}
	void stop() {
		cout << "宝马车停止...." << endl;
	}
	void alarm() {
		cout << "宝马车的喇叭声音...." << endl;
	}
	void engineBoom() {
		cout << "宝马车的引擎声音...." << endl;
	}
};
//抽象建造者
class CarBuilder
{
public:
	virtual void SetSequnce(list<string> sequence) = 0;
	virtual CarModel* getCarModel() = 0;
};
class BenzBuilder
{
private:
	BenzModel* banz = new BenzModel();
public:
	CarModel* getCarModel() {
		return this->banz;
	};
	void SetSequnce(list<string> sequence)
	{
		this->banz->setSequence(sequence);
	}
};
class BWMBuilder
{
private:
	BWMModel* bwm = new BWMModel();
public:
	CarModel* getCarModel() {
		return this->bwm;
	};
	void SetSequnce(list<string> sequence)
	{
		this->bwm->setSequence(sequence);
	}
};
//导演类（建造者指挥类）
class Director {
private:
	list<string> sequence;
	BenzBuilder* benzber = new BenzBuilder();
	BWMBuilder* bwmber = new BWMBuilder();
public:
	CarModel* getABenzModel() {
		this->sequence.clear();
		this->sequence.push_back("start");
		this->sequence.push_back("stop");
		this->benzber->SetSequnce(sequence);
		return this->benzber->getCarModel();
	}
	CarModel* getBBenzModel() {
		this->sequence.clear(); 
		this->sequence.push_back("engineBoom");
		this->sequence.push_back("start");
		this->sequence.push_back("stop");
		this->benzber->SetSequnce(sequence);
		return this->benzber->getCarModel();
	}
	CarModel* getABWMModel() {
		this->sequence.clear();
		this->sequence.push_back("alarm");
		this->sequence.push_back("start");
		this->sequence.push_back("stop");
		this->bwmber->SetSequnce(sequence);
		return this->bwmber->getCarModel();
	}
	CarModel* getBBWMModel() {
		this->sequence.clear();
		this->sequence.push_back("start");
		this->benzber->SetSequnce(sequence);
		this->bwmber->SetSequnce(sequence);
		return this->bwmber->getCarModel();
	}
};
int main()
{
	Director* dor = new Director();
	cout << "-----------ABenz----------" << endl;
	dor->getABenzModel()->run();
	cout << "-----------BBenz----------" << endl;
	dor->getBBenzModel()->run();
	cout << "-----------ABWM----------" << endl;
	dor->getABWMModel()->run();
	cout << "-----------BBWM----------" << endl;
	dor->getBBWMModel()->run();
}