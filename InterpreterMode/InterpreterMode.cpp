//---------------------------------------------------------
//设计模式练习：解释器模式
//
//作者：Mxd--
//时间：2020/05/30
//----------------------------------------------------------
#include<iostream>
#include<map>
#include <stack>
#include <string>
using namespace std;

//抽象表达式类
class Expression {
public:
	virtual int interpreter(map<string,int> var) = 0;
};
//变量解析器
class VarExpression :public Expression
{
private:
	string _key;
public:
	VarExpression(string key)
	{
		this->_key = key;
	}
	int interpreter(map<string, int> var)
	{
		return var[this->_key];
	}
};
//抽象运算符号解析器
class SymbolExpression :public Expression
{
protected:
	Expression* _left;
	Expression* _right;
public:
	SymbolExpression(Expression* left, Expression* right)
	{
		this->_left = left;
		this->_right = right;
	}
};
//加法解析器
class AddExpression :public SymbolExpression
{
public:
	AddExpression(Expression* left, Expression* right) :SymbolExpression(left, right)
	{
	}
	int interpreter(map<string, int> var)
	{
		return SymbolExpression::_left->interpreter(var) + SymbolExpression::_right->interpreter(var);
	}
};
//减法解析器
class SubExpression :public SymbolExpression
{
public:
	SubExpression(Expression* left, Expression* right) :SymbolExpression(left, right)
	{
	}
	int interpreter(map<string, int> var)
	{
		return SymbolExpression::_left->interpreter(var) - SymbolExpression::_right->interpreter(var);
	}
};
//解释器封装类
class Calculator
{
private:
	Expression* expression;
public:
	Calculator(string expStr)
	{
		stack<Expression*> stack;
		Expression* left;
		Expression* right;
		//这里将expStr 按照递归的方式转换到一个Expression中
		//然后再依次拆解运算
		for (int i = 0; i < expStr.size(); i++)
		{
			switch (expStr[i])
			{
			case '+':
				left = stack.top();
				stack.pop();
				right = new VarExpression(to_string(expStr[++i]));
				stack.push(new AddExpression(left, right));
				break;
			case '-':
				left = stack.top();
				stack.pop();
				right = new VarExpression(to_string(expStr[++i]));
				stack.push(new SubExpression(left, right));
				break;
			default:
				stack.push(new VarExpression(to_string(expStr[i])));
				break;
			}
		}
		this->expression = stack.top();
		stack.pop();
	}
	int run(map<string, int> var)
	{
		return this->expression->interpreter(var);
	}
};
int main()
{
	while (true)
	{
		cout << "请输入表达式" << endl;
		string expStr;
		getline(cin, expStr);
		map<string, int> var;
		for (char ch : expStr)
		{
			if (ch != '+' && ch != '-')
			{
				//var 中 找不到ch
				if (!(var.find(to_string(ch)) != var.end()))
				{
					int in;
					cout << "请输入" << ch << "的值：";
					cin >> in;
					var[to_string(ch)] = in;
				}
			}
		}
		Calculator cal = Calculator(expStr);
		cout << "运算结果为：" << expStr << "=" << cal.run(var) << endl;
		cin.get();
	}
}