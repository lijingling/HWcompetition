#include "deploy.h"
#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;

vector<int> GetNumFromChar(char* topo)
{
	vector<int> infovalue;
	int i = 0;
	int tempnum = 0;
	while(topo[i] != '\n')
	{
		char info = topo[i];
		if(info == ' ')
		{
			infovalue.push_back(tempnum);
			tempnum = 0;
			i++;
		}
		else if(info <= '9' && info >= '0')
		{
			tempnum = tempnum*10+ (info - '0');
			i++;
		}
		else 
			i++;
	}
	infovalue.push_back(tempnum);
	return infovalue;
}

//你要完成的功能总入口
void deploy_server(char * topo[MAX_EDGE_NUM], int line_num,char * filename)
{
	/*get info from network*/
	//network basic information line 0
	vector<int> network_info = GetNumFromChar(topo[0]); //0: num of network node; 1: num of link; 2:num of consumption node
	int NumOfNetworkNode = network_info[0];
	cout << network_info[0] << endl;//0: num of network node;
	cout << network_info[1] << endl;//1: num of link;
	int NumOfConsume = network_info[2];
	cout << network_info[2] << endl;//2:num of consumption node

	//cost of video deployment line 2
	vector<int> CostOfVideo = GetNumFromChar(topo[2]);
	cout << CostOfVideo[0] << endl;

	int listline = 0;
	//info of link start from 5
	vector<vector<LinkValue*> > InfoOfLink(NumOfNetworkNode ,vector<LinkValue*>(NumOfNetworkNode));
	for(listline=4; topo[listline][0]!='\r'; ++listline)
	{
		vector<int> linkinfo = GetNumFromChar(topo[listline]);
		LinkValue* templink = new LinkValue(linkinfo[2], linkinfo[3]);
		InfoOfLink[linkinfo[0]][linkinfo[1]] = templink;
	}
	cout << "lslsl"<<(InfoOfLink[0][20]== NULL)  << endl;
	cout << InfoOfLink.size() << ' ' << InfoOfLink[0].size() << endl;
	listline += 1;
	cout << "line of the start of consum: " << listline << endl;

	//info of consumption
	ConsumNode* InfoOfConsum[NumOfConsume];
	for(; listline<line_num; listline++)
	{
		vector<int> linkinfo = GetNumFromChar(topo[listline]);
		InfoOfConsum[linkinfo[0]] = new ConsumNode(linkinfo[1], linkinfo[2]);
	}
	cout << "lslsl"<<(InfoOfConsum[0]->networknode)  << endl;
	cout << "line of the enf of consum: " << listline << endl;
	
	/**/






	// 需要输出的内容
	//char * topo_file = (char *)"17\n\n0 8 0 20\n21 8 0 20\n9 11 1 13\n21 22 2 20\n23 22 2 8\n1 3 3 11\n24 3 3 17\n27 3 3 26\n24 3 3 10\n18 17 4 11\n1 19 5 26\n1 16 6 15\n15 13 7 13\n4 5 8 18\n2 25 9 15\n0 7 10 10\n23 24 11 23";

	// 直接调用输出文件的方法输出到指定文件中(ps请注意格式的正确性，如果有解，第一行只有一个数据；第二行为空；第三行开始才是具体的数据，数据之间用一个空格分隔开)
	//write_result(test, filename);

}
