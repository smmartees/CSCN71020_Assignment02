#include "pch.h"
#include "CppUnitTest.h"

extern "C" {
#include "../BCSRec/main.h"
}

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace BCSRecUnitTests
{
	TEST_CLASS(UnitTest_getPerimeter)
	{
	public:
		
		TEST_METHOD(perimeter_length1_width1)
		{
			int length = 1;
			int width = 1;
			int expected = 4;	// perimeter should be the sum of all 4 sides.
			int actual = getPerimeter(&length, &width);
			Assert::AreEqual(expected, actual);
		}

	};

	TEST_CLASS(UnitTest_getArea)
	{
	public:

		TEST_METHOD(area_length2_width3)
		{
			int length = 2;
			int width = 3;
			int expected = 6;	// area should be the product of length & width sides.
			int actual = getPerimeter(&length, &width);
			Assert::AreEqual(expected, actual);
		}

	};
	TEST_CLASS(UnitTest_setLength)
	{
	public:

		TEST_METHOD(setLength_lowerOutOfBounds)
		{
			int length = 1;	// minimum input that is acceptable per the req.
			int lowInput = 0;	// 0 should be out of bounds per the requirements
			int expected = 1;	// length should remain unchanged as input is too low
			setLength(lowInput, &length);
			Assert::AreEqual(expected, length);
		}
		TEST_METHOD(setLength_upperOutOfBounds)
		{
			int length = 99;	// max input that is acceptable per the req.
			int highInput = 100;	// should be out of bounds per the req.
			int expected = 99;	// length should remain unchanged as input is too high.
			setLength(highInput, &length);
			Assert::AreEqual(expected, length);

		}
		TEST_METHOD(setLength_floatInput)
		{
			int length = 99;
			float floatInput = 3.14;	
			int expected = 3;	// function should implicitly cast variable as int.
			setLength(floatInput, &length);
			Assert::AreEqual(expected, length);
		}

	};
	TEST_CLASS(UnitTest_setWidth)
	{
	public:

		TEST_METHOD(setWidth_lowerOutOfBounds)
		{
			int width = 1;	// minimum input that is acceptable per the req.
			int lowInput = 0;	// 0 should be out of bounds per the requirements
			int expected = 1;	// width should remain unchanged as input is too low
			setLength(lowInput, &width);
			Assert::AreEqual(expected, width);
		}
		TEST_METHOD(setWidth_upperOutOfBounds)
		{
			int width = 99;	// max input that is acceptable per the req.
			int highInput = 100;	// should be out of bounds per the req.
			int expected = 99;	// width should remain unchanged as input is too high.
			setLength(highInput, &width);
			Assert::AreEqual(expected, width);
		}
		TEST_METHOD(setWidth_charInput)
		{
			int width = 99;
			char charInput = 's';
			int expected = 99;	// function should not take char input, thus no change.
			setLength(charInput, &width);
			Assert::AreEqual(expected, width);
		}

	};
}
