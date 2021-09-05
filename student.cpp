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

	this->initStudent();
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
	cout << "机房开放时间为周一至周五！" << endl;
	cout << "请输入申请预约的时间：" << endl;
	cout << "1、周一" << endl;
	cout << "2、周二" << endl;
	cout << "3、周三" << endl;
	cout << "4、周四" << endl;
	cout << "5、周五" << endl;
	int date = 0;
	int interval = 0;
	int room = 0;

	while (true)
	{
		cin >> date;
		if (date >= 1 && date <= 5)
		{
			break;
		}
		cout << "输入有误，请重新输入" << endl;
	}


	cout << "请输入申请预约的时间段：" << endl;
	cout << "1、上午" << endl;
	cout << "2、下午" << endl;

	while (true)
	{
		cin >> interval;
		if (interval >= 1 && interval <= 2)
		{
			break;
		}
		cout << "输入有误，请重新输入" << endl;
	}


	cout << "请选择机房：" << endl;

	for (vector<ComputerRoom>::iterator it = this->vCom.begin(); it != this->vCom.end(); it++)
	{
		cout << (*it).roomId << "号机房容量" << (*it).maxNum << endl;
	}
	/*cout << "1号机房容量：" << vCom[0].m_MaxNum << endl;
	cout << "2号机房容量：" << vCom[1].m_MaxNum << endl;
	cout << "3号机房容量：" << vCom[2].m_MaxNum << endl;*/

	while (true)
	{
		cin >> room;
		if (room >= 1 && room <= this->vCom.size())
		{
			break;
		}
		cout << "输入有误，请重新输入" << endl;
	}

	cout << "预约成功！审核中" << endl;

	ofstream ofs(OLDER_FILE, ios::app);

	ofs << "date:" << date << " ";
	ofs << "interval:" << interval << " ";
	ofs << "stuId:" << this->studentId << " ";
	ofs << "stuName:" << this->name << " ";
	ofs << "roomId:" << room << " ";
	ofs << "status:" << 1 << endl;

	ofs.close();

	system("pause");
	system("cls");

}

// 查看自身的预约-- - 查看自己的预约状态
void Student::showMyOlder()
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
		if (this->studentId == atoi(of.older[i]["stuId"].c_str()))
		{
			cout << "本周" << of.older[i]["date"] << " ";
			cout << "时间段:" << (of.older[i]["interval"] == "1" ? "上午" : "下午") << " ";
			cout << "预约人id:" << of.older[i]["stuId"] << " ";
			cout << "预约人:" << of.older[i]["stuName"] << " ";
			cout << "预约机房号:" << of.older[i]["roomId"] << " ";

			string status = "状态";
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

	}
		
	system("pause");
	system("cls");
	return;


}

// 查看所有预约-- - 查看全部预约信息以及预约状态
void Student::showAllOlder()
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
		cout << "时间段:" << (of.older[i]["interval"]== "1" ? "上午":"下午") << " ";
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

// 取消预约-- - 取消自身的预约，预约成功或审核中的预约均可取消
void Student::cancelOlder()
{
	OlderFile of;

	if (of.size==0)
	{
		cout << "无预约记录" << endl;
		system("pause");
		system("cls");
		return;
	}


	cout << "请选择要取消的预约。0表示返回。" << endl;
	
	vector<int>v;
	int index = 1;
	for (int i = 0; i < of.size; i++)
	{
		if (this->studentId == atoi(of.older[i]["stuId"].c_str()))
		{
			if (atoi(of.older[i]["status"].c_str()) == 1 || atoi(of.older[i]["status"].c_str()) == 2)
			{
				v.push_back(i);
				cout << index++ << " ";
				cout << "本周" << of.older[i]["date"] << " ";
				cout << "时间段:" << (of.older[i]["interval"] == "1" ? "上午" : "下午") << " ";
				cout << "预约人id:" << of.older[i]["stuId"] << " ";
				cout << "预约人:" << of.older[i]["stuName"] << " ";
				cout << "预约机房号:" << of.older[i]["roomId"] << " ";

				string status = "状态";
				if (of.older[i]["status"] == "1")
				{
					status += "审核中";
				}
				else if (of.older[i]["status"] == "2")
				{
					status += "预约成功";
				}

				cout << status << endl;

			}
			
		}

	}

	int select;
	while (true)
	{
		cin >> select;
		if (select >= 0 && select <= v.size())
		{
			if (select == 0)
			{
				system("cls");
				break;
			}
			else
			{
				of.older[v[select - 1]]["status"] = "0";
				cout << "取消预约成功" << endl;
				of.upDateOlder();
				system("cls");
				break;
			}
		}
		else
		{
			cout << "选择有误，任意键退出" << endl;
			system("pause");
			system("cls");
			return;
		}
	}

	return;

}


//初始化容器
void Student::initStudent()
{
	ifstream ifs;
	ifs.open(COMPUTER_FILE, ios::in);

	this->vCom.clear();

	ComputerRoom c;
	while (ifs >> c.roomId && ifs >> c.maxNum)
	{
		this->vCom.push_back(c);
	}

	ifs.close();

}