//
// Created by florentina on 06.03.2023.
//

#include <cstdarg>
#include "Math.h"
#include <cstring>
#include <cstdlib>
#include <string>

using namespace std;

int Math::Add(int x, int y) {
    return x+y;
}

int Math::Add(int x, int y, int z) {
    return x+y+z;
}

int Math::Add(double x, double y) {
    return x+y;
}

int Math::Add(double x, double y, double z) {
    return 0;
}

int Math::Mul(int x, int y) {
    return x*y;
}

int Math::Mul(int x, int y, int z) {
    return x*y*z;
}

int Math::Mul(double x, double y) {
    return x*y;
}

int Math::Mul(double x, double y, double z) {
    return x*y*z;
}

int Math::Add(int count, ...)
{
    int val;
    int sum = 0;
    va_list v1;
    va_start(v1, count);
    for (int i = 0; i < count; i++)
    {
        val = va_arg(v1, int);
        sum += val;
    }
    va_end(v1);
    return sum;
}


char* Math::Add(const char* name1, const char* name2)
{
    int x = atoi(name1);
    int y = atoi(name2);
    int z = x + y;
    int length = snprintf(nullptr, 0, "%d", z);
    char* result = new char[length + 1];
    snprintf(result, length + 1, "%d", z);
    return result;

}
