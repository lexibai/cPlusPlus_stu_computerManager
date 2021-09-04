#pragma once
#include <iostream>
#include <map>
#include "globalFile.h"
using namespace std;


class OlderFile
{
public:
	//构造函数
	OlderFile();

	//添加older
	void upDateOlder();

	//存放older的容器
	map<int, map<string, string>>older;

	//容器目前存放的数量
	int size;

};