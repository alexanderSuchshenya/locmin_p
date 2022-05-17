#include "locminreorder.h"
using namespace std;

int main()
{
	int nvert, nedge;
	cout << "number of verticies: ";
	cin >> nvert;
	cout << "number of edges: ";
	cin >> nedge;

	cout << "input edges: [verticie1 verticie2]:" << endl;
	vector<vector<int>> edges(nvert);
	for (int i = 0; i < nedge; i++)
	{
		int a, b;
		cin >> a >> b;
		edges[a].push_back(b);
		edges[b].push_back(a);
	}
	cout << "edges initialized" << endl;

	vector<int> sortedorder (nvert);
	vector<bool> notsorted (nvert, true);
	for (int i = 0; i < nvert; i++)
	{
		int min = -1;
		for (int j = 0; j < nvert; j++)
		{
			if(notsorted[j] && (min == -1 || edges[min].size() < edges[j].size()))
			{
				min = j;	
			}
		}
		sortedorder[i] = min;
		notsorted[min] = false;
	}

	cout << "sorted order:" << endl;
	for (int i = 0; i < nvert; i++)
	{
		for (int j = 0; j < edges[sortedorder[i]].size(); j++)
		{
			cout << edges[sortedorder[i]][j] << " ";
		}
		cout << endl;
	}

	int m = 10;
	cout << "local search start" << endl;
	m_paintgraf (edges, sortedorder, m);
	cout << "programme end" << endl;
	return 0;
}
