#ifndef GAME_H
#define GAME_H

#include "vec2.h"

// v = u + at
struct t_entity
{	
	vec2 u;
	vec2 v;
	vec2 a;
};

#define DEFAULT_GRAVITY -10.0
#define DEFAULT_JUMPV 7.0

typedef struct t_gameworld
{
	struct t_entity	player;
	double			jumpvelocity;
	double			gravity;
} gameworld;

// should be bitmasked
// and manage overlap with char buffer
typedef struct t_input
{
	vec2 dir;
	// char* keys;
} input;

// functions
gameworld* new_world();
gameworld* process(gameworld* g, double deltatime, char input);

#endif
