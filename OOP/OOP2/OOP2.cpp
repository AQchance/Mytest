#include <bits/stdc++.h>

using namespace std;

class People {
public:

    People(int a, double h, double w) {
        age = a;
        height = h;
        weight = w;
        num++;
    }
    void Eating() {
        weight += 1;
    }
    void Sporting() {
        height += 1;
    }
    void Sleeping() {
        age++;
        height += 1;
        weight += 1;
    }
    void Show()
    {
        cout << "Age:" << age << endl << "Height:" << height << endl << "Weight:" << weight << endl;
    }
    static void ShowNum() {
        cout << "Num:" << num << endl;
    }
protected:
    int age;
    double height;
    double weight;
    static int num;
};
int People::num = 0;
class Student {
public:
    Student(char nm[], int nu, int math, int english) {
        strcpy(name, nm);
        num = nu;
        mathScore = math;
        englishScore = english;
        count++;
        mathTotalScore += math;
        englishTotalScore += english;
    }
    void ShowBase() {
        cout << "Name:" << name << endl
            << "Num:" << num << endl
            << "MathScore:" << mathScore << endl
            << "EnglishScore:" << englishScore << endl;
    }
    void ShowStatic() {
        cout << "Count:" << count << endl
            << "MathTotalScore:" << mathTotalScore << endl
            << "EnglishTotalScore:" << englishTotalScore << endl;
    }
private:
    char name[18];
    int num;
    int mathScore;
    int englishScore;
    static int count;
    static int mathTotalScore;
    static int englishTotalScore;
};
int Student::count = 0;
int Student::mathTotalScore = 0;
int Student::englishTotalScore = 0;
class Dog {
public:

    Dog(char n[], int a, char* s, double w) {
        strcpy(name, n);
        age = a;
        strcpy(sex, s);
        weight = w;
    }
    void ShowMessage() {
        cout << "Name:" << name << endl
            << "Age:" << age << endl
            << "Sex:" << sex << endl
            << "Weight:" << weight << endl;
    }
private:
    char name[20];
    int age;
    char sex[10];
    double weight;
};
class Account {
public:
    Account(int ac, char us[], char pa[], double ba, double apr) {
        accountNum = ac;
        strcpy(userName, us);
        strcpy(password, pa);
        balance = ba;
        APR = apr;
    }
    void Save(char* u, char* p, double money) {
        if (strcmp(u, userName) == 0 && strcmp(p, password) == 0) {
            balance += money;
            cout << "Saved!" << endl;
        }
        else cout << "Username or password errored!" << endl;
    }
    void Withdraw(char* u, char* p, double money) {
        if (strcmp(u, userName) == 0 && strcmp(p, password) == 0) {
            if (money <= balance) {
                balance -= money;
                cout << "Withdrawn!" << endl;
            }
            else {
                cout << "Failed!" << endl;
            }
        }
        else cout << "Username or password errored" << endl;
    }
    double Calculate() {
        return balance * (1 + APR);
    }
    void ShowMessage(char* u, char* p) {
        if (strcmp(u, userName) == 0 && strcmp(p, password) == 0) {
            cout << "AccountNum:" << accountNum << endl
                << "Balance:" << balance << endl
                << "APR:" << APR << endl;
        }
        else cout << "Username or password errored!" << endl;
    }
private:
    int accountNum;
    char userName[20];
    char password[20];
    double balance;
    double APR;
};
int main()
{
    //test1
    cout << "Test1:" << endl << endl;
    People p1(20, 175, 130);
    p1.Eating();
    p1.Sporting();
    p1.Sleeping();
    p1.Show();
    p1.ShowNum();
    People p2(23, 182, 153);
    p2.ShowNum();
    cout << endl;
    //test2
    cout << "Test2:" << endl << endl;
    char a[20] = { 'd','c','z' };
    char b[20] = { 'd','x','p' };
    Student stu1(a, 702, 100, 100);
    stu1.ShowBase();
    stu1.ShowStatic();
    Student stu2(b, 627, 99, 99);
    stu2.ShowStatic();
    cout << endl;
    //test3
    cout << "Test3:" << endl << endl;
    char c[20] = { 'P','e','t','e','r' };
    char d[20] = { 'm','a','l','e' };
    Dog dog(c, 5, d, 50);
    Dog *e = &dog;
    e->ShowMessage();
    cout << endl;
    //test4
    cout << "Test4:" << endl << endl;
    char f[20] = "dcz";
    char fp[20] = "123456";
    char g[20] = "dxp";
    char gp[20] = "456789";
    Account ac1(1, f, fp, 10000, 0.02);
    Account ac2(1, g, gp, 20000, 0.02);
    ac1.Withdraw(g, gp, 1000);
    ac1.Withdraw(f, fp, 2000);
    ac1.Withdraw(f, fp, 20000);
    cout <<"Money:" << ac2.Calculate() << endl;
    return 0;
}