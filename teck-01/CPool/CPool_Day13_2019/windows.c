#include <SFML/Window.h>
#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <stdlib.h>

sfRenderWindow *createMy_window(unsigned int width,
                                   unsigned int height)
{
    sfRenderWindow *window;
    sfVideoMode    mode = {width, height, 32};
    window = sfRenderWindow_create(mode, "window", sfResize | sfClose, NULL);
    return (window);
}

sfTexture *SetMySprite ()
{
    sfTexture *texture;
    sfSprite *sprite;
    texture = sfTexture_createFromFile("index.jpg", NULL);
    sprite = sfSprite_create();
    sfSprite_setTexture(sprite, texture, sfTrue);
    return (sprite);

}
int main()
{
    sfRenderWindow *window;
    sfSprite *sprite;
    sfEvent event;
    sfUint8 *pixels;

    int width = 500;
    int height = 500;
    int bitsPP = 32;

    pixels = malloc(width * height * bitsPP / 8);
    pixels[0] = 255;
    pixels[1] = 0;
    pixels[2] = 0;
    pixels[3] = 0;
    
    window = createMy_window(800, 600);
    sprite = SetMySprite();
    
    while (sfRenderWindow_isOpen(window)) {
        display_framebuffer (pixels, width, height);
        sfRenderWindow_display(window);
        while (sfRenderWindow_pollEvent(window, &event)) {
            if (event.type == sfEvtClosed)
                sfRenderWindow_close(window);
    }
        sfRenderWindow_drawSprite(window, sprite, NULL);
    }
    sfRenderWindow_destroy(window);
    return (0);
}

