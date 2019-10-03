#include <iostream>
#include <cstdint>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>

using namespace std;

decltype(auto) DFS(vector<vector<int>>& graph, int node, vector<bool> red, vector<bool> green, bool isGreen)
{
	if (isGreen)
	{
		//jesli juz tu byl z tym kolorem to mamy petle
		if (green[node] == true)
		{
			return true;
		}
		green[node] = true;
	}
	else
	{
		//jw
		if (red[node] == true)
		{
			return true;
		}
		red[node] = true;
	}

	if (graph[node].size() == 0)
	{
		return false;
	}

	bool isLoop = false;

	for (auto v : graph[node])
	{
		if (DFS(graph, v, red, green, !isGreen))
		{
			isLoop = true;
			break;
		}
	}

	return isLoop;
}

decltype(auto) FindPath(vector<vector<int>>& graph, vector<int>& redParents, vector<int>& greenParents, int vertex, int start)
{
	//prepare stack and push last element
	cout << "TAK\n";
	bool greenNow = false;
	stack<int> results;
	results.push(vertex);

	//process path to start
	while (vertex != start)
	{
		if (greenNow)
		{
			vertex = greenParents[vertex];
			greenNow = false;
		}
		else
		{
			vertex = redParents[vertex];
			greenNow = true;
		}

		results.push(vertex);

		//start is red (test 6 and 10)
		if (vertex == start && greenNow == true)
		{
			greenNow = false;
			vertex = greenParents[vertex];
			results.push(vertex);
		}
	}

	//display results
	while (results.size() != 0)
	{
		cout << results.top() << " ";
		results.pop();
	}
	cout << "\n";
}

auto BFS(vector<vector<int>>& graph, int start, int size) -> void
{
	//prepare visited vectors
	vector<bool> isRed(size, false);
	vector<bool> isGreen(size, false);
	vector<int> redParents(size, -1);
	vector<int> greenParents(size, -1);

	//prepare first element
	isGreen[start] = true;
	queue<pair<int, bool>> queue; //info: true -> green; false -> red
	queue.push({ start, true });

	//start processing graph
	while (queue.size() != 0)
	{
		int vertex = queue.front().first;
		bool color = queue.front().second;
		queue.pop();

		//go to next vertex

		for (auto v : graph[vertex])
		{
			if (color)
			{
				if (!isRed[v])
				{
					isRed[v] = true;
					queue.push({ v,false });
					if(greenParents[v]==-1)
						greenParents[v] = vertex;
				}
			}
			else
			{
				if (!isGreen[v])
				{
					isGreen[v] = true;
					queue.push({ v,true }); 
					if (redParents[v] == -1)
						redParents[v] = vertex;
				}
			}
		}

		//visit vertex
		if (graph[vertex].size() == 0 && isGreen[vertex] && color == true)
		{
			FindPath(graph, redParents, greenParents, vertex, start);
			return;
		}
	}

	vector<bool> red(size, false);
	vector<bool> green(size, false);

	if (DFS(graph, start, red, green, true))
	{
		cout << "REMIS\n";
	}
	else
	{
		cout << "NIE\n";
	}
}

auto main(void) -> int
{
	ios::sync_with_stdio(false);

	uint32_t t, n, m, s, x, y;
	cin >> t;

	for (uint32_t i = 0; i != t; i++)
	{
		//initialize graph
		std::cin >> n >> m >> s;
		vector<vector<int>> graph(n); //vector of vector of neighbors

		//load graph
		for (auto j = 0; j != m; j++)
		{
			cin >> x >> y;
			graph[x].emplace_back(y);
		}

		//sort lists of neighbors for BFS (test: 3, 4, 9)
		for (auto& x : graph)
		{
			sort(x.begin(), x.end());
		}

		BFS(graph, s, n);
	}

	return 0;
}