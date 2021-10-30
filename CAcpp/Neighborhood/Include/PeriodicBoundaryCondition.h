#include "IBoundaryCondition.h"

namespace CA
{
	class PeriodicBoundaryCondition : public IBoundaryCondition
	{
	public:
		PeriodicBoundaryCondition(GrainGrowth grainGrowth, UINT lengthX, UINT widthY, UINT heightZ);
		void SetNeihborhoodStrategy(GrainGrowth grainGrowth);
		VecIndex3D SetIndexToNeighborhood(UINT const& x, UINT const& y, UINT const& z);
	private:
		UINT m_lengthX;
		UINT m_widthY;
		UINT m_heightZ;
		INeighborhood m_neighborhood;
	};
}