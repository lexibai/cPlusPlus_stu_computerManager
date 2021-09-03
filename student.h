#pragma once
#include "identity.h"
#include <iostream>

class Student :public Identity
{
public:

	//学生编号
	int studentId;

	//默认构造
	Student();

	//有参构造
	Student(int id, string name, string password);

	//学生菜单页面
	virtual void operMenu();

	//申请预约-- - 预约机房
	void applyOlder();

	// 查看自身的预约-- - 查看自己的预约状态
	void showMyOlder();

	// 查看所有预约-- - 查看全部预约信息以及预约状态
	void showAllOlder();

	// 取消预约-- - 取消自身的预约，预约成功或审核中的预约均可取消
	void cancelOlder();

};