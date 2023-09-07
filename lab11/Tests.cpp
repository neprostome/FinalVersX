#include "algorithms/all_of.h"
#include "algorithms/any_of.h"
#include "algorithms/find_backward.h"
#include "algorithms/find_not.h"
#include "algorithms/is_palindrome.h"
#include "algorithms/is_partitioned.h"
#include "algorithms/is_sorted.h"
#include "algorithms/none_of.h"
#include "algorithms/one_of.h"
#include "utils/xrange.h"
#include "utils/zip.h"

#include <gtest/gtest.h>

#include <list>
#include <vector>

TEST(XRangeTest, RangeWithFloatStep) {
    auto x = xrange(1.5, 5.5);
    std::vector<int> v{x.begin(), x.end()};
    std::vector<int> expected{1, 2, 3, 4};
    EXPECT_EQ(v, expected);
}

TEST(XRangeTest, RangeWithIntStep) {
    auto x = xrange(4);
    std::vector<int> v{x.begin(), x.end()};
    std::vector<int> expected{0, 1, 2, 3};
    EXPECT_EQ(v, expected);
}

TEST(XRangeTest, RangeWithNegativeStep) {
    auto x = xrange(4, -1, -1);
    std::vector<int> v{x.begin(), x.end()};
    std::vector<int> expected{4, 3, 2, 1, 0};
    EXPECT_EQ(v, expected);
}

TEST(ZipTest, ZipTwoContainers) {
    std::list<int> l = {1, 2, 3, 4, 5};
    std::vector<char> v = {'a', 'b', 'c', 'd'};
    std::vector<std::pair<int, char>> expected = {{1, 'a'},
                                                  {2, 'b'},
                                                  {3, 'c'},
                                                  {4, 'd'}};
    std::vector<std::pair<int, char>> result;

    for (auto p: zip(l, v)) {
        result.push_back(p);
    }

    EXPECT_EQ(result, expected);
}

//all_of
TEST(AllOfTest, AllTrue) {
    std::vector<int> v = {1, 2, 3, 4, 5};
    bool result = algorithms::all_of(v.begin(), v.end(), [](int i){ return i > 0; });
    EXPECT_TRUE(result);
}

TEST(AllOfTest, NotAllTrue) {
    std::vector<int> v = {1, 2, -3, 4, 5};
    bool result = algorithms::all_of(v.begin(), v.end(), [](int i){ return i > 0; });
    EXPECT_FALSE(result);
}

TEST(AllOfTest, EmptyRange) {
    std::vector<int> v = {};
    bool result = algorithms::all_of(v.begin(), v.end(), [](int i){ return i > 0; });
    EXPECT_TRUE(result);
}

//any_of
TEST(AnyOfTest, AllFalse) {
    std::vector<int> v = {-1, -2, -3, -4, -5};
    bool result = algorithms::any_of(v.begin(), v.end(), [](int i){ return i > 0; });
    EXPECT_FALSE(result);
}

TEST(AnyOfTest, NotAllFalse) {
    std::vector<int> v = {-1, 2, -3, 4, -5};
    bool result = algorithms::any_of(v.begin(), v.end(), [](int i){ return i > 0; });
    EXPECT_TRUE(result);
}

TEST(AnyOfTest, EmptyRange) {
    std::vector<int> v = {};
    bool result = algorithms::any_of(v.begin(), v.end(), [](int i){ return i > 0; });
    EXPECT_FALSE(result);
}

//find_backward
TEST(FindBackwardTest, Found) {
    std::vector<int> v = {1, 2, 3, 4, 5};
    auto result = algorithms::find_backward(v.begin(), v.end(), 3);
    EXPECT_EQ(result, v.begin() + 2);
}

TEST(FindBackwardTest, EmptyRange) {
    std::vector<int> v = {};
    auto result = algorithms::find_backward(v.begin(), v.end(), 1);
    EXPECT_EQ(result, v.end());
}

//find_not
TEST(FindNotTest, FoundElement) {
    std::vector<int> v = {2, 2, 3, 2, 1};
    auto it = algorithms::find_not(v.begin(), v.end(), 2);
    EXPECT_EQ(*it, 3);
}

TEST(FindNotTest, NotFoundElement) {
    std::vector<int> v = {5, 5, 5, 5, 5};
    auto it = algorithms::find_not(v.begin(), v.end(), 5);
    EXPECT_EQ(it, v.end());
}

TEST(FindNotTest, EmptyRange) {
    std::vector<int> v = {};
    auto it = algorithms::find_not(v.begin(), v.end(), 0);
    EXPECT_EQ(it, v.end());
}

//is_palindrome
TEST(IsPalindromeTest, IntegerPalindrome) {
    std::vector<int> v = {1, 2, 3, 2, 1};
    bool result = algorithms::is_palindrome(v.begin(), v.end(), [](int a, int b){ return a == b; });
    EXPECT_TRUE(result);
}

TEST(IsPalindromeTest, IntegerNonPalindrome) {
    std::vector<int> v = {1, 2, 3, 4, 5};
    bool result = algorithms::is_palindrome(v.begin(), v.end(), [](int a, int b){ return a == b; });
    EXPECT_FALSE(result);
}

TEST(IsPalindromeTest, StringPalindrome) {
    std::string s = "racecar";
    bool result = algorithms::is_palindrome(s.begin(), s.end(), [](char a, char b){ return a == b; });
    EXPECT_TRUE(result);
}

TEST(IsPalindromeTest, StringNonPalindrome) {
    std::string s = "hello";
    bool result = algorithms::is_palindrome(s.begin(), s.end(), [](char a, char b){ return a == b; });
    EXPECT_FALSE(result);
}

TEST(IsPalindromeTest, AbsoluteValuePalindrome) {
    std::vector<int> v = {-1, 2, -3, 2, -1};
    bool result = algorithms::is_palindrome(v.begin(), v.end(), [](int a, int b){ return std::abs(a) == std::abs(b); });
    EXPECT_TRUE(result);
}

//is_partitioned
TEST(IsPartitionedTest, NotPartitioned) {
    std::vector<int> v = {1, 3, 2, 4, 5};
    auto result = algorithms::is_partitioned(v.begin(), v.end(), [](int i){ return i % 2 == 1; });
    EXPECT_FALSE(result);
}

TEST(IsPartitionedTest, EmptyRange) {
    std::vector<int> v = {};
    auto result = algorithms::is_partitioned(v.begin(), v.end(), [](int i){ return i % 2 == 1; });
    EXPECT_TRUE(result);
}

//is_sorted
TEST(IsSortedTest, Sorted) {
    std::vector<int> v = {1, 2, 3, 4, 5};
    auto result = algorithms::is_sorted(v.begin(), v.end(), [](int a, int b){ return a < b; });
    EXPECT_TRUE(result);
}

TEST(IsSortedTest, NotSorted) {
    std::vector<int> v = {1, 3, 2, 4, 5};
    auto result = algorithms::is_sorted(v.begin(), v.end(), [](int a, int b){ return a < b; });
    EXPECT_FALSE(result);
}

TEST(IsSortedTest, EmptyRange) {
    std::vector<int> v = {};
    auto result = algorithms::is_sorted(v.begin(), v.end(), [](int a, int b){ return a < b; });
    EXPECT_TRUE(result);
}

//none_of
TEST(NoneOfTest, AllFalse) {
    std::vector<int> v = {-1, -2, -3, -4, -5};
    bool result = algorithms::none_of(v.begin(), v.end(), [](int i){ return i > 0; });
    EXPECT_TRUE(result);
}

TEST(NoneOfTest, NotAllFalse) {
    std::vector<int> v = {-1, 2, -3, 4, -5};
    bool result = algorithms::none_of(v.begin(), v.end(), [](int i){ return i > 0; });
    EXPECT_FALSE(result);
}

TEST(NoneOfTest, EmptyRange) {
    std::vector<int> v = {};
    bool result = algorithms::none_of(v.begin(), v.end(), [](int i){ return i > 0; });
    EXPECT_TRUE(result);
}

//one_of
TEST(OneOfTest, MultipleMatches) {
    std::vector<int> v = {1, 2, 3, 4, 6};
    bool result = algorithms::one_of(v.begin(), v.end(), [](int i){ return i % 2 == 0; });
    EXPECT_FALSE(result);
}

TEST(OneOfTest, NoMatches) {
    std::vector<int> v = {1, 3, 5, 7, 9};
    bool result = algorithms::one_of(v.begin(), v.end(), [](int i){ return i % 2 == 0; });
    EXPECT_FALSE(result);
}

TEST(OneOfTest, EmptyRange) {
    std::vector<int> v = {};
    bool result = algorithms::one_of(v.begin(), v.end(), [](int i){ return i % 2 == 0; });
    EXPECT_FALSE(result);
}