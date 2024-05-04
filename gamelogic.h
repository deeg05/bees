#ifndef GAMELOGIC_H_
#define GAMELOGIC_H_
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <stdlib.h>
#include <math.h>

/* Player structure
 *
 * ltex - facing left texture
 * rtex - facing right texture
 * state - current animation state
 * facing - current facing (0 - left, 1 - right)
 *
 */

typedef struct Bees 
{
	unsigned int count;
	float (*coords)[2];
	unsigned int ForceBBox;
	float x, y;
	float r;
} bees;

//void LoadPlayerTexture(player* player, SDL_Renderer* renderer, const char* path);
void InitBees(bees* bees, unsigned int count, SDL_Rect bbox);
void RenderBees(bees* bees, SDL_Renderer* renderer);
void DestroyBees(bees* bees);
void BeesStep(bees* bees);

int CheckInBBox(SDL_Rect* bbox, float x, float y);

#endif 
