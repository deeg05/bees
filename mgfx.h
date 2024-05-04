#ifndef MEIGFX_H_
#define MEIGFX_H_

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

/* Animated Texture
 * Structure for animated textures
 * AdvanceTexture(frames) advances texture by exact number of frames
 * SetFrame(frame) sets frame of texture by number
 */

typedef struct AnimatedTexture 
{
	SDL_Texture** textures;
	unsigned int count;
	unsigned int frame;
} AnimatedTexture;

// void LoadAnimatedTexture(AnimatedTexture* texture, unsigned int frames);
void AdvanceTexture(AnimatedTexture* texture, unsigned int frames);
void SetFrame(AnimatedTexture* texture, unsigned int frame); 

TTF_Font* LoadFont(char* path, int fontSize);
SDL_Texture* RenderText(char* caption, TTF_Font* font, SDL_Color color, SDL_Renderer* renderer);
void CloseFont(TTF_Font* font);

#endif
