
template<typename T>
Array<T>::Array() : array(NULL), size(0) {
	std::cout << "Default constructor was called" << std::endl;
}

template<typename T>
Array<T>::Array(unsigned int n) : size(n) {
	std::cout << "Constructor with parameter was called" << std::endl;
	if (n == 0)
		array = NULL;
	else {
		array = new T[n];
		for (size_t i = 0; i < size; i++)
			array[i] = T();
	}
}

template<typename T>
Array<T>::Array(const Array& other) : size(other.size) {
	std::cout << "Copy constructor was called" << std::endl;
	if (other.size == 0)
		array = NULL;
	else {
		array = new T[other.size];
		for (size_t i = 0; i < other.size; i++)
			array[i] = other.array[i];
	}
}

template<typename T>
Array<T>&	Array<T>::operator=(const Array& other) {
	std::cout << "Assignment operator was called" << std::endl;
	if (this != &other) {
		delete[] array;
		size = other.size;
		if (other.size == 0)
			array = NULL;
		else {
			array = new T[other.size];
			for (size_t i = 0; i < other.size; i++)
				array[i] = other.array[i];
		}
	}
	return (*this);
}

template<typename T>
T& Array<T>::operator[](size_t index) {
	if (index >= ArraySize())
		throw std::out_of_range("Index is out of bounds");
	return (array[index]);
}

template<typename T>
const T& Array<T>::operator[](size_t index) const {
	std::cout<<"dad"<<std::endl;
	if (index >= ArraySize())
		throw std::out_of_range("Index is out of bounds");
	return (array[index]);
}

template<typename T>
size_t	Array<T>::ArraySize() const {
	if (!array)
		return (0);
	return (size);
}

template<typename T>
Array<T>::~Array() {
	std::cout << "Destructor was called" << std::endl;
	delete[] array;
	array = NULL;
}