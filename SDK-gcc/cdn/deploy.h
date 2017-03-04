#ifndef __ROUTE_H__
#define __ROUTE_H__

#include "lib_io.h"
#include <vector>
using namespace std;

struct LinkValue
{
	int bandwidth = 0;
	int rentingcost;
	LinkValue(int x, int y) : bandwidth(x), rentingcost(y) {}
};

struct ConsumNode
{
	int networknode;
	int requirement;
	ConsumNode(int x, int y) : networknode(x), requirement(y) {}
};


vector<int> GetNumFromChar(char* topo);

void deploy_server(char * graph[MAX_EDGE_NUM], int edge_num, char * filename);

	

#endif
