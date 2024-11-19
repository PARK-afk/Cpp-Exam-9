#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>
# include <ctime>
# include <cstdlib>

template <typename T>
class Array
{
	private:
		T *Data;
		unsigned int size;
	public:
		Array() : size(0), Data(new T[size]) {}
		explicit Array(unsigned int n) : Data(new T[n]), size(n) {}
		
		Array(Array const &other) : size(other.size)
		{
			Data = new T[size];
			for (unsigned int i = 0; i < size; i++) {
				Data[i] = other.Data[i];
			}
		}
		
		Array &operator=(Array const &other)
		{
			if (this != other) {
				delete[] Data;
				size = other.size;
				Data = new T[size];
				for (unsigned int i = 0; i < size; i++) {
					Data[i] = other.Data[i];
				}
			}
			return (*this);
		}
		
		
		T &operator[](unsigned int n) const
		{
			if (n >= size) {
				throw std::out_of_range("Index out of Bound");
			}
			return (Data[n]);
		}
		
		
		unsigned int getSize()
		{
			return (this->size);
		}
		
		~Array()
		{
			delete[] Data;
		}
};

#endif
