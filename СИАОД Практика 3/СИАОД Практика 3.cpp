#include <iostream>
#include <string>
#include <vector>

using namespace std;

//Префикс функция
vector<int> prefix_function(string s) 
{ 
	int n = (int)s.length(); //Для итерации по вектору
	vector<int> pi(n); //Место хранения значений префикс функции

	//Дальше какая-то хрень. Смотрите в текстовике ссылки
	for (int i = 1; i < n; ++i) {
		int j = pi[i - 1];
		while (j > 0 && s[i] != s[j])
			j = pi[j - 1];
		if (s[i] == s[j])  
			++j;
		pi[i] = j;
	}

	cout << endl << "Значение префикс функции: ";
	for (size_t i = 0; i < pi.size(); i++) //Вывод значений префикс функции
	{
		cout << pi[i];
	}
	return pi; //Можно, в принципе, не возвращать вектор, а просто в функции через цикл вывести значение вектора pi.
}

void main()
{
	setlocale(LC_ALL, "ru");

	char stroca[1024] = "Hi,my,name-is.max:What!is?your;name?My,name.is;jeck.How;old,are.you?I.am;18" ; //Рандомный текст для первой части задания
	char stroca_2[1024]; //Вспомогательная строка

	cout << endl << stroca; //Выводим первую строку в качестве изначального образца

	for (size_t i = 0; i < sizeof(stroca); i++) //Чистим 1-ю строку от знаков препинания, кроме последнего
	{
		if ( (stroca[i] == '.' || stroca[i] == '!' || stroca[i] == '?') && stroca[i + 1] == '\0') {
			break;
		}
		else if ((stroca[i] >= '!' && stroca[i] < '0') || (stroca[i] >= ':' && stroca[i] < 'A'))  {
			stroca[i] = ' ';
		}
	}

	cout << endl << stroca; //Выводим чистую первую строку

	for (size_t i = 0; i < sizeof(stroca); i++) //Итерируемся по строке
	{
		//Если предыдущие символы не ' ', ' ', '.' и следующий символ заглавная буква то:
		if (stroca[i + 1] >= 'A' && stroca[i + 1] <= 'Z' && !(stroca_2[i - 2] == '.' && stroca_2[i - 1] == ' ' && stroca_2[i] == ' ')) {
			
			for (size_t j = 0; j < i; j++) 
			{
				stroca_2[j] = stroca[j]; //Заполняем вспомогательную строку до пробела и заглавной буквы
			}
			//Вставляем знак препинания и 2 пробела
			stroca_2[i] = '.';
			stroca_2[i + 1] = ' ';
			stroca_2[i + 2] = ' ';
			
			 i += 3; //Перескакиваем через вставленых 3 символа
			
			for (size_t j = i; j < sizeof(stroca); j++)
			{
				stroca_2[j] = stroca[j - 2]; //Дозаполняем вспомогательную строку
			}

			for (size_t i = 0; i < sizeof(stroca); i++)
			{
				stroca[i] = stroca_2[i]; //Итоговый результат копируем в 1-ую строку
			}
		}	
	}

	cout << endl << stroca_2 << endl; //Вывод финального образца

	string s = "abcabcd"; //Рандомная строка для второй части задания
	prefix_function(s); //Вызов префикс функции
}