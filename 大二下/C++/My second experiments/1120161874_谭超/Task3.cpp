//#include"stdafx.h"
#include<iostream>
#include<bitset>
#include<cmath>
using namespace std;
class IntChar//定义IntChar类，该类中仅含一个int型成员变量
{
private:
	int store = 0;
public:
	IntChar(string s);//定义该类的构造函数
	void ASC_Print();
	void Binary_Print();
	void Int_Print();
};
IntChar::IntChar(string s)
{
	int len = s.length();
	int i = 0;
	while (len--)//将一个长度不大于4的字符串转化为整数存储在整型变量store中
	{
		store += s[len] * pow(2, i * 8);
		i++;
	}
}
void IntChar::ASC_Print()//将该整数分为四个字符输出
{
	int rep = store;
	int i = 4;
	while (i--)
	{
		int h= pow(2,i*8);
		int left = rep/h;
		rep %= h;
		if (left != 0) cout << char(left);//每次取整数的前8个二进制位转化为字符输出
	}
	cout << endl;
}
void IntChar::Binary_Print()//将该整数 以32位二进制输出
{
	int rep = store;
	cout << bitset<sizeof(int) * 8>(rep)<< endl;//调用bitset函数 
}
void IntChar::Int_Print()//直接输出该整数
{
	cout << store<<endl;
}
int main()
{
	IntChar IC("Love");//创建一个IntChar类
	IC.ASC_Print();//调用该类的各个函数
	IC.Binary_Print();
	IC.Int_Print();
	//system("pause");
}