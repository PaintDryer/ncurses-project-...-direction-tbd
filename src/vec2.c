#include "vec2.h"

// some initialisers
static inline vec2 vec_zero()
{
	vec2 v = {};
	return (v);
}

static inline vec2 new_vec(int x, int y)
{
	vec2 v = {.x = x, .y = y};
	return (v);
}
