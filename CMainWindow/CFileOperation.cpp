#include <iostream>
#include <fstream>
#include <sstream>
#include "CFileOperation.h"
using namespace std;

CFileOperation::CFileOperation()
{
}

CFileOperation::~CFileOperation()
{
}

bool CFileOperation::ReadFile(string fileName, CDataManager &dataManager)
{
	ifstream inputFile(fileName);
	if (inputFile.is_open())
	{
		string line;
		getline(inputFile, line);
		string name1, name2;
		//SNode node1, node2;
		SEdge edge;
		while (getline(inputFile, line))
		{
			istringstream stringLine(line);
			stringLine >> name1 >> name2;
			//node1.nodeName = name1;
			//node2.nodeName = name2;
			edge.nodeLocation1 = stoi(name1);
			edge.nodeLocation2 = stoi(name2);
			dataManager.SetEdgeData(edge);
		}
	}
	inputFile.close();
	return true;
}