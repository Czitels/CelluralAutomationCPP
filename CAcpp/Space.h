#include "Cell.h"
#include "Neighborhood/interface/IBoundaryCondition.h"

namespace CA
{
	class Space
	{
	public:
		struct Grain
		{
			Index3D index;
			UINT type;
		};

		Space(BoundaryConditions boundaryConditions, GrainGrowth grainGrowth, UINT lengthX, UINT widthY, UINT heightZ);
		void SetBoundaryCondition(BoundaryConditions boundaryConditions, GrainGrowth grainGrowth, UINT lengthX, UINT widthY, UINT heightZ);
		void RandomNucleation(UINT amountNucleos, UINT amountOfDifferentGrains);
		void GrainGrowth();
	private:
		UINT m_lengthX;
		UINT m_widthY;
		UINT m_heightZ;
		ULLINT m_amountOfCells;
		boost::multi_array<Cell, 3> m_population;
		std::vector<Grain> m_initialNucleos;
		std::unique_ptr<IBoundaryCondition> m_ptrBoundaryCondition;
		std::shared_ptr<INeighborhood> m_ptrNeighborhood;
	};
}