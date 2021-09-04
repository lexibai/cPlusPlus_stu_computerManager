#include "manager.h"
using namespace std;


//��ӡѧ������
void printStudent(Student s)
{
	cout << "ѧ��idΪ��" << s.studentId << "  ѧ��������Ϊ��" << s.name << "  ѧ��������Ϊ��" << s.password << endl;
}


//��ӡ��ʦ����
void printTeacher(Teacher & t)
{
	cout << "��ʦidΪ��" << t.TeacherId << "  ��ʦ������Ϊ��" << t.name << "  ��ʦ������Ϊ��" << t.password << endl;
}



//���캯��
Manager::Manager()
{


}

Manager::Manager(string name, string password)
{
	this->name = name;
	this->password = password;

	this->initVector();
}

//����Ա�˵�����
void Manager::operMenu()
{
	cout << "��ӭ����Ա��" << this->name << "��¼��" << endl;
	cout << "\t\t ---------------------------------\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          1.����˺�            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          2.�鿴�˺�            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          3.�鿴����            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          4.���ԤԼ            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          0.ע����¼            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t ---------------------------------\n";
	cout << "��ѡ�����Ĳ����� " << endl;

}

//����˻�
void Manager::addPerson()
{
	//ѡ�������˺ŵ�����
	cout << "������Ҫ����˺ŵ����ͣ�\n\t1.ѧ��\n\t2.��ʦ" << endl;
	int select;
	cin>>select;

	string fType;
	if (select == STUDENT_TYPE)
	{
		fType = STUDENT_FILE;
		cout << "������ѧ�����" << endl;
	}
	else
	{
		fType = TEACHER_FILE;
		cout << "������̹����" << endl;
	}


	//�򿪶�Ӧ�ļ��������
	ofstream ofs;
	ofs.open(fType, ios::out | ios::app);
	int fId;
	string fName;
	string fPassword;

	//��ȡ����id
	cin >> fId;

	//�ж�id�Ƿ��ظ�
	if (checkRepeat(fId, select))
	{
		cout << "id�����ظ�����������˳���" << endl;
		system("pause");
		system("cls");
		ofs.close();
		return;
	}

	cout << "�������û���" << endl;
	cin >> fName;
	cout << "����������" << endl;
	cin >> fPassword;

	ofs << fId <<" "<< fName<< " " << fPassword<<endl;
	cout << "��ӳɹ�" << endl;

	this->initVector();

	system("pause");
	system("cls");
	ofs.close();

}

//�鿴�˻�
void Manager::showPerson()
{
	cout << " ��ѡ��鿴���ݣ�\n1.ѧ��\n2.��ʦ" << endl;
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

//�鿴������¼
void Manager::showComputer()
{
	for (vector<ComputerRoom>::iterator it = this->managerComputerRoom.begin(); it != this->managerComputerRoom.end(); it++)
	{
		cout << "������ţ�" << (*it).roomId << "   ��������������" << (*it).maxNum << endl;
	}
	system("pause");
	system("cls");
}

//���ԤԼ��¼
void Manager::cancelFile()
{
	ofstream ofs;
	ofs.open(OLDER_FILE, ios::trunc);
	ofs.close();

	cout << "��ճɹ�" << endl;

	system("pause");
	system("cls");
}



//��ʼ��vector����
void Manager::initVector()
{
	ifstream ifs;
	ifs.open(STUDENT_FILE, ios::in);

	if (!ifs.is_open())
	{
		cout << "�ļ������ڡ�" << endl;
	}

	this->managerStudent.clear();
	this->managerTeacher.clear();
	this->managerComputerRoom.clear();

	//��ʼ��ѧ��
	Student s;
	while (ifs >> s.studentId && ifs >> s.name && ifs >> s.password)
	{
		this->managerStudent.push_back(s);
	}
	cout << "��ǰѧ������Ϊ" << this->managerStudent.size() << endl;
	ifs.close();

	//��ʼ����ʦ
	ifs.open(TEACHER_FILE, ios::in);

	if (!ifs.is_open())
	{
		cout << "�ļ������ڡ�" << endl;
	}

	Teacher t;
	while (ifs >> t.TeacherId && ifs >> t.name && ifs >> t.password)
	{
		this->managerTeacher.push_back(t);
	}
	cout << "��ǰ��ʦ����Ϊ" << this->managerTeacher.size() << endl;

	ifs.close();


	//��ʼ������
	ifs.open(COMPUTER_FILE, ios::in);

	if (!ifs.is_open())
	{
		cout << "�ļ������ڡ�" << endl;
	}

	ComputerRoom c;
	while (ifs >> c.roomId && ifs >> c.maxNum)
	{
		this->managerComputerRoom.push_back(c);
	}
	cout << "��ǰ��������Ϊ��" << this->managerComputerRoom.size() << endl;

	ifs.close();
}


//���id�Ƿ��ظ�
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