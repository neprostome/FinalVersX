#ifndef LAB11_FIND_NOT_H
#define LAB11_FIND_NOT_H

namespace algorithms {

template <typename InputIterator, typename T>
InputIterator find_not(InputIterator first, InputIterator last, const T& value) {
    while (first != last && *first == value) {
        ++first;
    }
    if (first == last) {
        return last;
    }
    return first;
}

} // namespace algorithms

#endif //LAB11_FIND_NOT_H
