#include "INeighborhood.h"

namespace CA
{
	class VonNeumannNeighborhood: public INeighborhood
	{
	public:
		~INeighborhood() {}
		VecIndex3D SetIndexToNeighborhood(UINT const& x, UINT const& y, UINT const& z);
		VecIndex3D GrainGrowth(UINT const& x, UINT const& y, UINT const& z);
	};
}