#include "Cell.h"

namespace CA
{
	class INeighborhood
	{
	public:
		virtual ~INeighborhood() = 0;
		virtual VecIndex3D SetIndexToNeighborhood(UINT const& x, UINT const& y, UINT const& z) = 0;
	};
}