#pragma once

#include <stddef.h>
#include <stdio.h>

/**
 * @brief Подсчтет 
 * 
 * @tparam T 
 * @param container 
 * @return T 
 */
template <class T>
size_t counting_zeros(const T& container)
{
    size_t count = 0;
    for (const auto& i : container) {
        if (i == 0) {
            count++;
        }
    }
    return count;
}