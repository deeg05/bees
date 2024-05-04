#include "gamelogic.h"

void InitBees(bees* bees, unsigned int count, SDL_Rect bbox)
{
	bees->count = count;
	bees->coords = malloc(count * 2 * sizeof(float));
	for (unsigned int i = 0; i < count; ++i)
	{
		float x = bbox.x + ((float)(rand() % (3 * bbox.w))) / 3;
		float y = bbox.y + ((float)(rand() % (3 * bbox.h))) / 3;
		bees->coords[i][0] = x;
		bees->coords[i][1] = y;
	}
}

void RenderBees(bees* bees, SDL_Renderer* renderer)
{
	SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 0xFF);
	for (unsigned int i = 0; i < bees->count; ++i)
	{
		SDL_RenderDrawPoint(renderer, bees->coords[i][0], bees->coords[i][1]);
	}
}

void DestroyBees(bees* bees)
{
}

void BeesStep(bees* bees)
{
	for (unsigned int i = 0; i < bees->count; ++i)
	{
		float dx = (float)(rand() % 3) - 1;
		float dy = (float)(rand() % 3) - 1;
		bees->coords[i][0] += 2*dx;
		bees->coords[i][1] += 2*dy;
		
		if (bees->ForceBBox &&
			((bees->coords[i][0] - bees->x) * (bees->coords[i][0] - bees->x) + (bees->coords[i][1] - bees->y) * (bees->coords[i][1] - bees->y)) > bees->r * bees->r)
		{
			float dx, dy;
			dx = (bees->x - bees->coords[i][0]);
			dy = (bees->y - bees->coords[i][1]);
			float w = sqrt(dx * dx + dy * dy);
			dx /= w;
			dy /= w;
			dx *= 2;
			dy *= 2;

			bees->coords[i][0] += dx + ((float)(rand() % 5))*((float)(rand() % 3) - 1.f);
			bees->coords[i][1] += dy + ((float)(rand() % 5))*((float)(rand() % 3) - 1.f);
		}
	}
}
