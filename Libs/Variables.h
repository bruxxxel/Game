#define SYSTEM_VARIABLES	ALLEGRO_DISPLAY *display = NULL; \
							ALLEGRO_TIMER *timer = NULL; \
							\
							ALLEGRO_AUDIO_STREAM *soundtrack = NULL; \
							ALLEGRO_MIXER *mixer = NULL; \
							ALLEGRO_VOICE *voice = NULL; \
							\
							ALLEGRO_EVENT_QUEUE *event_queue = NULL; \
							ALLEGRO_EVENT ev; \
							\
							ALLEGRO_FONT *titlefont = al_load_ttf_font("Assets/Fonts/Minecraft.ttf",titlefontsize,ALLEGRO_TTF_MONOCHROME); \
							ALLEGRO_FONT *menufont = al_load_ttf_font("Assets/Fonts/Minecraft.ttf",menufontsize,ALLEGRO_TTF_MONOCHROME); \
							ALLEGRO_FONT *debugfont = al_load_ttf_font("Assets/Fonts/Timeless-Bold.ttf",debugfontsize,ALLEGRO_TTF_MONOCHROME); \
							\
							ALLEGRO_BITMAP *choraoirl = al_load_bitmap("Assets/Images/ChoraoIRL.png"); \
							ALLEGRO_BITMAP *menu_block = al_load_bitmap("Assets/Images/Skate.png"); \
							ALLEGRO_BITMAP *menu_background = al_load_bitmap("Assets/Images/Background.bmp"); \
							ALLEGRO_BITMAP *guita = al_load_bitmap("Assets/Images/Guita.png"); \
							\
							ALLEGRO_MOUSE_STATE mouse_state; \
							ALLEGRO_KEYBOARD_STATE keyboard_state;

#define GAME_VARIABLES		value player_init_ypos = 3 * height[dm]/4;	/*	Posição Vertical do Personagem	*/ \
							value player_ymovement = 0;					/*	Movimento Vertical do Personagem*/ \
							\
							bool jump = false; \
							\
							unsigned int jumptime = 0;

#define GAME_MATH_LOGIC		value h = (height[dm]); \
							value f = (120); \
							value rad = (3/f); \
							\
							player_ymovement = -150*prop*sin(rad*jumptime*M_PI); \
							value player_ypos = player_init_ypos + player_ymovement;

//  End of File