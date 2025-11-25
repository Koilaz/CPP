#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include<stack>

bool is_operator(char c);

class RPN
{
public:


	void	import_input(char *argv);
	int		get_result();

    RPN();
    ~RPN();

	class NotValidRPN : public std::exception
	{
		public:
		virtual const char* what() const throw();
	};

private:

	std::stack<int> _stack;
	std::stack<char> _input;
    RPN(const RPN& other);
    RPN& operator=(const RPN& rhs);
};

#endif // RPN_HPP
