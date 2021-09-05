#include "teacher.h"

//默认构造
Teacher::Teacher()
{

}

//有参构造
Teacher::Teacher(int id, string name, string password)
{
	this->TeacherId = id;
	this->name = name;
	this->password = password;
}

//老师菜单页面
void Teacher::operMenu()
{
	cout << "欢迎教师：" << this->name << "登录！" << endl;
	cout << "\t\t ----------------------------------\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t|          1.查看所有预约          |\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t|          2.审核预约              |\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t|          0.注销登录              |\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t ----------------------------------\n";
	cout << "请选择您的操作： " << endl;
}


// 查看所有预约-- - 查看全部预约信息以及预约状态
void Teacher::showAllOlder()
{

}

// 审核预约
void Teacher::auditOlder()
{

}