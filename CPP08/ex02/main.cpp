#include "MutantStack.hpp"
#include <iostream>
#include <algorithm>
#include <list>
#include <limits>

int main()
{
	std::cout << "Test from subject:" << std::endl;
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << "	Mutant stack top: " << mstack.top() << std::endl;
	mstack.pop();
	std::cout << "	Mutant stack size: " << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(737 * 737);
	mstack.push( std::numeric_limits<int>::max());
	mstack.push( std::numeric_limits<int>::min());
	mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
	std::cout << "	Current iterator value: " << *it << std::endl;
	++it;
	}
	std::stack<int> s(mstack);

	std::cout << "Same tests but with list instead of stack:" << std::endl;
	std::list<int> mlist;
	mlist.push_back(5);
	mlist.push_back(17);
	std::cout << "	List top: " << mlist.back() << std::endl;
	mlist.pop_back();
	std::cout << "	List size: " << mlist.size() << std::endl;
	mlist.push_back(3);
	mlist.push_back(5);
	mlist.push_back(737);
	mlist.push_back(737 * 737);
	mlist.push_back( std::numeric_limits<int>::max());
	mlist.push_back( std::numeric_limits<int>::min());
	mlist.push_back(0);
	std::list<int>::iterator lit = mlist.begin();
	std::list<int>::iterator lite = mlist.end();
	++lit;
	--lit;
	while (lit != lite)
	{
		std::cout << "	Current iterator value: " << *lit << std::endl;
		++lit;
	}
	return 0;
}