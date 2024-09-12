#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "contact.hpp"

#define MAX_CONTACTS 8

class PhoneBook {

public:

	PhoneBook();

	void	addContact(const Contact& contact);
	void	displayContact(int index) const;
	void	displayContacts() const;

private:

	Contact	contacts[MAX_CONTACTS];
	int		count;

};

#endif