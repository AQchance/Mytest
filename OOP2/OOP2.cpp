#include <bits/stdc++.h>

using namespace std;
//终于可以输入中文了
//以前我是有多懒啊233
class People
{
public:
    People(int a, double h, double w)
    {
        age = a;
        height = h;
        weight = w;
        num++;
    }
    void Eating()
    {
        weight += 1;
    }
    void Sporting()
    {
        height += 1;
    }
    void Sleeping()
    {
        age++;
        height += 1;
        weight += 1;
    }
    void Show()
    {
        cout << "Age:" << age << endl
             << "Height:" << height << endl
             << "Weight:" << weight << endl;
    }
    static void ShowNum()
    {
        cout << "Num:" << num << endl;
    }

protected:
    int age;
    double height;
    double weight;
    static int num;
};
class Student
{
public:
    Student(char nm[], int nu, int english, int math)
    {
        strcpy(name, nm);
        num = nu;
        mathScore = math;
        englishScore = english;
        count++;
    }
    void ShowBase()
    {
        cout << "Name:" << name << endl
             << "Num:" << num << endl
             << "MathScore:" << mathScore << endl
             << "EnglishScore:" << englishScore << endl;
    }
    void ShowStatic()
    {
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

class Dog
{
public:
    Dog(char *n, int a, char *s, double w)
    {
        strcpy(name, n);
        age = a;
        strcpy(sex, s);
        weight = w;
    }
    void ShowMessage()
    {
        cout << "Name:" << name << endl
             << "Age:" << age << endl
             << "Sex:" << sex << endl
             << "Weight:" << weight << endl;
    }

private:
    char *name;
    int age;
    char sex[10];
    double weight;
};
class Account
{
public:
    Account(int ac, char us[], char pa[], double ba, double apr)
    {
        accountNum = ac;
        strcpy(userName, us);
        strcpy(password, pa);
        balance = ba;
        APR = apr;
    }
    void Save(char *u, char *p, double money)
    {
        if (strcpy(u, userName) == 0 && strcpy(p, password) == 0)
        {
            balance += money;
            cout << "Saved!" << endl;
        }
        else
            cout << "Username or password errored!" << endl;
    }
    void Withdraw(char *u, char *p, double money)
    {
        if (strcpy(u, userName) == 0 && strcpy(p, password) == 0)
        {
            if (money <= balance)
            {
                balance -= money;
                cout << "Withdrawn!" << endl;
            }
            else
            {
                cout << "Failed!" << endl;
            }
        }
        else
            cout << "Username or password errored" << endl;
    }
    double Calculate()
    {
        return balance * (1 + APR);
    }
    void ShowMessage(char *u, char *p)
    {
        if (strcpy(u, userName) == 0 && strcpy(p, password) == 0)
        {
            cout << "AccountNum:" << accountNum << endl
                 << "Balance:" << balance << endl
                 << "APR:" << APR << endl;
        }
        else
            cout << "Username or password errored!" << endl;
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
    People p1(20, 175, 130);
    p1.Eating();
    p1.Sporting();
    p1.Sleeping();
    p1.Show();
    p1.ShowNum();
    People p2(23, 182, 153);
    p2.ShowNum;
    return 0;
}