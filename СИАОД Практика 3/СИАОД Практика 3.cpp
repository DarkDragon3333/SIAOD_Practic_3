#include <iostream>
#include <string>
#include <vector>

using namespace std;

//Префикс функция
void prefix_function(string s) 
{ 
	int n = (int)s.length(); //Для итерации по вектору
	vector<int> arr(n); //Место хранения значений префикс функции
	for (int i = 1; i < n; ++i) {
		int j = arr[i - 1];
		while (j > 0 && s[i] != s[j])
			j = arr[j - 1];
		if (s[i] == s[j])  
			++j;
		arr[i] = j;
	}

	cout << endl << "Значение префикс функции: ";
	for (size_t i = 0; i < arr.size(); i++) //Вывод значений префикс функции
	{
		cout << arr[i];
	}
}

void Redactor(char stroca[1024]) {

	char stroca_1[1024]; //Основная строка
	char stroca_2[1024]; //Вспомогательная строка

	for (size_t i = 0; i < sizeof(stroca_1); i++)
	{
		stroca_1[i] = stroca[i]; //Заполняем основную строку
	}

	cout << endl << stroca_1; //Выводим основную строку в качестве изначального образца

	for (size_t i = 0; i < sizeof(stroca_1); i++) //Чистим 1-ю строку от знаков препинания, кроме последнего
	{
		if ((stroca_1[i] == '.' || stroca_1[i] == '!' || stroca_1[i] == '?') && stroca_1[i + 1] == '\0') {
			break;
		}
		else if ((stroca_1[i] >= '!' && stroca_1[i] < '0') || (stroca_1[i] >= ':' && stroca_1[i] < 'A')) {
			stroca_1[i] = ' ';
		}
	}

	cout << endl << stroca_1; //Выводим отредактированную основную строку

	for (size_t i = 0; i < sizeof(stroca_1); i++) //Итерируемся по строке
	{
		//Если предыдущие символы не ' ', ' ', '.' и следующий символ заглавная буква то:
		if (stroca_1[i + 1] >= 'A' && stroca_1[i + 1] <= 'Z' && !(stroca_2[i - 2] == '.' && stroca_2[i - 1] == ' ' && stroca_2[i] == ' ')) {

			for (size_t j = 0; j < i; j++)
			{
				stroca_2[j] = stroca_1[j]; //Заполняем вспомогательную строку до пробела и заглавной буквы
			}
			//Вставляем знак препинания и 2 пробела
			stroca_2[i] = '.';
			stroca_2[i + 1] = ' ';
			stroca_2[i + 2] = ' ';

			i += 3; //Перескакиваем через вставленых 3 символа

			for (size_t j = i; j < sizeof(stroca_1); j++)
			{
				stroca_2[j] = stroca_1[j - 2]; //Дозаполняем вспомогательную строку
			}

			for (size_t i = 0; i < sizeof(stroca_1); i++)
			{
				stroca_1[i] = stroca_2[i]; //Итоговый результат копируем в 1-ую строку
			}
		}
	}
	cout << endl << stroca_2 << endl; //Вывод финального образца
}

void main()
{
	setlocale(LC_ALL, "ru");

	char stroca[1024] = "Hi,my,name-is.max:What!is?your;name?My,name.is;jeck.How;old,are.you?I.am;18" ; //Текст для первой части задания
	Redactor(stroca);  //Вызов функции редактирования

	string s = "abcabcd"; //Рандомная строка для второй части задания
	prefix_function(s); //Вызов префикс функции
}