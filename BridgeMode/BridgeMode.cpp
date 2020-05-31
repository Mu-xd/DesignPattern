//---------------------------------------------------------
//设计模式练习：桥梁模式
//
//作者：Mxd--
//时间：2020/05/31
//----------------------------------------------------------
#include<iostream>
using namespace std;

 //抽象产品类
class Product
{
public:
    virtual void beProducted() = 0;
    virtual void beSelled() = 0;
};
//具体产品
class House :public Product
{
public:
    void beProducted()
    {
        cout << "生产出的房子是这样的..." << endl;
    }
    void beSelled()
    {
        cout << "生产出的房子卖出去了..." << endl;
    }
};
class Ipod :public Product
{
public:
    void beProducted()
    {
        cout << "生产出的Ipod是这样的..." << endl;
    }
    void beSelled()
    {
        cout << "生产出的Ipod卖出去了..." << endl;
    }
};
//抽象公司类
class Corp
{
private:
    Product* _product;
public:
    Corp(Product* product)
    {
        this->_product = product;
    }
    void makeMoney() {
        this->_product->beProducted();
        this->_product->beSelled();
    }
};
//具体产品类
class HoseCorp :public Corp
{
public:
    HoseCorp(Product* product) :Corp(product)
    {
    }
    void makeMoney() {
        Corp::makeMoney();
        cout << "地产公司赚大钱了..." << endl;
    }
};
class ShanZhaiCorp :public Corp
{
public:
    ShanZhaiCorp(Product* product) :Corp(product)
    {
    }
    void makeMoney() {
        Corp::makeMoney();
        cout << "山寨公司赚大钱了..." << endl;
    }
};
int main()
{
    cout << "---------------房产公司运行---------------------" << endl;
    HoseCorp houseCorp = HoseCorp(new House());
    houseCorp.makeMoney();
    cout << "-------------山寨公司运行------------------------" << endl;
    ShanZhaiCorp(new Ipod()).makeMoney();
}