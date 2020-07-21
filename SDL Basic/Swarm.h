#pragma once
#include "Particle.h"


class Swarm
{
public:
	const static int n_particles = 5000;

private:
	Particle* m_particles;
	int last_time;

public:
	Swarm();
	virtual ~Swarm();
	void update(int elapsed);

	Particle* get_particles() { return m_particles; }
};

