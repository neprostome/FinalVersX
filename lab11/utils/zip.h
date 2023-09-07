#ifndef LAB11_ZIP_H
#define LAB11_ZIP_H

#include <iterator>

template<typename Container1, typename Container2>
class ZipIterator {
public:
    using value_type1 = typename Container1::value_type;
    using value_type2 = typename Container2::value_type;
    using iterator1 = typename Container1::const_iterator;
    using iterator2 = typename Container2::const_iterator;

    ZipIterator(iterator1 it1, iterator1 end1, iterator2 it2, iterator2 end2) :
    it1_(it1), end1_(end1), it2_(it2), end2_(end2) {}

    std::pair<value_type1, value_type2> operator*() const {
        return std::make_pair(*it1_, *it2_);
    }

    bool operator!=(const ZipIterator& other) const {
        return (it1_ != other.it1_ && it1_ != end1_) && (it2_ != other.it2_ && it2_ != end2_);
    }

    bool operator==(const ZipIterator& other) const {
        return !(*this != other);
    }

    ZipIterator& operator=(const ZipIterator& other) {
        if (this != &other) {
            it1_ = other.it1_;
            end1_ = other.end1_;
            it2_ = other.it2_;
            end2_ = other.end2_;
        }
        return *this;
    }

    ZipIterator& operator++() {
        ++it1_;
        ++it2_;
        return *this;
    }

    ZipIterator operator++(int) {
        ZipIterator copy(*this);
        ++(*this);
        return copy;
    }

    ZipIterator& operator--() {
        --it1_;
        --it2_;
        return *this;
    }

    ZipIterator operator--(int) {
        ZipIterator copy(*this);
        --(*this);
        return copy;
    }

private:
    iterator1 it1_;
    iterator1 end1_;
    iterator2 it2_;
    iterator2 end2_;
};

template<typename Container1, typename Container2>
class zip {
public:
    zip(const Container1& container1, const Container2& container2)
    : container1_(container1), container2_(container2) {}

    ZipIterator<Container1, Container2> begin() const {
        return ZipIterator<Container1, Container2>(container1_.begin(), container1_.end(),
                                                   container2_.begin(), container2_.end());
    }

    ZipIterator<Container1, Container2> end() const {
        return ZipIterator<Container1, Container2>(container1_.end(), container1_.end(),
                                                   container2_.end(), container2_.end());
    }

private:
    const Container1& container1_;
    const Container2& container2_;
};

#endif //LAB11_ZIP_H
