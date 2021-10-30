#include "Cell.h"

void CA::Cell::SetNeighbors(VecIndex3D const& neighbors)
{
	m_Neighbors.clear();
	m_Neighbors = neighbors;
}