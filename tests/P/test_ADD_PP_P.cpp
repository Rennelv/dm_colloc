#include <gtest/gtest.h>

#include "N/LongNatural.hpp"
#include "P/ADD_PP_P.hpp"
#include "P/Polynomial.hpp"
#include "Q/LongRational.hpp"
#include "Z/LongInteger.hpp"

TEST(Test_ADD_PP_P, SameDegreeTerms) {
    std::map<LongNatural, LongRational> poly1;
    std::map<LongNatural, LongRational> poly2;
    std::map<LongNatural, LongRational> expected;

    // poly1: (3/5)x^2 + (7/8)x + 2
    LongRational deg21 = LongRational(LongInteger("3"), LongNatural("5"));
    LongRational deg11 = LongRational(LongInteger("7"), LongNatural("8"));
    LongRational deg01 = LongRational(LongInteger("2"), LongNatural("1"));
    poly1.emplace(LongNatural("2"), deg21);
    poly1.emplace(LongNatural("1"), deg11);
    poly1.emplace(LongNatural("0"), deg01);

    // poly2: (2/5)x^2 + (1/8)x + 3
    LongRational deg22 = LongRational(LongInteger("2"), LongNatural("5"));
    LongRational deg12 = LongRational(LongInteger("1"), LongNatural("8"));
    LongRational deg02 = LongRational(LongInteger("3"), LongNatural("1"));
    poly2.emplace(LongNatural("2"), deg22);
    poly2.emplace(LongNatural("1"), deg12);
    poly2.emplace(LongNatural("0"), deg02);

    // expected: x^2 + x + 5
    LongRational deg23 = LongRational(LongInteger("1"), LongNatural("1"));
    LongRational deg13 = LongRational(LongInteger("1"), LongNatural("1"));
    LongRational deg03 = LongRational(LongInteger("5"), LongNatural("1"));
    expected.emplace(LongNatural("2"), deg23);
    expected.emplace(LongNatural("1"), deg13);
    expected.emplace(LongNatural("0"), deg03);

    Polynomial a(poly1);
    Polynomial b(poly2);
    Polynomial expected_poly(expected);

    EXPECT_EQ(ADD_PP_P(a, b), expected_poly);
}

TEST(Test_ADD_PP_P, DifferentDegrees) {
    std::map<LongNatural, LongRational> poly1;
    std::map<LongNatural, LongRational> poly2;
    std::map<LongNatural, LongRational> expected;

    // poly1: x^3 + (2/3)x
    LongRational deg31 = LongRational(LongInteger("1"), LongNatural("1"));
    LongRational deg11 = LongRational(LongInteger("2"), LongNatural("3"));
    poly1.emplace(LongNatural("3"), deg31);
    poly1.emplace(LongNatural("1"), deg11);

    // poly2: (3/2)x^2 + 1
    LongRational deg22 = LongRational(LongInteger("3"), LongNatural("2"));
    LongRational deg02 = LongRational(LongInteger("1"), LongNatural("1"));
    poly2.emplace(LongNatural("2"), deg22);
    poly2.emplace(LongNatural("0"), deg02);

    // expected: x^3 + (3/2)x^2 + (2/3)x + 1
    LongRational deg33 = LongRational(LongInteger("1"), LongNatural("1"));
    LongRational deg23 = LongRational(LongInteger("3"), LongNatural("2"));
    LongRational deg13 = LongRational(LongInteger("2"), LongNatural("3"));
    LongRational deg03 = LongRational(LongInteger("1"), LongNatural("1"));
    expected.emplace(LongNatural("3"), deg33);
    expected.emplace(LongNatural("2"), deg23);
    expected.emplace(LongNatural("1"), deg13);
    expected.emplace(LongNatural("0"), deg03);

    Polynomial a(poly1);
    Polynomial b(poly2);
    Polynomial expected_poly(expected);

    EXPECT_EQ(ADD_PP_P(a, b), expected_poly);
}

TEST(Test_ADD_PP_P, ZeroPolynomial) {
    std::map<LongNatural, LongRational> poly1;
    std::map<LongNatural, LongRational> poly2;
    std::map<LongNatural, LongRational> expected;

    // poly1: (4/3)x^2 + (1/2)x
    LongRational deg21 = LongRational(LongInteger("4"), LongNatural("3"));
    LongRational deg11 = LongRational(LongInteger("1"), LongNatural("2"));
    poly1.emplace(LongNatural("2"), deg21);
    poly1.emplace(LongNatural("1"), deg11);

    // poly2: 0
    LongRational deg02 = LongRational(LongInteger("0"), LongNatural("1"));
    poly2.emplace(LongNatural("0"), deg02);

    // expected: (4/3)x^2 + (1/2)x
    LongRational deg23 = LongRational(LongInteger("4"), LongNatural("3"));
    LongRational deg13 = LongRational(LongInteger("1"), LongNatural("2"));
    expected.emplace(LongNatural("2"), deg23);
    expected.emplace(LongNatural("1"), deg13);

    Polynomial a(poly1);
    Polynomial b(poly2);
    Polynomial expected_poly(expected);

    EXPECT_EQ(ADD_PP_P(a, b), expected_poly);
}

TEST(Test_ADD_PP_P, HigherDegreeForSecondPolynomial) {
    std::map<LongNatural, LongRational> poly1;
    std::map<LongNatural, LongRational> poly2;
    std::map<LongNatural, LongRational> expected;

    // poly1: (1/2)x + 3
    LongRational deg11 = LongRational(LongInteger("1"), LongNatural("2"));
    LongRational deg01 = LongRational(LongInteger("3"), LongNatural("1"));
    poly1.emplace(LongNatural("1"), deg11);
    poly1.emplace(LongNatural("0"), deg01);

    // poly2: (5/4)x^3 + (2/3)x^2 + 1
    LongRational deg32 = LongRational(LongInteger("5"), LongNatural("4"));
    LongRational deg22 = LongRational(LongInteger("2"), LongNatural("3"));
    LongRational deg02 = LongRational(LongInteger("1"), LongNatural("1"));
    poly2.emplace(LongNatural("3"), deg32);
    poly2.emplace(LongNatural("2"), deg22);
    poly2.emplace(LongNatural("0"), deg02);

    // expected: (5/4)x^3 + (2/3)x^2 + (1/2)x + 4
    LongRational deg33 = LongRational(LongInteger("5"), LongNatural("4"));
    LongRational deg23 = LongRational(LongInteger("2"), LongNatural("3"));
    LongRational deg13 = LongRational(LongInteger("1"), LongNatural("2"));
    LongRational deg03 = LongRational(LongInteger("4"), LongNatural("1"));
    expected.emplace(LongNatural("3"), deg33);
    expected.emplace(LongNatural("2"), deg23);
    expected.emplace(LongNatural("1"), deg13);
    expected.emplace(LongNatural("0"), deg03);

    Polynomial a(poly1);
    Polynomial b(poly2);
    Polynomial expected_poly(expected);

    EXPECT_EQ(ADD_PP_P(a, b), expected_poly);
}
