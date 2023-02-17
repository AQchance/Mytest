#include <bits/stdc++.h>
#include <fstream>

using namespace std;

const size_t MAX_Point_Number = 87575;
const size_t MAX_Edge_Number = 125000;
const double eps = 1e-6;

class Point {
private:
	int x;
	int y;
	int num;
public:
	Point(){}
	Point(int xa, int ya, int numa) :x(xa), y(ya), num(numa) {
	}
	int getx() const { return x; }
	int gety() const { return y; }
	int getnum() const { return num; }
	void setx(int x) { this->x = x; }
	void sety(int y) { this->y = y; }
	void setnum(int num) { this->num = num; }
	double dist(Point p1) {
		int x2 = (p1.getx() - x) * (p1.getx() - x);
		int y2 = (p1.gety() - y) * (p1.gety() - y);
		return sqrt(x2 + y2);
	}
};
//创建边的数据结构（但是没有用到）
/*class Edge {
private:
	int from;
	int to;
public:
	Edge(int f, int t) :from(f), to(t) {};
	int getfrom() const { return from; }
	int getto() const { return to; }
	double dist(Point p1, Point p2) {
		int x2 = (p1.getx() - p2.getx()) * (p1.getx() - p2.getx());
		int y2 = (p1.gety() - p2.gety()) * (p1.gety() - p2.gety());
		return sqrt(x2 + y2);
	}
};*/

typedef struct LI{
	Point p;
	struct LI* next;
}ListNode;

ListNode* L[MAX_Point_Number];
double dist[MAX_Point_Number];
bool used[MAX_Point_Number];

void calculate(int start, int x) {
	double sum = 0;
	int i = start;
	int cnt = 0;
	//实现了想法1，只要找到了这样的一条路径就立即停止算法并输出
	while (dist[x] + eps >= 0x42) {
		ListNode* tmp;
		for (tmp = L[i]->next; tmp != NULL; tmp = tmp->next) {
			int n = tmp->p.getnum();
			dist[n] = min(L[i]->p.dist(tmp->p) + dist[i], dist[n]);
		}
		int n = 0;
		double choice = (0x42);
		choice += choice;
		//需要一个优先队列来实现操作
		//需要把这些dist和predict_dist的和进行比较，用值作为优先级
		//每次取出一个点之后，以取出的点为基准，重新计算优先级进行排列
		for (int k = 0; k < MAX_Point_Number; k++) {
			if (used[k] == false && dist[k] + eps < choice) {
				choice = dist[k];
				n = k;
			}
		}
		i = n;
		cnt++;
		if (cnt > 88000) {
			cout << "没有这样的路径！" << endl;
			return;
		}
	}
	cout << "最短路径为：" << dist[x] << endl;
}

int main()
{
	int ex;
	cout << "请输入：" << endl;
	while (1) {
		memset(dist, 0x42, sizeof(dist));
		memset(used, false, sizeof(used));
		int n, v, e, x, y, num, m;
		/*
		输入文件中的内容
		*/
		ifstream in("C:\\Users\\lenovo\\Desktop\\usa.txt", ios::in);
		if (!in.is_open())
		{
			cerr << "open error!" << endl;
			exit(0);
		}
		in >> v >> e;
		for (int i = 0; i < v; i++) {
			in >> num >> x >> y;
			L[i] = new ListNode;
			L[i]->next = NULL;
			L[i]->p.setnum(num);
			L[i]->p.setx(x);
			L[i]->p.sety(y);
		}
		for (int i = 0; i < e; i++) {
			in >> x >> y;
			ListNode* tmp1 = new ListNode;
			ListNode* tmp2;
			tmp1->next = NULL;
			tmp1->p = L[y]->p;
			for (tmp2 = L[x]; tmp2->next != NULL; tmp2 = tmp2->next) {
			}
			tmp2->next = tmp1;
		}
		cin >> m >> n;
		dist[m] = 0.0;
		used[m] = true;
		calculate(m, n);
		cout << "输入0以结束输入，输入1继续" << endl;
		cin >> ex;
		if (ex == 0) {
			cout << "结束输入！" << endl;
			return 0;
		}
		else {
			cout << "请继续输入:" << endl;
		}
	}
	return 0;
}

