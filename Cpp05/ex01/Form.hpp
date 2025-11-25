#ifndef FORM_HPP
#define FORM_HPP

#include<iostream>
#include<string>

class Bureaucrat;

class Form
{
public:

    Form();
	Form(const std::string name, int req_sign, int req_exec);
    Form(const Form& other);
    Form& operator=(const Form& rhs);
    ~Form();

	const std::string	getName()const;
	bool				is_signed() const;
	int					getReqSign() const;
	int					getReqExec() const;
	void				beSigned(Bureaucrat bur);

	class GradeTooHighException : public std::exception
	{
		public:
		virtual const char* what() const throw();
	};

	class GradeTooLowException : public std::exception
	{
		public:
		virtual const char* what() const throw();
	};


private:

	const std::string	_name;
	bool				_signed;
	const int			_req_sign;
	const int			_req_exec;
};

std::ostream &operator<<(std::ostream & os, Form const &bur);

#endif
