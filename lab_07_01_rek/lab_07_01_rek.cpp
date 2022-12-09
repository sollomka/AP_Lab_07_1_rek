#include "pch.h"
#include "CppUnitTest.h"
#include "../Ap_lab_07_1_rek/lab_07_1_rek.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace lab0701rek
{
	TEST_CLASS(lab0701rek)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			int R[2][2] =
			{
				{13, -14},
				{12, 26}
			};
			int* pR[2] = { R[0], R[1] };
			int S = 0;
			int k = 0;
			Calc(pR, 2, 2, 0, 0, S, k);
			int result = S;
			Assert::AreEqual(result, 51);
		}
	};
}
