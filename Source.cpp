#include <iostream>
#include <omp.h>
#include <time.h>
#include <cmath>

using namespace std;

double euler(long long n)
{
    double result = 0;

    for (long long i = 0; i < n; i++)
    {
        result += 1/(pow(i+1, 2));
    }
    result = sqrt(result*6);
    return result;
}

int main()
{
    long long n = pow(10, 15);
    double result = 0;
    clock_t start = clock();
    omp_set_num_threads(8);
#pragma omp parallel for
    for (long long i = 0; i < n; i++)
    {
        result += 1 / (pow(i+1, 2));
    }

    clock_t end = clock();
    double sec = (double)(end - start);

    result = sqrt(result * 6);

    cout << result << endl;
    cout << sec << " sec" << endl;

    system("pause");
    return 0;
}