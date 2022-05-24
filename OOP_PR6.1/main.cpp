#include "Array.hpp"
#include <iostream>
#include <time.h>
#include <stdexcept>
#include <exception>
#include <cmath>
using namespace std;
typedef Array::value_type* TArray;

int main()
{
    int n;
    cout << "n = "; cin >> n;
    Array c = Array(2 * n);
    
    srand((unsigned)time(NULL));
    Array::value_type A = -50;
    Array::value_type B = 50;
    
    TArray a = new Array::value_type[n];
    
    for (int i = 0; i < 2 * n; i++)
        a[i] = A + rand() % int(B - A + 1);
    
    cout << "Created array" << endl;
    Array::iterator l = const_cast<Array::iterator>(c.begin());
    for (int j = 0; j < 2 * n; j++, l++)
        *l = a[j];
    cout << c;
    
    cout << "With added sum and average" << endl;
    int c_sum = c.sum();
    int c_average = c.average();
    c.push_back(c_sum);
    c.push_back(c_average);
    cout << c;

    cout << "With added first non-pair number" << endl;
    c.add_absolute_non_pair();
    cout << c;

    return 0;
}
