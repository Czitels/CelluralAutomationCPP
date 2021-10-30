#include "INeighborhood.h"

namespace CA
{
	class IBoundaryCondition
	{
	public:
		virtual ~IBoundaryCondition() = 0;
		virtual VecIndex3D SetIndexToNeighborhood(UINT const& x, UINT const& y, UINT const& z) = 0;
	};
}