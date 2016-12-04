#ifndef SDATASTRUCTURE_H
#define SDATASTRUCTURE_H
#include <string>

struct SNode
{
	std::string nodeName;
	double label_x;
	double label_y;
	double F_x;
	double F_y;
};

struct SEdge
{
	std::string nodeName1;
	std::string nodeName2;
};


#endif // SDATASTRUCTURE_H