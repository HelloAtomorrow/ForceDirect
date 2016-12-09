/*
文件操作类，提供文件的输入输出接口。
将文件中读取的数据存入DataManager中
*/

#ifndef CFILEOPERATION_H
#define CFILEOPERATION_H

#include <string>
#include "SDataStructure.h"
#include "CDataManager.h"
using namespace std;

class CFileOperation
{
public:
	CFileOperation();
	~CFileOperation();
	static bool ReadFile(string fileName, CDataManager &dataManager);

private:

};
#endif //CFILEOPERATION_H
