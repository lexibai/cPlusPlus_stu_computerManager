#pragma once
#include <vector>
#include <fstream>
#include <iostream>
#include <algorithm>
#include "identity.h"
#include "student.h"
#include "teacher.h"
#include "computerRoom.h"
#include "globalFile.h"

class Manager :public Identity
{
public:

	//构造函数
	Manager();
	Manager(string name, string password);

	//管理员菜单界面
	virtual void operMenu();

	//添加账户
	void addPerson();

	//查看账户
	void showPerson();

	//查看机房记录
	void showComputer();

	//清除预约记录
	void cancelFile();


public:
	//初始化vector容器
	void initVector();
	//学生容器
	vector<Student> managerStudent;
	//老师容器
	vector<Teacher> managerTeacher;
	//机房容器
	vector<ComputerRoom> managerComputerRoom;

	//检查id是否重复
	bool checkRepeat(int id,int type);


};