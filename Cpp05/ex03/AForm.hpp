#ifndef FORM_HPP
#define FORM_HPP

#include<iostream>
#include<string>

class Bureaucrat;

class AForm
{
public:

    AForm();
	AForm(const std::string name, int req_sign, int req_exec);
    AForm(const AForm& other);
    AForm& operator=(const AForm& rhs);
    virtual ~AForm();

	virtual void		execute(Bureaucrat const &executor) const = 0;
	void				allow_exec(Bureaucrat const &executor) const;
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
	class FormNotSignedException : public std::exception
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

std::ostream &operator<<(std::ostream & os, AForm const &bur);

#endif
