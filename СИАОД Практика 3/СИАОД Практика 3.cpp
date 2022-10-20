#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> prefix_function(string s) {
	int n = (int)s.length();
	vector<int> pi(n);
	for (int i = 1; i < n; ++i) {
		int j = pi[i - 1];
		while (j > 0 && s[i] != s[j])
			j = pi[j - 1];
		if (s[i] == s[j])  ++j;
		pi[i] = j;
	}
	for (size_t i = 0; i < pi.size(); i++)
	{
		cout << pi[i];
	}
	return pi;
}

int main()
{
	setlocale(LC_ALL, "ru");

	char stroca[1024] = "Hi,my,name-is.max:What!is?your;name?My,name.is;jeck.How;old,are.you?" ;
	char stroca_2[1024];
	

	for (size_t i = 0; i < sizeof(stroca); i++)
	{
		stroca_2[i] = stroca[i];
	}


	for (size_t i = 0; i < sizeof(stroca); i++)
	{
		if ( (stroca[i] == '.' || stroca[i] == '!' || stroca[i] == '?') && stroca[i + 1] == '\0') {
			break;
		}
		else if ((stroca[i] >= '!' && stroca[i] < '0') || (stroca[i] >= ':' && stroca[i] < 'A'))  {
			stroca[i] = ' ';
		}
	}

	cout << endl << stroca;

	int index = 0;
	for (size_t i = index; i < sizeof(stroca); i++)
	{
		index++;
		if (stroca[i + 1] >= 'A' && stroca[i + 1] <= 'Z' && !(stroca_2[i - 2] == '.' && stroca_2[i - 1] == ' ' && stroca_2[i] == ' ')) {
			
			for (size_t j = 0; j < i; j++) 
			{
				stroca_2[j] = stroca[j];
			}

			stroca_2[i] = '.';
			stroca_2[i + 1] = ' ';
			stroca_2[i + 2] = ' ';

			index += 3;
			
			for (size_t j = (i + 3); j < sizeof(stroca); j++)
			{
				stroca_2[j] = stroca[j - 2];
			}

			for (size_t i = 0; i < sizeof(stroca); i++)
			{
				stroca[i] = stroca_2[i];
			}
		}	
	}

	string s = "abcabcd";

	cout << endl << stroca_2 << endl;
	
	prefix_function(s);
	return 0;
}