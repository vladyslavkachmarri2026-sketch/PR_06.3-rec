#include "pch.h"
#include "CppUnitTest.h"
#include "../PR_6.3 rec.cpp" 
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace PR63recUnitTest
{
	TEST_CLASS(PR63recUnitTest)
	{
	public:

		// 1. Тест для звичайної рекурсивної функції CountOdd
		TEST_METHOD(TestCountOdd_NonTemplate)
		{
			int a[5] = { -5, 2, 3, 8, 7 }; // Непарні: -5, 3, 7 (всього 3)
			int expected = 3;

			// Передаємо 0 як початковий індекс i
			int actual = CountOdd(a, 5, 0);

			Assert::AreEqual(expected, actual);
		}

		// 2. Тест для шаблонної рекурсивної функції CountOdd<int>
		TEST_METHOD(TestCountOdd_Template)
		{
			int b[6] = { -1, 0, 1, 3, 4, 5 }; // Непарні: -1, 1, 3, 5 (всього 4)
			int expected = 4;

			int actual = CountOdd<int>(b, 6, 0);

			Assert::AreEqual(expected, actual);
		}

		// 3. Тест на відсутність непарних елементів у масиві
		TEST_METHOD(TestCountOdd_ZeroOdds)
		{
			int c[4] = { -4, -2, 0, 6 };
			int expected = 0;

			Assert::AreEqual(expected, CountOdd(c, 4, 0));
			Assert::AreEqual(expected, CountOdd<int>(c, 4, 0));
		}
	};
}
