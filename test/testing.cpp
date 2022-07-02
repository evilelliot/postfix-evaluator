/*
* File: testing.cpp
* Author: Alberto Ocaranza
* Project: postfix evaluator.
* Function: testing file.
*/
#include "../src/Evaluator.hpp"
#include <gtest/gtest.h>
#include <string>
#include <math.h>

TEST(EvalSum, FloatTesting){
    float expected = 25.02 + 234;
    std::string exp = "25.02 234 +";
    float result = Eval::Evaluator::eval(exp);

    ASSERT_FLOAT_EQ(expected, result); 
}
TEST(EvalRest, FloatTesting){
    float expected = 25.02 - 234;
    std::string exp = "25.02 234 -";
    float result = Eval::Evaluator::eval(exp);

    ASSERT_FLOAT_EQ(expected, result);
}
TEST(EvalMultiplication, FloatTesting){
    float expected = 25.02 * 234;
    std::string exp = "25.02 234 *";
    float result = Eval::Evaluator::eval(exp);

    ASSERT_FLOAT_EQ(expected, result);
}
TEST(EvalDivision, FloatTesting){
    float expected = 25.02 / 234;
    std::string exp = "25.02 234 /";
    float result = Eval::Evaluator::eval(exp);

    ASSERT_FLOAT_EQ(expected, result);
}
TEST(EvalPow, FloatTesting){
    float expected = pow(25.02, 234);
    std::string exp = "25.02 234 ^";
    float result = Eval::Evaluator::eval(exp);

    ASSERT_FLOAT_EQ(expected, result);
}
TEST(EvalComplex, FloatTesting){
    std::string a = "3 2 + 2 ^ 3 + 9 - 3 2 ^ +";
    float      _a = Eval::Evaluator::eval(a);

    std::string b = "78 30 0.5 28 8 + * - 6 / +";
    float      _b = Eval::Evaluator::eval(b);
    

    ASSERT_FLOAT_EQ(28, _a);
    ASSERT_FLOAT_EQ(80, _b);
}
int main(int argc, char **argv){
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}