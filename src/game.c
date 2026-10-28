#include "game.h"
#include "vec2.h"
#include "deltatime.h"
#include <stdlib.h>

gameworld* new_world()
{
	gameworld* g = malloc(sizeof(gameworld));
	g->player.u = vec_zero();
	g->player.v = vec_zero();
	g->jumpvelocity = DEFAULT_JUMPV;
	g->gravity = DEFAULT_GRAVITY;
	return g;
}

// ideally bitmasked inputs
gameworld* process(gameworld* g, double deltatime, char input)
{
	// apply velocity to position
	g->player.u.x += g->player.v.x * deltatime;
	g->player.u.y += g->player.v.y * deltatime;

	// floor check
	if (g->player.u.y < 0)
		g->player.u.y = 0;

	// apply gravity
	if (g->player.u.y == 0 && g->player.v.y < 0)
		g->player.v.y = 0;
	else
		g->player.v.y += g->gravity * deltatime;
	
}
