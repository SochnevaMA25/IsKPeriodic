#pragma once
#include <iostream>
#include <string>

using namespace std;


class Algoritm
{
public:
    const string& txt;
    int* lps;
    int count;
    int len;
    Algoritm(const string& t, int len, int k)
        : txt(t), len(len), count(k)
    {
        if (check(count) == true)
        {
            isKPeriodic(txt, len, count);
        }
    }

    //проверка числа кратности
    bool check(int x) {
        if (x <= 0) {
            cout << "Кратность не может быть равна нулю или быть меньше нуля" << endl;
            return false;
        }
        return true;
    }

    bool isPrefix(string str, int len, int i, int k)
    {
        // так как подстрока длины len не может начинаться с индекса i
        if (i + k > len)
            return false;
        for (int j = 0; j < k; j++)
        {
            //проверка несоответствия символов между префиксом и подстрокой, начинающейся с индекса i
            if (str[i] != str[j])
                return false;
            i++;
        }
        return true;
    }

    //Функция, определяющая соответствует ли заявляенное число кратности строки
    void isKPeriodic(string str, int len, int k)
    {
        //Проверка все ли подстроки равны к префиксу длины k строки
        for (int i = k; i < len; i += k)
            if (!isPrefix(str, len, i, k))
            {
                cout << "Строка: " << str << "не кратна числу " << k << endl;
            }
        cout << "Строка: " << str << " кратна числу " << k << endl;
    }
};

