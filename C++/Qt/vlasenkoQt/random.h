#pragma once
#include <random>
#include <cassert>


struct PRNG{
    std::mt19937 engine;
};
void initGenerator(PRNG& generator);
// Генерирует целое число в диапазоне [minValue, maxValue)
unsigned getRandomInt(PRNG& generator, unsigned minValue, unsigned maxValue);
// Генерирует число с плавающей точкой в диапазоне [minValue, maxValue)
double getRandomDouble(PRNG& generator, double minValue, double maxValue);
// Генерация массива нормированных на единицу чисел
double* getNormRandomDouble(PRNG& generator, int n);
