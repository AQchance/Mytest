#include <bits/stdc++.h>
#include <time.h>
//该函数原型位于<algorithm>头文件中
/*using namespace std;

int main()
{
    clock_t start,end;
    start=clock();
    int i,j,n,k;
    int a[10]={0};
    cin>>n;
    for(i=1,k=1;i<=n;i++){
	k*=i;
    }
    for(i=0;i<n;i++){
	a[i]=i+1;
    }
    for(i=0;i<k;i++){
	for(j=0;j<n;j++){
	    cout<<setw(5)<<a[j];
	}
	cout<<endl;
	next_permutation(a,a+n);
    }
    end=clock();
    cout<<"time:"<<((end-start)/CLOCKS_PER_SEC)*1000<<"ms"<<endl;
    return 0;
}*/

using namespace std;
int n,pd[100],used[100];//pd是判断是否用过这个数
void print()//输出函数
{
    int i;
    for(i=1;i<=n;i++)
    printf("%5d",used[i]);//保留五位常宽
    cout<<endl;
}
void dfs(int k)//深搜函数，当前是第k格
{
    int i;
    if(k==n) //填满了的时候
    {
        print();//输出当前解
        return;
    }
    for(i=1;i<=n;i++)//1-n循环填数
    {
        if(!pd[i])//如果当前数没有用过
        {
            pd[i]=1;//标记一下
            used[k+1]=i;//把这个数填入数组
            dfs(k+1);//填下一个
            pd[i]=0;//回溯
        }
    }
}
int main()
{
    clock_t start,end;
    start=clock();
    cin>>n;
    dfs(0);//注意，这里是从第0格开始的！
    end=clock();
    cout<<"time:"<<((end-start)/CLOCKS_PER_SEC)*1000<<"ms"<<endl;
    return 0;
}
//注释掉的部分显然应该运行速度更快而且没有使用深递归，更加好用好理解
