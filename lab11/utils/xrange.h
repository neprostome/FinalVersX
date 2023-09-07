#ifndef LAB11_XRANGE_H
#define LAB11_XRANGE_H

#include <iterator>

template <typename T>
class XRangeIterator {
public:
    using iterator_category = std::input_iterator_tag;
    using value_type = T;
    using difference_type = T;
    using pointer = T*;
    using reference = T&;

    XRangeIterator(T current, T step) : current_(current), step_(step) {}

    bool operator!=(const XRangeIterator& other) const {
        if (step_ > 0) {
            return current_ < other.current_;
        } else {
            return current_ > other.current_;
        }
    }

    bool operator==(const XRangeIterator& other) const {
        return !(*this != other);
    }

    value_type operator*() const {
        return current_;
    }

    XRangeIterator& operator=(const XRangeIterator& other) {
        if (this != &other) {
            current_ = other.current_;
            step_ = other.step_;
        }
        return *this;
    }

    XRangeIterator& operator++() {
        current_ += step_;
        return *this;
    }

    XRangeIterator operator++(int) {
        XRangeIterator copy(*this);
        ++(*this);
        return copy;
    }

    XRangeIterator& operator--() {
        current_ -= step_;
        return *this;
    }

    XRangeIterator operator--(int) {
        XRangeIterator copy(*this);
        --(*this);
        return copy;
    }

private:
    T current_;
    T step_;
};

template <typename T>
class xrange {
public:
    explicit xrange(T first, T end) : first_(first), last_(end), step_(1) {}
    explicit xrange(T last) : first_(0), last_(last), step_(1) {}
    explicit xrange(T first, T end, T step) : first_(first), last_(end), step_(step) {}

    XRangeIterator<T> begin() const {
        return XRangeIterator<T>(first_, step_);
    }

    XRangeIterator<T> end() const {
        return XRangeIterator<T>(last_, step_);
    }

private:
    T first_;
    T last_;
    T step_;
};

#endif //LAB11_XRANGE_H
