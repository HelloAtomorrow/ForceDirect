/*
 *bool CDataPre::CheckNode(string str)
 *检查数据是否合法：是否用数字以外的字符来表示节点
 *如果数据合法(即用数字表示节点)则返回true
 *否则返回false
 
 *int CDataPre::CountNode(string str)
 *检查连接是否合法：节点对（每行）是否多于两个节点
 *返回该行连接的节点个数

 *bool CDataPre::SaveLegalEdge()
 *将处理后的合法数据存储在private的vector<vector<string> > m_edge中
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
	
	bool SaveLegalEdge();					//保存合法节点	
	void PrintOut();						//输出
	vector<vector<string> > GetTotalEdge();	//Get函数，用于外部数据获取封装的私有变量

private:
	int CountNode(string line);				//统计每行的节点个数
	bool CheckNode(string node);			//检查节点的合法性

private:
	vector<vector<string> > m_edge;			//二重vector，用来保存边
};
#endif //CDATAPREPROCESS_H