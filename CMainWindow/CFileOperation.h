/*
�ļ������࣬�ṩ�ļ�����������ӿڡ�
���ļ��ж�ȡ�����ݴ���DataManager��
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
