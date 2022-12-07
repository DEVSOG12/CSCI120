#include "gtest/gtest.h"

#include "ArrayMaxHeap.hpp"

//read more at
//https://github.com/google/googletest/blob/master/googletest/docs/primer.md

// macro from Google test
// to create tests
TEST(ArrayMaxHeap, isEmpty) {

    ArrayMaxHeap<int> intHeap;
    EXPECT_TRUE(intHeap.isEmpty());

    intHeap.add(10);
    EXPECT_FALSE(intHeap.isEmpty());
}

TEST(ArrayMaxHeap, add) {

    ArrayMaxHeap<int> intHeap;
    intHeap.add(99);

    EXPECT_FALSE(intHeap.isEmpty());
    EXPECT_EQ(intHeap.peekTop(),99);
    //cout << intHeap.peekTop()<<endl;

}
// examples of tests for the Stack ADT
/*TEST(StackArray, pop) {

    StackArray<char> charStack;
    charStack.push('A');

    char c = charStack.pop();

    EXPECT_EQ(c, 'A');
}


TEST(StackArray, showStructure_Empty) {

    StackArray<char> charStack;

    std::stringstream buffer;
    // Save cout's buffer here
    std::streambuf *sbuf = std::cout.rdbuf();

    // Redirect cout to our stringstream buffer or any other ostream
    std::cout.rdbuf(buffer.rdbuf());

    charStack.showStructure();

    EXPECT_EQ(buffer.str(), "Empty stack.\n\n");

    // When done redirect cout to its old self
    std::cout.rdbuf(sbuf);
}

TEST(StackArray, showStructure) {
    StackArray<char> charStack;
    charStack.push('A');
    charStack.push('B');
    charStack.push('C');

    std::stringstream buffer;
    // Save cout's buffer here
    std::streambuf *sbuf = std::cout.rdbuf();
    // Redirect cout to our stringstream buffer or any other ostream
    std::cout.rdbuf(buffer.rdbuf());

    charStack.showStructure();

    EXPECT_EQ(buffer.str(), "top = 2\n0\t1\t2\t3\t4\t5\t6\t7\t\nA\tB\t[C]\t\n\n");

    // When done redirect cout to its old self
    std::cout.rdbuf(sbuf);
}
*/



/*
 *
 void push(const DataType& newDataItem) throw (logic_error);
    DataType pop() throw (logic_error);

    void clear();

    bool isEmpty() const;
    bool isFull() const;

    void showStructure() const;
 * */