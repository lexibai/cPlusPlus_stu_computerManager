#include "teacher.h"

//Ĭ�Ϲ���
Teacher::Teacher()
{

}

//�вι���
Teacher::Teacher(int id, string name, string password)
{
	this->TeacherId = id;
	this->name = name;
	this->password = password;
}

//��ʦ�˵�ҳ��
void Teacher::operMenu()
{
	cout << "��ӭ��ʦ��" << this->name << "��¼��" << endl;
	cout << "\t\t ----------------------------------\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t|          1.�鿴����ԤԼ          |\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t|          2.���ԤԼ              |\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t|          0.ע����¼              |\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t ----------------------------------\n";
	cout << "��ѡ�����Ĳ����� " << endl;
}


// �鿴����ԤԼ-- - �鿴ȫ��ԤԼ��Ϣ�Լ�ԤԼ״̬
void Teacher::showAllOlder()
{

}

// ���ԤԼ
void Teacher::auditOlder()
{

}