#define CREATE_DISPLAY		display = al_create_display(width[dm], height[dm]);						/*	Criação do Display	*/ \
							al_set_new_display_option(ALLEGRO_SAMPLE_BUFFERS, 1, ALLEGRO_SUGGEST);	/*	Anti-Serrilhamento	*/ \
							al_set_new_display_option(ALLEGRO_SAMPLES, 8, ALLEGRO_SUGGEST);			/*	Anti-Serrilhamento	*/ \
							al_set_window_title(display, "Chorão Pro Skater");						/*	Nome do Display		*/ \
							\
							al_set_new_display_flags(ALLEGRO_WINDOWED); \
							al_set_new_display_flags(ALLEGRO_RESIZABLE); \
							\
							al_clear_to_color(al_map_rgb(0, 0, 0));

#define EVENTQUEUE		    event_queue = al_create_event_queue(); \
							timer_trig = al_create_event_queue(); \
							\
							al_register_event_source(event_queue, al_get_display_event_source(display)); \
							al_register_event_source(event_queue, al_get_keyboard_event_source()); \
							al_register_event_source(timer_trig, al_get_timer_event_source(timer));

#define RESIZEFONT			menufontsize = 15 * width[dm] / 640;		/*	Adaptação do tamanho da fonte pela resolução*/ \
							titlefontsize = 30 * width[dm] / 640;		/*	Adaptação do tamanho da fonte pela resolução*/ \
							debugfontsize = 20 * width[dm] / 640;		/*	Adaptação do tamanho da fonte pela resolução*/ \
							menufont = al_load_ttf_font("Assets/Fonts/Minecraft.ttf",menufontsize,ALLEGRO_TTF_MONOCHROME); \
							titlefont = al_load_ttf_font("Assets/Fonts/Minecraft.ttf",titlefontsize,ALLEGRO_TTF_MONOCHROME);

#define DEGUB_SHOW_VARS		al_draw_textf(debugfont,al_map_rgb(255,255,255),0,0,0,"player_ypos: %Lf",player_ypos); \
							al_draw_textf(debugfont,al_map_rgb(255,255,255),0,1*debugfontsize,0,"jumptime: %i",jumptime); \
							al_draw_textf(debugfont,al_map_rgb(255,255,255),0,2*debugfontsize,0,"enemy_ypos: %Lf",enemy_ypos); \
							al_draw_textf(debugfont,al_map_rgb(255,255,255),0,3*debugfontsize,0,"player_ymovement: %Lf",player_ymovement); \
							al_draw_textf(debugfont,al_map_rgb(255,255,255),0,4*debugfontsize,0,"f: %Lf",f); \
							al_draw_textf(debugfont,al_map_rgb(255,255,255),0,5*debugfontsize,0,"hardness: %Lf",hardness); \
							/*al_draw_textf(debugfont,al_map_rgb(255,255,255),0,2*debugfontsize,0,"jump: %s",jump ?"true":"false");*/

#define JUMP_LOGIC			if (jumptime >= 40) { \
								if (ev.type == ALLEGRO_EVENT_KEY_DOWN) { \
									if (ev.keyboard.keycode == ALLEGRO_KEY_UP) { \
										jump = true; \
									} \
								} \
								if (ev.type != ALLEGRO_EVENT_KEY_DOWN) { \
									jump = false; \
								} \
								jumptime = 0; \
							} \
							if (jump == true && !(player_ypos > prop*9*(h/(10*prop)))) { \
								jumptime++; \
							}

#define TIMER_FLIP_DISP		al_wait_for_event(timer_trig,&ev); \
							if (ev.type == ALLEGRO_EVENT_TIMER) { \
								al_flush_event_queue(timer_trig); \
								al_flip_display(); \
							}

#define MUSIC(x)        	soundtrack = al_load_audio_stream(x,4,44800);

#define VOICEMIXER  		mixer = al_create_mixer(44100, ALLEGRO_AUDIO_DEPTH_FLOAT32, ALLEGRO_CHANNEL_CONF_2); \
							voice = al_create_voice(44100, ALLEGRO_AUDIO_DEPTH_INT16, ALLEGRO_CHANNEL_CONF_2);

#define TRACKTOVOICE    	al_set_audio_stream_playmode(soundtrack, ALLEGRO_PLAYMODE_LOOP); \
							al_attach_audio_stream_to_mixer(soundtrack, mixer); \
							al_attach_mixer_to_voice(mixer, voice);

#define TERMINATE_AUDIO		al_destroy_audio_stream(soundtrack); \
							al_destroy_mixer(mixer); \
							al_destroy_voice(voice);

#define TERMINATE_IMAGES	al_destroy_bitmap(choraoirl); \
							al_destroy_bitmap(menu_block); \
							al_destroy_bitmap(menu_background); \
							al_destroy_bitmap(guita);

#define TERMINATE			al_destroy_display(display); \
							al_destroy_timer(timer); \
							al_destroy_event_queue(event_queue); \
							\
							al_destroy_font(titlefont); \
							al_destroy_font(menufont); \
							al_destroy_font(debugfont); \
							\
							al_shutdown_font_addon(); \
							al_shutdown_image_addon(); \
							al_shutdown_primitives_addon(); \
							\
							al_uninstall_audio(); \
							al_uninstall_keyboard(); \
							al_uninstall_mouse();

//  End of File