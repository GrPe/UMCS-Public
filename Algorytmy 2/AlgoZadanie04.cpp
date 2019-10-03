#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#include <stack>
#include <map>
#include <limits>
#include <algorithm>
#include <memory>
#include <unordered_map>
#include <cstdint>

using namespace std;

#define ALL(container) begin(container), end(container)


//unsigned long zapytajJanusza(unsigned id) {
//	unsigned long value = 0;
//	switch (id) {
//	case 3:
//		value = 7;
//		break;
//	case 5:
//		value = 9;
//		break;
//	}
//	return value;
//}

bool BFS(vector<vector<pair<int16_t, int>>>& graph, int16_t start, int16_t end, vector<int16_t>& parents)
{
	vector<bool> visited(graph.size(), false);
	queue<uint16_t> queue;

	queue.push(start);
	visited[start] = true;
	bool exit = false;

	while (!queue.empty())
	{
		uint16_t vertex = queue.front();
		queue.pop();

		for (auto& e : graph[vertex])
		{
			if (!visited[e.first] && e.second > 0)
			{
				visited[e.first] = true;
				queue.push(e.first);
				parents[e.first] = vertex;
				if (e.first == end)
				{
					exit = true;
					break;
				}
			}
		}
		if (exit) break;
	}

	return (parents[end] != -1); //path not found
}

unsigned long EdmondsKarp(vector<vector<pair<int16_t, int>>>& graph, int16_t start, int16_t end, unsigned long expectedValue)
{
	unsigned long actualFlow = 0;

	vector<vector<pair<int16_t, int>>> fgraph(graph);

	while (true)
	{
		vector<int16_t> parents(graph.size(), -1);
		if (!BFS(fgraph, start, end, parents)) break;

		queue<int> queue;
		int tempFlow = numeric_limits<int>::max();

		for (int16_t v = end; v != start; v = parents[v])
		{
			tempFlow = min(tempFlow, find_if(fgraph[parents[v]].begin(), fgraph[parents[v]].end(), [&v](pair<int16_t, int>& p) -> bool { return p.first == v; })->second);
				
		}

		for (int16_t v = end; v != start; v = parents[v])
		{
			find_if(fgraph[parents[v]].begin(), fgraph[parents[v]].end(), [&v](pair<int16_t, int>& p) -> bool { return p.first == v; })->second -= tempFlow;
		}

		actualFlow += tempFlow;
		if (actualFlow >= expectedValue) break;
	}

	return actualFlow;
}

int main()
{
	ios::sync_with_stdio(false);

	int v, e, s;
	cin >> v >> e >> s;

	vector<vector<pair<int16_t, int>>> graph(v);

	int a, b, w;
	for (int i = 0; i < e; i++)
	{
		cin >> a >> b >> w;
		graph[a].push_back({ b, w });
	}

	for (int i = graph.size() - 1; i >= 0; --i)
	{
		if (graph[i].empty())
		{
			unsigned long temp = EdmondsKarp(graph, s, i, zapytajJanusza(i));
			if (temp >= zapytajJanusza(i))
				cout << i << " OK\n";
			else
				cout << i << " NIE " << temp << "\n";
		}
	}

	return 0;
}