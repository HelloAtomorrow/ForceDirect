#include "CForceGuidanceAlgorithm.h"


CForceGuidanceAlgorithm::CForceGuidanceAlgorithm(vector<vector<string> > totalEdge, double kElasticity, double kCoulomb)
	: m_kElasticity(kElasticity), m_kCoulomb(kCoulomb)
{
	//����vector<vector<string> >�����ж�ȡÿ���ߣ���ÿ���ߴ���m_EdgeData����ÿ���ڵ����m_NodeData��ע��ڵ�ȥ��
}

CForceGuidanceAlgorithm::~CForceGuidanceAlgorithm()
{

}

bool CForceGuidanceAlgorithm::InitialPosition()
{
	//����m_NodeData���vector�������е�ÿ���ڵ�SNode��ʼ����label_x��label_y��rand()�����������ֵ��F_x��F_y��ʼ��Ϊ0
	return true;
}

bool CForceGuidanceAlgorithm::AlgorithmCompute()
{
	/*�㷨��������������Ϊpublic�������ṩ����ӿڣ�
	�ڱ������е���ComputeElasticity()��ComputeCoulomb()��UpdataPosition()������������ֵ
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