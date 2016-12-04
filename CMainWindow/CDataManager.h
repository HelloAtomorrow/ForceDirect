/*
*DataManager用于管理数据，是数据的存储对象。
*需要提供Get和Set两种函数，用于外部读取数据和写入数据。
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
	bool SetNodeData(SNode node, int num);		//将vector<SNode>中第num个位置的节点设置为传入的node
	bool SetNodeData(SNode node);				//在vector<SNode>的尾部添加node
	bool SetEdgeData(SEdge);					//在vector<SEdge>的尾部添加edge
	const vector<SNode>& GetNodeData();			//获取vector<SNode>的引用，该引用为常量引用
	const vector<SEdge>& GetEdgeData();

private:
	vector<SNode> m_NodeData;					//节点vector
	vector<SEdge> m_EdgeData;					//边vector
};
#endif // !CDATAMANAGER_H
