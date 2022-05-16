#include "about.h"

void view_about(){
    // SFML VARIABLE
    sfRenderWindow *window;
    sfTexture *texture;
    sfSprite *sprite;
    sfFont *font;
    sfText *text;
    sfEvent event;

    // TEXTURE AND SPRITE
    texture = sfTexture_createFromFile("assets/image/About Design.png", NULL);

    // FONT
    font = sfFont_createFromFile("assets/font/Roboto-Regular.ttf");

    // WINDOW
    sfVideoMode mode = {1280, 720, 30};
    window = sfRenderWindow_create(mode, "Brilliant", sfResize | sfClose, NULL);

    // FRAME LIMIT
    sfRenderWindow_setFramerateLimit(window, 30);

    while (sfRenderWindow_isOpen(window)){
        // SPRITE
        sprite = sfSprite_create();
        sfSprite_setTexture(sprite, texture, sfTrue);
        while (sfRenderWindow_pollEvent(window, &event)){
            if (event.type == sfEvtClosed){
                sfRenderWindow_close(window);
            }
        }
        // CLEAR SCREEN
        sfRenderWindow_clear(window, sfBlack);

        // DRAW SPRITE
        sfRenderWindow_drawSprite(window, sprite, NULL);\

        sfVector2f pos;
        pos.x = 550;
        pos.y = 100;

        // TITLE
        text = sfText_create();
        sfText_setFont(text, font);
        sfText_setString(text, "Brilliant");
        sfText_setCharacterSize(text, 50);
        sfText_setStyle(text, sfTextBold);
        sfText_setPosition(text, pos);
        sfText_setColor(text, sfBlack);
        sfRenderWindow_drawText(window, text, NULL);
        sfText_destroy(text);

        // DESCRIPTION
        pos.x = 200;
        pos.y = 200;

        text = sfText_create();
        sfText_setFont(text, font);
        sfText_setLineSpacing(text, 1.4);
        sfText_setString(text, "Brilliant adalah aplikasi berbasis console dengan fitur GUI yang mampu mengolah data buku.\n"
                         "\nBrilliant dibuat menggunakan:\n"
                         "1. C Programming Languange\n"
                         "2. SFML (Simple Fast Media Library)\n"
                         "3. IDE CodeBlocks\n"
                         "\nAnggota Kelompok:\n"
                         "1. Putu Widyantara Artanta Wibawa (2108561005)\n"
                         "2. I Made Suma Gunawan (2108561108)\n"
                         "3. Raindra Pramathana (2108561117)\n"
                         "4. Rafly Shaquille Subhan (2108561118)\n");
        sfText_setCharacterSize(text, 20);
        sfText_setPosition(text, pos);
        sfText_setColor(text, sfBlack);
        sfRenderWindow_drawText(window, text, NULL);
        sfText_destroy(text);

        // UPDATE WINDOW
        sfRenderWindow_display(window);

        // CLEAN UP
        sfSprite_destroy(sprite);
    }
    // OTHER CLEAN UP
    sfFont_destroy(font);
    sfRenderWindow_destroy(window);
    sfTexture_destroy(texture);
}
