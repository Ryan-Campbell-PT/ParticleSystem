#ifndef PARTICLEEMITTER_H
#define PARTICLEEMITTER_H

#include "Math\Matrix.h"
#include "Math\Vect4D.h"
#include "Particle.h"

#include <list>

struct LL
{
	LL()
	{

	}

	virtual ~LL()
	{

	}

	void clear()
	{

	}


	Particle *particle;
	LL *next;
	LL *prev;

};

class ParticleEmitter
{
public:
	ParticleEmitter();
	~ParticleEmitter();
	
	void SpawnParticle();
	void update();
	void draw();

	void addParticleToList(Particle *p );
	void removeParticleFromList( Particle *p);

	void Execute(Vect4D &pos, Vect4D &vel, Vect4D &sc);

private:
	//128
	Vect4D	start_position;
	Vect4D	start_velocity;

	float	max_life;
	int		max_particles;
	int		last_active_particle;
	float	spawn_frequency;
	float	last_spawn;
	float	last_loop;


	// added for speed efficiency
	int bufferCount;
	Particle *headParticle;
	Vect4D	vel_variance;
	Vect4D	pos_variance;
	float	scale_variance;

	//my attempt to get rid of any stl
//	LL *head;
//	LL *tail;
//	LL *drawBuffer;
//	LL *particle_list;
	std::list<Particle> drawBuffer;
	std::list<Particle> particle_list;
};

#endif // PARTICLEEMITTER_H
