#ifndef LAB11_ONE_OF_H
#define LAB11_ONE_OF_H

namespace algorithms {

template <typename InputIterator, typename Predicate>
bool one_of(InputIterator first, InputIterator last, Predicate predicate) {
    bool found = false;
    while (first != last) {
        if (predicate(*first)) {
            if (found) {
                return false;
            }
            found = true;
        }
        ++first;
    }
    return found;
}

} // namespace algorithms

#endif //LAB11_ONE_OF_H
