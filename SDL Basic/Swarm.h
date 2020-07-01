#pragma once
#include "Particle.h"


class Swarm
{
public:
	const static int n_particles = 5000;

private:
	Particle* m_particles;

public:
	Swarm();
	virtual ~Swarm();

	Particle* get_particles() { return m_particles; }
};

