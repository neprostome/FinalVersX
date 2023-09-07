#ifndef LAB11_IS_PARTITIONED_H
#define LAB11_IS_PARTITIONED_H

namespace algorithms {

template<typename ForwardIterator, typename Predicate>
bool is_partitioned(ForwardIterator first, ForwardIterator last, Predicate predicate) {
    bool found_satisfying = false;
    bool found_not_satisfying = false;

    while (first != last) {
        if (predicate(*first)) {
            found_satisfying = true;
            if (found_not_satisfying) {
                return false;
            }
        } else {
            found_not_satisfying = true;
            if (found_satisfying) {
                return false;
            }
        }
        ++first;
    }
    return true;
}

} // namespace algorithms

#endif //LAB11_IS_PARTITIONED_H
