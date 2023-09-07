#ifndef LAB11_NONE_OF_H
#define LAB11_NONE_OF_H

namespace algorithms {

template <typename InputIterator, typename Predicate>
bool none_of(InputIterator first, InputIterator last, Predicate predicate) {
    while (first != last) {
        if (predicate(*first)) {
            return false;
        }
        ++first;
    }
    return true;
}

} // namespace algorithms

#endif //LAB11_NONE_OF_H
