#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    bool validPath(int n, vector<vector<int>> &edges, int source, int destination)
    {
        const int cap = n;
        vector<int> parents(cap);
        // 初始化并查集
        for (int i = 0; i < cap; i++)
        {
            parents[i] = i;
        }
        for (int i = 0; i < edges.size(); i++)
        {
            int x = edges[i][1];
            int y = edges[i][0];
            // 找出两个节点的父节点
            while (x != parents[x])
            {
                x = parents[x];
            }
            while (y != parents[y])
            {
                y = parents[y];
            }
            // 这一步检查是否成环，如果二者已经连通，不必再执行union操作
            if (x == y)
                continue;
            // 执行union操作
            parents[x] = edges[i][0];
        }
        // 分别查找源节点和目的节点的父节点
        while (source != parents[source])
        {
            source = parents[source];
        }
        while (destination != parents[destination])
        {
            destination = parents[destination];
        }
        // 检查父节点是否相等即可得出结果
        return source == destination;
    }
};

int main()
{
    Solution sol;
    int n = 3;
    vector<vector<int>> edges = {{0, 1}, {1, 2}, {2, 0}};
    cout << sol.validPath(n, edges, 0, 2) << endl;
    return 0;
}