#define TERMINATE	    { \
						al_destroy_display(display); \
						\
						al_uninstall_audio(); \
						al_uninstall_keyboard(); \
						al_uninstall_mouse(); \
						al_shutdown_font_addon(); \
						al_shutdown_ttf_addon(); \
						}

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

//  End of File