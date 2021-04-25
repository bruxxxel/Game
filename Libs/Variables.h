#define GLOBALS				struct enemy_properties { \
								int y_max; \
								int x_min; \
								int x_max; \
							};

#define SYSTEM_VARIABLES	ALLEGRO_DISPLAY *display = NULL; \
							ALLEGRO_TIMER *timer = NULL; \
							ALLEGRO_TIMER *enemy_timer = NULL; \
							\
							ALLEGRO_AUDIO_STREAM *soundtrack = NULL; \
							ALLEGRO_MIXER *mixer = NULL; \
							ALLEGRO_VOICE *voice = NULL; \
							\
							ALLEGRO_EVENT_QUEUE *event_queue = NULL; \
							ALLEGRO_EVENT_QUEUE *timer_trig = NULL; \
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

#define GAME_VARIABLES		value player_init_ypos = 9 * prop * height[dm]/(10*prop);	/*	Posição Vertical do Personagem		*/ \
							value player_ymovement = 0;									/*	Movimento Vertical do Personagem	*/ \
							value player_ypos = player_init_ypos;						/*	Movimentação relativa do Personagem	*/ \
							value enemy_ypos = player_init_ypos - (height[dm]/20);		/*	Posição Relativa do inimigo			*/ \
							value hardness = 10;										/*	Dificuldade Inicial					*/ \
							\
							int player_xpos = 0; \
							int enemy_count = 0; \
							int rnd = 0; \
							int cldrnd = 0; \
							\
							bool jump = false; \
							bool enemy_trig = false; \
							bool cloud_trig = true; \
							\
							unsigned int enemy_draw_time = 0; \
							unsigned int cloud_draw_time = 0; \
							unsigned int jumptime = 0;
							\
							value f; \
							value h; \
							value rad;

#define GAME_MATH_LOGIC		h = (height[dm]); \
							f = (120); \
							rad = (3/f); \
							\
							player_ymovement = -250*prop*sin(rad*jumptime*M_PI); \
							player_ypos = player_init_ypos + player_ymovement; \
							hardness = (prop*10) + ((pow((enemy_count),2))/75);

#define GAME_IMAGES			ALLEGRO_BITMAP *enemy_1 = al_load_bitmap("Assets/Images/Camelo.png"); \
							ALLEGRO_BITMAP *enemy_2 = al_load_bitmap("Assets/Images/Broken_Skate.png"); \
							ALLEGRO_BITMAP *enemy_3 = al_load_bitmap("Assets/Images/Havan.png"); \
							ALLEGRO_BITMAP *choris = al_load_bitmap("Assets/Images/Choris.png"); \
							ALLEGRO_BITMAP *sol = al_load_bitmap("Assets/Images/Sol.png"); \
							ALLEGRO_BITMAP *cloud_1 = al_load_bitmap("Assets/Images/Nuvem1.png"); \
							ALLEGRO_BITMAP *cloud_2 = al_load_bitmap("Assets/Images/Nuvem2.png"); \
							ALLEGRO_BITMAP *cloud_3 = al_load_bitmap("Assets/Images/Nuvem3.png"); \

//  End of File