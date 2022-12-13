#include <bits/stdc++.h>

using namespace std;

class Student{
    public:
	Student(){
	    num=0;
	    score=0;
	}
	void SetNum(int n){
	    num=n;
	}
	void SetScore(int s){
	    score=s;
	}
	int GetNum(){
	    return num;
	}
	int GetScore(){
	    return score;
	}
    private:
	int num;
	int score;
};

int max(Student *stu,int m){
    int i,n=stu->GetNum(),s=stu->GetScore();
    for(i=0;i<m;i++,stu++){
	if(s<stu->GetScore()){
	    n=stu->GetNum();
	    s=stu->GetScore();
	}
    }
    return n;
}

int main(){
    Student *stu=new Student[5];
    Student *stu0=stu;
    for(int i=0;i<5;i++,stu++){
	stu->SetNum(i+1);
    }
    stu=stu0;
    for(int i=0,j=90;i<5;i++,j++,stu++){
	stu->SetScore(j);
    }
    Student *p=stu0;
    for(int i=0;i<5;i++,p++){
	if(p->GetNum()==1||p->GetNum()==3||p->GetNum()==5){
	     cout<<"NUM:"<<p->GetNum()<<endl<<"Score:"<<p->GetScore()<<endl;
	}
    }
   int maxnum=max(stu0,5);
   cout<<"MaxScoreNum:"<<maxnum<<endl;
   delete [] stu0;
    return 0;
}




