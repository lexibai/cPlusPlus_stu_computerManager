#pragma once
#include <iostream>
#include <map>
#include "globalFile.h"
using namespace std;


class OlderFile
{
public:
	//���캯��
	OlderFile();

	//���older
	void upDateOlder();

	//���older������
	map<int, map<string, string>>older;

	//����Ŀǰ��ŵ�����
	int size;

};