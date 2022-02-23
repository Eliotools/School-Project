/*
** EPITECH PROJECT, 2019
** my_defender
** File description:
** defender
*/

/*
-l csfml-graphics -l csfml-audio -l csfml-window -l csmfl-system
*/

#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/Audio.h>
#include <stddef.h>
#include <stdlib.h>
#include <SFML/System/Vector2.h>
#include <SFML/Config.h>
#include <SFML/Window/Export.h>
#include <SFML/Window/Types.h>
#include "include/my.h"

void killer(drawing show, window window, menu menu)
{
    sfMusic_destroy(menu.menu_song);
    sfRenderWindow_destroy(window.window);
    sfSprite_destroy(show.play_s);
    sfTexture_destroy(show.play_t);
    sfSprite_destroy(show.r_play_s);
    sfTexture_destroy(show.r_play_t);
    sfSprite_destroy(menu.exit);
    sfTexture_destroy(menu.exit_t);
    sfTexture_destroy(menu.menu_screen_t);
    sfSprite_destroy(menu.menu_screen);
}

void set_up(drawing *show)
{

}

void title_set_up(menu *menu)
{
    menu->pos_name.x = 840;
    menu->pos_name.y = 280;
    menu->menu_name = sfText_create();
    menu->name = "Railgun Defender";
    menu->name_texture = sfFont_createFromFile("ressources/font.ttf");
    sfText_setPosition(menu->menu_name, menu->pos_name);
    sfText_setString(menu->menu_name, menu->name);
    sfText_setFont(menu->menu_name, menu->name_texture);
}

void set_up_menu(drawing *show, menu *menu)
{
    show->sprite_pos_play.x = 840;
    show->sprite_pos_play.y = 480;
    menu->pos.x = 840;
    menu->pos.y = 680;
    title_set_up(menu);
    show->r_play_t = sfTexture_createFromFile("ressources/n_play.png", NULL);
    show->r_play_s = sfSprite_create();
    show->play_t = sfTexture_createFromFile("ressources/play.png", NULL);
    show->play_s = sfSprite_create();
    menu->exit_t = sfTexture_createFromFile("ressources/exit_b.png", NULL);
    menu->exit = sfSprite_create();
    menu->menu_screen_t = sfTexture_createFromFile("ressources/menu_screen.jpg", NULL);
    menu->menu_screen = sfSprite_create();
    sfSprite_setTexture(menu->menu_screen, menu->menu_screen_t, sfTrue);
    sfSprite_setTexture(show->play_s, show->play_t, sfTrue);
    sfSprite_setTexture(menu->exit, menu->exit_t, sfTrue);
    sfSprite_setTexture(show->r_play_s, show->r_play_t, sfTrue);
    sfSprite_setPosition(show->play_s, show->sprite_pos_play);
    sfSprite_setPosition(show->r_play_s, show->sprite_pos_play);
    sfSprite_setPosition(menu->exit, menu->pos);
    menu->menu_song = sfMusic_createFromFile("ressources/menu_song.ogg");
}

void escape_game(window window)
{
    if (sfKeyboard_isKeyPressed(sfKeyEscape) == 1)
        sfRenderWindow_close(window.window);
}

void draw__menu_sprite(window *window, drawing *show, menu *menu)
{
    sfRenderWindow_drawSprite(window->window, menu->menu_screen, NULL);
    sfRenderWindow_drawSprite(window->window, menu->exit, NULL);
    sfRenderWindow_drawSprite(window->window, show->play_s, NULL);
    sfRenderWindow_drawSprite(window->window, show->r_play_s, NULL);
}

void check_button(window window)
{
    sfVector2i coordonee;

    if (sfMouse_isButtonPressed(sfMouseLeft) == sfTrue) {
        coordonee = sfMouse_getPositionRenderWindow(window.window);
    }
}

void event_manage(window window, drawing show, sfEvent event, menu *menu)
{

    while (sfRenderWindow_pollEvent(window.window, &event)) {
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(window.window);
        if (event.type == sfEvtKeyPressed)
            escape_game(window);
        if (event.type == sfEvtMouseButtonPressed)
            check_button(window);
        if (event.type == sfEvtMouseButtonPressed) {
            menu->menu_screen_t = sfTexture_createFromFile("ressources/map.png", NULL);
            menu->menu_screen = sfSprite_create();
            sfSprite_setTexture(menu->menu_screen, menu->menu_screen_t, sfTrue);
            printf("la\n");
        }
    }
}

void init_window(window *window)
{
    window->mode.width = 1920;
    window->mode.height = 1080;
    window->mode.bitsPerPixel = 32;
}

void open_menu(drawing *show, window *window, menu *menu)
{
    draw__menu_sprite(window, show, menu);
    //menu_event_manage(window, show, menu);
}

void runner()
{
    menu menu;
    drawing show;
    window window;
    init_window(&window);
    window.window = sfRenderWindow_create(window.mode, "Railgun defender !", sfResize | sfClose, NULL);
    set_up(&show);
    set_up_menu(&show, &menu);
    sfMusic_setLoop(menu.menu_song, sfTrue);
    sfMusic_play(menu.menu_song);
    while (sfRenderWindow_isOpen(window.window)) {
        sfRenderWindow_display(window.window);
        open_menu(&show, &window, &menu);
        event_manage(window, show, window.event, &menu);

    }
    killer(show, window, menu);
}

void main()
{
    runner();
}
