//
//  Algoritm.h
//  IsKPeriodic
//
//  Created by Marina Sochneva on 10.12.2022.
//
#define Algoritm_h
#include <string>

using namespace std;

bool ThrowIfZero(int x) {
    if (x <= 0) {
        cout << "Кратность не может быть равна нулю или быть меньше нуля" << endl;
        return false;
    }
    return true;
}

class Algoritm
{
public:
    const string& txt;
    int* lps;
    int count;
    Algoritm(int k, const string& t)
        : count(k), txt(t)
    {
        if(ThrowIfZero(count) == true)
        {
            IsKPeriodic(count, txt);
        }
    }
    
void computeLPS(string str, int* lps) // префиксная функция и формирование массива lps для алгоритма КМП
{
    int j = 0;

    lps[0] = 0; // lps[0] всегда 0

    int i = 1;
    while (i < str.size()) {
        if (str[i] == str[j]) {
    j++;
    lps[i] = j;
    i++;
        }
        else
        {
            if (j != 0) {
    j = lps[j - 1];
            }
            else
            {
    lps[i] = 0;
                i++;
            }
        }
    }
}
void IsKPeriodic(int K, const string& txt) // функция проверки кратности на основе алгоритма КМП
{
    string str; // формируем подстрку, беря начальные символы строки по колличеству К
    for (int i = 0; i < K; ++i)
        str.push_back(txt[i]);

    int* lps = new int[str.size()];

    computeLPS(str, lps);

    int i = 0;
    int j = 0;
    int value = 0;
    while (i < txt.size()) {
        if (str[j] == txt[i])
        {
            j++;
            i++;
        }
        if (j == str.size()) {
            value++; // считаем совпадения
            j = lps[j - 1];
        }

        else if (i < txt.size() && str[j] != txt[i]) {
            if (j != 0)
            {
                j = lps[j - 1];
            }
            else
            {
                i = i + 1;
            }
        }
    }
    if (K * value == txt.size()) // если количество найденных совпадений, помноженное на К, равно длине строки, то строка кратна К
    {
        cout << "Строка " << txt << " кратна " << K << endl;
    }
    else
    {
        cout << "Строка " << txt << " не кратна " << K << endl; // иначе не кратна
    }
    delete[] lps;
}
};

