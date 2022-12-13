#include <iostream>
#include"Algoritm.h"

using namespace std;

int main() 
{
	setlocale(LC_ALL, "");
	string txt;
	cout << "Введите строку: " << endl;
	cin >> txt;
	int len = txt.length();
	int K; // проверка строки на кратность этому числу
	cout << "Введите кратность: " << endl;
	cin >> K;
	Algoritm a(txt, len, K);
	return 0;
}

