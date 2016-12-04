#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include "CDataPreprocess.h"
using namespace std;

CDataPreprocess::CDataPreprocess()
{

}

CDataPreprocess::~CDataPreprocess()
{

}

int CDataPreprocess::CountNode(string line)
{
	int count = 1;
	for (unsigned int i = 0; i < line.length(); i++)
	{
		if (line[i] == ' ')
		{
			count++;
		}
	}
	return count;
}

bool CDataPreprocess::CheckNode(string str)
{
	stringstream sin(str);
	double d;
	char   c;
    if(!(sin >> d))  
        return false;  
    if(sin >> c)  
        return false;  
    return true;  
}

bool CDataPreprocess::SaveLegalEdge()
{
	vector<string> stemp(2);
	string in_str;
	ifstream in("newadjmatrix7_2062.txt");
	if (in.is_open())
	{
		if(getline(in, in_str));         //使第一行不参与判断
        while(getline(in, in_str))
		{
			if( CountNode(in_str) == 2 )
			{
				istringstream is(in_str);
                is >> stemp[0] >> stemp[1];
				if( CheckNode(stemp[0]) && CheckNode(stemp[1]) )
				{
					m_edge.push_back(stemp);
				}
			}
		}
	}
	return true;
}


void CDataPreprocess::PrintOut()
{
	for(int j = 0;j<m_edge.size();j++)
    {
    	cout<<"The  "<<j+1<<"th edge: "<<m_edge[j][0]<<" connect with  "<<m_edge[j][1]<<endl;
    }
}

vector<vector<string> > CDataPreprocess::GetTotalEdge()
{
	return m_edge;
}