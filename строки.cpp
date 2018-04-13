// строки.cpp : Defines the entry point for the console application.
//
//1)Дана строка из латинского алфавита.Удалить из нее повторяющиеся символы, а так же все пробелы.

//2)Задана строка, необходимо найти заданную подстроку, удалить ее, и заменить ее на новую указанную строку. (наглядный метод)

//3)Вводим строку, которая должна содержать буквы и целые числа или иные символы. Необходимо найти все числа, 
которые содержаться в строке и поемстить их в отдельный массив.

//4) дана стркоа, состоящая из прописных и заглавных букв. 

// 1)Необходимо посчитать количество заглавных и прописных букв. 
 
// 2)Если заглавная буква стоит в начале слова, то все буквы становятся заглавными, иначе все последующие буквы слова становятся строчными //и опять статисктику //

//5)Дан текст,неосмысленный, в перемешку. Необходимо сортировать слова по призначной части : 
если в слове больше русских букв , то в русский, иначе в английский. 
Для наглядности программного исполнения буквы английского выделяются красным, русского-зеленым.

#define _CRT_SECURE_NO_WARNINGS
#include "stdafx.h"
#include <iostream>
#include <Windows.h>
#include <string>
#include<cstring>
int const N = 500;
using namespace std;
int main()
{// перед использованием убедитесь, что шрифт консоли "lucida console", иначе просто изменить в настройках шрифт для корректной работы программы
	setlocale(LC_ALL, "Rus");
	SetConsoleCP(1251);// позволяет записывать русские символы в строки/массивы 
	SetConsoleOutputCP(1251);
	
	
	//1.
	string one;//строка, вводимая пользователем
	system("color 70");//сделает цвет фона не ярко белым, а цвет букв черным.
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE); //позволит в дальнейшем менять цвет отдельных частей слов
	int k = 0; //количесвто повторов 
	cout << "Пожалуйста, введите строку для удаления в ней повторяющихся символов и пробелов: " << endl;
	getline(cin, one);
	
	cout<< " Ваша строка, если в ней есть повторяющиеся символы, удалим их: " << endl;
	//процесс удаления повторяющихся символов
	for (int i=0; i<one.length(); i++)
		for (int j=i+1; j<one.length();j++)
			if (one[j] == one[i] || one[j] == ' ')
			{
				one.erase(j, 1);//операция удаления
				j--;
			}
	
	cout << endl;
	cout << "Получившаяся строка: " << endl;
	cout << one<<endl;
//2.
	string two;//строка вводимая пользователем
	string two1;//подстрока вводимая пользователем 
	cout << "Введите строку, в которой будет производиться удаление: " << endl;
	getline(cin, two);
	cout << "Введите строку,которую ходите удалить из вышеуказанной: " << endl;
	getline(cin, two1);
	size_t pos = two.find(two1);//поиск индекса первого вхождения подстроки в строку
								// защита от дурака
	if (pos == string::npos)

		cout << "В веденной вами строке нет такого сочетания! " << endl;
	else
	{
		cout << "Удалим выделенное сочетание букв: " << endl;
		//окраска подстроки
		for (int i = 0; i < two.length(); i++)
		{
			if (i < pos || i >= pos + two1.length())
			{
				SetConsoleTextAttribute(hConsole, (WORD)((7 << 4) | 0));
				cout << two[i];
			}
			else {
				SetConsoleTextAttribute(hConsole, (WORD)((12 << 4) | 5));
				cout << two[i];
			}
		}

		cout << endl;
		cout << "Результат удаления: " << endl;

		two.erase(pos, two1.length());//удаляем заданную подстроку
		cout << two << endl;
		string append;//строка , которую пользователь вводит для вставки
		cout << "Введите строку, которую хотите вставить вместо удаленной: " << endl;
		getline(cin, append);
		two.insert(pos, append);//вставляет строку на место удаленной
		cout << "Результат добавления: " << endl;
		//выделяет вставленную строку иным цветом
		for (int i = 0; i < two.length(); i++)
		{
			if (i < pos || i >= pos + append.length())
			{
				SetConsoleTextAttribute(hConsole, (WORD)((7 << 4) | 0));
				cout << two[i];
			}
			else {
				SetConsoleTextAttribute(hConsole, (WORD)((12 << 4) | 5));
				cout << two[i];
			}
		}
		cout << endl;
	}
		//3.
		string rez; //строка, где будут храниться наши числа
		string three;//введенная пользователем строка 
		string basa = "0123456789"; 
		cout << "Введите строку,из которой хотите извлечь целые числа: " << endl;
		getline(cin, three);
		//посик чисел
		for (int i = 0; i < three.length();i++)
		{
			size_t pos = basa.find(three[i]);
			if (pos != string::npos)
			{//сохраняет разрядность, введенного пользователем числа
				if (three[i+1] >='0' && three[i+1]<='9')//если дальше идет число мы не поставим пробел, иначе поставим 
					rez = rez + three[i];
				else
					rez = rez + three[i]+ " ";
				
			}
		}
		cout << "Все целые числа строки: " << rez << endl;
	
	//4.

	string four;//строка, вводимая пользователем
	//можно было обойтись и без этого, просто я поздно поняла, но в падлу переписывать.
	string strRandE = "абвгдеёжзиклмнопрстуфхцчшщъыьэюяabcdefghijklmnopqrstuvwxyz";//строка строчных
	string strbigRandE = "АБВГДЕЁЖЗИКЛМНОПРСТУФХЦЧШЩъыьЭЮЯABCDEFGHIJKLMNOPQRSTUVWXYZ";//строка заглавных
	
	cout << "Введите строку , в которой хотите изменить регистр: " << endl;
	getline(cin,four);
	int K = 0,sim=0;//К-счетчик заглавных,sim-счетчик символов
	k = 0;//счетчик строчных
		  //статистика
	for (int i = 0; i < four.length(); i++)
	{
		size_t pos = strRandE.find(four[i]); 
		if (pos != string::npos)//если мы нашли наш символ в строчных 
			k++;
		else
		{
			size_t pos = strbigRandE.find(four[i]);
			if (pos != string::npos)//если мы нашли наш символ в заглавных
				K++;
			else
				sim++;
		}
	}
	cout << "Статистика введенных вами символов: " << endl;
	cout << "Заглавные: " << K << endl << " Строчные: " << k << endl << " Символы: " << sim << endl;
	//замена регистра
	for (int i = 0; i < four.length();)
	{
		if ((four[i] >= 'A'&&four[i] <= 'Z') || (four[i] >= 'А'&&four[i] <= 'Я'))
		{
			while (four[i] != ' '&&four[i] != '\0')
			{
				four[i] = toupper(four[i]);//превращает строчные в заглавные 
				i++;
			}
		}
		else
		{
			if ((four[i] >= 'a'&&four[i] <= 'z') || (four[i] >= 'а'&&four[i] <= 'я'))
			{
				while (four[i] != ' '&&four[i] != '\0')
				{
					four[i] = tolower(four[i]);//превращает заглавные в строчные 
					i++;
				}
			}
			else
				i++;//символы и прочую штуку оставляет неизменной
		}
		i++;
	}
	
	cout << "Получившаяся после преобразования строка: " << endl << four << endl;
	//обнуляем счетчики статистики и считаем её заново 
	k = 0;
	K = 0;
	sim = 0;
	for (int i = 0; i < four.length(); i++)
	{
		size_t pos = strRandE.find(four[i]);
		if (pos != string::npos)
			k++;
		else
		{
			size_t pos = strbigRandE.find(four[i]);
			if (pos != string::npos)
				K++;
			else
				sim++;
		}
	}
	cout << "Статистика введенных вами символов после преобразования: " << endl;
	cout << "Заглавные: " << K << endl << " Строчные: " << k << endl << " Символы: " << sim << endl;


	//5.
	int rus = 0, eng = 0;//колличество русских и английских символов
	string five;//строка, вводимая пользователем 
	string russian, english; //группы русских и английских
	cout << "Введите строку, которую хотите сортировать по словам(признак сортировки указан в описании программы): " << endl;
	getline(cin, five);
	
	cout << "В вашей строке красным выделены английские символами, а зеленым русские: " << endl;
	//окраска букв
	for (int i = 0; i < five.length(); i++)
	{
		if ((five[i] >= 'a'&& five[i] <= 'z') || (five[i] >= 'A'&&five[i] <= 'Z'))
		{
			SetConsoleTextAttribute(hConsole, (WORD)((12<< 4) | 0));
			cout <<five[ i];
		}
		else {
			if ((five[i] >= 'а'&& five[i] <= 'я') || (five[i] >= 'А'&&five[i] <= 'Я'))
			{
				SetConsoleTextAttribute(hConsole, (WORD)((10 << 4) | 0));
				cout << five[i];
			}
			else {
			SetConsoleTextAttribute(hConsole, (WORD)((7 << 4) | 0));
			cout << five[i];
		}
		}
	}
	cout << endl;
	for (int i = 0; i < five.length();)
	{
		eng = 0;
		rus = 0;
		k = i;//кстати, здесь k мы используем, как сохранения позиции i перед началом слова, чтобы потом вывести его в соответствующую группу 
		//считаем в слове количество русских и английских букв
		while (five[i] != ' '&& five[i] != '\0')
		{
			if ((five[i] >= 'a'&& five[i] <= 'z') || (five[i] >= 'A'&&five[i] <= 'Z'))
				eng++;

			else
				if ((five[i] >= 'а'&& five[i] <= 'я') || (five[i] >= 'А'&&five[i] <= 'Я'))
					rus++;
				
			i++;
		}
		i++;

		if (rus >= eng) //если русских букв больше либо равно английским, тогда прибавить к русским словам данное слово
		{
			for (k;k < i-1;k++)
			{
				russian = russian + five[k];
			}
			russian += ", ";
		}
		else
		{
			for (k;k < i-1;k++)
			{
				english = english + five[k];//иначе прибавим данное слово к английским
			}
			english += ", ";
		}

	}
	cout << endl;
	SetConsoleTextAttribute(hConsole, (WORD)((7 << 4) | 0));//вовращаем нашему фону и буквам предыдущий цвет 
	cout << "Разделим слова по принципу: если в слове больше русских букв или русских и английских одинаковое количество, то отнесем его к русским, иначе к английскийм. " << endl;
	cout << "Русские: " << endl;
	cout << russian << endl;
	cout << "Английские: " << endl << english << endl;
	system("pause");
    return 0;
}

