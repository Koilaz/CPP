#include "Base.hpp"

int main()
{
	int n = 10;
	Base *base[n];
	for(int i = 0; i < n; ++i)
	{
		base[i] = Base::generate();
		std::cout<<"\nidentify with pointer :"<<std::endl;
		Base::identify(base[i]);
		std::cout<<"identify with reference :"<<std::endl;
		Base::identify(base[i]);
		delete base[i];
	}
	return 0;
}
