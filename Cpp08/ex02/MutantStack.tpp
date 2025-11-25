template<typename T>
typename MutantStack<T>::iterator MutantStack<T>::end()
{
	return this->c.end();
}

template<typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin()
{
	return this->c.begin();
}


template<typename T>
MutantStack<T>::MutantStack() : std::stack<T>()
{

}
template<typename T>
MutantStack<T>::MutantStack(const MutantStack& other) : std::stack<T>(other)
{

}

template<typename T>
MutantStack<T>& MutantStack<T>::operator=(const MutantStack& src)
{
    if (this != &src)
	{
		*this = *src;
    }
    return *this;
}

template<typename T>
MutantStack<T>::~MutantStack()
{

}
