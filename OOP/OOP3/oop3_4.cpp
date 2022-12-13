#include <bits/stdc++.h>

using namespace std;

class Date{
    private:
	int year;
	int month;
	int day;
    public:
	Date(int y,int m,int d){
	    year=y;
	    month=m;
	    day=d;
	}
	friend class Time;
};

class Time{
    private:
	int hour;
	int minute;
	int second;
    public:
	Time(int h, int m,int s){
	    hour=h;
	    minute=m;
	    second=s;
	}
	void Display(Date &d){
	    cout<<"Time:"<<endl;
	    cout<<d.day<<"/"<<d.month<<"/"<<d.year<<" "
		<<hour<<":"<<minute<<":"<<second<<endl;
	}
};

int main(){
    Date d(2022,11,11);
    Time t(14,39,55);
    t.Display(d);
    return 0;
}
