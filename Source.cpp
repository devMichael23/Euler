#include <iostream>
#include <omp.h>
#include <time.h>
#include <cmath>

using namespace std;

void euler(long long n, int threads)
{
    double result = 0;
#pragma omp parallel num_threads(threads)
    {
        clock_t start = clock();

    #pragma omp parallel for
        for (long long i = 0; i < n; i++)
        {
            result += 1 / (pow(i + 1, 2));
        }

        result = sqrt(result * 6);
        clock_t end = clock();
        double sec = (double)(end - start) / CLOCKS_PER_SEC;
        cout << "result = " << result << "; " << sec << " sec; threads = " << threads << "; n = 10^10" << endl;
    }
    
}

int main()
{
#pragma region n = 10^10
    int threads = 1;
    long long n = pow(10, 10);
    euler(n, threads);

    threads = 4;
    euler(n, threads);

    threads = 8;
    euler(n, threads);

    threads = 16;
    euler(n, threads);

    threads = 32;
    euler(n, threads);

    threads = 64;
    euler(n, threads);
#pragma endregion

#pragma region n = 10^11
    n = pow(10, 11);

    threads = 1;
    euler(n, threads);

    threads = 4;
    euler(n, threads);

    threads = 8;
    euler(n, threads);

    threads = 16;
    euler(n, threads);

    threads = 32;
    euler(n, threads);

    threads = 64;
    euler(n, threads);
#pragma endregion

#pragma region n = 10^12
    n = pow(10, 12);

    threads = 1;
    euler(n, threads);

    threads = 4;
    euler(n, threads);

    threads = 8;
    euler(n, threads);

    threads = 16;
    euler(n, threads);

    threads = 32;
    euler(n, threads);

    threads = 64;
    euler(n, threads);
#pragma endregion

#pragma region n = 10^13
    n = pow(10, 13);

    threads = 1;
    euler(n, threads);

    threads = 4;
    euler(n, threads);

    threads = 8;
    euler(n, threads);

    threads = 16;
    euler(n, threads);

    threads = 32;
    euler(n, threads);

    threads = 64;
    euler(n, threads);
#pragma endregion

#pragma region n = 10^14
    n = pow(10, 14);

    threads = 1;
    euler(n, threads);
 
    threads = 4;
    euler(n, threads);
 
    threads = 8;
    euler(n, threads);
 
    threads = 16;
    euler(n, threads);
 
    threads = 32;
    euler(n, threads);
 
    threads = 64;
    euler(n, threads);
 #pragma endregion

#pragma region n = 10^15
    n = pow(10, 15);

    threads = 1;
    euler(n, threads);

    threads = 4;
    euler(n, threads);
 
    threads = 8;
    euler(n, threads);
 
    threads = 16;
    euler(n, threads);
 
    threads = 32;
    euler(n, threads);
 
    threads = 64;
    euler(n, threads);
 #pragma endregion


    system("pause");
    return 0;
}