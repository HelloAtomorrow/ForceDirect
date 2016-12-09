#include "CDataManager.h"
#include <iostream>
using namespace std;

vector<SNode> CDataManager::m_NodeData(2063);
vector<SEdge> CDataManager::m_EdgeData;
CDataManager::CDataManager()//:m_NodeData(2063)
{

}

CDataManager::~CDataManager()
{

}

bool CDataManager::SetNodeData(SNode node, int location)
{
	if (location >= m_NodeData.size())
	{
		cout << "vector over size!" << endl;
		return false;
	}
	m_NodeData[location] = node;
	return true;
}

//vector<SNode>::iterator CDataManager::SetNodeData(SNode node)
//{
//	vector<SNode>::iterator location;
//	for (location = m_NodeData.begin(); location != m_NodeData.end(); ++location)
//	{
//		if (node.nodeName == location->nodeName)
//		{
//			return location;
//		}		
//	}
//	//m_NodeData.insert(location, node);
//	m_NodeData.push_back(node);
//	location = m_NodeData.begin();
//	return location;
//}

bool CDataManager::SetEdgeData(SEdge edge)
{
	m_EdgeData.push_back(edge);
	return true;
}

const vector<SNode> &CDataManager::GetNodeData()
{
	return m_NodeData;
}
const vector<SEdge> &CDataManager::GetEdgeData()
{
	return m_EdgeData;
}