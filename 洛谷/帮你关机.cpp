#include <bits/stdc++.h>
#include <windows.h>
using namespace std;

int main()
{
	string s1, s2;
	system("shutdown -s");
	cout << "Your computer will be shut down in 60 seconds unless you enter¡°Hail Hydra¡±." << endl;
	s1 = "Hail Hydra!";
flag:
	getline(cin,s2);
	if (s1 == s2) {
		cout << "Hydra will remember your loyalty!";
		system("shutdown -a");
		Sleep(5000);
	}
	else {
		cout << "What the hell do you mean " << s2 << "?" << endl;
		goto flag;
	}
	return 0;
}
