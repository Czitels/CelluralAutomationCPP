#pragma once
#include <array>
#include <vector>
#include "boost/multi_array.hpp"

#include "Types.h"
namespace CA
{
	struct Cell;

	using Index3D = std::array<boost::multi_array<CA::Cell, 3>::index, 3>;
	using VecIndex3D = std::vector<Index3D>;

	struct Cell
	{
		static UINT ms_ID;

		Cell(UINT State = 0, UINT x = 0, UINT y = 0, UINT z = 0) :m_ID(ms_ID), m_State(State), m_x(x), m_y(y), m_z(z), m_Neighbors({ {0,0,0} }), full(false)
		{
			++ms_ID;
		}

		void SetNeighbors(VecIndex3D const& neighbors);

		bool full;
		UINT m_ID;
		UINT m_State;
		// TO.DO: change m_xyz to Index3D, solve instatiation fail
		UINT m_x;
		UINT m_y;
		UINT m_z;
		VecIndex3D m_Neighbors;	
	}; 
	UINT Cell::ms_ID = 0;
}