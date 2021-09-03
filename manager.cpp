#include "manager.h"
using namespace std;


//打印学生函数
void printStudent(Student s)
{
	cout << "学生id为：" << s.studentId << "  学生的姓名为：" << s.name << "  学生的密码为：" << s.password << endl;
}


//打印老师函数
void printTeacher(Teacher & t)
{
	cout << "老师id为：" << t.TeacherId << "  老师的姓名为：" << t.name << "  老师的密码为：" << t.password << endl;
}



//构造函数
Manager::Manager()
{


}

Manager::Manager(string name, string password)
{
	this->name = name;
	this->password = password;

	this->initVector();
}

//管理员菜单界面
void Manager::operMenu()
{
	cout << "欢迎管理员：" << this->name << "登录！" << endl;
	cout << "\t\t ---------------------------------\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          1.添加账号            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          2.查看账号            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          3.查看机房            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          4.清空预约            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          0.注销登录            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t ---------------------------------\n";
	cout << "请选择您的操作： " << endl;

}

//添加账户
void Manager::addPerson()
{
	//选中输入账号的类型
	cout << "请输入要添加账号的类型：\n\t1.学生\n\t2.老师" << endl;
	int select;
	cin>>select;

	string fType;
	if (select == STUDENT_TYPE)
	{
		fType = STUDENT_FILE;
		cout << "请输入学生编号" << endl;
	}
	else
	{
		fType = TEACHER_FILE;
		cout << "请输入教工编号" << endl;
	}


	//打开对应文件进行添加
	ofstream ofs;
	ofs.open(fType, ios::out | ios::app);
	int fId;
	string fName;
	string fPassword;

	//获取输入id
	cin >> fId;

	//判断id是否重复
	if (checkRepeat(fId, select))
	{
		cout << "id输入重复，点任意键退出。" << endl;
		system("pause");
		system("cls");
		ofs.close();
		return;
	}

	cout << "请输入用户名" << endl;
	cin >> fName;
	cout << "请输入密码" << endl;
	cin >> fPassword;

	ofs << fId <<" "<< fName<< " " << fPassword<<endl;
	cout << "添加成功" << endl;

	this->initVector();

	system("pause");
	system("cls");
	ofs.close();

}

//查看账户
void Manager::showPerson()
{
	cout << " 请选择查看内容：\n1.学生\n2.老师" << endl;
	int select;
	cin >> select;

	if (select == STUDENT_TYPE)
	{
		//for_each(this->managerStudent.begin(), this->managerStudent.end(), printStudent);
		for (vector<Student>::iterator it = this->managerStudent.begin(); it != this->managerStudent.end(); it++)
		{
			printStudent(*it);
		}
	}
	else if(select == TEACHER_TYPE)
	{
		for (vector<Teacher>::iterator it = this->managerTeacher.begin(); it != this->managerTeacher.end(); it++)
		{
			printTeacher(*it);
		}
	}
	system("pause");
	system("cls");
}

//查看机房记录
void Manager::showComputer()
{
	for (vector<ComputerRoom>::iterator it = this->managerComputerRoom.begin(); it != this->managerComputerRoom.end(); it++)
	{
		cout << "机房编号：" << (*it).roomId << "   机房电脑数量：" << (*it).maxNum << endl;
	}
	system("pause");
	system("cls");
}

//清除预约记录
void Manager::cancelFile()
{
	ofstream ofs;
	ofs.open(OLDER_FILE, ios::trunc);
	ofs.close();

	cout << "清空成功" << endl;

	system("pause");
	system("cls");
}



//初始化vector容器
void Manager::initVector()
{
	ifstream ifs;
	ifs.open(STUDENT_FILE, ios::in);

	if (!ifs.is_open())
	{
		cout << "文件不存在。" << endl;
	}

	this->managerStudent.clear();
	this->managerTeacher.clear();
	this->managerComputerRoom.clear();

	//初始化学生
	Student s;
	while (ifs >> s.studentId && ifs >> s.name && ifs >> s.password)
	{
		this->managerStudent.push_back(s);
	}
	cout << "当前学生数量为" << this->managerStudent.size() << endl;
	ifs.close();

	//初始化老师
	ifs.open(TEACHER_FILE, ios::in);

	if (!ifs.is_open())
	{
		cout << "文件不存在。" << endl;
	}

	Teacher t;
	while (ifs >> t.TeacherId && ifs >> t.name && ifs >> t.password)
	{
		this->managerTeacher.push_back(t);
	}
	cout << "当前老师数量为" << this->managerTeacher.size() << endl;

	ifs.close();


	//初始化机房
	ifs.open(COMPUTER_FILE, ios::in);

	if (!ifs.is_open())
	{
		cout << "文件不存在。" << endl;
	}

	ComputerRoom c;
	while (ifs >> c.roomId && ifs >> c.maxNum)
	{
		this->managerComputerRoom.push_back(c);
	}
	cout << "当前机房数量为：" << this->managerComputerRoom.size() << endl;

	ifs.close();
}


//检查id是否重复
bool Manager::checkRepeat(int id, int type)
{
	if (type == STUDENT_TYPE)
	{
		for (vector<Student>::iterator it = this->managerStudent.begin(); it != this->managerStudent.end(); it++)
		{
			if ((*it).studentId == id)
			{
				return true;
			}
		}
	}
	else if(type == TEACHER_TYPE)
	{
		for (vector<Teacher>::iterator it = this->managerTeacher.begin(); it != this->managerTeacher.end(); it++)
		{
			if ((*it).TeacherId == id)
			{
				return true;
			}
		}
	}

	return false;
}