#include <bits/stdc++.h>

using namespace std;

class Person{
    private:
	int ID;
	string name;
    public:
	Person();
	Person(int ID, string name){
	    this->ID = ID;
	    this->name = name;
	}
	virtual void Show(){
	    cout<<"ID:"<<ID<<endl;
	    cout<<"Name:"<<name<<endl;
	}
};

class Student:public Person
{
    private:
	int classnumber;
	int score;
    public:
	Student();
	Student(int id, string na, int cn, int sc): Person(id, na), classnumber(cn), score(sc){}
	void Show(){
	    Person::Show();
	    cout<<"ClassNumber:"<< classnumber <<endl;
	    cout<<"Score:"<< score <<endl;
	}
};

class Teacher:public Person
{
    private:
	string title;
	string department;
    public:
	Teacher();
	Teacher(int id, string na, string tit, string dep): Person(id, na), title(tit), department(dep){}
	void Show(){
	    Person::Show();
	    cout<<"Title:"<< title <<endl;
	    cout<<"Department:"<< department <<endl;
	}
};

int main()
{
    Person p(12138,"Duan");
    Person *tmp;
    Student s(200601, "Du", 18, 98);
    Teacher t(369, "Zhe", "A", "B");
    tmp = &p;
    tmp->Show();
    tmp = &s;
    tmp->Show();
    tmp = &t;
    tmp->Show();
    return 0;
}
