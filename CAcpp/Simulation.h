#include <memory>

#include "Space.h"

namespace CA 
{
	class Simulation
	{
	public:
		Simulation() = default;
		bool Init();
		bool LoadSpaceFromConfigFile();
		bool RunSimulation(); 
	private:
		CA::Space m_Space;
	};
}