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
	int nodeLocation1;        //保存两个下标，分别对应vector<SNode>中对应的节点
	int nodeLocation2;
};


#endif // SDATASTRUCTURE_H