#include "VonNeumannNeighborhood.h"

namespace CA
{
	VecIndex3D VonNeumannNeighborhood::SetIndexToNeighborhood(UINT const& x, UINT const& y, UINT const& z)
	{
		return
		{
			{x-1,y,z},
			{x,y-1,z},
			{x,y,z-1},
			{x+1,y,z},
			{x,y+1,z},
			{x,y,z+1}
		};
	}

	VecIndex3D VonNeumannNeighborhood::GrainGrowth(UINT const& x, UINT const& y, UINT const& z)
	{
		//to do here algorithm
		return;
	}
}