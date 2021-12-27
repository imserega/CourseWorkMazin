
//Includes
#include "postfix.h"

string postfix(string str) {
	Stack<string> temp;
	string postfix_string;  // converted string
	string buffer_str, dop;
	int pos;
	size_t size = -1;
	for (size_t i = 0; i < str.length(); i++)
	{
		buffer_str = str[i];
		if (isdigit(str[i]) || buffer_str == "." || buffer_str == "e" ) 
		{
			postfix_string += buffer_str;
			size++;
		}
		else if (buffer_str == " ") {
			if (postfix_string.length() != 0 && (postfix_string[postfix_string.length() - 1] != ' ')) {
				postfix_string += buffer_str;
				size++;
			}
		}
		else if (buffer_str == "p" && str[i + 1] == 'i')
		{
			postfix_string += buffer_str;
			postfix_string += str[i + 1];
			size = size + 2;
			i = i + 2;
		}
		else if (buffer_str == "f" && str[i + 1] == 'o')
		{
			dop = "(";
			temp.push(dop);
			dop = "\0";
			pos = str.find("(", i);
			dop.assign(str, i, pos - i);
			temp.push(dop);
			dop = "\0";
			str[pos] = ' ';
			i = pos;
		}
		else if (buffer_str == "s" && str[i + 1] == 'q')
		{
			dop = "(";
			temp.push(dop);
			dop = "\0";
			pos = str.find("(", i);
			dop.assign(str, i, pos - i);
			temp.push(dop);
			dop = "\0";
			str[pos] = ' ';
			i = pos;
		}
		else if (buffer_str == "s" && str[i + 1] == 'i')
		{
			dop = "(";
			temp.push(dop);
			dop = "\0";
			pos = str.find("(", i);
			dop.assign(str, i, pos - i);
			temp.push(dop);
			dop = "\0";
			str[pos] = ' ';
			i = pos;
		}
		else if (buffer_str == "c" && str[i + 1] == 'o')
		{
			dop = "(";
			temp.push(dop);
			dop = "\0";
			pos = str.find("(", i);
			dop.assign(str, i, pos - i);
			temp.push(dop);
			dop = "\0";
			str[pos] = ' ';
			i = pos;
		}
		else if (buffer_str == "c" && str[i + 1] == 't')
		{
			dop = "(";
			temp.push(dop);
			dop = "\0";
			pos = str.find("(", i);
			dop.assign(str, i, pos - i);
			temp.push(dop);
			dop = "\0";
			str[pos] = ' ';
			i = pos;
		}
		else if (buffer_str == "t" && str[i + 1] == 'g')
		{
			dop = "(";
			temp.push(dop);
			dop = "\0";
			pos = str.find("(", i);
			dop.assign(str, i, pos - i);
			temp.push(dop);
			dop = "\0";
			str[pos] = ' ';
			i = pos;
		}
		else if (buffer_str == "l" && str[i + 1] == 'o')
		{
			dop = "(";
			temp.push(dop);
			dop = "\0";
			pos = str.find("(", i);
			dop.assign(str, i, pos - i);
			temp.push(dop);
			dop = "\0";
			str[pos] = ' ';
			i = pos;
		}
		else if (buffer_str == "l" && str[i + 1] == 'n')
		{
			dop = "(";
			temp.push(dop);
			dop = "\0";
			pos = str.find("(", i);
			dop.assign(str, i, pos - i);
			temp.push(dop);
			dop = "\0";
			str[pos] = ' ';
			i = pos;
		}

		else if (buffer_str == "(")   
			temp.push(buffer_str);

		else if (buffer_str == "+" || buffer_str == "-" || buffer_str == "*" || buffer_str == "/" || buffer_str == "^")    
		{
			if (temp.isEmpty() || temp.peek() == "(") 
			{
				temp.push(buffer_str);
			}
			else if (priority_function(buffer_str) > priority_function(temp.peek())) 
			{
				temp.push(buffer_str);
			}

			else 
			{
				if (buffer_str == "-" && priority_function(temp.peek()) == 4) {
					temp.push(buffer_str);
				}
				else {
					while (((temp.size()) != 0) && (priority_function(buffer_str) <= priority_function(temp.peek()))) {
						postfix_string += temp.peek();
						postfix_string += ' ';
						size = size + 2;
						temp.pop();
					}
					temp.push(buffer_str);
				}
			}
		}
		else if (buffer_str == ")") 
		{

			while (temp.peek() != "(")
			{
				if (postfix_string.length() != 0 && (postfix_string[postfix_string.length() - 1] != ' ')) {
					postfix_string += ' ';
					size++;
				}
				postfix_string += temp.peek();
				size++;
				temp.pop();
			}
			if (temp.peek() == "(")
				temp.pop();
		}
	}
	while (!temp.isEmpty()) 
	{
		postfix_string += ' ';
		postfix_string += temp.peek();
		size = size + 2;
		temp.pop();
	}

	return postfix_string;
}
