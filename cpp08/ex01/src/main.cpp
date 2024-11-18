#include <cstdlib>
#include <ctime>

#include "Span.hpp"

void fillSpanWithRandomNumbers(Span &span, int count)
{
	srand(time(0));
	for (int i = 0; i < count; ++i)
	{
		span.addNumber(rand());
	}
}

void fillSpanWithRangeNumbers(Span &span, int count)
{
	srand(time(0));
	for (int i = 0; i < count; ++i)
	{
		span.addNumber(i);
	}
}

void fillSequentialNumbers(Span &span, int start, int step, int count)
{
	for (int i = 0; i < count; ++i)
	{
		span.addNumber(start + i * step);
	}
}


int main()
{
	try
	{
		std::cout << "test 1: should shortest 2, longest 14" << std::endl;
		Span sp(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);

		std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;   // 2
		std::cout << "Longest span: " << sp.longestSpan() << std::endl;     // 14
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	

	try
	{
		std::cout << "\ntest 2: 0 ~ 9999, ranged, should shortest 1, longest 9999" << std::endl;

		Span span(10000);
		fillSpanWithRangeNumbers(span, 10000);
		std::cout << "Shortest span: " << span.shortestSpan() << std::endl;
		std::cout << "Longest span: " << span.longestSpan() << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	try
	{
		std::cout << "\ntest 3: 10000 of random numbers" << std::endl;

		Span span(10000);
		fillSpanWithRandomNumbers(span, 10000);
		std::cout << "Shortest span: " << span.shortestSpan() << std::endl;
		std::cout << "Longest span: " << span.longestSpan() << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	try
	{
		std::cout << "\ntest 4: 1 to 10000, should shortest 5, longest 49995" << std::endl;

		Span span(10000);
		fillSequentialNumbers(span, 1, 5, 10000);
		std::cout << "Shortest span: " << span.shortestSpan() << std::endl;
		std::cout << "Longest span: " << span.longestSpan() << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	try
	{
		std::cout << "\ntest 5: has 1 number: should KO" << std::endl;

		Span span(1);
		fillSpanWithRandomNumbers(span, 1);
		std::cout << "Shortest span: " << span.shortestSpan() << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	try
	{
		Span span(1);
		fillSpanWithRandomNumbers(span, 1);
		std::cout << "Longest span: " << span.longestSpan() << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	return (0);
}