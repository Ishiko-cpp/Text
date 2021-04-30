/*
    Copyright (c) 2021 Xavier Leclercq
    Released under the MIT License
    See https://github.com/Ishiko-cpp/Text/blob/master/LICENSE.txt
*/

#include "ASCIITests.h"
#include "Ishiko/Text/ASCII.h"

using namespace Ishiko::Tests;
using namespace Ishiko::Text;

ASCIITests::ASCIITests(const TestNumber& number, const TestEnvironment& environment)
    : TestSequence(number, "ASCII tests", environment)
{
    append<HeapAllocationErrorsTest>("Split test 1", SplitTest1);
    append<HeapAllocationErrorsTest>("Split test 2", SplitTest2);
    append<HeapAllocationErrorsTest>("Split test 3", SplitTest3);
    append<HeapAllocationErrorsTest>("Split test 4", SplitTest4);
    append<HeapAllocationErrorsTest>("Split test 5", SplitTest5);
    append<HeapAllocationErrorsTest>("Split test 6", SplitTest6);
    append<HeapAllocationErrorsTest>("Split test 7", SplitTest7);
    append<HeapAllocationErrorsTest>("Split test 8", SplitTest8);
    append<HeapAllocationErrorsTest>("Split test 9", SplitTest9);
    append<HeapAllocationErrorsTest>("Split test 10", SplitTest10);
    append<HeapAllocationErrorsTest>("Split test 11", SplitTest11);
    append<HeapAllocationErrorsTest>("ToLowerCase test 1", ToLowerCaseTest1);
    append<HeapAllocationErrorsTest>("ToUpperCase test 1", ToUpperCaseTest1);
    append<HeapAllocationErrorsTest>("Trim test 1", TrimTest1);
    append<HeapAllocationErrorsTest>("Trim test 2", TrimTest2);
    append<HeapAllocationErrorsTest>("Trim test 3", TrimTest3);
    append<HeapAllocationErrorsTest>("Trim test 4", TrimTest4);
    append<HeapAllocationErrorsTest>("Trim test 5", TrimTest5);
    append<HeapAllocationErrorsTest>("Trim test 6", TrimTest6);
    append<HeapAllocationErrorsTest>("Trim test 7", TrimTest7);
    append<HeapAllocationErrorsTest>("Trim test 8", TrimTest8);
    append<HeapAllocationErrorsTest>("Trim test 9", TrimTest9);
    append<HeapAllocationErrorsTest>("Trim test 10", TrimTest10);
    append<HeapAllocationErrorsTest>("Trim test 11", TrimTest11);
}

void ASCIITests::SplitTest1(Test& test)
{
    std::vector<std::string> tokens = ASCII::Split("");

    ISHTF_FAIL_IF_NEQ(tokens.size(), 0);
    ISHTF_PASS();
}

void ASCIITests::SplitTest2(Test& test)
{
    std::vector<std::string> tokens = ASCII::Split("a");

    ISHTF_FAIL_IF_NEQ(tokens, std::vector<std::string>({ "a" }));
    ISHTF_PASS();
}

void ASCIITests::SplitTest3(Test& test)
{
    std::vector<std::string> tokens = ASCII::Split("abc");

    ISHTF_FAIL_IF_NEQ(tokens, std::vector<std::string>({ "abc" }));
    ISHTF_PASS();
}

void ASCIITests::SplitTest4(Test& test)
{
    std::vector<std::string> tokens = ASCII::Split("one two");

    ISHTF_FAIL_IF_NEQ(tokens, std::vector<std::string>({ "one", "two" }));
    ISHTF_PASS();
}

void ASCIITests::SplitTest5(Test& test)
{
    std::vector<std::string> tokens = ASCII::Split("one two three");

    ISHTF_FAIL_IF_NEQ(tokens, std::vector<std::string>({ "one", "two", "three" }));
    ISHTF_PASS();
}

void ASCIITests::SplitTest6(Test& test)
{
    std::vector<std::string> tokens = ASCII::Split(" ");

    ISHTF_FAIL_IF_NEQ(tokens.size(), 0);
    ISHTF_PASS();
}

void ASCIITests::SplitTest7(Test& test)
{
    std::vector<std::string> tokens = ASCII::Split("   ");

    ISHTF_FAIL_IF_NEQ(tokens.size(), 0);
    ISHTF_PASS();
}

void ASCIITests::SplitTest8(Test& test)
{
    std::vector<std::string> tokens = ASCII::Split("a ");

    ISHTF_FAIL_IF_NEQ(tokens, std::vector<std::string>({ "a" }));
    ISHTF_PASS();
}

void ASCIITests::SplitTest9(Test& test)
{
    std::vector<std::string> tokens = ASCII::Split("a   ");

    ISHTF_FAIL_IF_NEQ(tokens, std::vector<std::string>({ "a" }));
    ISHTF_PASS();
}

void ASCIITests::SplitTest10(Test& test)
{
    std::vector<std::string> tokens = ASCII::Split(" a ");

    ISHTF_FAIL_IF_NEQ(tokens, std::vector<std::string>({ "a" }));
    ISHTF_PASS();
}

void ASCIITests::SplitTest11(Test& test)
{
    std::vector<std::string> tokens = ASCII::Split(" one  two   three ");

    ISHTF_FAIL_IF_NEQ(tokens, std::vector<std::string>({ "one", "two", "three" }));
    ISHTF_PASS();
}

void ASCIITests::ToLowerCaseTest1(Test& test)
{
    std::string str = "Hello World!";

    ASCII::ToLowerCase(str);

    ISHTF_FAIL_IF_NEQ(str, "hello world!");
    ISHTF_PASS();
}

void ASCIITests::ToUpperCaseTest1(Test& test)
{
    std::string str = "Hello World!";

    ASCII::ToUpperCase(str);

    ISHTF_FAIL_IF_NEQ(str, "HELLO WORLD!");
    ISHTF_PASS();
}

void ASCIITests::TrimTest1(Test& test)
{
    std::string str = "";

    ASCII::Trim(str);

    ISHTF_FAIL_IF_NEQ(str, "");
    ISHTF_PASS();
}

void ASCIITests::TrimTest2(Test& test)
{
    std::string str = "a";

    ASCII::Trim(str);

    ISHTF_FAIL_IF_NEQ(str, "a");
    ISHTF_PASS();
}

void ASCIITests::TrimTest3(Test& test)
{
    std::string str = "abc";

    ASCII::Trim(str);

    ISHTF_FAIL_IF_NEQ(str, "abc");
    ISHTF_PASS();
}

void ASCIITests::TrimTest4(Test& test)
{
    std::string str = " ";

    ASCII::Trim(str);

    ISHTF_FAIL_IF_NEQ(str, "");
    ISHTF_PASS();
}

void ASCIITests::TrimTest5(Test& test)
{
    std::string str = "   ";

    ASCII::Trim(str);

    ISHTF_FAIL_IF_NEQ(str, "");
    ISHTF_PASS();
}

void ASCIITests::TrimTest6(Test& test)
{
    std::string str = " a";

    ASCII::Trim(str);

    ISHTF_FAIL_IF_NEQ(str, "a");
    ISHTF_PASS();
}

void ASCIITests::TrimTest7(Test& test)
{
    std::string str = "   a";

    ASCII::Trim(str);

    ISHTF_FAIL_IF_NEQ(str, "a");
    ISHTF_PASS();
}

void ASCIITests::TrimTest8(Test& test)
{
    std::string str = "a ";

    ASCII::Trim(str);

    ISHTF_FAIL_IF_NEQ(str, "a");
    ISHTF_PASS();
}

void ASCIITests::TrimTest9(Test& test)
{
    std::string str = "a   ";

    ASCII::Trim(str);

    ISHTF_FAIL_IF_NEQ(str, "a");
    ISHTF_PASS();
}

void ASCIITests::TrimTest10(Test& test)
{
    std::string str = " a ";

    ASCII::Trim(str);

    ISHTF_FAIL_IF_NEQ(str, "a");
    ISHTF_PASS();
}

void ASCIITests::TrimTest11(Test& test)
{
    std::string str = "  a   ";

    ASCII::Trim(str);

    ISHTF_FAIL_IF_NEQ(str, "a");
    ISHTF_PASS();
}