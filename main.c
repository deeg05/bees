#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_mouse.h>
#include <SDL2/SDL_timer.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

#include "gamelogic.h"
#include "mgfx.h"

float g = -0.163f;

int main(int argc, char *argv[]) {

	uint32_t win_width = 640, win_height = 480;

	if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
	{
		printf("Error initializing SDL: %s\n", SDL_GetError());
	}

	if (TTF_Init() != 0)
	{
		printf("Error initializing TTF: %s\n", SDL_GetError());
	}

	SDL_Window* win = SDL_CreateWindow("Bees",
									   SDL_WINDOWPOS_CENTERED,
									   SDL_WINDOWPOS_CENTERED,
									   win_width, win_height, 0);

	SDL_Color color = { 0, 0, 0, 0xFF};
	TTF_Font *font = LoadFont("font.ttf", 24);

	// Trigger hardware acceleration
	//uint32_t render_flags = SDL_RENDERER_ACCELERATED;
	uint32_t render_flags = 0;

	// Create renderer
	SDL_Renderer* renderer = SDL_CreateRenderer(win, -1, render_flags);

	int close = 0;

	SDL_Rect fpsbox;
	fpsbox.x = 0;
	fpsbox.y = 0;

	SDL_Rect bbox;
	bbox.x = 100;
	bbox.y = 100;
	bbox.w = 100;
	bbox.h = 100;

	bees bees;
	InitBees(&bees, 500000, bbox);
	bees.ForceBBox = 0;
	bees.x = bbox.x;
	bees.y = bbox.y;
	bees.r = 1;

	unsigned int msec, frameStart = 0;
	double fps = 0;

	while(!close)
	{
		SDL_Event event;
		int mouseX, mouseY;
		msec = SDL_GetTicks() - frameStart;
		frameStart = SDL_GetTicks();
		if (msec > 0)
			fps = 1000.0 / (double) msec;
		char fps_string[256];
		sprintf(fps_string, "%f FPS", fps);
		while (SDL_PollEvent(&event))
		{
			SDL_GetMouseState(&mouseX, &mouseY);
			bees.x = mouseX;
			bees.y = mouseY;
			switch (event.type)
			{
				case SDL_QUIT:
					close = 1;
					break;

				case SDL_MOUSEBUTTONDOWN:
					switch (event.button.button)
					{
						case SDL_BUTTON_LEFT:
							bees.ForceBBox = 1;
							break;
					}
					break;

				case SDL_MOUSEBUTTONUP:
					switch (event.button.button)
					{
						case SDL_BUTTON_LEFT:
							bees.ForceBBox = 0;
							break;
					}
					break;

				case SDL_KEYUP:
					switch (event.key.keysym.scancode) 
					{
						case SDL_SCANCODE_W:
						case SDL_SCANCODE_UP:
							break;
						case SDL_SCANCODE_A:
						case SDL_SCANCODE_LEFT:
							break;
						case SDL_SCANCODE_S:
						case SDL_SCANCODE_DOWN:
							break;
						case SDL_SCANCODE_D:
						case SDL_SCANCODE_RIGHT:
							break;
						default:
							break;
					}
					break;

				case SDL_KEYDOWN:
					switch (event.key.keysym.scancode) 
					{
						case SDL_SCANCODE_W:
						case SDL_SCANCODE_UP:
							break;
						case SDL_SCANCODE_A:
						case SDL_SCANCODE_LEFT:
							break;
						case SDL_SCANCODE_S:
						case SDL_SCANCODE_DOWN:
							break;
						case SDL_SCANCODE_D:
						case SDL_SCANCODE_RIGHT:
							break;
						default:
							break;
					}
					break;
			}
		}

		//SDL_Delay(1000 / 240);
		SDL_Texture *fps = RenderText(fps_string, font, color, renderer);
		int fpsW, fpsH;
		SDL_QueryTexture(fps, NULL, NULL, &fpsW, &fpsH);
		fpsbox.w = fpsW;
		fpsbox.h = fpsH;
		
		SDL_SetRenderDrawColor(renderer, 153, 153, 153, 255);
		SDL_RenderClear(renderer);

		BeesStep(&bees);

		RenderBees(&bees, renderer);
		SDL_RenderCopy(renderer, fps, NULL, &fpsbox);
		SDL_RenderPresent(renderer);
	}

	//DestroyPlayer(player);
	//free(player);
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(win);
	SDL_Quit();

	return 0;
}
