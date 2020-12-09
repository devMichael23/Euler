#include <iostream>
#include "mpi.h"
#include <chrono>

using namespace std;

// Параллельное вычисление числа π, используя ряд Эйлера
double euler(int n)
{
    double result = 0;

    for (int i = 0; i < n; i++)
    {
        result += 1 / (pow(i + 1, 2));
    }

    result = sqrt(result * 6);

    return result;
}

void mpi_euler(int n, int size, int rank)
{
    int recieve[] = { 0 };
    int arr[] = { 0 };
    int count = n / size;
    int start, stop;
    double begin = MPI_Wtime();
    double local_sum = 0.0;
    double global_sum = 0.0;

    if (rank == 0)
    {
        for (int i = 1; i < size; i++)
        {
            arr[0] = i * count;
            MPI_Send(arr, 1, MPI_INT, i, 1, MPI_COMM_WORLD);
        }
        for (int i = 0; i < count; i++)
        {
            local_sum += 1 / (pow(i + 1, 2));
        }
        //cout << "Главный процесс вывел сумму = " << local_sum << endl;
    }
    if (rank > 0 && rank != size - 1)
    {
        MPI_Recv(recieve, 1, MPI_INT, 0, 1, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        start = recieve[0];
        stop = start + count;
        // Включая start, не включая stop
        //cout << "Процесс " << rank << " получил start = " << start << " и stop = " << stop << endl;
        for (int i = start; i < stop; i++)
        {
            local_sum += 1 / (pow(i + 1, 2));
        }
        //cout << "Процесс " << rank << " вывел сумму = " << local_sum << endl;
    }
    if (rank == size - 1)
    {
        MPI_Recv(recieve, 1, MPI_INT, 0, 1, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        start = recieve[0];
        stop = n;
        // Включая start, не включая stop
        //cout << "Последний процесс " << rank << " получил start = " << start << " и stop = " << stop << endl;
        for (int i = start; i < stop; i++)
        {
            local_sum += 1 / (pow(i + 1, 2));
        }
        //cout << "Последний процесс " << rank << " вывел сумму = " << local_sum << endl;
    }
    MPI_Reduce(&local_sum, &global_sum, 1, MPI_DOUBLE, MPI_SUM, 0, MPI_COMM_WORLD);
    if (rank == 0)
    {
        double result = sqrt(global_sum * 6);
        double end = MPI_Wtime();
        double time = end - begin;
        cout << endl;
        cout << "Программа посчитала число p = " << result << "; time = " << time << endl;
    }
}

int main(int* argc, char** argv)
{
    setlocale(LC_CTYPE, "rus");

    int size, rank;
    int n = 100000000;

    MPI_Init(argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);


    if (rank == 0)
    {
        cout << "Практическая работа №4" << endl;
        cout << "Распределенное программирование для систем с общей памятью с использованием основ технологии MPI" << endl;
        cout << "Бузыкин Игорь" << endl;
        
    }
    if (size == 1)
    {
        cout << endl;
        cout << "Последовательный метод вычисления:" << endl;
        cout << "n = " << n << endl;
        clock_t start = clock();

        double result = euler(n);

        clock_t end = clock();
        double sec = (double)(end - start) / CLOCKS_PER_SEC;
        cout << "Последовательное вычисление дало результат p = " << result << "; time = " << sec << endl;
        cout << endl;
    }

    if (size > 1)
    {
        mpi_euler(n, size, rank);
    }

    MPI_Finalize();

    return 0;
}