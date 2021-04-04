//	Definições
	#include "Libs/AllegroHeader.h"
	#include "Libs/Macros.h"
	#include "Libs/Variables.h"
	#define DEBUG
	//#define MUSIC

int main () {

	//	Início do programa

		VARIABLES    //	Definição de Variáveis
		LIBINITMACRO //	Inicia as Bibliotecas
		INSTALLMACRO //	Instalação dos Componentes

		{//	Criação dos componentes
		
			display = al_create_display(width, height);

			{// Fila de eventos

				event_queue = al_create_event_queue();

				al_register_event_source(event_queue, al_get_display_event_source(display));
				al_register_event_source(event_queue, al_get_keyboard_event_source());
				al_register_event_source(event_queue, al_get_mouse_event_source());
			}

			{//	Música
				#ifdef MUSIC
					mixer = al_create_mixer(44100, ALLEGRO_AUDIO_DEPTH_FLOAT32, ALLEGRO_CHANNEL_CONF_2);
					voice = al_create_voice(44100, ALLEGRO_AUDIO_DEPTH_INT16, ALLEGRO_CHANNEL_CONF_2);
					soundtrack = al_load_audio_stream("./Assets/Audio/Soundtrack.ogg",4,44800);
		
					al_set_audio_stream_playmode(soundtrack, ALLEGRO_PLAYMODE_LOOP);
					al_attach_audio_stream_to_mixer(soundtrack, mixer);
					al_attach_mixer_to_voice(mixer, voice);
				#endif
			}
		}

	TERMINATE
    #ifdef DEBUG
       	sleep (3);
	#endif
	return 0;
}