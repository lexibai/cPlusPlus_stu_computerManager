#include <iostream>
#include <fstream>
#include <string>
#include "identity.h"
#include "student.h"
#include "teacher.h"
#include "manager.h"
#include "globalFile.h"
using namespace std;

//管理员子菜单
void managerMenu(Identity*& manager)
{

	while (true)
	{
		manager->operMenu();
		Manager* man = (Manager*)manager;


		int select;
		cin >> select;
		switch (select)
		{
		case 1:
			//1.添加账号
			man->addPerson();
			break;
		case 2:
			//2.查看账号 
			man->showPerson();
			break;
		case 3:
			// 3.查看机房
			man->showComputer();
			break;
		case 4:
			// 4.清空预约
			man->cancelFile();
			break;
		default:
			//0.注销登录 
			delete manager;
			cout << "注销成功" << endl;
			system("pause");
			system("cls");
			return;
		}
	}

}

//学生子菜单
void studentMenu(Identity*& student)
{

	while (true)
	{
		student->operMenu();
		Student* stu = (Student*)student;


		int select;
		cin >> select;
		switch (select)
		{
		case 1:
			//申请预约
			stu->applyOlder();
			break;
		case 2:
			//查看自己的预约
			stu->showMyOlder();
			break;
		case 3:
			//查看全部预约
			stu->showAllOlder();
			break;
		case 4:
			//取消预约
			stu->cancelOlder();
			break;
		default:
			//0.注销登录 
			delete student;
			cout << "注销成功" << endl;
			system("pause");
			system("cls");
			return;
		}
	}

}

//登录验证
void loginIn(const string fileName, int type)
{
	Identity* person = NULL;

	ifstream ifs;
	ifs.open(fileName, ios::in);

	if (!ifs.is_open())
	{
		cout << "文件打开失败" << endl;
		system("pause");
		system("cls");
		return;
	}

	int id = 0;
	string name;
	string password;

	if (type == STUDENT_TYPE)
	{
		cout << "请输入学生id号" << endl;
		cin >> id;
	}
	else if (type == TEACHER_TYPE)
	{
		cout << "请输入老师id号" << endl;
		cin >> id;
	}

	cout << "请输入用户名" << endl;
	cin >> name;
	cout << "请输入密码" << endl;
	cin >> password;

	if (type == STUDENT_TYPE)
	{
		//学生验证
		ifstream ifs;
		ifs.open(STUDENT_FILE, ios::in);

		int fId;
		string fName;
		string fPassword;

		while (ifs >> fId && ifs >> fName && ifs >> fPassword)
		{
			if (fId == id && fName == name && fPassword == password)
			{
				cout << "验证成功，已登录" << endl;
				system("pause");
				system("cls");
				person = new Student(fId, fName, fPassword);
				return;
			}
		}

	}
	else if (type == TEACHER_TYPE)
	{
		//老师验证
		ifstream ifs;
		ifs.open(TEACHER_FILE, ios::in);

		int fId;
		string fName;
		string fPassword;

		while (ifs >> fId && ifs >> fName && ifs >> fPassword)
		{
			if (fId == id && fName == name && fPassword == password)
			{
				cout << "验证成功，已登录" << endl;
				system("pause");
				system("cls");
				person = new Teacher(fId, fName, fPassword);
				return;
			}

		}
	}
	else if (type == MANAGER_TYPE)
	{
		//管理员身份验证

		ifstream ifs;
		ifs.open(MANAGER_FILE, ios::in);

		string fName;
		string fPassword;

		while ( ifs >> fName && ifs >> fPassword)
		{
			if ( fName == name && fPassword == password)
			{
				cout << "验证成功，已登录" << endl;
				system("pause");
				system("cls");
				person = new Manager(fName, fPassword);
				managerMenu(person);
				return;
			}
		}

	}
	else
	{
		cout << "type类型输入有误" << endl;
		system("pause");
		system("cls");
		return;
	}

	cout << "登录失败，返回主菜单" << endl;
	system("pause");
	system("cls");

}



int main(void)
{
	int select;

	while (true)
	{
		cout << "======================  欢迎来到唐乐的机房预约系统  ====================="<< endl;
		cout << endl << "请输入您的身份" << endl;
		cout << "\t\t -------------------------------\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t|          1.学生代表           |\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t|          2.老    师           |\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t|          3.管 理 员           |\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t|          0.退    出           |\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t -------------------------------\n";
		cout << "输入您的选择: ";

		cin >> select;
		switch (select)
		{
		case STUDENT_TYPE:
			loginIn(STUDENT_FILE, STUDENT_TYPE);
			break;
		case TEACHER_TYPE:
			loginIn(TEACHER_FILE, TEACHER_TYPE);
			break;
		case MANAGER_TYPE:
			loginIn(MANAGER_FILE, MANAGER_TYPE);
			break;
		case 0:
			cout << "欢迎下次使用" << endl;
			system("pause");
			return 0;
			break;
		default:
			cout << "输入有误，请重新输入" << endl;
			system("pause");
			system("cls");
			break;
		}

	}

	system("pause");
	return 0;
}