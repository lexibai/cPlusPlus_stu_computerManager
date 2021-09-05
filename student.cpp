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
	cout << "��������ʱ��Ϊ��һ�����壡" << endl;
	cout << "����������ԤԼ��ʱ�䣺" << endl;
	cout << "1����һ" << endl;
	cout << "2���ܶ�" << endl;
	cout << "3������" << endl;
	cout << "4������" << endl;
	cout << "5������" << endl;
	int date = 0;
	int interval = 0;
	int room = 0;

	while (true)
	{
		cin >> date;
		if (date >= 1 && date <= 5)
		{
			break;
		}
		cout << "������������������" << endl;
	}


	cout << "����������ԤԼ��ʱ��Σ�" << endl;
	cout << "1������" << endl;
	cout << "2������" << endl;

	while (true)
	{
		cin >> interval;
		if (interval >= 1 && interval <= 2)
		{
			break;
		}
		cout << "������������������" << endl;
	}


	cout << "��ѡ�������" << endl;

	for (vector<ComputerRoom>::iterator it = this->vCom.begin(); it != this->vCom.end(); it++)
	{
		cout << (*it).roomId << "�Ż�������" << (*it).maxNum << endl;
	}
	/*cout << "1�Ż���������" << vCom[0].m_MaxNum << endl;
	cout << "2�Ż���������" << vCom[1].m_MaxNum << endl;
	cout << "3�Ż���������" << vCom[2].m_MaxNum << endl;*/

	while (true)
	{
		cin >> room;
		if (room >= 1 && room <= this->vCom.size())
		{
			break;
		}
		cout << "������������������" << endl;
	}

	cout << "ԤԼ�ɹ��������" << endl;

	ofstream ofs(OLDER_FILE, ios::app);

	ofs << "date:" << date << " ";
	ofs << "interval:" << interval << " ";
	ofs << "stuId:" << this->studentId << " ";
	ofs << "stuName:" << this->name << " ";
	ofs << "roomId:" << room << " ";
	ofs << "status:" << 1 << endl;

	ofs.close();

	system("pause");
	system("cls");

}

// �鿴�����ԤԼ-- - �鿴�Լ���ԤԼ״̬
void Student::showMyOlder()
{
	OlderFile of;

	if (of.size == 0)
	{
		cout << "û��ԤԼ��¼" << endl;
		system("pause");
		system("cls");
		return;
	}

	for (int i = 0; i < of.size; i++)
	{
		if (this->studentId == atoi(of.older[i]["stuId"].c_str()))
		{
			cout << "����" << of.older[i]["date"] << " ";
			cout << "ʱ���:" << (of.older[i]["interval"] == "1" ? "����" : "����") << " ";
			cout << "ԤԼ��id:" << of.older[i]["stuId"] << " ";
			cout << "ԤԼ��:" << of.older[i]["stuName"] << " ";
			cout << "ԤԼ������:" << of.older[i]["roomId"] << " ";

			string status = "״̬";
			if (of.older[i]["status"] == "1")
			{
				status += "�����";
			}
			else if (of.older[i]["status"] == "2")
			{
				status += "ԤԼ�ɹ�";
			}
			else if (of.older[i]["status"] == "-1")
			{
				status += "ԤԼʧ��";
			}
			else
			{
				status += "ԤԼ��ȡ��";
			}

			cout << status << endl;
		}

	}
		
	system("pause");
	system("cls");
	return;


}

// �鿴����ԤԼ-- - �鿴ȫ��ԤԼ��Ϣ�Լ�ԤԼ״̬
void Student::showAllOlder()
{
	OlderFile of;

	if (of.size == 0)
	{
		cout << "û��ԤԼ��¼" << endl;
		system("pause");
		system("cls");
		return;
	}

	for (int i = 0; i < of.size; i++)
	{
		cout << "����" << of.older[i]["date"] << " ";
		cout << "ʱ���:" << (of.older[i]["interval"]== "1" ? "����":"����") << " ";
		cout << "ԤԼ��id:" << of.older[i]["stuId"] << " ";
		cout << "ԤԼ��:" << of.older[i]["stuName"] << " ";
		cout << "ԤԼ������:" << of.older[i]["roomId"] << " ";

		string status = "״̬��";
		if (of.older[i]["status"] == "1")
		{
			status += "�����";
		}
		else if (of.older[i]["status"] == "2")
		{
			status += "ԤԼ�ɹ�";
		}
		else if (of.older[i]["status"] == "-1")
		{
			status += "ԤԼʧ��";
		}
		else
		{
			status += "ԤԼ��ȡ��";
		}

		cout << status << endl;
	}

	system("pause");
	system("cls");
	return;

}

// ȡ��ԤԼ-- - ȡ�������ԤԼ��ԤԼ�ɹ�������е�ԤԼ����ȡ��
void Student::cancelOlder()
{
	OlderFile of;

	if (of.size==0)
	{
		cout << "��ԤԼ��¼" << endl;
		system("pause");
		system("cls");
		return;
	}


	cout << "��ѡ��Ҫȡ����ԤԼ��0��ʾ���ء�" << endl;
	
	vector<int>v;
	int index = 1;
	for (int i = 0; i < of.size; i++)
	{
		if (this->studentId == atoi(of.older[i]["stuId"].c_str()))
		{
			if (atoi(of.older[i]["status"].c_str()) == 1 || atoi(of.older[i]["status"].c_str()) == 2)
			{
				v.push_back(i);
				cout << index++ << " ";
				cout << "����" << of.older[i]["date"] << " ";
				cout << "ʱ���:" << (of.older[i]["interval"] == "1" ? "����" : "����") << " ";
				cout << "ԤԼ��id:" << of.older[i]["stuId"] << " ";
				cout << "ԤԼ��:" << of.older[i]["stuName"] << " ";
				cout << "ԤԼ������:" << of.older[i]["roomId"] << " ";

				string status = "״̬";
				if (of.older[i]["status"] == "1")
				{
					status += "�����";
				}
				else if (of.older[i]["status"] == "2")
				{
					status += "ԤԼ�ɹ�";
				}

				cout << status << endl;

			}
			
		}

	}

	int select;
	while (true)
	{
		cin >> select;
		if (select >= 0 && select <= v.size())
		{
			if (select == 0)
			{
				system("cls");
				break;
			}
			else
			{
				of.older[v[select - 1]]["status"] = "0";
				cout << "ȡ��ԤԼ�ɹ�" << endl;
				of.upDateOlder();
				system("cls");
				break;
			}
		}
		else
		{
			cout << "ѡ������������˳�" << endl;
			system("pause");
			system("cls");
			return;
		}
	}

	return;

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