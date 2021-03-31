#include <iostream>
#include <cmath>
#include <vector>
#include <string>
using namespace std;

int main()
{
	string num,num1; //entered/deduced number
	cout << "Enter the number:" << endl;
	cin >> num;
	num1 = num;
	int ss; // numeral system
	cout << "Enter the numeral system" << endl;
	cin >> ss;
	int ii = num.size()-1;
	int i = 0;
	int d =0 ; // number in decimal numeral system
	 //translate to decimal number system
	while (i != num.size())
	{
		//Checking the correctness of the number
		if (int (num[i]>57)) 
		{
			if (int (num[i] - 'A' + 10) >= ss)
			{			
				cout << "Incorrect number";
				exit(1);
			}
		}
		if (int(num[i] <= 57))
		{
			if (int(num[i] - '0') >= ss)
			{
				cout << "Incorrect number";
				exit(1);
			}
		}
		//translate to decimal numeral system
		if (int(num[i] > 64))
		{
			d = d + (int(num[i]-'A' + 10)) * (pow(ss, ii));
		}
		if (int(num[i] <= 64)) 
		{
			d = d + (int(num[i] - '0')) * pow(ss, ii);
		}		
		ii -= 1;
		i += 1;
	}
	cout << "Enter the new numeral system" << endl;
	int nss; // new numeral system
	cin >> nss;
	vector<int> trs; // finish translated number;
	int b=0;
	while (d >= nss)
	{
		b = d % nss;
		trs.push_back(b);
		d = d / nss;
	}
	trs.push_back(d);
	// out finish number
	cout << "Number " << num1 << " from " << ss << "th numeral system to " << nss << "th numeral system is: ";
	for (int l = trs.size()-1; l >= 0; l--)
	{
		if (trs[l] > 9)
		{
			cout << char(trs[l] + '7');
		}
		else 
			cout  <<trs[l];		
	}
			return 0;
}
