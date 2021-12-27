
//Includes
#include <iomanip>
#include "calculus.h"
#include "postfix.h"
#include "tools.h"

//Defines
#define BOLDGREEN   "\033[1m\033[32m"      /* Bold Green */
#define BOLDYELLOW  "\033[1m\033[33m"      /* Bold Yellow */
#define BOLDBLUE    "\033[1m\033[34m"      /* Bold Blue */
#define RESET   "\033[0m"

//Rule printing func
void print_rules_of_usage(){
	std::cout << std::setw(50) << BOLDGREEN << "HELLO\n" << RESET;
	std::cout << "Functions: \n";
	std::cout << "+ --- sum of two elements\n";
	std::cout << "- --- difference of two elements\n";
	std::cout << "/ --- division of two elements\n";
	std::cout << "* --- multiply of two elements\n";
	std::cout << "sin() --- sine function\n";
	std::cout << "cos() --- cosine function\n";
	std::cout << "tg() --- tan fanction\n";
	std::cout << "ctg() --- cotan fanction\n";
	std::cout << "sqrt() --- square root function\n";
	std::cout << "ln() --- natural logarithm function\n";
	std::cout << "log() --- logarithm function\n";
	std::cout << "fot() --- (x*3 + 1)^2 custom function\n";
	cout << endl << endl;
	cout << "Rules how to enter the expression: please write |... = ENTER|\n";
}

int main() {
	print_rules_of_usage();
	string str;
	cout << "Input: " << endl;
	getline(cin, str, '=');
	string postfix_string;
	try {
		if (input_checker(str)) {
			postfix_string = postfix(str); 
		}
	}
	catch (const invalid_argument error) {
		cout << error.what() << endl << endl;
	}
	functions_convert(postfix_string);
	cout << "In postfix notaion: " << endl;
	cout << postfix_string << '\n';
	calculus(functions_convert(postfix_string));
	return 0;
}


