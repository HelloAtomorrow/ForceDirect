/*
力导向算法 核心
1. 随机分布初始节点位置；
2. 计算每次迭代局部区域内两两节点间的斥力所产生的单位位移（一般为正值）；
3. 计算每次迭代每条边的引力对两端节点所产生的单位位移（一般为负值）；
4. 步骤 2、3 中的斥力和引力系数直接影响到最终态的理想效果，它与节点间的距离、节点在系统所在区域的平均单位区域均有关，需要开发人员在实践中不断调整；
5. 累加经过步骤 2、3 计算得到的所有节点的单位位移；
6. 迭代 n 次，直至达到理想效果。
*/
#ifndef CFORCEGUDIANCEALGORITHM_H
#define CFORCEGUDIANCEALGORITHM_H

#include <vector>
#include "SDataStructure.h"

using namespace std;
class CForceGuidanceAlgorithm
{
public:
	//构造函数初始化节点vector和边vector。
	CForceGuidanceAlgorithm(vector<vector<string> > totalEdge, double kElasticity, double kCoulomb);
	~CForceGuidanceAlgorithm();

	bool InitialPosition();		//初始化节点位置为随机值
	bool AlgorithmCompute();	//算法迭代函数
	vector<SNode> GetNodeData();
	vector<SEdge> GetEdgeData();

private:
	bool ComputeElasticity();	//计算弹簧力函数
	bool ComputeCoulomb();		//计算库伦力函数
	bool UpdataPosition();		//更新节点位置

private:
	vector<SNode> m_NodeData;	//节点vector
	vector<SEdge> m_EdgeData;	//边vector
	double m_kElasticity;		//弹力系数
	double m_kCoulomb;			//库伦力系数
	double m_dt;				//更新位置步长
};
#endif  //!CFORCEGUDIANCEALGORITHM_H