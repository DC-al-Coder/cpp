#include "PmergeMe.hpp"
#include <iostream>
#include <algorithm>
#include <cmath>
#include <sstream>

PmergeMe::PmergeMe(){}

PmergeMe::PmergeMe(PmergeMe& ref)
 : origin(ref.origin), vctr(ref.vctr), lst(ref.lst), vstart(ref.vstart), vend(ref.vend), lstart(ref.lstart), lend(ref.lend)
{}

PmergeMe::~PmergeMe() {}

PmergeMe& PmergeMe::operator=(PmergeMe& ref)
{
	origin = ref.origin;
	vctr = ref.vctr;
	lst = ref.lst;
	vstart = ref.vstart;
	vend = ref.vend;
	lstart = ref.lstart;
	lend = ref.lend;
	return *this;
}

void	PmergeMe::run(int argc, char* argv[])
{
	try
	{
		parse(argc, argv);
		vstart = std::clock();
		mergeInsertVector(vctr);
		vend = std::clock();
		lstart = std::clock();
		mergeInsertList(lst);
		lend = std::clock();
		printResult();
		return ;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << '\n';
	}
}

void	PmergeMe::parse(int argc, char* argv[])
{
	if (argc < 2)
		throw PmergeMeException();
	for (size_t i = 1; i < static_cast<size_t>(argc); ++i)
	{
		std::stringstream	ss(argv[i]);
		int	n;
		ss >> n;
		if (n < 1 || ss.fail() || !ss.eof())
			throw PmergeMeException();
		origin.push_back(n);
		t_vect vec;
		vec.number = n;
		vctr.push_back(vec);
		t_list list;
		list.number = n;
		lst.push_back(list);
	}
}

void	PmergeMe::mergeInsertVector(std::vector<t_vect>& vctr)
{
	std::vector<t_vect> large;
	std::vector<t_vect> small;
	size_t n = vctr.size();
	if (n < 2)
		return ;
	for (size_t i = 0; i < (n / 2); ++i)
	{
		if (vctr[i].number > vctr[i + (n / 2)].number)
		{
			vctr[i].index_vect.push_back(i);
			large.push_back(vctr[i]);
			small.push_back(vctr[i + (n / 2)]);
		}
		else
		{
			vctr[i + (n / 2)].index_vect.push_back(i);
			small.push_back(vctr[i]);
			large.push_back(vctr[i + (n / 2)]);
		}
	}
	if (n % 2)
		small.push_back(vctr[n - 1]);

	mergeInsertVector(large);
	// adjust small according to large
	std::vector<t_vect> small_restored(small.size());
	size_t	largeindex;
	for (size_t i = 0; i < large.size(); i++)
	{
		largeindex = large[i].index_vect.back();
		large[i].index_vect.pop_back();
		small_restored[i] = small[largeindex];
	}
	if (small.size() != large.size())
		small_restored[small.size() - 1] = small.back();
	small = small_restored;

	vctr.clear();
	vctr.push_back(small[0]);
	for (std::vector<t_vect>::iterator it = large.begin(); it != large.end(); ++it)
		vctr.push_back(*it);

	//binary && insert
	size_t k = 3;
	while (jacobsthal(k - 1) < (n + 1) / 2)
	{
		size_t m = std::min(jacobsthal(k), (n + 1) / 2);
		size_t u = jacobsthal(k - 1) + m;
		for (size_t i = m; i != jacobsthal(k - 1); --i)
		{
			vctr.insert(std::lower_bound(vctr.begin(), vctr.begin() + u - 1, small[i - 1]), small[i - 1]);
			while (vctr[u - 1].number != large[i - 2].number && u != 0)
				u--;
		}
		k++;
	}
	return ;
}

void	PmergeMe::mergeInsertList(std::list<t_list>& lst)
{
	std::list<t_list> large;
	std::list<t_list> small;
	size_t n = lst.size();
	if (n < 2)
		return ;
	for (size_t i = 0; i < (n / 2); ++i)
	{
		if (lst.front().number > lst.back().number)
		{
			lst.front().index_list.push_back(i);
			large.push_back(lst.front());
			small.push_back(lst.back());
		}
		else
		{
			lst.back().index_list.push_back(i);
			large.push_back(lst.back());
			small.push_back(lst.front());
		}
		lst.pop_back();
		lst.pop_front();
	}
	if (n % 2)
		small.push_back(lst.front());

	mergeInsertList(large);
	// adjust small according to large
	std::list<t_list> small_restored(small.size());
	std::list<t_list>::iterator it_lst_large = large.begin();
	std::list<t_list>::iterator it_lst_small = small.begin();
	std::list<t_list>::iterator it_lst_small_restored = small_restored.begin();
	size_t	largeindex;
	for (size_t i = 0; i < large.size(); i++)
	{
		largeindex = it_lst_large->index_list.back();
		it_lst_large->index_list.pop_back();
		*it_lst_small_restored = *advanceListIter(small.begin(), largeindex);
		it_lst_large++;
		it_lst_small_restored++;
	}
	if (small.size() != large.size())
		small_restored.back() = small.back();
	small = small_restored;

	lst.clear();
	lst.push_back(small.front());
	for (std::list<t_list>::iterator it = large.begin(); it != large.end(); ++it)
		lst.push_back(*it);

	//binary && insert
	size_t k = 3;
	while (jacobsthal(k - 1) < (n + 1) / 2)
	{
		size_t m = std::min(jacobsthal(k), (n + 1) / 2);
		size_t u = jacobsthal(k - 1) + m;
		it_lst_large = advanceListIter(large.begin(), m - 2);
		it_lst_small = advanceListIter(small.begin(), m - 1);
		std::list<t_list>::iterator it_lst = advanceListIter(lst.begin(), u - 1);
		for (size_t i = m; i != jacobsthal(k - 1); --i)
		{
			std::list<t_list>::iterator lb = std::lower_bound(lst.begin(), it_lst, *it_lst_small);
			lst.insert(lb, *it_lst_small);
			while (it_lst->number != it_lst_large->number && u != 0)
			{
				u--;
				it_lst--;
			}
			it_lst_small--;
			it_lst_large--;
		}
		k++;
	}
	return ;
}

std::list<t_list>::iterator PmergeMe::advanceListIter(std::list<t_list>::iterator it, size_t n)
{
	std::advance(it, n);
	return it;
}

size_t	PmergeMe::jacobsthal(size_t k)
{
	return (std::pow(2, k) - std::pow(-1, k)) / 3;
}

void	PmergeMe::printResult()
{
	std::cout << "Before: ";
	for (size_t i = 0; i < origin.size(); ++i)
		std::cout << origin[i] << " ";
	std::cout << "\n";
	std::sort(origin.begin(), origin.end());
	std::cout << "After: ";
	for (size_t i = 0; i < vctr.size(); ++i)
		std::cout << vctr[i].number << " ";
	std::cout << "\n";
	std::list<t_list>::iterator it_lst = lst.begin();
	for (size_t i = 0; i < origin.size(); ++i)
	{
		if (origin[i] != vctr[i].number || origin[i] != it_lst->number)
			throw PmergeMeException();
		std::advance(it_lst, 1);
	}
	std::cout << "Time to process a range of " << origin.size() << " elements with std::vector : ";
	std::cout << (vend - vstart) * (CLOCKS_PER_SEC / 1000000) << "μs\n";
	std::cout << "Time to process a range of " << origin.size() << " elements with std::list : ";
	std::cout << (lend - lstart) * (CLOCKS_PER_SEC / 1000000) << "μs\n";
}

const char*	PmergeMe::PmergeMeException::what() const throw()
{
	return "Error";
}
