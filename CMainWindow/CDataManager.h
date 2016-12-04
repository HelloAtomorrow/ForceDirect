/*
*DataManager���ڹ������ݣ������ݵĴ洢����
*��Ҫ�ṩGet��Set���ֺ����������ⲿ��ȡ���ݺ�д�����ݡ�
*/

#ifndef CDATAMANAGER_H
#define CDATAMANAGER_H

#include <vector>
#include "SDataStructure.h"
using namespace std;

class DataManager
{
public:
	DataManager();
	~DataManager();
	bool SetNodeData(SNode node, int num);		//��vector<SNode>�е�num��λ�õĽڵ�����Ϊ�����node
	bool SetNodeData(SNode node);				//��vector<SNode>��β������node
	bool SetEdgeData(SEdge);					//��vector<SEdge>��β������edge
	const vector<SNode>& GetNodeData();			//��ȡvector<SNode>�����ã�������Ϊ��������
	const vector<SEdge>& GetEdgeData();

private:
	vector<SNode> m_NodeData;					//�ڵ�vector
	vector<SEdge> m_EdgeData;					//��vector
};
#endif // !CDATAMANAGER_H