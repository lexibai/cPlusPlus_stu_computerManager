#pragma once
#include "identity.h"

class Teacher :public Identity
{
public:

	//ѧ�����
	int TeacherId;

	//Ĭ�Ϲ���
	Teacher();

	//�вι���
	Teacher(int id, string name, string password);

	//��ʦ�˵�ҳ��
	void operMenu();

	// �鿴����ԤԼ-- - �鿴ȫ��ԤԼ��Ϣ�Լ�ԤԼ״̬
	void showAllOlder();

	// ���ԤԼ
	void auditOlder();

};