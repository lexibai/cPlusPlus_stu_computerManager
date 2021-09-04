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

	//���캯��
	Manager();
	Manager(string name, string password);

	//����Ա�˵�����
	virtual void operMenu();

	//����˻�
	void addPerson();

	//�鿴�˻�
	void showPerson();

	//�鿴������¼
	void showComputer();

	//���ԤԼ��¼
	void cancelFile();


public:
	//��ʼ��vector����
	void initVector();
	//ѧ������
	vector<Student> managerStudent;
	//��ʦ����
	vector<Teacher> managerTeacher;
	//��������
	vector<ComputerRoom> managerComputerRoom;

	//���id�Ƿ��ظ�
	bool checkRepeat(int id,int type);


};