#ifndef UTILS_HPP
#define UTILS_HPP

template<typename T> T random(T min, T max) {
    return min + (rand() % static_cast<int>(max - min + 1));
}

#endif // UTILS_HPP
