#include "BitcoinExchange.hpp"
#include <exception>
#include <iostream>

BitcoinExchange::BitcoinExchange(){};

BitcoinExchange::~BitcoinExchange(){};

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other): input(other.input), database(other.database){}

BitcoinExchange	&BitcoinExchange::operator=(const BitcoinExchange &other)   {
	if (this != &other) {
    	this->input = other.input;
	    this->database = other.database;
    }
    return (*this);
}

static bool isLeapYear(int year) {
	return (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));
}

bool BitcoinExchange::isValidDate(const std::string &date)  {
	int year, month, day;
	if (sscanf(date.c_str(), "%4d-%2d-%2d", &year, &month, &day) != 3) {
		return false;
	}
	if (month < 1 || month > 12 || day < 1 || year == 0) {
		return false;
	}
	switch (month) {
		case BitcoinExchange::February:
			return (day <= (isLeapYear(year) ? 29 : 28));
		case BitcoinExchange::April: 
		case BitcoinExchange::June:
		case BitcoinExchange::September:
		case BitcoinExchange::November:
			return (day <= 30);
		default:
			return (day <= 31);
	}
}

static bool isValidFloat(const std::string& str) {
	std::stringstream ss(str);
	double x;
	ss >> x;
	return ss.eof() && !ss.fail();
}

static bool isValidDateFormat(std::string &date) {
	if (date.length() != 10)
		return false;
	for (size_t i = 0; i < date.size(); ++i) {
		if ((i == 4 || i == 7)) {
			if (date[i] != '-')
				return false;
		}
		else {
			if (!isdigit(date[i]))
				return false;
		}
	}
	return true;
}

static double stringToDouble(const std::string& str) {
	std::stringstream ss(str);
	double result;

	ss >> result;
	if (ss.fail())
		return -1;
	return result;
}

BitcoinExchange::BitcoinExchange(const std::string &filename): input(filename)    {
	std::ifstream   datafile("data.csv");
	if(!datafile)
		exit (1 && (std::cout << "Error: could not find data.csv" << std::endl));
	std::string header;
	if (!getline(datafile, header))
		exit (1 && (std::cout << "Error: data.csv or file is empty" << std::endl));
	std::string     line;
	while (getline(datafile, line)) {
		size_t      delim_position = line.find(',');
		if (delim_position == std::string::npos)
			exit (1 && (std::cout << "Error: invalid data format in data.csv." << std::endl));
		std::string     date = line.substr(0, delim_position);
		if (!isValidDateFormat(date)|| !isValidDate(date))
			exit(1 && (std::cout << "Error: not valid date: " << line << std::endl));
		std::string		price_value = line.substr(delim_position + 1);
		if (!isValidFloat(price_value))
			exit(1 && (std::cout << "Error: not valid price: " << price_value << std::endl));
		double  price = stringToDouble(price_value);
		if (price < 0)
			exit(1 && (std::cout << "Error: price can't be negative: " << price_value << std::endl));
		this->database[date] = price;
	}
	datafile.close();
}

void    BitcoinExchange::exchange()   {

	std::ifstream   infile(this->input);
	if (!infile.is_open())
		exit (1 && (std::cout << "Error: could not open file: " << this->input << std::endl));
	std::string line;
	if (!getline(infile, line))
		exit(1 && std::cout << "Error: input file is empty" << std::endl);

	if (line != "date | value")
		exit(1 && std::cout << "Error: invalid or missing input file header" << std::endl);
	while (getline(infile, line))
	{
		if (line.empty())
			continue;
		size_t	delim_position = line.find('|');
		if (delim_position == std::string::npos) {
			std::cout << "Error: bad input: [" << line << "]" << std::endl;
			continue ;  
		}
		std::string     data = line.substr(0, delim_position - 1);
		if (!isValidDateFormat(data) || !isValidDate(data)) {
			std::cout << "Error: invalid date format: " << data << std::endl;
			continue;
		}
		std::string earliestDate = this->database.begin()->first;
		if (data < earliestDate) {
			std::cout << "Error: no info for date " << data << std::endl;
			continue;
		}
		std::string     value = line.substr(delim_position + 2);
		try {
			double  price = stringToDouble(value);
			if (price < 0 || price > 1000) {
				std::cout << "Error: values should be in range [0-1000] not: " << value << "\n";
				continue;
			}
			std::map<std::string, double>::iterator current_price = this->database.lower_bound(data);
			if (current_price == this->database.end()) {
				--current_price;
			}
			else if (current_price != this->database.begin() && current_price->first != data){
				std::map<std::string, double>::iterator prevIt = current_price;
				--prevIt;
				--current_price;
				if ((data.compare(current_price->first) - data.compare(prevIt->first)) > 0)
					current_price = prevIt;             
			}
			std::cout << data << "=> " << value << " = " << price * current_price->second << std::endl;
		} catch (const std::exception& e) {
			std::cout << "Error: bad input " << line << std::endl;
		}
	}
	infile.close();
}