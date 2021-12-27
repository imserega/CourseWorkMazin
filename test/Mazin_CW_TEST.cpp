#include "pch.h"
#include "CppUnitTest.h"
#include "..\CourseWorkMazin\main.cpp"
#include "..\CourseWorkMazin\tools.h"
#include "..\CourseWorkMazin\tools.cpp"
#include "..\CourseWorkMazin\postfix.cpp"
#include "..\CourseWorkMazin\calculus.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace MazinCWTEST
{
	TEST_CLASS(MazinCWTEST)
	{
	public:

		TEST_METHOD(Priority_TEST1)
		{
			

			string str1 = "-";
			string str2 = "+";
			string str3 = "*";
			string str4 = "/";
			string str5 = "^";
			string str6 = "sin";
			string str7 = "cos";
			string str8 = "tg";
			string str9 = "ctg";
			string str10 = "ln";
			string str11 = "log";
			string str12 = "fot";
			string str13 = "sqrt";

			Assert::IsTrue((priority_function(str1) == 1) &&
				(priority_function(str2) == 1) &&
				(priority_function(str3) == 2) &&
				(priority_function(str4) == 2) &&
				(priority_function(str5) == 3) &&
				(priority_function(str6) == 4) &&
				(priority_function(str7) == 4) &&
				(priority_function(str8) == 4) &&
				(priority_function(str9) == 4) &&
				(priority_function(str10) == 4) &&
				(priority_function(str11) == 4) &&
				(priority_function(str12) == 4) &&
				(priority_function(str13) == 4));
			
		}
		TEST_METHOD(Postfix_TEST1)
		{
			string str("fot(30) + 4 ^ 2");
			string postcheck = postfix(str);
			string check("30 fot 4 2 ^ +");
			Assert::IsTrue(check == postcheck);
		}

		TEST_METHOD(Postfix_TEST2)
		{
			string str("sin(30) * cos(20) + ln(2) ^ log(10)");
			string postcheck = postfix(str);
			string check("30 sin 20 cos * 2 ln 10 log ^ +");
			Assert::IsTrue(check == postcheck);
		}

		TEST_METHOD(Calculus_TEST1)
		{
			string str("2.5 2 * 2.5 +");
			double check = 7.5;
			Assert::AreEqual(check, calculus(str));
		}
		
	};
}
