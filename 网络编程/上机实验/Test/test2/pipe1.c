#include<unistd.h>
#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<errno.h>
#include<wait.h>
#include<string.h>
#include<sys/types.h>
using namespace std;

int main(int argc,char **argv)
{
	int pipe1[2],pipe2[2];
	//pid_t pid1,pid2;
	int n;
	char cstr[]="child1 data";
	char buf[128];
	//char buf2[128];
	//memset(buf1,'\0',128); //初始化
	//memset(buf2,'\0',128);

	if(pipe(pipe1)<0||pipe(pipe2)<0)
		cout<<"pipe error"<<endl;

	pid_t pid1=fork();
	pid_t pid2=fork();
	if(pid1==-1)
	{
		printf("fork pid1 failed!");
	}
	else if(pid1 > 0)
	{
		//父进程,用管道1读数据,管道2写数据
		cout<<"father PID:"<<getpid()<<endl;
		if(read(pipe1[0],buf,100)>0)
			cout<<"father received:"<<buf<<endl;
		write(pipe2[1],buf,strlen(buf));
	}
	else if(pid1==0)
	{
		cout<<"\npid1:"<<getpid()<<endl;
		//子进程1用管道1写数据
		close(pipe1[0]);//关闭pipe1读端口
		close(pipe2[0]);//关闭pipe2读端口
		close(pipe2[1]);//关闭pipe2写端口
		write(pipe1[1],cstr,strlen(cstr));
	}
	if(pid2==-1)
	{
		printf("fork pid2 failed!");
	}
	else if(pid2==0)
	{
		//子进程2用管道2读数据
		close(pipe1[0]);//关闭pipe1读端口
		close(pipe1[1]);//关闭pipe1写端口
		close(pipe2[1]);//关闭pipe2写端口
		if(read(pipe2[0],buf,128)>0)
		{
			cout<<"\npid2:"<<getpid()<<endl;
			//printf("\npid2 : pid=%d\n",getpid());
			//printf("pid2 : buf=%s\n",buf);
			cout<<"pid2 receive:"<<buf<<endl;
			exit(0);
		}
	}
	return 0;
}
