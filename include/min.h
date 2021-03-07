#pragma once

/**
 * @brief Возвращает наименьшее число из двух чисел
 * 
 * @tparam T числовой шаблоный параметр
 * @param a первое число
 * @param b второе число
 * @return T минимальное число
 */
template <typename T>
inline T min(T a, T b)
{
    if (a < b) {
        return a;
    }
    return b;
}