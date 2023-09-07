#ifndef LAB11_ALL_OF_H
#define LAB11_ALL_OF_H

namespace algorithms {

template <typename InputIterator, typename Predicate>
bool all_of(InputIterator first, InputIterator last, Predicate predicate) {
    while (first != last) {
        if (!predicate(*first)) {
            return false;
        }
        ++first;
    }
    return true;
}

} // namespace algorithms

#endif //LAB11_ALL_OF_H
