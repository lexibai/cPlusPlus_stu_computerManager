#pragma once
#include "identity.h"
#include <iostream>

class Student :public Identity
{
public:

	//ѧ�����
	int studentId;

	//Ĭ�Ϲ���
	Student();

	//�вι���
	Student(int id, string name, string password);

	//ѧ���˵�ҳ��
	virtual void operMenu();

	//����ԤԼ-- - ԤԼ����
	void applyOlder();

	// �鿴�����ԤԼ-- - �鿴�Լ���ԤԼ״̬
	void showMyOlder();

	// �鿴����ԤԼ-- - �鿴ȫ��ԤԼ��Ϣ�Լ�ԤԼ״̬
	void showAllOlder();

	// ȡ��ԤԼ-- - ȡ�������ԤԼ��ԤԼ�ɹ�������е�ԤԼ����ȡ��
	void cancelOlder();

};