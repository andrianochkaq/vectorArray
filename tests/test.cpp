#include <gtest/gtest.h>

TEST(TestCaseName, TestName) {
    EXPECT_EQ(1, 1);
    EXPECT_TRUE(true);
}

#include "Header.h"

// Тест для перевірки суми масиву
TEST(VectorOperationsTest, SumArrayCorrectness) {
    std::vector<double> testArr = { 1.0, 2.5, 3.5 };
    double expectedSum = 7.0;
    EXPECT_NEAR(sumArray(testArr), expectedSum, 1e-6);
}

// Тест для групування елементів (сумування по парах/трійках)
TEST(VectorOperationsTest, GroupArrayCorrectness) {
    std::vector<double> testArr = { 1.0, 2.0, 3.0, 4.0, 5.0 };
    int unite = 2;
    // Очікуємо: {1+2, 3+4} = {3.0, 7.0}. 5.0 ігнорується, бо не вистачає для повної групи.
    std::vector<double> result = groupArray(testArr, unite);

    ASSERT_EQ(result.size(), 2);
    EXPECT_DOUBLE_EQ(result[0], 3.0);
    EXPECT_DOUBLE_EQ(result[1], 7.0);
}

// Тест на пошук максимального елемента
TEST(VectorOperationsTest, MaxElementCorrectness) {
    std::vector<double> testArr = { -10.5, 45.0, 12.3, 0.0 };
    EXPECT_DOUBLE_EQ(maxElement(testArr), 45.0);
}

// Тест на видалення дублікатів
TEST(VectorOperationsTest, UniqueArrayCorrectness) {
    std::vector<double> testArr = { 1.0, 2.0, 1.0, 3.0, 2.0 };
    int duplicates = 0;
    std::vector<double> unique = uniqueArray(testArr, duplicates);

    EXPECT_EQ(unique.size(), 3);
    EXPECT_EQ(duplicates, 2);
}

// Тест сортування за зростанням
TEST(VectorOperationsTest, SortAscendingCorrectness) {
    std::vector<double> testArr = { 5.0, 1.0, 4.0 };
    std::vector<double> sorted = sortAscending(testArr);

    EXPECT_EQ(sorted[0], 1.0);
    EXPECT_EQ(sorted[2], 5.0);
}

