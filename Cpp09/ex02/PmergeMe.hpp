#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <climits>
#include <stdlib.h>
#include <algorithm>
#include <cmath>
#include <cstddef>

typedef struct pair
{
	int b;
	int s;
} pair;

class PmergeMe
{
public:

	void str_to_vec(char *str);
	void print_results();
	template<typename Container>
	void print_container(const Container& container, const std::string& label);
	std::vector<int>insert_small(std::vector<int> &small, std::vector<int> &big);
	void recursive_fj(std::vector<int> &main, std::vector<int> &tmp, size_t level);

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

	void insert(std::vector<int> &main, std::vector<int> &tmp, size_t lvl);
	bool less_cmp(const int &a, const int &b);
	void binary_insertion(std::vector<int>& vec, size_t begin, size_t end, int value);
	std::vector<int> insertion_order(int n);
	int	_comp_count;
	std::vector<int> _initial_vec;
	std::vector<int> _tmp;
	std::vector<int> _main;
	std::vector<int> _jacobstahl;
};

#endif // PMERGEME_HPP
