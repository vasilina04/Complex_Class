#include "pch.h"
#include "CppUnitTest.h"
#include "ComplexClass.h"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Test
{
	TEST_CLASS(Test)
	{
	public:

		TEST_METHOD(Constructor)
		{
			Complex<double> a(0, 0);
			Assert::IsTrue(a.getReal() == 0);
			Assert::IsTrue(a.getImag() == 0);
		}


		
		TEST_METHOD(TestAddition)
		{
			Complex<double> a(1, 2);
			Complex<double> b(3, 4);
			Complex<double> result = a + b;
			Assert::IsTrue(result.getReal() == 4 && result.getImag() == 6);
		}

		TEST_METHOD(GetTest)
		{
			Complex<double> a(2.2, -5.5);
			Assert::AreEqual(2.2, a.getReal());
			Assert::AreEqual(-5.5, a.getImag());
		}

		TEST_METHOD(TestSubtraction)
		{
			Complex<double> a(5, 6);
			Complex<double> b(3, 4);
			Complex<double> result = a - b;
			Assert::IsTrue(result.getReal() == 2 && result.getImag() == 2);
		}

		TEST_METHOD(TestMultiplication)
		{
			Complex<float> a(3.0, 4.0);
			Complex<float> b(1.0, 2.0);
			Complex<float> result = a * b;
			Assert::IsTrue(result.getReal() == -5.0 && result.getImag() == 10.0);
		}

		TEST_METHOD(TestDivision)
		{
			Complex<double> a(1.0, 2.0);
			Complex<double> b(3.0, 4.0);
			Complex<double> result = a / b;
			Assert::IsTrue(result.getReal() == 0.44 && result.getImag() == 0.08);
		}

		TEST_METHOD(TestEqualityOperatorWithComplex)
		{
			Complex<int> a(3, 4);
			Complex<int> b(3, 4);
			Assert::IsTrue(a == b);
		}


		TEST_METHOD(TestModulusLessThan)
		{
			Complex<float> a(3.0, 4.0);
			Assert::IsTrue(a < 6.0f);
		}

		TEST_METHOD(TestModulusGreaterThan)
		{
			Complex<float> a(3.0, 4.0);
			Assert::IsTrue(a > 2.0f);
		}

		TEST_METHOD(TestEqualityOperatorWithDouble)
		{
			Complex<double> a(3.0, 4.0);
			Assert::IsTrue(a.getReal() == 3.0);
		}

		TEST_METHOD(TEstComplexOperators) {
			Complex<int> c1(3, 4);
			Complex<int> c2(1, 2);
			Assert::IsTrue(c1 > c2);
			Assert::IsTrue(c1 >= c2);
			Assert::IsFalse(c1 < c2);
			Assert::IsFalse(c1 <= c2);
		}

	};
}
