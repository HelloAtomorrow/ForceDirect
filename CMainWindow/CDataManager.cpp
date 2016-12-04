#include "CDataManager.h"
#include <iostream>
using namespace std;

DataManager::DataManager()
{

}

DataManager::~DataManager()
{

}

bool DataManager::SetNodeData(SNode node, int num)
{
	if (num >= m_NodeData.size())
	{
		cout << "vector over size!" << endl;
		return false;
	}
	m_NodeData[num] = node;
	return true;
}

bool DataManager::SetNodeData(SNode node)
{
	m_NodeData.push_back(node);
	return true;
}

bool DataManager::SetEdgeData(SEdge edge)
{
	m_EdgeData.push_back(edge);
	return true;
}

const vector<SNode> &DataManager::GetNodeData()
{
	return m_NodeData;
}
const vector<SEdge> &DataManager::GetEdgeData()
{
	return m_EdgeData;
}