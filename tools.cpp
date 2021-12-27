
//Includes
#include "tools.h"


bool input_checker(string str) {
	bool check = true;
	for (size_t index = 0; index < str.length(); index++)
	{
		if (str[index] == '.' && (str[index - 1] > 57 && str[index - 1] < 48) && (str[index + 1] > 57 && str[index + 1] < 48)) {
			throw invalid_argument("Incorrect input of number");
			check = false;
		}
		else if (str[index] == '*' && (str[index - 1] == '(' || str[index + 1] == ')')) {
			throw invalid_argument("Incorrect input of application *");
			check = false;
		}
		else if (str[index] == '+' && (str[index - 1] == '(' || str[index + 1] == ')')) {
			throw invalid_argument("Incorrect input of application +");
			check = false;
		}
		else if (str[index] == '-' && str[index + 1] == ')') {
			throw invalid_argument("Incorrect input of application -");
			check = false;
		}
		else if (str[index] == '/' && (str[index - 1] == '(' || str[index + 1] == ')')) {
			throw invalid_argument("Incorrect input of application /");
			check = false;
		}
		else if (str[index] == '^' && str[index - 1] == '(') {
			throw invalid_argument("Incorrect input of application ^");
			check = false;
		}

		else if (str[index] == 'f' && str[index + 1] != 'o' && str[index + 2] != 't') {
			throw invalid_argument("Incorrect input of the fot function");
			check = false;
		}
		
		else if ((str[index] == 'f' && str[index + 1] == 'o' && str[index + 2] == 't') && (str[index + 3] != '(' || (index != 0 && (str[index - 2] != 45 && str[index - 2] != 47 && str[index - 2] != 94 && str[index - 1] != 40 && str[index - 2] != 42 && str[index - 2] != 43)))) {
			throw invalid_argument("Incorrect arithmetics the fot function");
			check = false;
		}
		
		else if (str[index] == 'f' && str[index + 1] == 'o' && str[index + 2] == 't') {
			index = index + 3;
		}

		else if (str[index] == 'c' && ((str[index + 1] != 'o' && str[index + 2] != 's') && (str[index + 1] != 't' && str[index + 2] != 'g'))) {
			throw invalid_argument("Incorrect input of the cos or ctg function");
			check = false;
		}
		else if ((str[index] == 'c' && ((str[index + 1] == 'o' && str[index + 2] == 's') || (str[index + 1] == 't' && str[index + 2] == 'g'))) && (str[index + 3] != '(' || (index != 0 && (str[index - 2] != 45 && str[index - 2] != 47 && str[index - 2] != 94 && str[index - 1] != 40 && str[index - 2] != 42 && str[index - 2] != 43)))) {
			throw invalid_argument("Incorrect input of arithmetics the cos or ctg function");
			check = false;
		}
		else if (str[index] == 'c' && str[index + 1] == 'o' && str[index + 2] == 's') {
			index = index + 3;
		}
		else if (str[index] == 'c' && str[index + 1] == 't' && str[index + 2] == 'g') {
			index = index + 3;
		}

		else if (str[index] == 's' && ((str[index + 1] != 'i' && str[index + 2] != 'n') && (str[index + 1] != 'q' && str[index + 2] != 'r' && str[index + 3] != 't'))) {
			throw invalid_argument("Incorrect input of the sin or sqrt function");
			check = false;
		}
		else if ((str[index] == 's' && str[index + 1] == 'i' && str[index + 2] == 'n') && (str[index + 3] != '(' || (index != 0 && (str[index - 2] != 45 && str[index - 2] != 47 && str[index - 2] != 94 && str[index - 1] != 40 && str[index - 2] != 42 && str[index - 2] != 43)))) {
			throw invalid_argument("Incorrect arithmetics the sin function");
			check = false;
		}
		else if ((str[index] == 's' && str[index + 1] == 'q' && str[index + 2] == 'r' && str[index + 3] == 't') && (str[index + 4] != '(' || (index != 0 && (index != 0 && (str[index - 2] != 45 && str[index - 2] != 47 && str[index - 2] != 94 && str[index - 1] != 40 && str[index - 2] != 42 && str[index - 2] != 43))))) {
			throw invalid_argument("Incorrect arithmetics the sqrt function");
			check = false;
		}
		else if (str[index] == 's' && str[index + 1] == 'q' && str[index + 2] == 'r' && str[index + 3] == 't') {
			index = index + 4;
		}
		else if (str[index] == 's' && str[index + 1] == 'i' && str[index + 2] == 'n') {
			index = index + 3;
		}


		else if (str[index] == 'l' && ((str[index + 1] != 'o' && str[index + 2] != 'g') && (str[index + 1] != 'n'))) {
			throw invalid_argument("Incorrect input of the log or ln function");
			check = false;
		}
		else if ((str[index] == 'l' && str[index + 1] == 'o' && str[index + 2] == 'g') && (str[index + 3] != '(' || (index != 0 && (str[index - 2] != 45 && str[index - 2] != 47 && str[index - 2] != 94 && str[index - 1] != 40 && str[index - 2] != 42 && str[index - 2] != 43)))) {
			throw invalid_argument("Incorrect arithmetics the log function");
			check = false;
		}
		else if ((str[index] == 'l' && str[index + 1] == 'n') && (str[index + 2] != '(' || (index != 0 && (str[index - 2] != 45 && str[index - 2] != 47 && str[index - 2] != 94 && str[index - 1] != 40 && str[index - 2] != 42 && str[index - 2] != 43)))) {
			throw invalid_argument("Incorrect arithmetics the ln function");
			check = false;
		}
		else if (str[index] == 'l' && str[index + 1] == 'o' && str[index + 2] == 'g') {
			index = index + 3;
		}
		else if (str[index] == 'l' && str[index + 1] == 'n') {
			index = index + 2;
		}


		else if (str[index] == 't' && str[index + 1] != 'g') {
			throw invalid_argument("Incorrect input of the tg function");
			check = false;
		}
		else if ((str[index] == 't' && str[index + 1] == 'g') && (str[index + 2] != '(' || (index != 0 && (str[index - 2] != 45 && str[index - 2] != 47 && str[index - 2] != 94 && str[index - 1] != 40 && str[index - 2] != 42 && str[index - 2] != 43)))) {
			throw invalid_argument("Incorrect arithmetics the tg function");
			check = false;
		}
		else if (str[index] == 't' && str[index + 1] == 'g') {
			index = index + 2;
		}

		else if (str[index] == 'p' && str[index + 1] != 'i') {
			throw invalid_argument("Incorrect input of the PI const");
			check = false;
		}
		else if ((str[index] == 'p' && str[index + 1] == 'i') && ((str[index + 3] != 45 && str[index + 3] != 47 && str[index + 3] != 94 && str[index + 2] != 41 && str[index + 3] != 42 && str[index + 3] != 43) || (index != 0 && (str[index - 2] != 45 && str[index - 2] != 47 && str[index - 2] != 94 && str[index - 1] != 40 && str[index - 2] != 42 && str[index - 2] != 43)))) {
			throw invalid_argument("Incorrect arithmetics the PI const");
			check = false;
		}
		else if (str[index] == 'p' && str[index + 1] == 'i') {
			index = index + 2;
		}
		else if (str[index] == 'e' && ((str[index + 2] != 45 && str[index + 2] != 47 && str[index + 2] != 94 && str[index + 1] != 41 && str[index + 2] != 42 && str[index + 2] != 43) || (index != 0 && (str[index - 2] != 45 && str[index - 2] != 47 && str[index - 2] != 94 && str[index - 1] != 40 && str[index - 2] != 42 && str[index - 2] != 43)))) {
			throw invalid_argument("Incorrect arithmetics the E const");
			check = false;
		}
		/*
		else if (str[index] == '=') {}
		else if (str[index] == ' ') {}
		else if (str[index] == ' ' && str[index] != '=' && str[index] != 'a' && str[index] != 'b' && str[index] != 'e' && str[index] != 'c' && str[index] != 'o' && str[index] != 's' && str[index] != 't' && str[index] != 'g' && str[index] != 'i' && str[index] != 'n' && str[index] != 'q' && str[index] != 'r' && str[index] != 'l' && str[index] != 'p' && str[index] != '+' && str[index] != '-' && str[index] != '/' && str[index] != '*' && str[index] != '^' /*&& str[index] != ')' && str[index] != '(' && !(str[index] <= 57 && str[index] >= 48)) {
			throw invalid_argument("Invalid character. The calculator can use only numbers like double, brackets, actions: +, -, *, /, ^ and functions: sin, cos, tg, ctg, sqrt, log, ln, abs");
			check = false;
		}
		*/
		

	}
	return check;
}

string functions_convert(string str) {
	//Functions: sqrt, foo, sin, cos, log, ln, tg, ctg
	int val1 = str.find("sin");
	if (val1 != -1) {
		str.replace(str.find("sin"), 3, "s");
	}
	int val2 = str.find("cos");
	if (val2 != -1) {
		str.replace(str.find("cos"), 3, "c");
	}
	int val3 = str.find("sqrt");
	if (val3 != -1) {
		str.replace(str.find("sqrt"), 4, "q");
	}
	int val4 = str.find("fot");
	if (val4 != -1) {
		str.replace(str.find("fot"), 3, "f");
	}
	int val5 = str.find("log");
	if (val5 != -1) {
		str.replace(str.find("log"), 3, "l");
	}
	int val6 = str.find("ln");
	if (val6 != -1) {
		str.replace(str.find("ln"), 2, "n");
	}
	int val7 = str.find("tg");
	if (val7 != -1) {
		str.replace(str.find("tg"), 2, "t");
	}
	int val8 = str.find("ctg");
	if (val8 != -1) {
		str.replace(str.find("ctg"), 3, "y");
	}
	return str;
}
int priority_function(string i)
{
	int operation_weight;
	if (i == "*" || i == "/")
		operation_weight = 2;
	else if (i == "^")
		operation_weight = 3;
	else if (i == "sin" || i == "cos" || 
			 i == "tg" || i == "ctg" || 
			 i == "sqrt" || i == "log" || 
			 i == "ln" || i == "fot")
		operation_weight = 4;
	else
		operation_weight = 1;
	return operation_weight;
}