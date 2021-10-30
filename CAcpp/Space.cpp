#include <memory>
#include <random>

#include "Space.h"
#include "VonNeumannNeighborhood.h"

namespace CA
{
	CA::Space::Space(BoundaryConditions boundaryConditions, GrainGrowth grainGrowth, UINT lengthX, UINT widthY, UINT heightZ) :
		m_lengthX(lengthX),
		m_widthY(widthY),
		m_heightZ(heightZ),
		m_amountOfCells(m_lengthX * m_widthY * m_heightZ)
	{
		SetBoundaryCondition(boundaryConditions, grainGrowth, lengthX, widthY, heightZ)

		for (size_t z = 0; z < m_heightZ; z++)
		{
			for (size_t y = 0; y < m_widthY; y++)
			{
				for (size_t x = 0; x < m_lengthX; x++)
				{
					m_population[z][y][x] = Cell({ z,y,x });
					m_population[z][y][x].m_Neighbors = m_ptrBoundaryCondition->SetIndexToNeighborhood(x, y, z);
					m_population[z][y][x].m_x = x;
					m_population[z][y][x].m_y = y;
					m_population[z][y][x].m_z = z;
				}
			}
		}
	}

	void CA::Space::SetBoundaryCondition(BoundaryConditions boundaryConditions, GrainGrowth grainGrowth, UINT lengthX, UINT widthY, UINT heightZ)
	{
		switch (boundaryConditions)
		{
		case BoundaryConditions::periodic:
			{
				m_ptrBoundaryCondition = std::make_unique<CA::PeriodicBoundaryCondition>(grainGrowth, lengthX, widthY, heightZ);
			}
		default:
			break;
		}
		m_ptrNeighborhood = std::make_shared<CA::VonNeumannNeighborhood>();
	}

	void CA::Space::RandomNucleation(UINT amountNucleos, UINT amountOfDifferentGrains)
	{
		std::random_device rd;
		std::mt19937 mt(rd());
		std::uniform_real_distribution<UINT> distX(0, m_lengthX-1);
		std::uniform_real_distribution<UINT> distY(0, m_widthY-1);
		std::uniform_real_distribution<UINT> distZ(0, m_heightZ-1);
		std::uniform_real_distribution<UINT> distGrain(1, amountOfDifferentGrains);

		for (size_t i = 0; i < amountNucleos; i++)
		{
			m_initialNucleos.push_back(Grain({ distX(mt), distY(mt), distZ(mt) }, distGrain(mt)));
		}
	}

	void CA::Space::GrainGrowth()
	{
		while (m_initialNucleos.empty())
		{
			auto x = 
		}
		for (auto &x : m_initialNucleos)
		{
			m_population(x.index).full = true;
			for (auto &z : m_population(x.index).m_Neighbors)
			{
				m_population(z).state = x.type;
				if (!m_population(z).full)
				{
					m_initialNucleos.push_back(z, x.type);
				}
			}
		}
	}
}