#include "Swarm.h"

Swarm::Swarm() {
	m_particles = new Particle[n_particles];
}

Swarm::~Swarm() {
	delete[] m_particles;
}