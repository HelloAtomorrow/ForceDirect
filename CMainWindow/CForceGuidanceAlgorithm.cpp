#include "CForceGuidanceAlgorithm.h"


CForceGuidanceAlgorithm::CForceGuidanceAlgorithm()
{
	
}

CForceGuidanceAlgorithm::~CForceGuidanceAlgorithm()
{

}

bool CForceGuidanceAlgorithm::AlgorithmCompute(CDataManager &dataManager, const double kElasticity, const double kCoulomb, const double dt)
{
	/*算法迭代函数，设置为public函数，提供对外接口,
	在本函数中调用InitialPosition()初始化坐标位置,
	然后调用ComputeElasticity()，ComputeCoulomb()，UpdataPosition()函数更新坐标值
	*/
	InitialPosition(dataManager);
	const int MAXLOOP = 10;
	for (int i = 0; i < MAXLOOP; i++)
	{
		ComputeCoulomb(dataManager, kCoulomb);
		ComputeElasticity(dataManager, kElasticity);
		UpdataPosition(dataManager, dt);
	}
	return true;
}

bool CForceGuidanceAlgorithm::InitialPosition(CDataManager &dataManager)
{
	//遍历m_NodeData这个vector，对其中的每个节点SNode初始化，label_x，label_y用rand()函数生成随机值；F_x和F_y初始化为0
	const vector<SNode> &nodeData = dataManager.GetNodeData();
	SNode node;
	for (int location = 0; location < nodeData.size(); location++)
	{		
		node.label_x = rand() % 500;
		node.label_y = rand() % 500;
		node.F_x = 0;
		node.F_y = 0;
		dataManager.SetNodeData(node, location);
	}
	return true;
}

bool CForceGuidanceAlgorithm::ComputeElasticity(CDataManager &dataManager, const double kElasticity)
{
	const vector<SNode> &nodeData = dataManager.GetNodeData();
	const vector<SEdge> &edgeData = dataManager.GetEdgeData();
	int location1, location2;
	double dx, dy, distance, F_Elasticity;
	SNode node1, node2;
	for (int i = 0; i < edgeData.size(); i++)
	{
		location1 = edgeData[i].nodeLocation1;
		location2 = edgeData[i].nodeLocation2;
		dx = nodeData[location1].label_x - nodeData[location2].label_x;
		dy = nodeData[location1].label_y - nodeData[location2].label_y;
		distance = sqrt(dx *dx + dy * dy);
		if (distance >= 0.0001)
		{
			F_Elasticity = kElasticity * distance;
			node1.label_x = nodeData[location1].label_x;
			node1.label_y = nodeData[location1].label_y;
			node1.F_x = nodeData[location1].F_x + F_Elasticity * dx / distance;
			node1.F_y = nodeData[location1].F_y + F_Elasticity * dx / distance;
			dataManager.SetNodeData(node1, location1);

			node2.label_x = nodeData[location2].label_x;
			node2.label_y = nodeData[location2].label_y;
			node2.F_x = nodeData[location2].F_x - F_Elasticity * dx / distance;
			node2.F_y = nodeData[location2].F_y - F_Elasticity * dx / distance;
			dataManager.SetNodeData(node1, location2);
		}
	}
	return true;
}

bool CForceGuidanceAlgorithm::ComputeCoulomb(CDataManager &dataManager, const double kCoulomb)
{
	const vector<SNode> nodeData = dataManager.GetNodeData();
	double dx, dy, distance, F_Coulomb;
	SNode node1, node2;
	for (int i = 0; i < nodeData.size() - 1; i++)
	{
		for (int j = i + 1; j < nodeData.size(); j++)
		{
			dx = nodeData[i].label_x - nodeData[j].label_x;
			dy = nodeData[i].label_y - nodeData[j].label_y;
			distance = sqrt(dx *dx + dy * dy);
			if (distance >= 0.0001)
			{
				F_Coulomb = kCoulomb / (distance * distance);
				node1.label_x = nodeData[i].label_x;
				node1.label_y = nodeData[i].label_y;
				node1.F_x = nodeData[i].F_x - F_Coulomb * dx / distance;
				node1.F_y = nodeData[i].F_y - F_Coulomb * dy / distance;
				dataManager.SetNodeData(node1, i);

				node2.label_x = nodeData[j].label_x;
				node2.label_y = nodeData[j].label_y;
				node2.F_x = nodeData[j].F_x + F_Coulomb * dx / distance;
				node2.F_y = nodeData[j].F_y + F_Coulomb * dy / distance;
				dataManager.SetNodeData(node2, j);
			}
		}
	}
	return true;
}

bool CForceGuidanceAlgorithm::UpdataPosition(CDataManager &dataManager, const double dt)
{
	const vector<SNode> nodeData = dataManager.GetNodeData();
	double dx, dy;
	SNode node;
	for (int i = 0; i < nodeData.size(); i++)
	{
		dx = dt * nodeData[i].F_x;
		dy = dt * nodeData[i].F_y;
		node.F_x = 0;
		node.F_y = 0;
		node.label_x = nodeData[i].label_x + dx;
		node.label_y = nodeData[i].label_y + dy;
		dataManager.SetNodeData(node, i);
	}
	return true;
}