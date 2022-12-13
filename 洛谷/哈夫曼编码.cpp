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
    // ����С����
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &weight);
        myQ.push(weight);
    }
    while (myQ.size() > 1)
    {
        // ѡ������Ȩֵ��С�Ľ��
        tp1 = myQ.top();
        myQ.pop();
        tp2 = myQ.top();
        myQ.pop();
        num = tp1 + tp2;
        ans += num;
        // �����½��
        myQ.push(num);
    }
    printf("%d", ans);
    return 0;
}