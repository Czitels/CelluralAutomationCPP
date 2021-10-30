#include <fstream>

#include "Simulation.h"

namespace CA
{
	bool CA::Simulation::Init()
	{
		if (LoadSpaceFromConfigFile())
		{
			return true;
		}
		return false;
	}

	bool CA::Simulation::LoadSpaceFromConfigFile()
	{
		return false;
	}

	bool CA::Simulation::RunSimulation()
	{

	}
}