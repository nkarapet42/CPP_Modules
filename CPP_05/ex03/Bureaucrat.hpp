#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include <exception>

class	AForm;

class	Bureaucrat {

public:

	Bureaucrat();
	Bureaucrat(const std::string& name, const int grade);
	Bureaucrat(const Bureaucrat& other);
	Bureaucrat& operator=(const Bureaucrat& other); 
	~Bureaucrat();

	const	std::string getName() const ;
	int					getGrade() const ;

	void	incrementgrade();
	void	decrementgrade();

	void	signForm(AForm& form);

	void	executeForm(AForm const & form); 

	class	GradeTooHighException : public std::exception {
		public:
			const char*	what() const throw();
	};
	class	GradeTooLowException : public std::exception {
		public:
			const char*	what() const throw();
	};

private:

	const	std::string	name;
	int		grade;

};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& point);

#include "AForm.hpp"

#endif