#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <climits>
#include <stdlib.h>
#include <algorithm>
#include <cmath>
#include <cstddef>
#include <deque>
#include <ctime>

class PmergeMe
{
public:

	void str_to_vec(char *str);
	void how_long_johnson();
	void print_results(int vector_comparisons, int deque_comparisons);

	PmergeMe();
	PmergeMe(const PmergeMe &other);
	PmergeMe &operator=(const PmergeMe &rhs);
	~PmergeMe();

	class UnvalidInput : public std::exception
	{
		public:
		virtual const char* what() const throw();
		UnvalidInput(std::string msg);
		virtual ~UnvalidInput() throw();

		private:
		std::string _msg;
	};

private:
	
	void ford_johnson_vector(std::vector<int> &main, std::vector<int> &tmp, size_t level);
	void ford_johnson_deque(std::deque<int> &main, std::deque<int> &tmp, size_t level);
	bool less_cmp(const int &a, const int &b);
	int	_comp_count;

	std::vector<int> 	_initial_vec;

//Template functions
	template <typename container>
	void				insert(container &main, container &tmp, size_t lvl);
	template <typename container>
	void 				binary_insertion(container& vec, size_t begin, size_t end, int value);
	template <typename container>
	container			insertion_order(int n);
//deque

	std::deque<int>		_jacobstahl_deque;
	long long			_elapsed_deque;
	std::deque<int>		_main_deque;
//vector
	std::vector<int>	_jacobstahl_vector;
	std::vector<int>	_main_vector;
	long long 			_elapsed_vector;
};

#endif
