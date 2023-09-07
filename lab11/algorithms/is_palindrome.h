#ifndef LAB11_IS_PALINDROME_H
#define LAB11_IS_PALINDROME_H

namespace algorithms {

template <typename BidirectionalIterator, typename Predicate>
bool is_palindrome(BidirectionalIterator first,
                   BidirectionalIterator last, Predicate predicate) {
    while (first != last && first != --last) {
        if (!predicate(*first, *last)) {
            return false;
        }
        ++first;
    }
    return true;
}

} // namespace algorithms

#endif //LAB11_IS_PALINDROME_H
