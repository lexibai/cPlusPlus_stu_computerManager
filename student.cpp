#include "student.h"

//Ĭ�Ϲ���
Student::Student()
{
	studentId = 0;
	name = ' ';
	password = ' ';
}

//�вι���
Student::Student(int id, string name, string password)
{
	this->studentId = id;
	this->name = name;
	this->password = password;

	this->initStudent();
}

//ѧ���˵�ҳ��
void Student::operMenu()
{
	cout << "��ӭѧ������" << this->name << "��¼��" << endl;
	cout << "\t\t ----------------------------------\n";
	cout << "\t\t|                                 |\n";
	cout << "\t\t|          1.����ԤԼ              |\n";
	cout << "\t\t|                                 |\n";
	cout << "\t\t|          2.�鿴�ҵ�ԤԼ          |\n";
	cout << "\t\t|                                 |\n";
	cout << "\t\t|          3.�鿴����ԤԼ          |\n";
	cout << "\t\t|                                 |\n";
	cout << "\t\t|          4.ȡ��ԤԼ              |\n";
	cout << "\t\t|                                 |\n";
	cout << "\t\t|          0.ע����¼              |\n";
	cout << "\t\t|                                 |\n";
	cout << "\t\t ----------------------------------\n";
	cout << "��ѡ�����Ĳ����� " << endl;

}

//����ԤԼ-- - ԤԼ����
void Student::applyOlder()
{

}

// �鿴�����ԤԼ-- - �鿴�Լ���ԤԼ״̬
void Student::showMyOlder()
{

}

// �鿴����ԤԼ-- - �鿴ȫ��ԤԼ��Ϣ�Լ�ԤԼ״̬
void Student::showAllOlder()
{

}

// ȡ��ԤԼ-- - ȡ�������ԤԼ��ԤԼ�ɹ�������е�ԤԼ����ȡ��
void Student::cancelOlder()
{

}


//��ʼ������
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