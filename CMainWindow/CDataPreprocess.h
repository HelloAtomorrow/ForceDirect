/*
 *bool CDataPre::CheckNode(string str)
 *��������Ƿ�Ϸ����Ƿ�������������ַ�����ʾ�ڵ�
 *������ݺϷ�(�������ֱ�ʾ�ڵ�)�򷵻�true
 *���򷵻�false
 
 *int CDataPre::CountNode(string str)
 *��������Ƿ�Ϸ����ڵ�ԣ�ÿ�У��Ƿ���������ڵ�
 *���ظ������ӵĽڵ����

 *bool CDataPre::SaveLegalEdge()
 *�������ĺϷ����ݴ洢��private��vector<vector<string> > m_edge��
 */
#ifndef CDATAPREPROCESS_H
#define CDATAPREPROCESS_H
#include <string>
#include <vector>
using namespace std;

class CDataPreprocess
{
public:
	CDataPreprocess();
	~CDataPreprocess();
	
	bool SaveLegalEdge();					//����Ϸ��ڵ�	
	void PrintOut();						//���
	vector<vector<string> > GetTotalEdge();	//Get�����������ⲿ���ݻ�ȡ��װ��˽�б���

private:
	int CountNode(string line);				//ͳ��ÿ�еĽڵ����
	bool CheckNode(string node);			//���ڵ�ĺϷ���

private:
	vector<vector<string> > m_edge;			//����vector�����������
};
#endif //CDATAPREPROCESS_H