#include <iostream>
#include <list>

template <typename T>
void print_list(std::list<T> &lst)
{
	typename std::list<T>::iterator it = lst.begin();
	typename std::list<T>::iterator ite = lst.end();
	while (it != ite)
	{
		std::cout << *it << " | ";
		it++;
	}
	std::cout << std::endl;
	std::cout << std::endl;
}


// compare only integral part:
bool mycomparison(double first, double second)
{
	return (int(first) < int(second));
}


int main()
{
    std::list<double> first, second;

	first.push_back(3.1);
	first.push_back(2.2);
	first.push_back(2.9);

	second.push_back(3.7);
	second.push_back(7.1);
	second.push_back(1.4);

	first.sort();
	second.sort();

	first.merge(second);

	// (second is now empty)

	second.push_back(2.1);

	first.merge(second, mycomparison);

	std::cout << "first contains: ";
	print_list(first);
	std::cout << "secont contains: ";
	print_list(second);
    return 0;
}
