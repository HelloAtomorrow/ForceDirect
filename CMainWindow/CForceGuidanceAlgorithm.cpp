#include "CForceGuidanceAlgorithm.h"


CForceGuidanceAlgorithm::CForceGuidanceAlgorithm(vector<vector<string> > totalEdge, double kElasticity, double kCoulomb)
	: m_kElasticity(kElasticity), m_kCoulomb(kCoulomb)
{
	//遍历vector<vector<string> >，从中读取每条边，将每条边存入m_EdgeData，将每个节点存入m_NodeData，注意节点去重
}

CForceGuidanceAlgorithm::~CForceGuidanceAlgorithm()
{

}

bool CForceGuidanceAlgorithm::InitialPosition()
{
	//遍历m_NodeData这个vector，对其中的每个节点SNode初始化，label_x，label_y用rand()函数生成随机值；F_x和F_y初始化为0
	return true;
}

bool CForceGuidanceAlgorithm::AlgorithmCompute()
{
	/*算法迭代函数，设置为public函数，提供对外接口，
	在本函数中调用ComputeElasticity()，ComputeCoulomb()，UpdataPosition()函数更新坐标值
	*/
	return true;
}

vector<SNode> CForceGuidanceAlgorithm::GetNodeData()
{
	return m_NodeData;
}

vector<SEdge> CForceGuidanceAlgorithm::GetEdgeData()
{
	return m_EdgeData;
}

bool CForceGuidanceAlgorithm::ComputeElasticity()
{
	return true;
}

bool CForceGuidanceAlgorithm::ComputeCoulomb()
{
	return true;
}

bool CForceGuidanceAlgorithm::UpdataPosition()
{
	return true;
}