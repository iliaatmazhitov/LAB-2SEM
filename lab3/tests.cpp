//
// Created by Илья Атмажитов on 21.06.2024.
//


#include "tests.h"



void runAllTests() {
    testConstructor();
    testPushBackAndGet();
    testAddition();
    testScalarMultiplication();
    testDotProduct();
    testAssignment();
    std::cout << "All tests passed successfully!" << std::endl;
}

void testConstructor() {
    Vector<int> v1(1, 3); // ArraySequence с размером 3
    Vector<double> v2(2, 3); // ListSequence с размером 3
    assert(v1.get_size() == 3);
    assert(v2.get_size() == 3);
}

void testPushBackAndGet() {
    Vector<int> v(1, 3);
    v[0] = 1;
    v[1] = 2;
    v[2] = 3;
    assert(v.get_size() == 3);
    assert(v[0] == 1);
    assert(v[1] == 2);
    assert(v[2] == 3);
}

void testAddition() {
    Vector<int> v1(1, 2);
    v1[0] = 1;
    v1[1] = 2;
    Vector<int> v2(1, 2);
    v2[0] = 3;
    v2[1] = 4;
    Vector<int> v3 = v1 + v2;
    assert(v3[0] == 4);
    assert(v3[1] == 6);
}

void testScalarMultiplication() {
    Vector<double> v(1, 2);
    v[0] = 1.0;
    v[1] = 2.0;
    Vector<double> result = v * 2.0;
    assert(result[0] == 2.0);
    assert(result[1] == 4.0);
}

void testDotProduct() {
    Vector<int> v1(1, 2);
    v1[0] = 1;
    v1[1] = 2;
    Vector<int> v2(1, 2);
    v2[0] = 3;
    v2[1] = 4;
    assert(v1.dot(v2) == 11);
}

void testAssignment() {
    Vector<int> v1(1, 2);
    v1[0] = 1;
    v1[1] = 2;
    Vector<int> v2(2);
    v2 = v1;
    assert(v2.get_size() == 2);
    assert(v2[0] == 1);
    assert(v2[1] == 2);
}