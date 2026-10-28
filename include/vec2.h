#ifndef VEC2_H
#define VEC2_H

typedef struct t_vec2
{
	double	x;
	double	y;
} vec2;

static inline vec2 vec_zero();
static inline vec2 new_vec(int x, int y);
#endif
