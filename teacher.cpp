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

	OlderFile of;

	if (of.size == 0)
	{
		cout << "没有预约记录" << endl;
		system("pause");
		system("cls");
		return;
	}

	for (int i = 0; i < of.size; i++)
	{
		cout << "本周" << of.older[i]["date"] << " ";
		cout << "时间段:" << (of.older[i]["interval"] == "1" ? "上午" : "下午") << " ";
		cout << "预约人id:" << of.older[i]["stuId"] << " ";
		cout << "预约人:" << of.older[i]["stuName"] << " ";
		cout << "预约机房号:" << of.older[i]["roomId"] << " ";

		string status = "状态：";
		if (of.older[i]["status"] == "1")
		{
			status += "审核中";
		}
		else if (of.older[i]["status"] == "2")
		{
			status += "预约成功";
		}
		else if (of.older[i]["status"] == "-1")
		{
			status += "预约失败";
		}
		else
		{
			status += "预约已取消";
		}

		cout << status << endl;
	}

	system("pause");
	system("cls");
	return;

}

// 审核预约
void Teacher::auditOlder()
{

}