// Practice2.cpp: 定义控制台应用程序的入口点。
//

#include<iostream>
#include"ComplexNum.h"
using std::cin;
using std::cout;
using std::endl;

int main()
{
	ComplexNum a(3, 4);
	ComplexNum c;
	cout << "Please input a complex number:"<<endl;
	while (cin>>c)
	{
		cout << "c is " << c << endl;
		cout << "conjuate is " << ~c << endl;
		cout << "a is " << a << endl;
		cout << "a + c is " << a + c << endl;
		cout << "a -c is " << a - c << endl;
		cout << "a*c is" << a * c << endl;
		cout << "6*c is " << 6  *  c << endl;
		cout << "Please input a complex number:" << endl;
	}
	cout << "Task Finished." << endl;
	
	
	cin.get();

	
	
	return 0;
}

