#include "locminreorder.h"
using namespace std;

int paintvector (vector<vector<int>> &edges, vector<int> order)
{
	int N = edges.size();
	vector<int> colors(N, -1);

	for (int c = 0; c < N; c++)
	{
		vector<bool> vacant(N, true);
		for (int i = 0; i < edges[c].size(); i++)
			if (colors[edges[c][i]] > -1)
				vacant[colors[edges[c][i]]] = false;
		int newcolor = 0;
		while (!vacant[newcolor])
			newcolor = newcolor + 1;
		colors[c] = newcolor;
	}

	int colornum = 0;
	for (int i = 0; i < N; i++)
		if (colors[i] > colornum) colornum = colors[i];
	colornum = colornum + 1;

	cout << "_";
	for (int i = 0; i < N; i++)
		cout << order[i] << " ";
	cout << ": " << colornum << endl;

	return colornum;
}

int m_paintgraf (vector<vector<int>> &edges, vector<int> startingorder, int m)
{
	int N = edges.size();
	int count = 0;
	bool ongoing = true;
	vector<int> currentorder = startingorder;
	while (ongoing && count < m)
	{
		count = count + 1;
		int currentmin = -1;
		vector<int> bestorder;

		for (int i = 0; i < N-1; i++)
			for (int j = i+1; j < N; j++)
			{
				vector<int> neworder = currentorder;
				int tmp = neworder[i];
				neworder[i] = neworder[j];
				neworder[j] = tmp;

				int newmin = paintvector(edges, neworder);
				if (currentmin == -1 || currentmin > newmin)
				{
					currentmin = newmin;
					bestorder = neworder;
				}
			}

		if (currentmin == paintvector(edges, currentorder))
		{
			ongoing = false;
		}
		else
		{
			currentorder = bestorder;
		}
	}

	cout << endl << "reached minimal value at step " << count << endl;
	return paintvector(edges, currentorder);
}

int full_paintgraf (vector<vector<int>> &edges, vector<int> startingorder)
{
        int N = edges.size();
        int count = 0;
        bool ongoing = true;
        vector<int> currentorder = startingorder;
        while (ongoing)
        {
                count = count + 1;
                int currentmin = -1;
                vector<int> bestorder;

                for (int i = 0; i < N-1; i++)
                        for (int j = i+1; j < N; j++)
                        {
                                vector<int> neworder = currentorder;
                                int tmp = neworder[i];
                                neworder[i] = neworder[j];
                                neworder[j] = tmp;

                                int newmin = paintvector(edges, neworder);
                                if (currentmin == -1 || currentmin > newmin)
                                {
                                        currentmin = newmin;
                                        bestorder = neworder;
                                }
                        }

                if (currentmin == paintvector(edges, currentorder))
                {
                        ongoing = false;
                }
                else
                {
                        currentorder = bestorder;
                }
        }

        cout << endl << "reached minimal value at step " << count << endl;
        return paintvector(edges, currentorder);
}
