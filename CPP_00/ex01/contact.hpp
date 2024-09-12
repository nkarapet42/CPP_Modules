#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <iostream>
#include <iomanip>
#include <string>

class Contact {

public:

	void setContact(const std::string& firstName, const std::string& lastName,
					const std::string& nickname, const std::string& phoneNumber,
					const std::string& darkestSecret);
	void displaySummary(int index) const;
	void displayContact() const;

private:

	std::string firstName;
	std::string lastName;
	std::string nickname;
	std::string phoneNumber;
	std::string darkestSecret;
	std::string truncateField(const std::string& field) const;

};

#endif