# include "phonebook.hpp"

bool isDigit(char c) {
    return (c >= '0' && c <= '9');
}

bool isLetter(char c) {
    return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}

void	addContact(PhoneBook& phoneBook) {
	std::string FirstName, LastName, NickName, PhoneNum, DarkSec;
	int			flag;

	while (1)
	{
		flag = 0;
		std::cout << "Enter FirstName" << std::endl;
		std::getline(std::cin, FirstName);
		for(size_t i = 0; i < FirstName.size();i++)
		{
			if (!isLetter(FirstName[i]))
			{
				std::cout << "The FirstName must contain only letter" << std::endl;
				flag = 1;
				break ;
			}
		}
		if (flag == 0)
			break ;
	}
	while (1)
	{
		flag = 0;
		std::cout << "Enter LastName" << std::endl;
		std::getline(std::cin, LastName);
		for(size_t i = 0; i < LastName.size();i++)
		{
			if (!isLetter(LastName[i]))
			{
				std::cout << "The LastName must contain only letters" << std::endl;
				flag = 1;
				break ;
			}
		}
		if (flag != 1)
			break ;
	}
	std::cout << "Enter NickName" << std::endl;
	std::getline(std::cin, NickName);
	while (1)
	{
		flag = 0;
		std::cout << "Enter PhoneNum" << std::endl;
		std::getline(std::cin, PhoneNum);
		for(size_t i = 0; i < PhoneNum.size();i++)
		{
			if (!isDigit(PhoneNum[i]))
			{
				std::cout << "The Number must contain only digits" << std::endl;
				flag = 1;
				break ;
			}
		}
		if (flag != 1)
			break ;
	}
	std::cout << "Enter DarkSec" << std::endl;
	std::getline(std::cin, DarkSec);

	if (FirstName.empty() || LastName.empty() || NickName.empty()
		|| PhoneNum.empty() || DarkSec.empty()) {
		std::cout << "There is empty blank" << std::endl;
		return ;
	}

	Contact contacts;

	contacts.setContact(FirstName,LastName,NickName,PhoneNum,DarkSec);
	phoneBook.addContact(contacts);
}	

void	searchContact(const PhoneBook& phoneBook) {
	int index;

	phoneBook.displayContacts();
	std::cout << "Enter the index of the contact to display: ";
	std::cin >> index;
	std::cin.ignore();
	phoneBook.displayContact(index);
}

int	main(void) {
	PhoneBook phoneBook;
	std::string command;

	while (1)
	{
		std::cout << "Enter command (ADD, SEARCH, EXIT): ";
		std::getline(std::cin, command);

		if (command == "ADD")
			addContact(phoneBook);
		else if (command == "SEARCH")
			searchContact(phoneBook);
		else if (command == "EXIT")
			break;
		else
			std::cout << "Invalid command." << std::endl;
	}
	return (0);
}