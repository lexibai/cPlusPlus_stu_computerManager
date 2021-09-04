#include <iostream>
#include <fstream>
#include <string>
#include "identity.h"
#include "student.h"
#include "teacher.h"
#include "manager.h"
#include "globalFile.h"
using namespace std;

//����Ա�Ӳ˵�
void managerMenu(Identity*& manager)
{

	while (true)
	{
		manager->operMenu();
		Manager* man = (Manager*)manager;


		int select;
		cin >> select;
		switch (select)
		{
		case 1:
			//1.����˺�
			man->addPerson();
			break;
		case 2:
			//2.�鿴�˺� 
			man->showPerson();
			break;
		case 3:
			// 3.�鿴����
			man->showComputer();
			break;
		case 4:
			// 4.���ԤԼ
			man->cancelFile();
			break;
		default:
			//0.ע����¼ 
			delete manager;
			cout << "ע���ɹ�" << endl;
			system("pause");
			system("cls");
			return;
		}
	}

}

//ѧ���Ӳ˵�
void studentMenu(Identity*& student)
{

	while (true)
	{
		student->operMenu();
		Student* stu = (Student*)student;


		int select;
		cin >> select;
		switch (select)
		{
		case 1:
			//����ԤԼ
			stu->applyOlder();
			break;
		case 2:
			//�鿴�Լ���ԤԼ
			stu->showMyOlder();
			break;
		case 3:
			//�鿴ȫ��ԤԼ
			stu->showAllOlder();
			break;
		case 4:
			//ȡ��ԤԼ
			stu->cancelOlder();
			break;
		default:
			//0.ע����¼ 
			delete student;
			cout << "ע���ɹ�" << endl;
			system("pause");
			system("cls");
			return;
		}
	}

}

//��¼��֤
void loginIn(const string fileName, int type)
{
	Identity* person = NULL;

	ifstream ifs;
	ifs.open(fileName, ios::in);

	if (!ifs.is_open())
	{
		cout << "�ļ���ʧ��" << endl;
		system("pause");
		system("cls");
		return;
	}

	int id = 0;
	string name;
	string password;

	if (type == STUDENT_TYPE)
	{
		cout << "������ѧ��id��" << endl;
		cin >> id;
	}
	else if (type == TEACHER_TYPE)
	{
		cout << "��������ʦid��" << endl;
		cin >> id;
	}

	cout << "�������û���" << endl;
	cin >> name;
	cout << "����������" << endl;
	cin >> password;

	if (type == STUDENT_TYPE)
	{
		//ѧ����֤
		ifstream ifs;
		ifs.open(STUDENT_FILE, ios::in);

		int fId;
		string fName;
		string fPassword;

		while (ifs >> fId && ifs >> fName && ifs >> fPassword)
		{
			if (fId == id && fName == name && fPassword == password)
			{
				cout << "��֤�ɹ����ѵ�¼" << endl;
				system("pause");
				system("cls");
				person = new Student(fId, fName, fPassword);
				return;
			}
		}

	}
	else if (type == TEACHER_TYPE)
	{
		//��ʦ��֤
		ifstream ifs;
		ifs.open(TEACHER_FILE, ios::in);

		int fId;
		string fName;
		string fPassword;

		while (ifs >> fId && ifs >> fName && ifs >> fPassword)
		{
			if (fId == id && fName == name && fPassword == password)
			{
				cout << "��֤�ɹ����ѵ�¼" << endl;
				system("pause");
				system("cls");
				person = new Teacher(fId, fName, fPassword);
				return;
			}

		}
	}
	else if (type == MANAGER_TYPE)
	{
		//����Ա�����֤

		ifstream ifs;
		ifs.open(MANAGER_FILE, ios::in);

		string fName;
		string fPassword;

		while ( ifs >> fName && ifs >> fPassword)
		{
			if ( fName == name && fPassword == password)
			{
				cout << "��֤�ɹ����ѵ�¼" << endl;
				system("pause");
				system("cls");
				person = new Manager(fName, fPassword);
				managerMenu(person);
				return;
			}
		}

	}
	else
	{
		cout << "type������������" << endl;
		system("pause");
		system("cls");
		return;
	}

	cout << "��¼ʧ�ܣ��������˵�" << endl;
	system("pause");
	system("cls");

}



int main(void)
{
	int select;

	while (true)
	{
		cout << "======================  ��ӭ�������ֵĻ���ԤԼϵͳ  ====================="<< endl;
		cout << endl << "�������������" << endl;
		cout << "\t\t -------------------------------\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t|          1.ѧ������           |\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t|          2.��    ʦ           |\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t|          3.�� �� Ա           |\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t|          0.��    ��           |\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t -------------------------------\n";
		cout << "��������ѡ��: ";

		cin >> select;
		switch (select)
		{
		case STUDENT_TYPE:
			loginIn(STUDENT_FILE, STUDENT_TYPE);
			break;
		case TEACHER_TYPE:
			loginIn(TEACHER_FILE, TEACHER_TYPE);
			break;
		case MANAGER_TYPE:
			loginIn(MANAGER_FILE, MANAGER_TYPE);
			break;
		case 0:
			cout << "��ӭ�´�ʹ��" << endl;
			system("pause");
			return 0;
			break;
		default:
			cout << "������������������" << endl;
			system("pause");
			system("cls");
			break;
		}

	}

	system("pause");
	return 0;
}