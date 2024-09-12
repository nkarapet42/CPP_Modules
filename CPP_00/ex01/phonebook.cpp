#include "phonebook.hpp"

PhoneBook::PhoneBook() : count(0) {}

void PhoneBook::addContact(const Contact& contact) {
	if (count < MAX_CONTACTS) {
		contacts[count] = contact;
		count++;
	} else {
		for (int i = 1; i < MAX_CONTACTS; i++) {
			contacts[i - 1] = contacts[i];
		}
		contacts[MAX_CONTACTS - 1] = contact;
	}
}

void PhoneBook::displayContacts() const {
	std::cout << std::setw(10) << "Index" << "|"
				<< std::setw(10) << "First Name" << "|"
				<< std::setw(10) << "Last Name" << "|"
				<< std::setw(10) << "Nickname" << std::endl;
	for (int i = 0; i < count; i++) {
		contacts[i].displaySummary(i);
	}
}

void PhoneBook::displayContact(int index) const {
	if (index >= 0 && index < count) {
		contacts[index].displayContact();
	} else {
		std::cout << "Invalid index." << std::endl;
	}
}