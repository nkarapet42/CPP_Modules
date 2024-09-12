#include "contact.hpp"

void Contact::setContact(const std::string& firstName, const std::string& lastName,
						const std::string& nickname, const std::string& phoneNumber,
						const std::string& darkestSecret) {
	this->firstName = firstName;
	this->lastName = lastName;
	this->nickname = nickname;
	this->phoneNumber = phoneNumber;
	this->darkestSecret = darkestSecret;
}

void Contact::displaySummary(int index) const {
	std::cout << std::setw(10) << index << "|";
	std::cout << std::setw(10) << truncateField(firstName) << "|";
	std::cout << std::setw(10) << truncateField(lastName) << "|";
	std::cout << std::setw(10) << truncateField(nickname) << std::endl;
}

void Contact::displayContact() const {
	std::cout << "First Name: " << firstName << std::endl;
	std::cout << "Last Name: " << lastName << std::endl;
	std::cout << "Nickname: " << nickname << std::endl;
	std::cout << "Phone Number: " << phoneNumber << std::endl;
	std::cout << "Darkest Secret: " << darkestSecret << std::endl;
}

std::string Contact::truncateField(const std::string& field) const {
	if (field.length() > 10)
		return field.substr(0, 9) + ".";
	return field;
}