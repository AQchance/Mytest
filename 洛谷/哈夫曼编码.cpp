#include <queue>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    int n = 0;
    cin >> n;
    int ans = 0;
    int weight = 0;
    int tp1 = 0;
    int tp2 = 0;
    int num = 0;
    priority_queue<int, vector<int>, greater<int>> myQ;
    // 构造小根堆
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &weight);
        myQ.push(weight);
    }
    while (myQ.size() > 1)
    {
        // 选择两个权值最小的结点
        tp1 = myQ.top();
        myQ.pop();
        tp2 = myQ.top();
        myQ.pop();
        num = tp1 + tp2;
        ans += num;
        // 生成新结点
        myQ.push(num);
    }
    printf("%d", ans);
    return 0;
}