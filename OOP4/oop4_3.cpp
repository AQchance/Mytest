#include <bits/stdc++.h>

using namespace std;

const double pi =3.1415926535;

class Shape{
    public:
        virtual double area() const {
	   return 0.0;
	}
	virtual void Shapename() const = 0;
};

class Circle:public Shape{
    private:
	double redius;
    public:
	Circle(double r){
	    this->redius = r;
	}
	virtual void Shapename() const{
	   cout<< "This is a circle."<<endl;
	}
	virtual double area() const{
	    cout<<"The area of this circle is  "<< pi * redius * redius << "."  <<endl;
	    return pi * redius * redius;
	}
};

class Square:public Shape{
    private:
	double side_length;
    public:
	Square(double side_length){
	    this->side_length = side_length;
	}
	virtual void Shapename() const{
	    cout<<"This is a square."<<endl;
	}
	virtual double area() const{
	    cout<<"The area of this square is "<< side_length * side_length << "." <<endl;
	    return side_length * side_length;
	}
};

class Rectangle:public Shape{
    private:
	double length;
	double width;
    public:
	Rectangle(double length, double width){
	    this->length = length;
	    this->width = width;
	}
	virtual void Shapename() const{
	    cout<< "this is a rectangle." <<endl;
	}
	virtual double area() const{
	    cout<< "The area of this rectangle is " << length * width << "." <<endl;
	    return length * width;
	}
};

class Trapezoid:public Shape{
    private:
	double top_length;
	double bottom_length;
	double height;
    public:
	Trapezoid(double top_length, double bottom_length, double height){
	    this->top_length = top_length;
	    this->bottom_length =bottom_length;
	    this->height = height;
	}
	virtual void Shapename() const{
	    cout<< "This is a trapezoid." <<endl;
	}
	virtual double area() const{
	    cout<< "The area of this trapezoid is " << (top_length + bottom_length) * height / 2 << "." <<endl;
	    return (top_length + bottom_length) * height / 2;
	}
};

class Triangle:public Shape{
    private:
	double side1;
	double side2;
	double side3;
    public:
	Triangle(double side1, double side2, double side3){
	    this->side1 = side1;
	    this->side2 = side2;
	    this->side3 = side3;
	}
	virtual void Shapename() const{
	    cout<< "This is a triangle." <<endl;
	}
	virtual double area() const{
	    double s = (side1 + side2 + side3) / 2;
	    cout<< "The area of this triangle is " << sqrt(s * (s - side1) * (s - side2) * (s - side3)) << "." <<endl;
	    return sqrt(s * (s - side1) * (s - side2) * (s - side3));
	}
};

int main()
{
    Circle c(3);
    Square s(5);
    Rectangle r(4, 6);
    Trapezoid tra(3, 7, 5);
    Triangle tri(3, 4, 5);
    Shape *p[5]={&c, &s, &r, &tra, &tri};
    double sum = 0;
    for(int i = 0; i < 5; i++){
	p[i]->Shapename();
	sum += p[i]->area();
    }
    cout<<"Sum: "<<sum<<endl;
    return 0;
}

