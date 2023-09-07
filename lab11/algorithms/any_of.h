#ifndef LAB11_ANY_OF_H
#define LAB11_ANY_OF_H

namespace algorithms {

template <typename InputIterator, typename Predicate>
bool any_of(InputIterator first, InputIterator last, Predicate predicate) {
    while (first != last) {
        if (predicate(*first)) {
            return true;
        }
        ++first;
    }
    return false;
}

} // namespace algorithms

#endif //LAB11_ANY_OF_H
