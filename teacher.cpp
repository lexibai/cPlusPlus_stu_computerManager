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

}