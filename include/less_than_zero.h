#pragma once

#include <stddef.h>
#include <stdio.h>

/**
 * @brief Подсчтет отрицательных чисел
 * 
 * @tparam T тип контейнера (int, float, double)
 * @param container контейнер с числами
 * @return количество отрицательных чисел в контейнере
 */
template <class T>
size_t less_than_zero(const T& container)
{
    size_t count = 0;
    for (const auto& i : container) {
        if (i < 0) {
            count++;
        }
    }
    return count;
}