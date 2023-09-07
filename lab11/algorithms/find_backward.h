#ifndef LAB11_FIND_BACKWARD_H
#define LAB11_FIND_BACKWARD_H

namespace algorithms {

template <typename BidirectionalIterator, typename T>
BidirectionalIterator find_backward(BidirectionalIterator first,
                                    BidirectionalIterator last, const T& value) {
    while (last != first) {
        --last;
        if (*last == value) {
            return last;
        }
    }
    return last;
}

} // namespace algorithms

#endif //LAB11_FIND_BACKWARD_H
