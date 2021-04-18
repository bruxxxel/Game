#define CREATE_DISPLAY	al_set_new_display_option(ALLEGRO_SAMPLE_BUFFERS, 1, ALLEGRO_SUGGEST);	/*	Anti-Serrilhamento	*/ \
						al_set_new_display_option(ALLEGRO_SAMPLES, 8, ALLEGRO_SUGGEST);			/*	Anti-Serrilhamento	*/ \
						display = al_create_display(width[dm], height[dm]);						/*	Criação do Display	*/ \
						\
						al_set_new_display_flags(ALLEGRO_WINDOWED); \
						al_set_new_display_flags(ALLEGRO_RESIZABLE);

#define EVENTQUEUE	    event_queue = al_create_event_queue(); \
						\
						al_register_event_source(event_queue, al_get_display_event_source(display)); \
						al_register_event_source(event_queue, al_get_keyboard_event_source()); \
						al_register_event_source(event_queue, al_get_mouse_event_source());

#define MUSIC(x)        soundtrack = al_load_audio_stream(x,4,44800);

#define VOICEMIXER  	mixer = al_create_mixer(44100, ALLEGRO_AUDIO_DEPTH_FLOAT32, ALLEGRO_CHANNEL_CONF_2); \
						voice = al_create_voice(44100, ALLEGRO_AUDIO_DEPTH_INT16, ALLEGRO_CHANNEL_CONF_2);

#define TRACKTOVOICE    al_set_audio_stream_playmode(soundtrack, ALLEGRO_PLAYMODE_LOOP); \
						al_attach_audio_stream_to_mixer(soundtrack, mixer); \
						al_attach_mixer_to_voice(mixer, voice);

#define RESIZEFONT		menufontsize = 15 * width[dm] / 640;	/*	Adaptação do tamanho da fonte pela resolução	*/ \
						titlefontsize = 30 * width[dm] / 640;	/*	Adaptação do tamanho da fonte pela resolução 	*/ \
						menufont = al_load_ttf_font("Assets/Fonts/Minecraft.ttf",menufontsize,ALLEGRO_TTF_MONOCHROME); \
						titlefont = al_load_ttf_font("Assets/Fonts/Minecraft.ttf",titlefontsize,ALLEGRO_TTF_MONOCHROME);

#define TERMINATE		al_destroy_display(display); \
						\
						al_destroy_audio_stream(soundtrack); \
						al_destroy_mixer(mixer); \
						al_destroy_voice(voice); \
						\
						al_destroy_font(titlefont); \
						al_destroy_font(menufont); \
						\
						al_destroy_bitmap(choraoirl);\
						al_destroy_bitmap(menu_block);\
						al_destroy_bitmap(menu_background);\
						\
						al_shutdown_font_addon(); \
						al_shutdown_ttf_addon(); \
						al_shutdown_image_addon(); \
						al_shutdown_primitives_addon(); \
						\
						al_uninstall_audio(); \
						al_uninstall_keyboard(); \
						al_uninstall_mouse();

//  End of File