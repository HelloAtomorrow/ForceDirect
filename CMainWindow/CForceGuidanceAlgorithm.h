///*
//力导向算法 核心
//1. 随机分布初始节点位置；
//2. 计算每次迭代局部区域内两两节点间的斥力所产生的单位位移（一般为正值）；
//3. 计算每次迭代每条边的引力对两端节点所产生的单位位移（一般为负值）；
//4. 步骤 2、3 中的斥力和引力系数直接影响到最终态的理想效果，它与节点间的距离、节点在系统所在区域的平均单位区域均有关，需要开发人员在实践中不断调整；
//5. 累加经过步骤 2、3 计算得到的所有节点的单位位移；
//6. 迭代 n 次，直至达到理想效果。
//*/
#ifndef CFORCEGUDIANCEALGORITHM_H
#define CFORCEGUDIANCEALGORITHM_H

#include <vector>
#include "SDataStructure.h"
#include "CDataManager.h"
using namespace std;

class CForceGuidanceAlgorithm
{
public:
	//构造函数初始化节点vector和边vector。
	CForceGuidanceAlgorithm();
	~CForceGuidanceAlgorithm();
	
	bool AlgorithmCompute(CDataManager &dataManager, const double kElasticity, const double kCoulomb, const double dt);	//算法迭代函数
	bool InitialPosition(CDataManager &dataManager);								//初始化节点位置为随机值
	bool ComputeElasticity(CDataManager &dataManager, const double kElasticity);	//计算弹簧力函数
	bool ComputeCoulomb(CDataManager &dataManager, const double kCoulomb);			//计算库伦力函数
	bool UpdataPosition(CDataManager &dataManager, const double dt);				//更新节点位置

//private:
	//double m_kElasticity;		//弹力系数
	//double m_kCoulomb;		//库伦力系数
	//double m_dt;				//更新位置步长
};
#endif  //CFORCEGUDIANCEALGORITHM_H