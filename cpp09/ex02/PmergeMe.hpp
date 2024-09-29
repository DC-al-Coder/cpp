#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <vector>
# include <list>
# include <exception>
# include <ctime>

typedef struct s_vect
{
	int	number;
	std::vector<size_t> index_vect;
	bool operator<(const s_vect& other) const
	{
		return number < other.number;
    }
}	t_vect;

typedef struct s_list
{
	int	number;
	std::list<size_t> index_list;
	bool operator<(const s_list& other) const
	{
		return number < other.number;
    }
}	t_list;

class PmergeMe
{
public:
	PmergeMe();
	PmergeMe(PmergeMe& ref);
	~PmergeMe();
	PmergeMe& operator=(PmergeMe& ref);

	void						run(int argc, char* argv[]);
	void						parse(int argc, char* argv[]);
	void						mergeInsertVector(std::vector<t_vect>&);
	void						mergeInsertList(std::list<t_list>&);
	std::list<t_list>::iterator	advanceListIter(std::list<t_list>::iterator it, size_t n);
	size_t						jacobsthal(size_t k);
	void						printResult();

	class PmergeMeException : public std::exception
	{
	public:
		virtual const char*	what() const throw();
	};

private:
	std::vector<int>	origin;
	std::vector<t_vect>	vctr;
	std::list<t_list>	lst;
	std::clock_t		vstart;
	std::clock_t		vend;
	std::clock_t		lstart;
	std::clock_t		lend;
};

#endif
