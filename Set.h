#pragma once
template<typename T>

class Set
{
private:
	T* list;
	int capacity;
	int counter;

public:
	//Constructors
	Set();
	Set(int capacityInput);
	Set(const Set<T>& source);

	//Destructor
	~Set();

	//Operator Overloads
	Set<T>& operator=(const Set<T>& rhs);
	friend std::ostream& operator<<(std::ostream& os, const Set<T>& obj) {
		if (obj.counter == 0)
		{
			os << "{}";
		}
		else
		{
			os << "{";
			for (size_t i = 0; i < obj.counter; i++)
			{
				if (i != obj.counter - 1)
				{
					os << obj.list[i] << ", ";
				}
				else
				{
					os << obj.list[i] << "}";
				}

			}
		}
		return os;
	}
	friend std::istream& operator>>(std::istream& is, Set<T>& obj)
	{
		for (size_t i = obj.counter; i < obj.capacity; i++)
		{
			obj.list[i] = obj.list[i - 1] + 1;
			std::cout << i << ". Element: " << obj.list[i] << std::endl;
			obj.counter++;
		}
		return is;
	}
	Set<T> operator+(const Set<T> & rhs);
	Set<T> operator-(const Set<T>& rhs);
	bool operator==(const Set<T>& rhs);
	bool operator!=(const Set<T>& rhs);
	Set<T>& operator+=(const Set<T>& rhs);
	bool operator<(const Set<T>& rhs);

	//Other Methods
	void addElement(T elementInput);
	bool removeElement(T elementInput);
};

template<typename T>
inline Set<T>::Set()
	:list{nullptr}, capacity{10}, counter{0}
{
	list = new T[capacity];
}

template<typename T>
inline Set<T>::Set(int capacityInput)
	:list{nullptr}, capacity{capacityInput}, counter{0}
{
	list = new T[capacityInput];
}

template<typename T>
inline Set<T>::Set(const Set& source)
	:list{nullptr}, capacity{source.capacity}, counter{source.counter}
{
	list = new T[source.capacity];

	for (size_t i = 0; i < source.capacity; i++)
	{
		list[i] = source.list[i];
	}
}

template<typename T>
inline Set<T>::~Set()
{
	delete[] list;
}

template<typename T>
inline Set<T>& Set<T>::operator=(const Set<T>& rhs)
{
	if (this == &rhs)
	{
		return *this;
	}
	else
	{
		delete[] list;

		list = new T[rhs.capacity];
		capacity = rhs.capacity;
		counter = rhs.counter;

		for (size_t i = 0; i < rhs.capacity; i++)
		{
			list[i] = rhs.list[i];
		}

		return *this;
	}
}

template<typename T>
inline Set<T> Set<T>::operator+(const Set<T>& rhs)
{
	int counterSame{ 0 };
	for (size_t i = 0; i < counter; i++)
	{
		for (size_t j = 0; j < rhs.counter; j++)
		{
			if (list[i] == rhs.list[j])
			{
				counterSame++;
			}
		}
	}
	Set<T> tempSet{ counter + rhs.counter - counterSame };
	for (size_t i = 0; i < counter; i++)
	{
		tempSet.addElement(list[i]);
	}
	for (size_t i = 0; i < rhs.counter; i++)
	{
		tempSet.addElement(rhs.list[i]);
	}

	return tempSet;
}

template<typename T>
inline Set<T> Set<T>::operator-(const Set<T>& rhs)
{
	Set<T> diff{ *this };
	for (size_t i = 0; i < rhs.counter; i++)
	{
		diff.removeElement(rhs.list[i]);
	}
	return diff;
}

template<typename T>
inline bool Set<T>::operator==(const Set<T>& rhs)
{
	bool check = true;
	if (counter != rhs.counter)
	{
		check = false;
	}
	else
	{
		for (size_t i = 0; i < counter; i++)
		{
			if (list[i] != rhs.list[i])
				check = false;
		}
	}

	return check;
}

template<typename T>
inline bool Set<T>::operator!=(const Set<T>& rhs)
{
	if (*this == rhs)
	{
		return false;
	}
	else
		return true;
}

template<typename T>
inline Set<T>& Set<T>::operator+=(const Set<T>& rhs)
{
	*this = *this + rhs;
	return *this;
}

template<typename T>
inline bool Set<T>::operator<(const Set<T>& rhs)
{
	bool check{ false };
	for (size_t i = 0; i < counter; i++)
	{
		for (size_t j = 0; j < rhs.counter; j++)
		{
			if (list[i] != rhs.list[j])
			{
				check = true;
			}
		}
	}
	return check;
}

template<typename T>
inline void Set<T>::addElement(T elementInput)
{
	bool check{ false };

	for (size_t i = 0; i < counter; i++)
	{
		if (list[i] == elementInput)
		{
			check = true;
		}
	}
	if (!check)
	{
		list[counter] = elementInput;
		counter++;
	}
}

template<typename T>
inline bool Set<T>::removeElement(T elementInput)
{
	bool check{ false };
	for (size_t i = 0; i < counter; i++)
	{
		if (list[i] == elementInput)
		{
			check = true;

			for (size_t j = i; j < counter; j++)
			{
				list[j] = list[j + 1];
			}
			counter--;
		}
	}
	return check;
}
