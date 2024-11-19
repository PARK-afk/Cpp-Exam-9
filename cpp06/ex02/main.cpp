#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base *generate(void) {
	std::srand(time(NULL));
	int num = std::rand() % 3;

	if (num == 0) return (new A);
	else if (num == 1) return (new B);
	else return (new C);
}

void identify(Base* p) {
	if (dynamic_cast<A *>(p)) {
		std::cout << "A point" << std::endl;
	} else if (dynamic_cast<B *>(p)) {
		std::cout << "B point" << std::endl;
	} else if (dynamic_cast<C *>(p)) {
		std::cout << "C point" << std::endl;
	} else {
		std::cout << "Unknown type" << std::endl;
	}
}

void identify(Base& p) {
	try
	{
		A& a = dynamic_cast<A&>(p);
		(void)a;
		std::cout << "ref A" << std::endl;
	}
	catch(const std::bad_cast&)
	{
		try
		{
			B& b = dynamic_cast<B&>(p);
			(void)b;
			std::cout << "ref B" << std::endl;
		}
		catch(const std::bad_cast&)
		{
			try
			{
				C& c = dynamic_cast<C&>(p);
				(void)c;
				std::cout << "ref C" << std::endl;
			}
			catch(const std::bad_cast&)
			{
				std::cout << "Unknown type" << std::endl;
			}
		}
	}
	
}

int main(){
	Base *random;
	A a;
	B b;
	C c;

	random = generate();
	identify(random);
    std::cout << std::endl;
	identify(NULL);
	std::cout << std::endl;
	identify(a);
	std::cout << std::endl;
	identify(b);
	std::cout << std::endl;
	identify(c);
	std::cout << std::endl;
	identify(*random);
	std::cout << std::endl;
	delete random;
	return (0);
}