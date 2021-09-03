#pragma once
#include <string>
using namespace std;

class Identity
{
public:

	//菜单界面虚函数
	virtual void operMenu() = 0;

	//用户名与密码
	string name;
	string password;

};