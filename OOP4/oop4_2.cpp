#include <bits/stdc++.h>

using namespace std;
//定义Teacher类
class Teacher{
    private:
	string name;
	int age;
	string sex;
	string address;
	string phone;
	string title;
    public:
	Teacher();
	Teacher(string name, int age, string sex, string address, string phone, string title);
	void display();//类内声明函数
};
//类外定义函数
void Teacher::display(){
    cout<< "Name:" << name << endl;
    cout<< "Age:" << age << endl;
    cout<< "Sex:" << sex << endl;
    cout<< "Address:" << address << endl;
    cout<< "Phone:" << phone << endl;
    cout<< "Title:" << title << endl;
}

Teacher::Teacher(string name, int age, string sex, 
	string address, string phone, string title){
    this->name = name;
    this->age = age;
    this->sex = sex;
    this->address = address;
    this->phone = phone;
    this->title = title;
}

//定义Cadre类
class Cadre{
    private:
	string name;
	int age;
	string sex;
	string address;
	string phone;
	string post;
    public:
	Cadre();
	Cadre(string name, int age, string sex, 
	string address, string phone, string post);
	void display();
	string Getpost();
	void Setpost();
};

void Cadre::display(){
    cout<< "Name:" << name << endl;
    cout<< "Age:" << age << endl;
    cout<< "Sex" << sex << endl;
    cout<< "Address:" << address << endl;
    cout<< "Phone" << phone << endl;
    cout<< "Post" << post << endl;
}

Cadre::Cadre(string name, int age, string sex, 
	string address, string phone, string post){
    this->name = name;
    this->age = age;
    this->sex = sex;
    this->address = address;
    this->phone = phone;
    this->post = post;
}



string Cadre::Getpost(){
    return post;
}

void Cadre::Setpost(){
    this->post = post;
}

class Teacher_Cadre:public Teacher, public Cadre
{
    private:
	double wages;
    public:
	Teacher_Cadre();
	Teacher_Cadre(string name, int age, string sex, 
	string address, string phone, string title, string post, double wages):Teacher(name, age, sex, address, phone, title),Cadre(name, age, sex, address, phone, post)
	{
	    this-> wages = wages;
	}
	void show(){
	    Teacher::display();
	    cout<< "Post:" << Cadre::Getpost() << endl;	    //使用Cadre中的Getpost函数来输出post
	    cout<<"Wages:" << wages << endl;		    
	}
};

int main()
{
    //定义一个Teacher_Cadre的对象
    Teacher_Cadre tc("Duan", 27, "female", "Qingdao", "65535",
	    "professor", "teacher", 10000);
    tc.show();
    return 0;
}
