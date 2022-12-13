#include <bits/stdc++.h>

using namespace std;

class Complex{
    public:
    Complex(){
	re=0;
	im=0;
    }
    Complex(double r,double i){
	re=r;
	im=i;
    }
    Complex operator+(Complex &c){
	Complex a;
	a.re=re+c.re;
	a.im=im+c.im;
	return a;
    }
    void Show(){
	cout<<"Result="<<re;
	if(im==0){
	    cout<<endl;
	    return;
	}
	if(im>0) cout<<"+";
	cout<<im<<"j"<<endl;
    }
    Complex operator-(Complex &c){
	Complex a;
	a.re=re-c.re;
	a.im=im-c.im;
	return a;
    }
    Complex operator*(Complex &c){
	Complex a;
	a.re=re*c.re-im*c.im;
	a.im=re*c.im+im*c.re;
	return a;
    }
    Complex operator/(Complex &c){
	Complex a;
	a.re=(re*c.re+im*c.im)/sqrt(c.re*c.re+c.im*c.im);
	a.im=(im*c.re-re*c.im)/sqrt(c.re*c.re+c.im*c.im);
	return a;
    }
    private:
    double re;
    double im;
};

int main()
{
    Complex a(5,-12),b(3,4),c;
    c=a+b;
    c.Show();
    c=a-b;
    c.Show();
    c=a*b;
    c.Show();
    c=a/b;
    c.Show();
    return 0;
}
