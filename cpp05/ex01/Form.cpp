#include "Form.hpp"

Form::Form(std::string const & name, int const grade_to_sign, int const grade_to_exec) : _signature(false), _name(name), _grade_to_sign(grade_to_sign), _grade_to_exec(grade_to_exec) {
	try {
		if (grade_to_sign < 1 || grade_to_exec < 1)
			throw GradeTooHighException();
		if (grade_to_sign > 150 || grade_to_exec > 150)
			throw GradeTooLowException();
	}
	catch (GradeTooHighException& H) {
		std::cout << H.what() << std::endl;
	}
	catch (GradeTooLowException& L) {
		std::cout << L.what() << std::endl;
	}
}

Form::~Form(void) {
}

Form::Form(const Form &cpy) : _name(cpy._name), _grade_to_sign(cpy._grade_to_sign), _grade_to_exec(cpy._grade_to_exec) {
	*this = cpy;
}

Form&	Form::operator=(const Form &a) {
	_signature = a._signature;
	return (*this);
}

bool			Form::getSignature() const {
	return (_signature);
}

std::string const &	Form::getName() const {
	return (_name);
}

int				Form::getGradetoSign() const {
	return (_grade_to_sign);
}

int				Form::getGradetoExec() const {
	return (_grade_to_exec);
}

void			Form::beSigned(Bureaucrat &B) {
	try {
		if (B.getGrade() > _grade_to_sign) {
			throw GradeTooLowException();
		}
	}
	catch (GradeTooLowException& L) {
		return ;
	}
	_signature = true;
}

std::ostream&	operator<<(std::ostream &o, Form const &i) {
	o << "Form " << i.getName() << ", grade required to sign: " << i.getGradetoSign() << " - grade required to execute: " << i.getGradetoExec();
	return (o);
}