#ifndef AFORM_HPP
# define AFORM_HPP

#include "Bureaucrat.hpp"

class	AForm {

public:

	AForm();
	AForm(const std::string name, const int grade_s, const int grade_e );
	AForm(const AForm& other);
	AForm& operator=(const AForm& other); 
	virtual	~AForm();

	const	std::string	getName() const ;
	bool				getIsSigned() const ;
	int					getGradeS()	const ;
	int					getGradeE()	const ;

	void				beSigned(Bureaucrat& loyal);
	void				execute(Bureaucrat const & executor) const;

	class	GradeTooHighException : public std::exception {
		public:
			const char*	what() const throw();
	};
	class	GradeTooLowException : public std::exception {
		public:
			const char*	what() const throw();
	};
	class	ExecuteUnsignedForm : public std::exception {
		public:
			const char*	what()	const throw();
	}

private:

	const	std::string name;
	bool				is_signed;
	const	int			grade_s;
	const	int			grade_e;

};

std::ostream& operator<<(std::ostream& os, const AForm& point);

#endif