#include <iostream>
#include <vector>
using namespace std;

// this function implements simple way to paint a graf
// fully determined by order of verticies in a paint list
// requires: edges list, verticie order
// returns: amount of colors used
int paintvector (vector<vector<int>> &edges, vector<int> order);

// this function goes through all the verticies m times trying
// to minimize number of colors used by changing verticies order
// requires: edges list, initial order, maximum iterration
// returns: found minimum number of colors
int m_paintgraf (vector<vector<int>> &edges, vector<int> startingorder, int m);

// this function goes through all the verticies trying to
// minimize number of colors used by changing verticies order
// until no other changes can be made
// requires: edges list, initial order, maximum iterration
// returns: found minimum number of colors
int full_paintgraf (vector<vector<int>> &edges, vector<int> startingorder);
