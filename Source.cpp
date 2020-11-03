#include <iostream>
#include <omp.h>
#include <time.h>
#include <cmath>

using namespace std;


// Параллельное вычисление числа π, используя ряд Эйлера
double euler(long long n, int threads)
{
    double result = 0;
    omp_set_num_threads(threads);
#pragma omp parallel
    {
        result = 0;

#pragma omp parallel for
        for (long long i = 0; i < n; i++)
        {
            result += 1 / (pow(i + 1, 2));
        }

        result = sqrt(result * 6);
    }
    return result;
}

int main()
{
    setlocale(LC_CTYPE, "Russian");
    cout << "Практическая работа №2" << endl;
    cout << "Параллельное программирование с использованием технолгии OpenMP" << endl;
    cout << "Бузыкин Игорь" << endl;
    cout << endl;
    cout << "Введите степень числа 10: ";
    int paw;
    cin >> paw;
    double result = 0;
    int threads = 1;
    cout << "Измерение скорости при n = 10^" << paw << endl;
    long long n = pow(10, paw);
    clock_t start = clock();

    result = euler(n, threads);

    clock_t end = clock();
    double sec = (double)(end - start) / CLOCKS_PER_SEC;
    cout << "result = " << result << "; " << sec << " sec; threads = " << threads << "; n = 10^" << paw << endl;

    threads = 4;
    start = clock();

    result = euler(n, threads);

    end = clock();
    sec = (double)(end - start) / CLOCKS_PER_SEC;
    cout << "result = " << result << "; " << sec << " sec; threads = " << threads << "; n = 10^" << paw << endl;

    threads = 8;
    start = clock();

    result = euler(n, threads);

    end = clock();
    sec = (double)(end - start) / CLOCKS_PER_SEC;
    cout << "result = " << result << "; " << sec << " sec; threads = " << threads << "; n = 10^" << paw << endl;

    threads = 16;
    start = clock();

    result = euler(n, threads);

    end = clock();
    sec = (double)(end - start) / CLOCKS_PER_SEC;
    cout << "result = " << result << "; " << sec << " sec; threads = " << threads << "; n = 10^" << paw << endl;

    threads = 32;
    start = clock();

    result = euler(n, threads);

    end = clock();
    sec = (double)(end - start) / CLOCKS_PER_SEC;
    cout << "result = " << result << "; " << sec << " sec; threads = " << threads << "; n = 10^" << paw << endl;

    threads = 64;
    start = clock();

    result = euler(n, threads);

    end = clock();
    sec = (double)(end - start) / CLOCKS_PER_SEC;
    cout << "result = " << result << "; " << sec << " sec; threads = " << threads << "; n = 10^" << paw << endl;
    cout << endl;


    return 0;
}