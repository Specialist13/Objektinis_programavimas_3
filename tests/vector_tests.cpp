#include <gtest/gtest.h>
#include <vector>
#include "../include/vector.h"

TEST(VectorTest, BaseConstructorInitializesCorrectly) {
    Vector<int> vec;
    EXPECT_EQ(vec.getSize(), 0);
    EXPECT_EQ(vec.getCapacity(), 10);
}

TEST(VectorTest, DestructorWorks) {
    std::weak_ptr<Vector<int>> weakRef;
    {
        auto ptr = std::make_shared<Vector<int>>();
        weakRef = ptr;

        EXPECT_FALSE(weakRef.expired());
    }

    EXPECT_TRUE(weakRef.expired());
}

TEST(VectorTest, PushBackAndAt) {
    Vector<int> vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);

    EXPECT_EQ(vec.getSize(), 3);
    EXPECT_EQ(vec.at(0), 1);
    EXPECT_EQ(vec.at(1), 2);
    EXPECT_EQ(vec.at(2), 3);
}

TEST(VectorTest, AtThrowsOnOutOfBounds) {
    Vector<int> vec;
    vec.push_back(42);
    EXPECT_THROW(vec.at(1), std::out_of_range);
}

TEST(VectorTest, CopyConstructorWorks) {
    Vector<std::string> vec;
    vec.push_back("a");
    vec.push_back("b");

    Vector<std::string> copy(vec);
    EXPECT_EQ(copy.getSize(), 2);
    EXPECT_EQ(copy.at(0), "a");
    EXPECT_EQ(copy.at(1), "b");
}

TEST(VectorTest, CopyAssignmentWorks) {
    Vector<int> vec;
    vec.push_back(5);
    vec.push_back(10);

    Vector<int> copy;
    copy = vec;

    EXPECT_EQ(copy.getSize(), 2);
    EXPECT_EQ(copy.at(0), 5);
    EXPECT_EQ(copy.at(1), 10);
}

TEST(VectorTest, MoveConstructorWorks) {
    Vector<int> vec;
    vec.push_back(42);
    Vector<int> moved(std::move(vec));

    EXPECT_EQ(moved.getSize(), 1);
    EXPECT_EQ(moved.at(0), 42);
    EXPECT_EQ(vec.getSize(), 0);
}

TEST(VectorTest, MoveAssignmentWorks) {
    Vector<int> vec;
    vec.push_back(7);
    Vector<int> moved;
    moved = std::move(vec);

    EXPECT_EQ(moved.getSize(), 1);
    EXPECT_EQ(moved.at(0), 7);
    EXPECT_EQ(vec.getSize(), 0);
}

TEST(VectorTest, ResizeIncreasesAndInitializes) {
    Vector<int> vec;
    vec.resize(3);
    EXPECT_EQ(vec.getSize(), 3);
    EXPECT_EQ(vec.at(0), 0);
    EXPECT_EQ(vec.at(1), 0);
    EXPECT_EQ(vec.at(2), 0);
}

TEST(VectorTest, ResizeShrinksCorrectly) {
    Vector<int> vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    vec.resize(1);
    EXPECT_EQ(vec.getSize(), 1);
    EXPECT_EQ(vec.at(0), 1);
}

TEST(VectorTest, ReserveIncreasesCapacity) {
    Vector<int> vec;
    vec.reserve(100);
    EXPECT_GE(vec.getCapacity(), 100);
}

TEST(VectorTest, ShrinkToFitReducesCapacity) {
    Vector<int> vec;
    for (int i = 0; i < 10; i++) vec.push_back(i);
    vec.reserve(50);
    vec.shrink_to_fit();
    EXPECT_EQ(vec.getCapacity(), vec.getSize());
}

TEST(VectorTest, ClearEmptiesVector) {
    Vector<int> vec;
    vec.push_back(10);
    vec.push_back(20);
    vec.clear();
    EXPECT_EQ(vec.getSize(), 0);
}

TEST(VectorTest, InsertAtIndex) {
    Vector<int> vec;
    vec.push_back(1);
    vec.push_back(3);
    vec.insert(1, 2);
    EXPECT_EQ(vec.getSize(), 3);
    EXPECT_EQ(vec.at(0), 1);
    EXPECT_EQ(vec.at(1), 2);
    EXPECT_EQ(vec.at(2), 3);
}

TEST(VectorTest, EraseAtIndex) {
    Vector<int> vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    vec.erase(1);
    EXPECT_EQ(vec.getSize(), 2);
    EXPECT_EQ(vec.at(0), 1);
    EXPECT_EQ(vec.at(1), 3);
}

TEST(VectorTest, PopBackRemovesLast) {
    Vector<int> vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.pop_back();
    EXPECT_EQ(vec.getSize(), 1);
    EXPECT_EQ(vec.at(0), 1);
}

TEST(VectorTest, FrontAndBackAccess) {
    Vector<int> vec;
    vec.push_back(5);
    vec.push_back(10);
    EXPECT_EQ(vec.front(), 5);
    EXPECT_EQ(vec.back(), 10);
}

TEST(VectorTest, EqualityOperatorWorks) {
    Vector<int> a, b;
    a.push_back(1);
    a.push_back(2);
    b.push_back(1);
    b.push_back(2);
    EXPECT_TRUE(a == b);
}

TEST(VectorTest, InequalityOperatorWorks) {
    Vector<int> a, b;
    a.push_back(1);
    b.push_back(2);
    EXPECT_TRUE(a != b);
}

TEST(VectorTest, RelationalOperators) {
    Vector<int> a, b;
    a.push_back(1);
    b.push_back(2);
    EXPECT_TRUE(a < b);
    EXPECT_TRUE(a <= b);
    EXPECT_TRUE(b > a);
    EXPECT_TRUE(b >= a);
}

TEST(VectorTest, AssignFillWorks) {
    Vector<int> vec;
    vec.assign(3, 99);
    EXPECT_EQ(vec.getSize(), 3);
    EXPECT_EQ(vec.at(0), 99);
    EXPECT_EQ(vec.at(1), 99);
    EXPECT_EQ(vec.at(2), 99);
}

TEST(VectorTest, AssignRangeWorks) {
    int arr[] = {10, 20, 30};
    Vector<int> vec;
    vec.assign(arr, arr + 3);
    EXPECT_EQ(vec.getSize(), 3);
    EXPECT_EQ(vec.at(1), 20);
}

TEST(VectorTest, AssignFromOtherVectorWorks) {
    Vector<int> vec1;
    vec1.push_back(100);
    vec1.push_back(200);

    Vector<int> vec2;
    vec2.assign(vec1);

    EXPECT_EQ(vec2.getSize(), 2);
    EXPECT_EQ(vec2.at(0), 100);
    EXPECT_EQ(vec2.at(1), 200);
}

TEST(VectorTest, BracketOperatorWorks) {
    Vector<int> vec;
    vec.push_back(10);
    vec[0] = 99;
    EXPECT_EQ(vec[0], 99);
}

TEST(VectorTest, GetDataReturnsPointer) {
    Vector<int> vec;
    vec.push_back(42);
    int* data = vec.getData();
    ASSERT_NE(data, nullptr);
    EXPECT_EQ(data[0], 42);
}

TEST(VectorTest, BeginAndEndIteratorsWork) {
    Vector<int> vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);

    int sum = 0;
    for (auto it = vec.begin(); it != vec.end(); ++it) {
        sum += *it;
    }
    EXPECT_EQ(sum, 6);
}

TEST(VectorTest, ReverseIteratorsWork) {
    Vector<int> vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);

    int product = 1;
    for (auto it = vec.rbegin(); it != vec.rend(); --it) {
        product *= *it;
    }
    EXPECT_EQ(product, 6); // 3 * 2 * 1
}

TEST(VectorTest, EmptyReturnsTrueForEmptyVector) {
    Vector<int> vec;
    EXPECT_TRUE(vec.empty());
    vec.push_back(1);
    EXPECT_FALSE(vec.empty());
}

TEST(VectorTest, MaxSizeIsCorrect) {
    Vector<int> vec;

    size_t expected_max = std::numeric_limits<size_t>::max() / sizeof(int);
    size_t actual_max = vec.max_size();

    EXPECT_EQ(actual_max, expected_max);
}

TEST(VectorTest, AppendRangeWorks) {
    Vector<int> vec;
    vec.assign(3, 4);
    std::vector<int> to_append = {10, 20, 30};
    vec.append_range(to_append);

    EXPECT_EQ(vec.getSize(), 6);
    EXPECT_EQ(vec.at(3), 10);
    EXPECT_EQ(vec.at(4), 20);
    EXPECT_EQ(vec.at(5), 30);
}

TEST(VectorTest, SwapWorks) {
    Vector<int> a, b;
    a.push_back(1);
    b.push_back(2);
    a.swap(b);
    EXPECT_EQ(a.at(0), 2);
    EXPECT_EQ(b.at(0), 1);
}
