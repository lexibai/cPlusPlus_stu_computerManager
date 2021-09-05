#pragma once
#include "identity.h"
#include "globalFile.h"
#include "olderFile.h"
#include <vector>
#include <iostream>
#include <fstream>

class Teacher :public Identity
{
public:

	//学生编号
	int TeacherId;

	//默认构造
	Teacher();

	//有参构造
	Teacher(int id, string name, string password);

	//老师菜单页面
	void operMenu();

	// 查看所有预约-- - 查看全部预约信息以及预约状态
	void showAllOlder();

	// 审核预约
	void auditOlder();

};