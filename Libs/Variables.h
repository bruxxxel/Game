#define VARIABLES   ALLEGRO_DISPLAY *display = NULL; \
					ALLEGRO_AUDIO_STREAM *soundtrack = NULL; \
					ALLEGRO_MIXER *mixer = NULL; \
					ALLEGRO_VOICE *voice = NULL; \
					ALLEGRO_EVENT_QUEUE *event_queue = NULL; \
					ALLEGRO_EVENT ev; \
					\
					ALLEGRO_FONT *titlefont = al_load_ttf_font("Assets/Fonts/Minecraft.ttf",2*menufontsize,0); \
					ALLEGRO_FONT *menufont = al_load_ttf_font("Assets/Fonts/Minecraft.ttf",menufontsize,0); \
					\
					ALLEGRO_BITMAP *choraoirl = al_load_bitmap("Assets/Images/ChoraoIRL.png"); \
					ALLEGRO_BITMAP *menu_block = al_load_bitmap("Assets/Images/Skate.png"); \
					ALLEGRO_BITMAP *menu_background = al_load_bitmap("Assets/Images/Background.bmp");

//  End of File