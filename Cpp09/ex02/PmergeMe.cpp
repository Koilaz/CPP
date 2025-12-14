#include "PmergeMe.hpp"

static size_t get_pair_position(const std::vector<int> &vec, int pair);
static std::vector<int> get_jacobsthal(size_t max);

static std::size_t minimalComparisons(std::size_t n)
{
	if (n <= 1)
		return 0; // rien à comparer

	long double log2_fact = 0.0L;
	for (std::size_t k = 2; k <= n; ++k)
		log2_fact += std::log((long double)k) / std::log(2.0L);

	return static_cast<std::size_t>(std::ceil(log2_fact));
}

static std::size_t fordJohnsonComparisons(std::size_t n)
{
	if (n <= 1)
		return 0;

	std::size_t sum = 0;
	for (std::size_t k = 1; k <= n; ++k)
	{
		if (k == 1)
			sum += 0; // ⌈lg 1⌉ = 0
		else
		{
			double log2_k = std::log((double)k) / std::log(2.0);
			sum += static_cast<std::size_t>(std::ceil(log2_k));
		}
	}
	return sum;
}

static bool valid_str(char *str)
{
	int i = 0;
	while (str[i])
	{
		if (!isdigit(str[i]) && str[i] != ' ' && str[i] != '-')
			return false;
		i++;
	}
	return true;
}

static bool check_double(std::vector<int> vec)
{
	if (vec.size() < 2)
		return false;
	std::vector<int>::iterator it = vec.begin();
	sort(vec.begin(), vec.end());
	while (it != vec.end() - 1)
	{
		if (*it == *(it + 1))
			return false;
		it++;
	}
	return true;
}

void PmergeMe::str_to_vec(char *str)
{
	if (!valid_str(str))
		throw UnvalidInput("unvalid character");
	while (*str)
	{
		while (*str == ' ')
			str++;
		if (*str == '\0')
			break;
		char *end;
		double d = strtod(str, &end);
		if (d > INT_MAX || d < INT_MIN || end[0] == '-')
			throw UnvalidInput("int overflow");
		_initial_vec.push_back(static_cast<int>(d));
		if (str != end)
			str = end;
		else
			throw UnvalidInput("this one was tricky");
	}
	if (_initial_vec.size() < 2)
		throw UnvalidInput("Less than 2 number");
	if (!check_double(_initial_vec))
		throw UnvalidInput(" double input with same value");
	print_container(_initial_vec, "initial vector: ");
}

void PmergeMe::recursive_fj(std::vector<int> &main, std::vector<int> &tmp, size_t lvl)
{
	{
		print_container(tmp, "tmp :");
		std::cout<<"level = "<<lvl<<std::endl;
	}
	if (tmp.size() < lvl)
	{
		_jacobstahl = get_jacobsthal(tmp.size());
		main.insert(main.begin(), tmp[lvl / 2 - 1]);
		//Uncomment fot Description
		{
			std::cout<<"insert bigest = "<< tmp[lvl / 2 -1]<<std::endl;
			std::cout<<"\n End of phase 1 (comparing pairs)\n"<<std::endl;
			std::cout<<"calculating Jacobstahl list for "<<tmp.size()<<" element: "<<std::endl;
			print_container(_jacobstahl, "");
		}
		return;
	}
	for (std::vector<int>::iterator it = tmp.begin() + lvl - 1; it < tmp.end(); it += lvl)
	{
		if (less_cmp(*it, *(it - lvl / 2)))
		{
			for (size_t i = 0; i < lvl / 2; i++)
				std::iter_swap(it - lvl + 1 + i, it - lvl / 2 + 1 + i);
		}
	}
	recursive_fj(main, tmp, lvl * 2);
	insert(main, tmp, lvl);
	//Uncomment fot Description
	{
		print_container(main, "main :");
		std::cout << "level = " << lvl << std::endl;
	}
}

/*static size_t count_insert(std::vector<int> &tmp, size_t lvl)
{
	int count = 0;
	size_t step = lvl / 2;
	for(size_t pos = step; (pos - 1) < tmp.size(); pos = pos + step)
	{
		if(pos % lvl)
			count++;
	}
	return count;
}*/

static std::vector<int> get_jacobsthal(size_t max)
{
	size_t j = 1;
	int n = 2;

	std::vector<int> jac;
	jac.push_back(0);
	jac.push_back(1);
	while (j <= max)
	{
		j = jac[n - 1] + 2 * jac[n - 2];
		jac.push_back(j);
		n++;
	}
	return (jac);
}

std::vector<int> PmergeMe::insertion_order(int n)
{
	std::vector<int> order;
	order.push_back(0);
	order.push_back(1);
	int i = 1;
	for (std::vector<int>::iterator it = _jacobstahl.begin() + 2; it != _jacobstahl.end() && *(it - 1) < n; it++)
	{
		if (*it <= n)
			i = *it;
		else
			i = n;
		while (i > *(it - 1))
		{
			order.push_back(i);
			i--;
		}
	}
	return (order);
}

void PmergeMe::insert(std::vector<int> &main, std::vector<int> &tmp, size_t lvl)
{
	size_t step = lvl / 2;
	std::vector<int> to_insert;
	std::vector<int> paired_larger;

	for (size_t pos = step; (pos - 1) < tmp.size(); pos = pos + step)
	{
		if (pos % lvl)
		{
			to_insert.push_back(tmp[pos - 1]);
			paired_larger.push_back(tmp[pos + step - 1]);
		}
	}
	std::vector<int> insert_order = insertion_order(to_insert.size());
	std::vector<int>::iterator index = insert_order.begin() + 1;
	//Uncomment fot Description
	{
		print_container(insert_order, "insertion order: ");
		print_container(to_insert, "to insert :");
	}
	for (; index < insert_order.end(); index++)
	{
		int &value = to_insert[*index - 1];
		int &pair = paired_larger[*index - 1];
		binary_insertion(main, 0, get_pair_position(main, pair), value);
		//std::cout<<"inserting :"<<value<<std::endl;
	}
}

static size_t get_pair_position(const std::vector<int> &vec, int value)
{
	for (std::vector<int>::const_iterator it = vec.begin(); it != vec.end(); it++)
	{
		if (*it == value)
			return (it - vec.begin());
	}
	return vec.size();
}

bool PmergeMe::less_cmp(const int &a, const int &b)
{
	_comp_count++;
	return (a < b);
}

void PmergeMe::binary_insertion(std::vector<int> &vec, size_t begin, size_t end, int value)
{
	if (begin >= end)
	{
		vec.insert(vec.begin() + begin, value);
		return;
	}
	size_t mid = begin + (end - begin) / 2;
	if (less_cmp(value, vec[mid]))
		binary_insertion(vec, begin, mid, value);
	else
		binary_insertion(vec, mid + 1, end, value);
}

void PmergeMe::print_results()
{
	recursive_fj(_main, _initial_vec, 2);
	print_container(_main, "After main: ");
	std::cout<<"theorical minimum comparison in worst case :"<<minimalComparisons(_initial_vec.size())<<std::endl;
	std::cout<<"Ford Johnson number of comparisons in worst case :"<<fordJohnsonComparisons(_initial_vec.size())<<std::endl;
	std::cout << "comparison count : " << _comp_count << std::endl;
}

template <typename Container>
void PmergeMe::print_container(const Container &container, const std::string &label)
{
	typename Container::const_iterator it = container.begin();
	std::cout << label;
	while (it != container.end())
	{
		std::cout << *it << " ";
		it++;
	}
	std::cout << std::endl;
}

const char *PmergeMe::UnvalidInput::what() const throw()
{
	return _msg.c_str();
}

PmergeMe::UnvalidInput::UnvalidInput(std::string msg)
{
	_msg = "Error: Unvalid Input " + msg;
}

PmergeMe::UnvalidInput::~UnvalidInput() throw()
{
}

PmergeMe::PmergeMe() : _comp_count(0)
{
}

PmergeMe::PmergeMe(const PmergeMe &other)
{
	(void)other;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &src)
{
	if (this != &src)
	{
	}
	return *this;
}

PmergeMe::~PmergeMe()
{
}
