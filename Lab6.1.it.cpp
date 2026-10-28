// Lab 6.1 (iterative)
#include <iostream>
#include <iomanip>
#include <ctime>
#include <cstdlib>

using namespace std;

void Create(int* a, const int size, const int Low, const int High);
void Print(const int* a, const int size);
bool IsSuitable(const int x);
int CountSuitable(const int* a, const int size);
int SumSuitable(const int* a, const int size);
void ZeroSuitable(int* a, const int size);

int main()
{
    srand((unsigned)time(NULL));  // ініціалізація генератора випадкових чисел

    const int n = 24;              // кількість елементів масиву
    int a[n];

    const int Low = -50;           // нижня межа діапазону значень
    const int High = 15;           // верхня межа діапазону значень

    Create(a, n, Low, High);
    cout << "Array:" << endl;
    Print(a, n);

    cout << "Count = " << CountSuitable(a, n) << endl;
    cout << "Sum = " << SumSuitable(a, n) << endl;

    ZeroSuitable(a, n);
    cout << "Modified array:" << endl;
    Print(a, n);

    return 0;
}

// формування масиву випадковими числами з [Low; High]
void Create(int* a, const int size, const int Low, const int High)
{
    for (int i = 0; i < size; i++)
        a[i] = Low + rand() % (High - Low + 1);
}

// виведення масиву в рядок
void Print(const int* a, const int size)
{
    for (int i = 0; i < size; i++)
        cout << setw(4) << a[i];
    cout << endl;
}

// критерій: елемент від'ємний або непарний
bool IsSuitable(const int x)
{
    return x < 0 || x % 2 != 0;
}

// кількість елементів, що задовольняють критерію
int CountSuitable(const int* a, const int size)
{
    int k = 0;
    for (int i = 0; i < size; i++)
        if (IsSuitable(a[i]))
            k++;
    return k;
}

// сума елементів, що задовольняють критерію
int SumSuitable(const int* a, const int size)
{
    int s = 0;
    for (int i = 0; i < size; i++)
        if (IsSuitable(a[i]))
            s += a[i];
    return s;
}

// заміна нулями елементів, що задовольняють критерію
void ZeroSuitable(int* a, const int size)
{
    for (int i = 0; i < size; i++)
        if (IsSuitable(a[i]))
            a[i] = 0;
}
