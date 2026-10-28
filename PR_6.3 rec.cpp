#include <iostream>
#include <iomanip>
#include <time.h>
using namespace std;

// Прототипи функцій (звичайна та шаблонна версії)
void Create(int* a, const int size, const int Low, const int High, int i);
template <typename T>
void Create(T* a, const int size, const int Low, const int High, int i);

void Print(int* a, const int size, int i);
template <typename T>
void Print(T* a, const int size, int i);

int CountOdd(int* a, const int size, int i);
template <typename T>
int CountOdd(T* a, const int size, int i);

int main()
{
    srand((unsigned)time(NULL)); // Ініціалізація генератора чисел

    const int n = 10;
    int Low = -10, High = 10;

    // Перший масив (виклики звичайних функцій)
    int a[n];
    Create(a, n, Low, High, 0);
    Print(a, n, 0);

    int s1 = CountOdd(a, n, 0);
    cout << "CountOdd(a, n) = " << s1 << endl;

    int s2 = CountOdd<int>(a, n, 0);
    cout << "CountOdd<int>(a, n) = " << s2 << endl;

    // Другий масив (виклики шаблонних функцій)
    int b[n];
    Create<int>(b, n, Low, High, 0);
    Print<int>(b, n, 0);

    int s3 = CountOdd<int>(b, n, 0);
    cout << "CountOdd<int>(b, n) = " << s3 << endl;

    return 0;
}

// Рекурсивна генерація масиву int
void Create(int* a, const int size, const int Low, const int High, int i)
{
    a[i] = Low + rand() % (High - Low + 1);
    if (i < size - 1) // Перехід до i + 1, поки не кінець масиву
        Create(a, size, Low, High, i + 1);
}

// Шаблонна генерація масиву
template <typename T>
void Create(T* a, const int size, const int Low, const int High, int i)
{
    a[i] = Low + rand() % (High - Low + 1);
    if (i < size - 1)
        Create<T>(a, size, Low, High, i + 1);
}

// Рекурсивний вивід масиву int
void Print(int* a, const int size, int i)
{
    cout << setw(4) << a[i];
    if (i < size - 1)
        Print(a, size, i + 1);
    else
        cout << endl; // Перенос рядка після останнього елемента
}

// Шаблонний вивід масиву
template <typename T>
void Print(T* a, const int size, int i)
{
    cout << setw(4) << a[i];
    if (i < size - 1)
        Print<T>(a, size, i + 1);
    else
        cout << endl;
}

// Рекурсивний підрахунок непарних елементів int
int CountOdd(int* a, const int size, int i)
{
    if (i < size)
    {
        if (a[i] % 2 != 0) // Якщо елемент непарний
            return 1 + CountOdd(a, size, i + 1);
        else
            return CountOdd(a, size, i + 1);
    }
    else
        return 0; // Базовий випадок (кінець масиву)
}

// Шаблонний підрахунок непарних елементів
template <typename T>
int CountOdd(T* a, const int size, int i)
{
    if (i < size)
    {
        if (a[i] % 2 != 0)
            return 1 + CountOdd<T>(a, size, i + 1);
        else
            return CountOdd<T>(a, size, i + 1);
    }
    else
        return 0;
}