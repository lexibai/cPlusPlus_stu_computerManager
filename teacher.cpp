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
		cout << "ʱ���:" << (of.older[i]["interval"] == "1" ? "����" : "����") << " ";
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

// ���ԤԼ
void Teacher::auditOlder()
{
	OlderFile of;

	if (of.size == 0)
	{
		cout << "��ԤԼ��¼" << endl;
		system("pause");
		system("cls");
		return;
	}


	cout << "��ѡ��Ҫ��˵�ԤԼ����0Ϊ���أ�" << endl;

	vector<int>v;
	int index = 1;
	for (int i = 0; i < of.size; i++)
	{
		if (atoi(of.older[i]["status"].c_str()) == 1)
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
			cout << status << endl;

		}

	}

	int select;
	int ret;
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
				cout << "��ѡ���Ƿ�ͨ��ԤԼ��" << endl;
				cout << "1.ͨ��" << "\n2.����" << endl;
				cin >> ret;

				if (ret == 1)
				{
					of.older[v[select - 1]]["status"] = "2";
					cout << "��ͨ��" << endl;
				}
				else
				{
					of.older[v[select - 1]]["status"] = "-1";
					cout << "�Ѳ���" << endl;
				}
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