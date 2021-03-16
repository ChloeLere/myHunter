/*
** EPITECH PROJECT, 2020
** my
** File description:
** functions in libmy.a
*/

#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <signal.h>
#include <string.h>
#include <bits/sigaction.h>
#include <ucontext.h>
#include <sys/wait.h>
#include <spawn.h>
#include <sys/select.h>
#include <SFML/Audio.h>
#include <SFML/Audio/Export.h>
#include <SFML/Audio/SoundStatus.h>
#include <SFML/Audio/Types.h>
#include <SFML/Window/Export.h>
#include <SFML/Window/Joystick.h>
#include <SFML/Window/Keyboard.h>
#include <SFML/Window/Mouse.h>
#include <SFML/Window/Sensor.h>
#include <SFML/Graphics.h>
#include <SFML/Graphics/RenderWindow.h>
#include <SFML/System/Export.h>
#include <SFML/System/Time.h>
#include <time.h>

typedef struct list_element_s
{
    void *data;
    struct list_element_s *next;
    struct list_element_s *prev;
}list_element_t;

typedef struct list_s
{
    int size;
    struct list_element_s *begin;
    struct list_element_s *end;
}*list_t;

typedef struct data_s
{
    int x;
    int y;
    int c;
    int nbr;
}data_t;

typedef struct game_object_s
{
    sfSprite *sprite;
    sfTexture *texture;
    sfVector2f position;
    sfIntRect box;
    sfVector2f scale;
}*game_object_t;

typedef struct text_s
{
    sfFont *font;
    sfText *text;
    sfVector2f position;
}*text_t;

typedef struct screen_s
{
    sfSprite *sprite;
    sfTexture *texture;
}*screen_t;

typedef struct info_s
{
    sfVector2f pb1;
    sfVector2f pb2;
    sfVector2f ppause;
    sfVector2f pl;
    sfIntRect bb1;
    sfIntRect bb2;
    sfIntRect bpause;
    sfIntRect bl;
    sfVector2f sb1;
    sfVector2f sb2;
    sfVector2f spause;
    sfVector2f sl;
}info_t;

typedef struct all_element_s
{
    game_object_t bird1;
    game_object_t bird2;
    game_object_t p_object;
    game_object_t life;
    screen_t backgroud;
    screen_t main_menu;
    screen_t paused;
    screen_t lose;
    screen_t win;
    text_t score;
    text_t high_sc;
    sfClock *clock_b1;
    sfClock *clock_b2;
    int status;
    int point;
    int hdl_life;
    int left_right;
    int left;
    int right;
    int temp;
    int maj;
}*all_element_t;

void my_putchar(char c);
void my_put_error(char c);
int my_putstr(char const *str);
int my_putstr_error(char *str);
int my_put_nbr(int nb);
int my_strlen(char const *str);
int my_nbrlen(int str);
int my_doublestrlen(char **str);
int my_put_nbr_pr(int nb);
int my_getnbr(char const *str);
int my_getnbr_with_i(char const *str, int i);
int my_printf(char *s, ...);
void my_put_nbr_oct(int nb);
void my_put_nbr_uns(unsigned int nb);
void check_string(char *type, va_list argv);
void check_int(char *type, va_list argv);
void check_char(char *type, va_list argv);
int check_other(char *type, va_list argv);
void convert(va_list argv, int base);
void convert_hexa_lower(va_list argv);
void convert_hexa_upper(va_list argv);
void convert_hexa_lower_int(int nbr, va_list argv);
void convert_hexa_lower_long(unsigned long nbr, va_list argv);
void free_all(char **to_free, int nbr_loop);
list_t create_list(void);
int listlen(list_t list);
list_t add_element_end(list_t list, void *data);
list_t add_element_first(list_t list, void *data);
void display_list_1d_arr(list_t list, char *elem_sep);
void display_list_char(list_t list, char *elem_sep);
void display_list_int(list_t list, char *elem_sep);
list_t rm_element_first(list_t list);
list_t rm_element_end(list_t list);
void rm_all(list_t list);
int edit_add(char *str, va_list argv, int add);
int space_or_plus(char str, va_list argv, int add);
void display_all_char(char *str);
void display_p(char *str, va_list argv);
void my_put_nbr_long(long nb);
double my_put_float(double nbr);
void my_put_short(short nb);
int load_file_in_mem(char const *filepath);
char *open_file(char *filepath, char *error_message);
int open_file_int(char *filepath);
int add_zero_or_space(char *str, va_list argv, int add);
void space_char(va_list argv, int nbr);
void zero_or_space_int(char str, va_list argv, int nb_z);
char **char_to_2dchar(char *argv);
int find_size(char *argv, int c);
int find_nb_char(char *argv);
int my_isneg (int n);
void c_free(char **str, int size);
int my_is_prime(int nb);
char *my_strcpy(char *dest, char const *src);
int my_str_islower(char const *str);
int my_str_isnum(char const *str);
int my_str_isprintable(char const *str);
int my_str_isupper(char const *str);
char *my_strlowcase(char *str);
char *my_strncat(char *dest, char const *src, int nb);
int my_strncmp(char const *s1, char const *s2, int n);
char *my_strncpy(char *dest, char const *src, int n);
char *my_strstr(char *str, char const *to_find);
char *my_strupcase(char *str);
int convert_in_all_base(int nb, char *base, int mod);

//main_hunter.c
int display_h(char *str);

//create_obj.c
text_t create_text(char *namefont, int x, int y);
game_object_t create_object(const char *name_sprite,
sfVector2f pos, sfIntRect rect, sfVector2f sc);
screen_t create_screen(char *name);
sfRenderWindow *create_window(unsigned int x, unsigned int y,
unsigned int bpp, char *title);

//open_window.c
void open_window(void);
void status_game(all_element_t obj, sfEvent event, sfRenderWindow *window);
void analyse_event(sfRenderWindow *window, sfEvent event, all_element_t obj);

//create_all_obj.c
all_element_t create_all_texts(all_element_t obj);
all_element_t create_all_screens(all_element_t obj);
all_element_t create_all_game_obj(all_element_t obj);
all_element_t create_all_obj(void);

//info_struct.c
info_t create_info_struct(void);

//destroy_all_element.c
void destroy_text_obj(text_t obj);
void destroy_screen_obj(screen_t obj);
void destroy_game_obj(game_object_t obj);
void destroy_all(all_element_t obj, sfRenderWindow *window);

//set_display.c
void set_text(char *ptn, text_t txt, int size);
void draw_obj(game_object_t obj, sfRenderWindow *window);
void set_game_obj(game_object_t obj, sfRenderWindow *window);
void display_window(sfRenderWindow *window);
void set_all_obj(all_element_t obj, sfRenderWindow *window);

//draw.c
void draw_win_lose(all_element_t obj, screen_t sc, sfRenderWindow *window);
void draw_main_paused(sfRenderWindow *window, screen_t obj);
void draw_game(all_element_t obj, sfRenderWindow *window);

//main_menu.c
void main_menu(all_element_t obj, sfEvent event, sfRenderWindow *window);
void analyse_event_start(all_element_t obj, sfEvent event,
sfRenderWindow *window);

//paused_menu.c
void paused_menu(all_element_t obj, sfEvent event, sfRenderWindow *window);
void analyse_event_paused(all_element_t obj, sfEvent event,
sfRenderWindow *window);

//game.c
void play_game(all_element_t obj, sfEvent event, sfRenderWindow *window);
void analyse_event_game(all_element_t obj, sfEvent event,
sfRenderWindow *window);
void handling_life(all_element_t obj);
int analyse_event_bp(all_element_t obj, sfEvent event,
sfRenderWindow *window);

//random.c
void right(all_element_t obj);
void left(all_element_t obj);
void random_spawn(all_element_t obj);

//touch.c
void touch_b1(all_element_t obj);
void touch_b2(all_element_t obj);

//handling_end_game.c
void put_game_to_zero(all_element_t obj);
void handling_end_game(all_element_t obj);

//win.c
void win_menu(all_element_t obj, sfEvent event, sfRenderWindow *window);
void a_e_win_lose(all_element_t obj, sfEvent event, sfRenderWindow *window);

//lose.c
void lose_menu(all_element_t obj, sfEvent event, sfRenderWindow *window);

//display_score.c
void display_score_game(all_element_t obj, sfRenderWindow *window);

//int_to_char.c
char *int_to_char(int nbr);
char *inverse_char(int size, char *nbr);

//spawn_enemy.c
void end_right(all_element_t obj);
void end_left(all_element_t obj);

//keep_in_memory.c
char *file_op(char *filepath, char *error);
char *find_the_bigger(int n, char *nbr);