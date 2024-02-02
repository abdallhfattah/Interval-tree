#include <gtest/gtest.h>
#include "../src/IntervalTree.hpp"
#include "../src/IntervalTree.cpp"

TEST(IntervalTreeTest, NoOverlappingIntervals)
{
    // Test Case 1: No Overlapping intervals
    IntervalTree intervalTree;
    testing::internal::CaptureStdout();
    intervalTree.insertInterval(35, 40);
    intervalTree.insertInterval(45, 50);
    intervalTree.insertInterval(42, 48);
    intervalTree.searchInterval(80, 83);
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "No Overlapping interval found for [80, 83]\n");
}

TEST(IntervalTreeTest, OverlappingIntervalFound)
{
    // Test Case 2: Overlapping interval found
    IntervalTree intervalTree;
    testing::internal::CaptureStdout();
    intervalTree.insertInterval(35, 40);
    intervalTree.insertInterval(45, 50);
    intervalTree.searchInterval(42, 48);
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "Overlapping interval found: [45, 50]\n");
}

TEST(IntervalTreeTest, OverlappingIntervalFoundRightChild)
{
    // Test Case 3: Overlapping interval found (right child)
    IntervalTree intervalTree;
    testing::internal::CaptureStdout();
    intervalTree.insertInterval(55, 60);
    intervalTree.insertInterval(65, 70);
    intervalTree.searchInterval(68, 75);
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "Overlapping interval found: [65, 70]\n");
}

TEST(IntervalTreeTest, OverlappingIntervalFoundLeftChild)
{
    // Test Case 4: Overlapping interval found (left child)
    IntervalTree intervalTree;
    testing::internal::CaptureStdout();
    intervalTree.insertInterval(75, 80);
    intervalTree.insertInterval(85, 90);
    intervalTree.searchInterval(78, 82);
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "Overlapping interval found: [75, 80]\n");
}

TEST(IntervalTreeTest, QueryIntervalFullyContainedInOneInterval)
{
    // Test Case 6: Query interval is fully contained in one interval
    IntervalTree intervalTree;
    testing::internal::CaptureStdout();
    intervalTree.insertInterval(115, 120);
    intervalTree.insertInterval(125, 130);
    intervalTree.searchInterval(118, 122);
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "Overlapping interval found: [115, 120]\n");
}

TEST(IntervalTreeTest, QueryIntervalNotFound)
{
    // Test Case 11: Query interval is not found
    IntervalTree intervalTree;
    testing::internal::CaptureStdout();
    intervalTree.searchInterval(200, 210);
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "No Overlapping interval found for [200, 210]\n");
}

TEST(IntervalTreeTest, OverlappingIntervalsWithNegativeValues)
{
    // Test Case 12: Overlapping intervals with negative values
    IntervalTree intervalTree;
    testing::internal::CaptureStdout();
    intervalTree.insertInterval(-10, -5);
    intervalTree.insertInterval(-20, -15);
    intervalTree.insertInterval(-30, -25);
    intervalTree.searchInterval(-18, -12);
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "Overlapping interval found: [-20, -15]\n");
}

TEST(IntervalTreeTest, OverlappingIntervalsWithZero)
{
    // Test Case 13: Overlapping intervals with zero
    IntervalTree intervalTree;
    testing::internal::CaptureStdout();
    intervalTree.insertInterval(0, 5);
    intervalTree.insertInterval(10, 15);
    intervalTree.searchInterval(2, 8);
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "Overlapping interval found: [0, 5]\n");
}

TEST(IntervalTreeTest, LargeValues)
{
    // Test Case 14: Large values
    IntervalTree intervalTree;
    testing::internal::CaptureStdout();
    intervalTree.insertInterval(1000, 1010);
    intervalTree.insertInterval(1020, 1030);
    intervalTree.searchInterval(1005, 1025);
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "Overlapping interval found: [1000, 1010]\n");
}

TEST(IntervalTreeTest, LargeNumberOfIntervals)
{
    // Test Case 15: Large number of intervals
    IntervalTree intervalTree;
    for (int i = 2000; i <= 2050; i += 5)
    {
        intervalTree.insertInterval(i, i + 3);
    }
    testing::internal::CaptureStdout();
    intervalTree.searchInterval(2035, 2045);
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "Overlapping interval found: [2035, 2038]\n");
}

TEST(IntervalTreeTest, QueryIntervalWithNegativeValues)
{
    // Test Case 16: Query interval with negative values
    IntervalTree intervalTree;
    testing::internal::CaptureStdout();
    intervalTree.searchInterval(-15, -10);
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "No Overlapping interval found for [-15, -10]\n");
}

TEST(IntervalTreeTest, QueryIntervalWithLargeValues)
{
    // Test Case 17: Query interval with large values
    IntervalTree intervalTree;
    testing::internal::CaptureStdout();
    intervalTree.searchInterval(3000, 3010);
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "No Overlapping interval found for [3000, 3010]\n");
}

TEST(IntervalTreeTest, QueryIntervalWithZero)
{
    // Test Case 18: Query interval with zero
    IntervalTree intervalTree;
    testing::internal::CaptureStdout();
    intervalTree.searchInterval(0, 3);
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "No Overlapping interval found for [0, 3]\n");
}

TEST(IntervalTreeTest, SingleInterval)
{
    // Test Case 19: Single interval
    IntervalTree singleIntervalTree;
    singleIntervalTree.insertInterval(50, 60);
    testing::internal::CaptureStdout();
    singleIntervalTree.searchInterval(55, 57);
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "Overlapping interval found: [50, 60]\n");
}

TEST(IntervalTreeTest, SingleIntervalQueryOutsideInterval)
{
    // Test Case 20: Single interval, query outside the interval
    IntervalTree singleIntervalTree;
    testing::internal::CaptureStdout();
    singleIntervalTree.searchInterval(70, 80);
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "No Overlapping interval found for [70, 80]\n");
}

TEST(IntervalTreeTest, SingleIntervalQueryWithNegativeValues)
{
    // Test Case 21: Single interval, query with negative values
    IntervalTree singleIntervalTree;
    testing::internal::CaptureStdout();
    singleIntervalTree.searchInterval(45, 48);
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "No Overlapping interval found for [45, 48]\n");
}

TEST(IntervalTreeTest, SingleIntervalQueryWithLargeValues)
{
    // Test Case 22: Single interval, query with large values
    IntervalTree singleIntervalTree;
    testing::internal::CaptureStdout();
    singleIntervalTree.searchInterval(100, 110);
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "No Overlapping interval found for [100, 110]\n");
}

TEST(IntervalTreeTest, EmptyTree)
{
    // Test Case 23: Empty tree
    IntervalTree emptyTree;
    testing::internal::CaptureStdout();
    emptyTree.searchInterval(5, 10);
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "No Overlapping interval found for [5, 10]\n");
}

TEST(IntervalTreeTest, OverlappingIntervalsWithSameLowHighValues)
{
    // Test Case 24: Overlapping intervals with same low and high values
    IntervalTree sameLowHighTree;
    testing::internal::CaptureStdout();
    sameLowHighTree.insertInterval(10, 20);
    sameLowHighTree.insertInterval(20, 30);
    sameLowHighTree.insertInterval(30, 40);
    sameLowHighTree.searchInterval(18, 22);
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "Overlapping interval found: [10, 20]\n");
}

TEST(IntervalTreeTest, QueryIntervalWithSameLowHighValues)
{
    // Test Case 25: Query interval with same low and high values
    IntervalTree sameLowHighTree;
    testing::internal::CaptureStdout();
    sameLowHighTree.searchInterval(30, 30);
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "No Overlapping interval found for [30, 30]\n");
}

TEST(IntervalTreeTest, OverlappingIntervalsOneContainingAnother)
{
    // Test Case 26: Overlapping intervals with one containing another
    IntervalTree containingIntervalsTree;
    testing::internal::CaptureStdout();
    containingIntervalsTree.insertInterval(5, 15);
    containingIntervalsTree.insertInterval(10, 12);
    containingIntervalsTree.searchInterval(8, 14);
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "Overlapping interval found: [5, 15]\n");
}

TEST(IntervalTreeTest, OverlappingIntervalsOneContainedWithinAnother)
{
    // Test Case 27: Overlapping intervals with one contained within another
    IntervalTree containedIntervalsTree;
    testing::internal::CaptureStdout();
    containedIntervalsTree.insertInterval(30, 40);
    containedIntervalsTree.insertInterval(35, 37);
    containedIntervalsTree.searchInterval(32, 38);
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "Overlapping interval found: [30, 40]\n");
}

TEST(IntervalTreeTest, OverlappingIntervalsWithEqualIntervals)
{
    // Test Case 28: Overlapping intervals with equal intervals
    IntervalTree equalIntervalsTree;
    testing::internal::CaptureStdout();
    equalIntervalsTree.insertInterval(5, 10);
    equalIntervalsTree.insertInterval(5, 10);
    equalIntervalsTree.insertInterval(5, 10);
    equalIntervalsTree.searchInterval(6, 8);
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "Overlapping interval found: [5, 10]\n");
}

TEST(IntervalTreeTest, RandomIntervals1)
{
    // Test Case 29: Random intervals
    IntervalTree randomIntervalsTree;
    testing::internal::CaptureStdout();
    randomIntervalsTree.insertInterval(20, 30);
    randomIntervalsTree.insertInterval(5, 15);
    randomIntervalsTree.insertInterval(25, 35);
    randomIntervalsTree.insertInterval(10, 12);
    randomIntervalsTree.searchInterval(8, 14);
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "Overlapping interval found: [5, 15]\n");
}

TEST(IntervalTreeTest, RandomIntervals2)
{
    // Test Case 30: Random intervals
    IntervalTree randomIntervalsTree;
    randomIntervalsTree.insertInterval(50, 60);
    randomIntervalsTree.insertInterval(70, 80);
    randomIntervalsTree.insertInterval(55, 65);
    randomIntervalsTree.insertInterval(75, 85);

    testing::internal::CaptureStdout();
    randomIntervalsTree.searchInterval(62, 78);
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "Overlapping interval found: [55, 65]\n");
}
