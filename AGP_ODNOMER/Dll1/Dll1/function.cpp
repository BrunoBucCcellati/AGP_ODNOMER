#include "pch.h"
#include "function.h"
#include <cmath>
#include <random>
#define M_PI 3.14159265358979323846
using namespace std;

double y(double x)
{
    double res = 0.0;
    for (int i = 1; i <= 5; i++)
    {
        res -= i * sin((i + 1) * x + i);
    }
    return res;
}

double HH(double x)
{
    const int HH_COUNT = 14;
    double a = 0.0;
    double b = 1.0;
    //
    default_random_engine generator;
    uniform_real_distribution<double> distribution(a, b);
    double A[20] = {};
    double B[20] = {};
    //
    for (int i = 0; i < 20; ++i)
    {
        A[i] = -1.1 + distribution(generator) * 2.0;
        B[i] = -1.1 + distribution(generator) * 2.0;
    }
    //
    double res = A[0];
    for (int i = 1; i < HH_COUNT; i++)
    {
        res += A[i] * sin(i * 2 * M_PI * x) + B[i] * cos(i * 2 * M_PI * x);
    }
    return res;
}

double SH(double x)
{
    const int SH_COUNT = 10;
    double a = 0.0;
    double b = 1.0;
    //
    default_random_engine generator;
    uniform_real_distribution<double> distribution(a, b);
    double A[20] = {};
    double B[20] = {};
    double K[20] = {};
    //
    for (int i = 0; i < 20; ++i)
    {
        A[i] = 10.0 * distribution(generator);
        B[i] = 1.0 + 0.2 * distribution(generator) * 2.0;
        K[i] = 5.0 + 20 * distribution(generator);
    }
    //
    double res = 0.0;
    for (int i = 1; i < SH_COUNT; i++)
    {
        res -= 1.0 / ((K[i] * (x - A[i]) * (x - A[i]) + B[i]));
    }
    return res;
}

double characteristic(double m, double x1, double x2, double y1, double y2)
{
    return (m * (x2 - x1) + pow((y2 - y1), 2) / (m * (x2 - x1)) - 2 * (y2 + y1));
}

double shag(double m, double x1, double x2, double y1, double y2)
{
    return ((x1 + x2) / 2) - ((y2 - y1) / (2 * m));
}