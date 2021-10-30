#include "PeriodicBoundaryCondition.h"
//#include "Types.h"

namespace CA
{
	PeriodicBoundaryCondition::PeriodicBoundaryCondition(GrainGrowth grainGrowth, UINT lengthX, UINT widthY, UINT heightZ)
		:m_lengthX(lengthX),
		 m_widthY(widthY),
		 m_heightZ(heightZ)
	{
		SetNeihborhoodStrategy(grainGrowth);
	}

	void PeriodicBoundaryCondition::SetNeihborhoodStrategy(GrainGrowth grainGrowth)
	{
		switch (grainGrowth)
		{
		case: GrainGrowth::VonNeumann
		{
			m_neighborhood = VonNeumannNeighborhood();
		}
		}
	}

	VecIndex3D PeriodicBoundaryCondition::SetIndexToNeighborhood(UINT const& x, UINT const& y, UINT const& z)
	{
		auto rawVecIndex3D = m_neighborhood.SetIndexToNeighborhood(x, y, z);

		//On periodic BC we set opposite number to set reference for cell on opposite side
		for (auto& index : rawVecIndex3D)
		{
			// x axis
			if (index[0] == -1)
			{
				index[0] = m_lengthX - 1;
			}
			else if (index[0] == m_lengthX)
			{
				index[0] = 0;
			}

			// y axis
			if (index[1] == -1)
			{
				index[1] = m_widthY - 1;
			}
			else if (index[1] == m_widthY)
			{
				index[1] = 0;
			}

			//z axis
			if (index[2] == -1)
			{
				index[2] = m_heightZ - 1;
			}
			else if (index[2] == m_heightZ)
			{
				index[2] = 0;
			}
		}

		return rawVecIndex3D;

	}
}