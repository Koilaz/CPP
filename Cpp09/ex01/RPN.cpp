#include "RPN.hpp"

bool is_operator(char c)
{
	if (c == '*' || c == '+' || c == '-' || c == '/')
		return true;
	return false;
}

void RPN::import_input(char *argv)
{
	int i = 0;
	while (argv[i] != '\0')
		i++;
	i--;
	while (i >= 0)
	{
		while (i >= 0 && isspace(argv[i]))
			i--;
		if (i >= 0 && (isdigit(argv[i]) || is_operator(argv[i])))
		{
			if (i > 0 && !isspace(argv[i - 1]))
				throw NotValidRPN();
			_input.push(argv[i]);
		}
		else if (i >= 0)
			throw NotValidRPN();
		i--;
	}
}

int RPN::get_result()
{
	int result = 0;
	while (!_input.empty())
	{
		char c = _input.top();
		_input.pop();
		if (isdigit(c))
			_stack.push(c - '0');
		else if (is_operator(c))
		{
			if (_stack.size() < 2)
				throw NotValidRPN();
			int tmp = _stack.top();
			_stack.pop();
			switch (c)
			{
			case '+':
			{
				result = (tmp + _stack.top());
				break;
			}
			case '-':
			{
				result = (_stack.top() - tmp);
				break;
			}
			case '*':
			{
				result = (tmp * _stack.top());
				break;
			}
			case '/':
			{
				if (tmp == 0)
					throw std::overflow_error("Division by zero");
				result = (_stack.top() / tmp);
				break;
			}
			default:
			{
				throw NotValidRPN();
				break;
			}
			}
			_stack.pop();
			_stack.push(result);
		}
		else
			throw NotValidRPN();
	}
	if (_stack.size() == 1)
		return _stack.top();
	else
		throw NotValidRPN();
	return (0);
}

const char *RPN::NotValidRPN::what() const throw()
{
	return "Error Unvalid polish reverse notation equation";
}

RPN::RPN()
{
}

RPN::RPN(const RPN &other)
{
	(void)other;
}

RPN &RPN::operator=(const RPN &src)
{
	(void)src;
	return *this;
}

RPN::~RPN()
{
}
