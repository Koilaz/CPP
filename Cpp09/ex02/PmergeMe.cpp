#include "PmergeMe.hpp"

template <typename Container>
static size_t 		get_pair_position(const Container &vec, int pair);
template <typename container>
static container 	get_jacobsthal(size_t max);
template <typename Container>
static void 		print_container(const Container &container, const std::string &label);
static std::size_t	minimalComparisons(std::size_t n);
static std::size_t	fordJohnsonComparisons(std::size_t n);
static bool 		valid_str(char *str);
static bool 		check_double(std::vector<int> vec);
static bool 		check_sorted(std::vector<int> vec);
static bool 		check_sorted_deque(std::deque<int> deq);

void PmergeMe::how_long_johnson()
{
	std::vector<int> copy_vector(_initial_vec);
	_comp_count = 0;
	clock_t start = clock();
	ford_johnson_vector(_main_vector, copy_vector, 2);
	clock_t end = clock();
	_elapsed_vector = (end - start) * 1000000 / CLOCKS_PER_SEC;
	int vector_comparisons = _comp_count;
	
	std::deque<int> copy_deque(_initial_vec.begin(), _initial_vec.end());
	_comp_count = 0;
	start = clock();
	ford_johnson_deque(_main_deque, copy_deque, 2);
	end = clock();	
	_elapsed_deque = (end - start) * 1000000 / CLOCKS_PER_SEC;
	int deque_comparisons = _comp_count;
	
	print_results(vector_comparisons, deque_comparisons);
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
}

void PmergeMe::ford_johnson_vector(std::vector<int> &main, std::vector<int> &tmp, size_t lvl)
{
	if (lvl > tmp.size())
	{
		main.insert(main.begin(), tmp[lvl / 2 - 1]);
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
	ford_johnson_vector(main, tmp, lvl * 2);
	insert(main, tmp, lvl);
}

void PmergeMe::ford_johnson_deque(std::deque<int> &main, std::deque<int> &tmp, size_t lvl)
{
	if (lvl > tmp.size())
	{
		main.insert(main.begin(), tmp[lvl / 2 - 1]);
		return;
	}
	for (std::deque<int>::iterator it = tmp.begin() + lvl - 1; it < tmp.end(); it += lvl)
	{
		if (less_cmp(*it, *(it - lvl / 2)))
		{
			for (size_t i = 0; i < lvl / 2; i++)
				std::iter_swap(it - lvl + 1 + i, it - lvl / 2 + 1 + i);
		}
	}
	ford_johnson_deque(main, tmp, lvl * 2);
	insert(main, tmp, lvl);
}

template <typename container>
void PmergeMe::insert(container &main, container &tmp, size_t lvl)
{
	size_t step = lvl / 2;
	container to_insert;
	container paired_larger;
	container unpaired;

	for (size_t pos = step; (pos - 1) < tmp.size(); pos = pos + step)
	{
		if (pos % lvl)
		{
			if (pos + step - 1 < tmp.size())
			{
				to_insert.push_back(tmp[pos - 1]);
				paired_larger.push_back(tmp[pos + step - 1]);
			}
			else
			{
				unpaired.push_back(tmp[pos - 1]);
			}
		}
	}
	container insert_order = insertion_order<container>(to_insert.size());
	typename container::iterator index = insert_order.begin() + 1;
	for (; index < insert_order.end(); index++)
	{
		int &value = to_insert[*index - 1];
		int &pair = paired_larger[*index - 1];
		binary_insertion(main, 0, get_pair_position(main, pair), value);
	}
	for (typename container::iterator it = unpaired.begin(); it != unpaired.end(); ++it)
	{
		binary_insertion(main, 0, main.size(), *it);
	}
}

template <typename container>
static container get_jacobsthal(size_t max)
{
	size_t j = 1;
	int n = 2;

	container jac;
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

template <typename container>
container PmergeMe::insertion_order(int n)
{
	container order;
	order.push_back(0);
	order.push_back(1);
	container jacobsthal = get_jacobsthal<container>(n);
	int i = 1;
	for (typename container::iterator it = jacobsthal.begin() + 2; it != jacobsthal.end() && *(it - 1) < n; it++)
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

template <typename container>
static size_t get_pair_position(const container &vec, int value)
{
	typename container::const_iterator it = vec.begin();
	size_t position = 0;
	while (it != vec.end())
	{
		if (*it == value)
			return position;
		++it;
		++position;
	}
	return vec.size();
}

bool PmergeMe::less_cmp(const int &a, const int &b)
{
	_comp_count++;
	return (a < b);
}

template <typename container>
void PmergeMe::binary_insertion(container &vec, size_t begin, size_t end, int value)
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

void PmergeMe::print_results(int vector_comparisons, int deque_comparisons)
{
	print_container(_initial_vec, "Initial input :");
	std::cout<<"theorical minimum comparison in worst case :"<<minimalComparisons(_initial_vec.size())<<std::endl;
	std::cout<<"Ford Johnson number of comparisons in worst case :"<<fordJohnsonComparisons(_initial_vec.size())<<std::endl;

	std::cout<<"##Ford Johnson Algorithm using vector<int> result##"<<std::endl;
	std::cout << "comparison count : " << vector_comparisons << std::endl;
	std::cout <<"Time elapsed: "<<_elapsed_vector<<" µs"<<std::endl;
	print_container(_main_vector, "Sorted output :");
	if(_main_vector.size() != _initial_vec.size() || !check_sorted(_main_vector))
		std::cout << "Error: vector size mismatch or not sorted!" << std::endl;
	else
		std::cout << "\033[32m✓ Vector sorted successfully with correct size.\033[0m" << std::endl;
	std::cout<<std::endl;

	std::cout<<"##Ford Johnson Algorithm using deque<int> result##"<<std::endl;
	std::cout << "comparison count : " << deque_comparisons << std::endl;
	std::cout <<"Time elapsed: "<<_elapsed_deque<<" µs\n"<<std::endl;
	print_container(_main_deque, "Sorted output :");
	if(_main_deque.size() != _initial_vec.size() || !check_sorted_deque(_main_deque))
		std::cout << "Error: deque size mismatch or not sorted!" << std::endl;
	else
		std::cout << "\033[32m✓ Deque sorted successfully with correct size.\033[0m" << std::endl;
}

template <typename Container>
static void print_container(const Container &container, const std::string &label)
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

static bool check_sorted(std::vector<int> vec)
{
	if (vec.size() < 2)
		return true;
	std::vector<int>::iterator it = vec.begin();
	while (it != vec.end() - 1)
	{
		if (*it > *(it + 1))
			return false;
		it++;
	}
	return true;
}

static bool check_sorted_deque(std::deque<int> deq)
{
	if (deq.size() < 2)
		return true;
	std::deque<int>::iterator it = deq.begin();
	while (it != deq.end() - 1)
	{
		if (*it > *(it + 1))
			return false;
		it++;
	}
	return true;
}

static std::size_t minimalComparisons(std::size_t n)
{
	if (n <= 1)
		return 0;

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
		if (k != 1)
		{
			double log2_k = std::log((double)k) / std::log(2.0);
			sum += static_cast<std::size_t>(std::ceil(log2_k));
		}
	}
	return sum;
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
