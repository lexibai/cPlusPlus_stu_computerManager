#include "student.h"

//默认构造
Student::Student()
{
	studentId = 0;
	name = ' ';
	password = ' ';
}

//有参构造
Student::Student(int id, string name, string password)
{
	this->studentId = id;
	this->name = name;
	this->password = password;

}

//学生菜单页面
void Student::operMenu()
{
	cout << "欢迎学生代表：" << this->name << "登录！" << endl;
	cout << "\t\t ----------------------------------\n";
	cout << "\t\t|                                 |\n";
	cout << "\t\t|          1.申请预约              |\n";
	cout << "\t\t|                                 |\n";
	cout << "\t\t|          2.查看我的预约          |\n";
	cout << "\t\t|                                 |\n";
	cout << "\t\t|          3.查看所有预约          |\n";
	cout << "\t\t|                                 |\n";
	cout << "\t\t|          4.取消预约              |\n";
	cout << "\t\t|                                 |\n";
	cout << "\t\t|          0.注销登录              |\n";
	cout << "\t\t|                                 |\n";
	cout << "\t\t ----------------------------------\n";
	cout << "请选择您的操作： " << endl;

}

//申请预约-- - 预约机房
void Student::applyOlder()
{

}

// 查看自身的预约-- - 查看自己的预约状态
void Student::showMyOlder()
{

}

// 查看所有预约-- - 查看全部预约信息以及预约状态
void Student::showAllOlder()
{

}

// 取消预约-- - 取消自身的预约，预约成功或审核中的预约均可取消
void Student::cancelOlder()
{

}