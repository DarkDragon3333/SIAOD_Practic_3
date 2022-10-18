#include <iostream>
#include <string>
#include <fstream>
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

	ofstream File;
	string stroka;

	int strSize = 0;
	int i = 0;

	File.open("try.txt");
	File.clear();
	if (!File.is_open()) {
		cout << "Not found";
	}
	else {
		string s = "Привет,меня,зовут,Максим,А,как,зовут,тебя,";
		strSize = s.length();
		File << s;
		File.close();

		ifstream Read("try.txt");
		getline(Read, stroka);
		Read.close();
	}

	for (int i = 0; i < strSize; i++)
	{
		if (stroka[i] >= 'А' && stroka[i] <= 'Я') {
			
		}
		else if (stroka[i] == ',') {
			stroka[i] = ' ';
			
		}
		cout << stroka[i];
	}
	cout << endl << stroka;
	
	return 0;
}