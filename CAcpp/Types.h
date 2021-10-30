#pragma once

namespace CA
{
	enum BoundaryConditions
	{
		absorbing,
		periodic
	};

	enum GrainGrowth
	{
		VonNeumann
	};

	using UINT = unsigned int;
	using ULLINT = unsigned long long int;
}