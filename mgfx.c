#include "mgfx.h"

TTF_Font* LoadFont(char* path, int fontSize)
{
	TTF_Font *font = TTF_OpenFont(path, fontSize);
	if (font == NULL)
	{
		return NULL;
	}
	return font;
}

SDL_Texture* RenderText(char* caption, TTF_Font* font, SDL_Color color, SDL_Renderer* renderer)
{
	SDL_Surface *surface = TTF_RenderText_Blended(font, caption, color);
	if (surface == NULL)
	{
		return NULL;
	}
	SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, surface);
	if (texture == NULL)
	{
		return NULL;
	}
	SDL_FreeSurface(surface);
	return texture;
}

void CloseFont(TTF_Font *font)
{
	TTF_CloseFont(font);
}
