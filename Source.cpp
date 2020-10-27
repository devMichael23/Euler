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
        result += 1 /(pow(i+1, 2));
    }
    result = sqrt(result*6);
    return result;
}

double euler(long long n, int threads)
{
    double result = 0;
    omp_set_num_threads(threads);
#pragma omp parallel for
    for (long long i = 0; i < n; i++)
    {
        result += 1 /(pow(i+1,2));
    }

    result = sqrt(result * 6);
    return result;
}

int main()
{
    // 4 8 16 32 64
#pragma region n = 10^10
    int threads = 1;
    long long n = pow(10, 6);
    double result = 0;
    clock_t start = clock();
    result = euler(n);
    clock_t end = clock();
    double sec = (double)(end - start) / CLOCKS_PER_SEC;
    printf("result = %f; %f sec; thread = %d; n = 10^10\n", result, sec, threads);

    threads = 4;
    start = clock();
    result = euler(n, threads);
    end = clock();
    sec = (double)(end - start) / CLOCKS_PER_SEC;
    printf("result = %f; %f sec; thread = %d; n = 10^10\n", result, sec, threads);

    threads = 8;
    start = clock();
    result = euler(n, threads);
    end = clock();
    sec = (double)(end - start) / CLOCKS_PER_SEC;
    printf("result = %f; %f sec; thread = %d; n = 10^10\n", result, sec, threads);

    threads = 16;
    start = clock();
    result = euler(n, threads);
    end = clock();
    sec = (double)(end - start) / CLOCKS_PER_SEC;
    printf("result = %f; %f sec; thread = %d; n = 10^10\n", result, sec, threads);

    threads = 32;
    start = clock();
    result = euler(n, threads);
    end = clock();
    sec = (double)(end - start) / CLOCKS_PER_SEC;
    printf("result = %f; %f sec; thread = %d; n = 10^10\n", result, sec, threads);

    threads = 64;
    start = clock();
    result = euler(n, threads);
    end = clock();
    sec = (double)(end - start) / CLOCKS_PER_SEC;
    printf("result = %f; %f sec; thread = %d; n = 10^10\n", result, sec, threads);
#pragma endregion

#pragma region n = 10^11
    n = pow(10, 7);

    threads = 1;
    start = clock();
    result = euler(n);
    end = clock();
    sec = (double)(end - start) / CLOCKS_PER_SEC;
    printf("result = %f; %f sec; thread = %d; n = 10^11\n", result, sec, threads);

    threads = 4;
    start = clock();
    result = euler(n, threads);
    end = clock();
    sec = (double)(end - start) / CLOCKS_PER_SEC;
    printf("result = %f; %f sec; thread = %d; n = 10^11\n", result, sec, threads);

    threads = 8;
    start = clock();
    result = euler(n, threads);
    end = clock();
    sec = (double)(end - start) / CLOCKS_PER_SEC;
    printf("result = %f; %f sec; thread = %d; n = 10^11\n", result, sec, threads);

    threads = 16;
    start = clock();
    result = euler(n, threads);
    end = clock();
    sec = (double)(end - start) / CLOCKS_PER_SEC;
    printf("result = %f; %f sec; thread = %d; n = 10^11\n", result, sec, threads);

    threads = 32;
    start = clock();
    result = euler(n, threads);
    end = clock();
    sec = (double)(end - start) / CLOCKS_PER_SEC;
    printf("result = %f; %f sec; thread = %d; n = 10^11\n", result, sec, threads);

    threads = 64;
    start = clock();
    result = euler(n, threads);
    end = clock();
    sec = (double)(end - start) / CLOCKS_PER_SEC;
    printf("result = %f; %f sec; thread = %d; n = 10^11\n", result, sec, threads);
#pragma endregion

#pragma region n = 10^12
    n = pow(10, 12);

    threads = 1;
    start = clock();
    result = euler(n);
    end = clock();
    sec = (double)(end - start) / CLOCKS_PER_SEC;
    printf("result = %f; %f sec; thread = %d; n = 10^12\n", result, sec, threads);

    threads = 4;
    start = clock();
    result = euler(n, threads);
    end = clock();
    sec = (double)(end - start) / CLOCKS_PER_SEC;
    printf("result = %f; %f sec; thread = %d; n = 10^12\n", result, sec, threads);

    threads = 8;
    start = clock();
    result = euler(n, threads);
    end = clock();
    sec = (double)(end - start) / CLOCKS_PER_SEC;
    printf("result = %f; %f sec; thread = %d; n = 10^12\n", result, sec, threads);

    threads = 16;
    start = clock();
    result = euler(n, threads);
    end = clock();
    sec = (double)(end - start) / CLOCKS_PER_SEC;
    printf("result = %f; %f sec; thread = %d; n = 10^12\n", result, sec, threads);

    threads = 32;
    start = clock();
    result = euler(n, threads);
    end = clock();
    sec = (double)(end - start) / CLOCKS_PER_SEC;
    printf("result = %f; %f sec; thread = %d; n = 10^12\n", result, sec, threads);

    threads = 64;
    start = clock();
    result = euler(n, threads);
    end = clock();
    sec = (double)(end - start) / CLOCKS_PER_SEC;
    printf("result = %f; %f sec; thread = %d; n = 10^12\n", result, sec, threads);
#pragma endregion

#pragma region n = 10^13
    n = pow(10, 13);

    threads = 1;
    start = clock();
    result = euler(n);
    end = clock();
    sec = (double)(end - start) / CLOCKS_PER_SEC;
    printf("result = %f; %f sec; thread = %d; n = 10^13\n", result, sec, threads);

    threads = 4;
    start = clock();
    result = euler(n, threads);
    end = clock();
    sec = (double)(end - start) / CLOCKS_PER_SEC;
    printf("result = %f; %f sec; thread = %d; n = 10^13\n", result, sec, threads);

    threads = 8;
    start = clock();
    result = euler(n, threads);
    end = clock();
    sec = (double)(end - start) / CLOCKS_PER_SEC;
    printf("result = %f; %f sec; thread = %d; n = 10^13\n", result, sec, threads);

    threads = 16;
    start = clock();
    result = euler(n, threads);
    end = clock();
    sec = (double)(end - start) / CLOCKS_PER_SEC;
    printf("result = %f; %f sec; thread = %d; n = 10^13\n", result, sec, threads);

    threads = 32;
    start = clock();
    result = euler(n, threads);
    end = clock();
    sec = (double)(end - start) / CLOCKS_PER_SEC;
    printf("result = %f; %f sec; thread = %d; n = 10^13\n", result, sec, threads);

    threads = 64;
    start = clock();
    result = euler(n, threads);
    end = clock();
    sec = (double)(end - start) / CLOCKS_PER_SEC;
    printf("result = %f; %f sec; thread = %d; n = 10^13\n", result, sec, threads);
#pragma endregion

#pragma region n = 10^14
    n = pow(10, 14);

    threads = 1;
    start = clock();
    result = euler(n);
    end = clock();
    sec = (double)(end - start) / CLOCKS_PER_SEC;
    printf("result = %f; %f sec; thread = %d; n = 10^14\n", result, sec, threads);

    threads = 4;
    start = clock();
    result = euler(n, threads);
    end = clock();
    sec = (double)(end - start) / CLOCKS_PER_SEC;
    printf("result = %f; %f sec; thread = %d; n = 10^14\n", result, sec, threads);

    threads = 8;
    start = clock();
    result = euler(n, threads);
    end = clock();
    sec = (double)(end - start) / CLOCKS_PER_SEC;
    printf("result = %f; %f sec; thread = %d; n = 10^14\n", result, sec, threads);

    threads = 16;
    start = clock();
    result = euler(n, threads);
    end = clock();
    sec = (double)(end - start) / CLOCKS_PER_SEC;
    printf("result = %f; %f sec; thread = %d; n = 10^14\n", result, sec, threads);

    threads = 32;
    start = clock();
    result = euler(n, threads);
    end = clock();
    sec = (double)(end - start) / CLOCKS_PER_SEC;
    printf("result = %f; %f sec; thread = %d; n = 10^14\n", result, sec, threads);

    threads = 64;
    start = clock();
    result = euler(n, threads);
    end = clock();
    sec = (double)(end - start) / CLOCKS_PER_SEC;
    printf("result = %f; %f sec; thread = %d; n = 10^14\n", result, sec, threads);
#pragma endregion

#pragma region n = 10^15
    n = pow(10, 15);

    threads = 1;
    start = clock();
    result = euler(n);
    end = clock();
    sec = (double)(end - start) / CLOCKS_PER_SEC;
    printf("result = %f; %f sec; thread = %d; n = 10^15\n", result, sec, threads);

    threads = 4;
    start = clock();
    result = euler(n, threads);
    end = clock();
    sec = (double)(end - start) / CLOCKS_PER_SEC;
    printf("result = %f; %f sec; thread = %d; n = 10^15\n", result, sec, threads);

    threads = 8;
    start = clock();
    result = euler(n, threads);
    end = clock();
    sec = (double)(end - start) / CLOCKS_PER_SEC;
    printf("result = %f; %f sec; thread = %d; n = 10^15\n", result, sec, threads);

    threads = 16;
    start = clock();
    result = euler(n, threads);
    end = clock();
    sec = (double)(end - start) / CLOCKS_PER_SEC;
    printf("result = %f; %f sec; thread = %d; n = 10^15\n", result, sec, threads);

    threads = 32;
    start = clock();
    result = euler(n, threads);
    end = clock();
    sec = (double)(end - start) / CLOCKS_PER_SEC;
    printf("result = %f; %f sec; thread = %d; n = 10^15\n", result, sec, threads);

    threads = 64;
    start = clock();
    result = euler(n, threads);
    end = clock();
    sec = (double)(end - start) / CLOCKS_PER_SEC;
    printf("result = %f; %f sec; thread = %d; n = 10^15\n", result, sec, threads);
#pragma endregion


    system("pause");
    return 0;
}