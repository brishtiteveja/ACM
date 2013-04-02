//============================================================================
// Name        : Boost.cpp
// Author      : Dhrubo Abdullah Khan
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <boost/lambda/lambda.hpp>
#include <iostream>
#include <iterator>
#include <algorithm>

using namespace std;

int main()
{
    using namespace boost::lambda;
    typedef std::istream_iterator<int> in;

//    std::for_each(in(std::cin), in(), std::cout << (_1 * 2) << " " );
}
