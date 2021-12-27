#include "calculus.h"

double calculus(string postfix_output) {
	Stack<double> calculus;
	string num_st;
	double number;
	double variable_first, variable_second, variable_third = 0;
	for (size_t i = 0; i < postfix_output.length(); i++) {
		if (isdigit(postfix_output[i]) || postfix_output[i] == '.')
			num_st += postfix_output[i];
		else if ((postfix_output[i] == ' ') && (isdigit(postfix_output[i - 1]))) {
			number = stod(num_st);
			calculus.push(number);
			num_st = "\0";;
		}
		else if (postfix_output[i] == '+' || postfix_output[i] == '-' || 
				 postfix_output[i] == '*' || postfix_output[i] == '/' || 
				 postfix_output[i] == '^' || postfix_output[i] == 's' || 
				 postfix_output[i] == 'c' || postfix_output[i] == 'q' || 
				 postfix_output[i] == 'f' || postfix_output[i] == 't' || 
				 postfix_output[i] == 'g' || postfix_output[i] == 'l' || 
				 postfix_output[i] == 'n') {
			if (postfix_output[i] == '+') {
				variable_second = calculus.peek();
				calculus.pop();
				variable_first = calculus.peek();
				calculus.pop();
				variable_third = variable_first + variable_second;
				calculus.push(variable_third);
				variable_third = 0;
			}
			if (postfix_output[i] == '-') {
				variable_second = calculus.peek();
				calculus.pop();
				if (calculus.isEmpty()) {
					variable_third = 0 - variable_second;
				}
				else {
					variable_first = calculus.peek();
					calculus.pop();
					variable_third = variable_first - variable_second;
				}
				calculus.push(variable_third);
				variable_third = 0;
			}
			if (postfix_output[i] == '*') {
				variable_second = calculus.peek();
				calculus.pop();
				variable_first = calculus.peek();
				calculus.pop();
				variable_third = variable_first * variable_second;
				calculus.push(variable_third);
				variable_third = 0;
			}
			if (postfix_output[i] == '/') {
				variable_second = calculus.peek();
				calculus.pop();
				variable_first = calculus.peek();
				calculus.pop();
				variable_third = variable_first / variable_second;
				calculus.push(variable_third);
				variable_third = 0;
			}
			if (postfix_output[i] == '^')
			{
				variable_second = calculus.peek();
				calculus.pop();
				variable_first = calculus.peek();
				calculus.pop();
				variable_third = pow(variable_first, variable_second);
				calculus.push(variable_third);
				variable_third = 0;
			}
			if (postfix_output[i] == 's') {
				variable_first = calculus.peek();
				calculus.pop();
				variable_third = sin(variable_first * PI / 180);
				calculus.push(variable_third);
			}
			if (postfix_output[i] == 'c') {
				variable_first = calculus.peek();
				calculus.pop();
				variable_third = cos(variable_first);
				calculus.push(variable_third);
				variable_third = 0;
			}
			if (postfix_output[i] == 'f') {
				variable_first = calculus.peek();
				calculus.pop();
				variable_third = (pow(((variable_first * 3) + 1), 2));
				calculus.push(variable_third);
				variable_third = 0;
			}
			if (postfix_output[i] == 'q') {
				variable_first = calculus.peek();
				calculus.pop();
				variable_third = sqrt(variable_first);
				calculus.push(variable_third);
				variable_third = 0;
			}
			if (postfix_output[i] == 't') {
				variable_first = calculus.peek();
				calculus.pop();
				variable_third = sin(variable_first) / cos(variable_first);
				calculus.push(variable_third);
				variable_third = 0;
			}
			if (postfix_output[i] == 'g') {
				variable_first = calculus.peek();
				calculus.pop();
				variable_third = cos(variable_first) / sin(variable_first);
				calculus.push(variable_third);
				variable_third = 0;
			}
			if (postfix_output[i] == 'l') {
				variable_first = calculus.peek();
				calculus.pop();
				variable_third = log10(variable_first);
				calculus.push(variable_third);
				variable_third = 0;
			}
			if (postfix_output[i] == 'n') {
				variable_first = calculus.peek();
				calculus.pop();
				variable_third = log(variable_first);
				calculus.push(variable_third);
				variable_third = 0;
			}
			if (postfix_output[i] == 'e') {
				variable_third = EULER_CONST;
				calculus.push(variable_third);
				variable_third = 0;
			}
			if (postfix_output[i] == 'p') {
				variable_third = PI;
				calculus.push(variable_third);
				variable_third = 0;
			}
		}
	}
	double result = calculus.peek();
	cout << "Result is = " << result << endl;
	return result;
}