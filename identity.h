#pragma once
#include <string>
using namespace std;

class Identity
{
public:

	//�˵������麯��
	virtual void operMenu() = 0;

	//�û���������
	string name;
	string password;

};