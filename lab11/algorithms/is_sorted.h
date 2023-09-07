#ifndef LAB11_IS_SORTED_H
#define LAB11_IS_SORTED_H

namespace algorithms {

template <typename ForwardIterator, typename Compare>
bool is_sorted(ForwardIterator first, ForwardIterator last, Compare comp) {
    if (first == last) {
        return true;
    }
    ForwardIterator next = first;
    while (++next != last) {
        if (comp(*next, *first)) {
            return false;
        }
        ++first;
    }
    return true;
}

} // namespace algorithms

#endif //LAB11_IS_SORTED_H
