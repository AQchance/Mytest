#include <bits/stdc++.h>

using namespace std;

class Matrix{
    public:
	Matrix(){
	    memset(a,0,sizeof(a));
	}
	friend ostream& operator<<(ostream &output,Matrix &m);
	friend istream& operator>>(istream &input,Matrix &m);
    private:
	int a[2][3];
};

 ostream & operator<<(ostream &output,Matrix &m){
     cout<<"Output:"<<endl;
    for(int i=0;i<2;i++){
	for(int j=0;j<3;j++){
    	    output<<m.a[i][j]<<" ";
	}
	output<<endl;
    }
    return output;
}
istream & operator>>(istream &input,Matrix &m){
    cout<<"Input:"<<endl;
    for(int i=0;i<2;i++){
	for(int j=0;j<3;j++){
	    input>>m.a[i][j];
	}
    }
    return input;
}


int main(){
    Matrix m;
    cin>>m;
    cout<<m;
    return 0;
}
