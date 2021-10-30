// CAcpp.cpp : Defines the entry point for the application.
//

#include "CAcpp.h"

#include <array>
#include <random>

using namespace std;

int main()
{
	boost::multi_array<CA::Cell, 3> population(boost::extents[12][9][45]);
	//std::vector<std::array<boost::multi_array<CA::Cell, 3>::index, 3>> idxs = { {999999,9999,99999}, {99999,99999,9999} };
	//
	//for (unsigned i = 0; i != 12; ++i)
	//	for (unsigned j = 0; j != 9; ++j)
	//		for (unsigned k = 0; k != 45; ++k)
	//			idxs.push_back({ i,j,k });

	//std::cout << idxs[0][1];
	//for (auto& x : idxs)
	//{
	//	std::cout << population(x).m_ID << std::endl;
	//}

	std::random_device rd;
	std::mt19937 mt(rd());
	std::uniform_real_distribution<double> dist(1.0, 10.0);

	for (int i = 0; i < 16; ++i)
	{
		std::cout << dist(mt) << "\n";
		std::cout << dist(mt) << "\n";
		std::cout << dist(mt) << "\n";
	}

	cout << "Hello CMake." << endl;
	return 0;
}
