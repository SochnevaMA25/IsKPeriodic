//
//  main.cpp
//  IsKPeriodic
//
//  Created by Marina Sochneva on 10.12.2022.
//

#include <iostream>
#include"Algoritm.h"

using namespace std;

int main() {
    setlocale(LC_ALL, "");
    string txt;
    cout << "Введите строку: " << endl;
    cin >> txt;
    int K; // проверка строки на кратность этому числу
    cout << "Введите кратность: " << endl;
    cin >> K;
    Algoritm a(K, txt);
    return 0;
}
