#include <gtest/gtest.h>
#include "Loan.h"

TEST(LoanTest, NormalEmiCalculation) {
    Loan loan(100000.0L, 10.0L, 5.0L);
    ASSERT_TRUE(loan.isValid());

    long double emi = loan.calculateMonthlyAmount();
    double expected = 2124.704471126833;
    EXPECT_NEAR((double)emi, expected, 1e-2);
}

TEST(LoanTest, InvalidInputHandling) {
    Loan l1(-1, 2, 3);
    EXPECT_FALSE(l1.isValid());

    Loan l2(5000, -5, 3);
    EXPECT_FALSE(l2.isValid());

    Loan l3(5000, 7, 0);
    EXPECT_FALSE(l3.isValid());
}

TEST(LoanTest, LargeTenureNoOverflow) {
    Loan loan(200000, 7.5, 50);
    ASSERT_TRUE(loan.isValid());
    EXPECT_GT((double)loan.calculateMonthlyAmount(), 0);
    EXPECT_GT((double)loan.calculateTotalAmount(), 0);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

