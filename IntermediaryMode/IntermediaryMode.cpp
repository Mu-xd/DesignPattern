#include<iostream>
using namespace std;
//抽象中介者
class AbstractMediator
{
public:
	virtual void execute(string str, int objects) = 0;
};

class AbstractColleague
{
protected:
	AbstractMediator* mediator;
public:
	AbstractColleague(AbstractMediator* _mediator)
	{
		this->mediator = _mediator;
	}
};
class Purchase:public AbstractColleague
{
public:
	Purchase(AbstractMediator* _madiator):AbstractColleague(_madiator)
	{
	}
	void buyIBMcomputer(int number)
	{
		this->mediator->execute("purchase.buy", number);
	};
	void refuseBuyIBM() {
		cout << "不采购IBM电脑" << endl;
	};
};
class Sale :public AbstractColleague
{
public:
	Sale(AbstractMediator* _madiator) :AbstractColleague(_madiator)
	{
	}
	void sellIBMComputer(int number);
	int getSaleStatus();
	void offSale();
};
class Stock:public AbstractColleague
{
public:
	Stock(AbstractMediator* _madiator) :AbstractColleague(_madiator)
	{
	}
	void increase(int number);
	void decrease(int number);
	int getStockNumber();
	void clearStock();
private:
	static int COMPUTER_NUMBER;
};
class Mediator :public AbstractMediator
{
protected:
	Purchase* purchase;
	Sale* sale;
	Stock* stock;
public:
	Mediator() {
		this->purchase = new Purchase(this);
		this->sale = new Sale(this);
		this->stock = new Stock(this);
	}
	void execute(string str, int objects) {
		if (str == "purchase.buy")
			this->buyComputer(objects);
		else if (str == "sale.sell")
			this->sellComputer(objects);
		else if (str == "sale.offsell")
			this->offSell();
		else if (str == "stock.clear")
			this->clearStock();

	};
private:
	void buyComputer(int number)
	{
		int saleStatus = this->sale->getSaleStatus();
		if (saleStatus > 80)
			cout << "采购IBM电脑：" << number << "台" << endl;
		else
			cout << "采购IBM电脑：" << number / 2 << "台" << endl;
	}
	void sellComputer(int number)
	{
		if (this->stock->getStockNumber() < number)
			this->purchase->buyIBMcomputer(number);
		this->stock->decrease(number);
	}
	void offSell()
	{
		cout << "折价销售IBM电脑：" + this->stock->getStockNumber() << "台" << endl;
	}
	void clearStock() {
		this->sale->offSale();
		this->purchase->refuseBuyIBM();
	}
};
//--------------------Stock-----------------------------------------------
int Stock::COMPUTER_NUMBER = 100;
void Stock::increase(int number)
{
	this->COMPUTER_NUMBER = this->COMPUTER_NUMBER + number;
	cout << "当前库存数量为：" << this->COMPUTER_NUMBER << endl;
};
void Stock::decrease(int number)
{
	this->COMPUTER_NUMBER = this->COMPUTER_NUMBER - number;
	cout << "当前库存数量为：" << this->COMPUTER_NUMBER << endl;
};
int Stock::getStockNumber()
{
	return this->COMPUTER_NUMBER;
}
void Stock::clearStock()
{
	cout << "清理存货数量为" << this->COMPUTER_NUMBER << endl;
	((Mediator*)this->mediator)->execute("stock.clear",0);
}

//--------------------Sale----------------------------------
void Sale::sellIBMComputer(int number)
{
	((Mediator*)this->mediator)->execute("sale.sell", number);
	cout << "销售IBM电脑" << number << "台" << endl;
}
int Sale::getSaleStatus()
{
	int saleStatus = rand() % 100 / 1;
	cout << "IBM电脑的销售情况为" << saleStatus << endl;
	return saleStatus;
}
void Sale::offSale()
{
	((Mediator*)this->mediator)->execute("sale.offSale", 0);
}


int main()
{
	Mediator* mediator = new Mediator();
	cout << "-----------------------采购电脑" << endl;
	Purchase* p = new Purchase(mediator);
	p->buyIBMcomputer(100);
	cout << "-----------------------销售电脑" << endl;
	Sale* sale = new Sale(mediator);
	sale->sellIBMComputer(1);
	cout << "-----------------------库存清理" << endl;
	Stock* stock = new Stock(mediator);
	stock->clearStock();



}