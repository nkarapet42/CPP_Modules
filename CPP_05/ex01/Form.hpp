#ifndef FORM_HPP
# define FORM_HPP

#include "Bureaucrat.hpp"

class	Form {

public:

	Form();
	Form(const std::string name, const int grade_s, const int grade_e );
	Form(const Form& other);
	Form& operator=(const Form& other); 
	~Form();

	const	std::string	getName() const ;
	bool				getIsSigned() const ;
	int					getGradeS()	const ;
	int					getGradeE()	const ;

	void				beSigned(Bureaucrat& loyal);

	class	GradeTooHighException : public std::exception {
		public:
			const char*	what() const throw();
	};
	class	GradeTooLowException : public std::exception {
		public:
			const char*	what() const throw();
	};

private:

	const	std::string name;
	bool				is_signed;
	const	int			grade_s;
	const	int			grade_e;

};

std::ostream& operator<<(std::ostream& os, const Form& point);

#endif