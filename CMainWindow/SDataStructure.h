#ifndef SDATASTRUCTURE_H
#define SDATASTRUCTURE_H
#include <string>
#include <vector>
using namespace std;

struct SNode
{
	//std::string nodeName;
	double label_x;
	double label_y;
	double F_x;
	double F_y;
};

struct SEdge
{
	int nodeLocation1;        //���������±꣬�ֱ��Ӧvector<SNode>�ж�Ӧ�Ľڵ�
	int nodeLocation2;
};


#endif // SDATASTRUCTURE_H