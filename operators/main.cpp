#include <iostream>

#include "arithmetic.h"

int main()
{
    // Operator precedence and associativity determine the order of operations
    // in an expression. The precedence of an operator is a value that
    // determines which operator is evaluated first in an expression. Operators
    // with higher precedence are evaluated first. The associativity of an
    // operator is a value that determines the order in which operators of the
    // same precedence are evaluated. Operators with left-to-right associativity
    // are evaluated from left to right. Operators with right-to-left
    // associativity are evaluated from right to left.

    // Evaluation of operands
    // Value computation

    // Be careful: Operands, function arguments, and subexpressions may be
    // evaluated in any order and may be evaluated more than once. The order of
    // evaluation of operands is unspecified.

    show_arithmetic_operators();

    return 0;
}