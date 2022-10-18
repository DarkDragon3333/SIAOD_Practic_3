#include <iostream>
#include <string>
#include "Search.h"

using namespace std;

//void increaseStr(char* &str, int &size) {
//	char* newStr = new char[size * 2];
//	for (int i = 0; i < size; i++) {
//		newStr[i] = str[i];
//	}
//	cout << endl << sizeof(*str);
//	delete[] str;
//	*str = *newStr;
//	cout << endl << sizeof(*str);
//}

int main()
{
	setlocale(LC_ALL, "ru");

	char stroca[1024] = "Hi,my,name-is.Max:What!is?your;name?" ;
	char stroca_2[1024];

	int* arr = new int[10];
	int* arrt = new int[11];

	for (size_t i = 0; i < 4; i++)
	{

	}

	for (size_t i = 0; i < sizeof(stroca); i++)
	{
		stroca_2[i] = stroca[i];
	}
	

	for (int i = 0; i < sizeof(stroca); i++)
	{
		if ( (stroca[i] == '.' or stroca[i] == '!' or stroca[i] == '?') and stroca[i + 1] == '\0') {
			break;
		}
		else if ( (stroca[i + 1] >= 'A' && stroca[i + 1] <= 'Z') and  ((stroca[i] >= '!' && stroca[i] <= '/') or  (stroca[i] >= ':' && stroca[i] <= '?')) and stroca[i + 1] != '\0' and stroca[i + 2] != '\0') {
			for (size_t j = 0; j <= i; j++)
			{
				stroca_2[j] = stroca[j];
			}
			
			stroca_2[i + 1] = ' ';
			stroca_2[i + 2] = ' ';

			for (size_t j = i + 3; j <= sizeof(stroca); j++)
			{
				stroca_2[j] = stroca[j];
			}
		}
		else if ((stroca[i] >= '!' && stroca[i] < '0') or (stroca[i] >= ':' && stroca[i] < 'A')) {
			stroca[i] = ' ';
		}
		cout << stroca_2[i];
	}
	cout << endl << stroca_2;
	
	return 0;
}