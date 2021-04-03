//  Bibliotecas Padrão
	#include <stdio.h>
	#include <math.h>

//  Bibliotecas Allegro
	#include <allegro5/allegro.h>
	#include <allegro5/allegro5.h>
	//  Bibliotecas Gráficas
		#include <allegro5/allegro_primitives.h>
		#include <allegro5/allegro_image.h>
	//	Bibliotecas de Áudio
		#include <allegro5/allegro_audio.h>
		#include <allegro5/allegro_acodec.h>
	//  Bibliotecas de Hardware
		#include <allegro5/keyboard.h>
		#include <allegro5/keycodes.h>
		#include <allegro5/mouse.h>
		#include <allegro5/mouse_cursor.h>

//	Definições
	#define DEBUG

void terminate (ALLEGRO_DISPLAY *display) {

	al_destroy_display (display);

	al_uninstall_audio;
	al_uninstall_keyboard;
	al_uninstall_mouse;
}

void main () {

	//	Início do programa

		int width = 600, height = 600;

		ALLEGRO_DISPLAY *display = NULL;
		ALLEGRO_AUDIO_STREAM *soundtrack = NULL;
		ALLEGRO_MIXER *mixer = NULL;
		ALLEGRO_VOICE *voice = NULL;
		ALLEGRO_EVENT_QUEUE *event_queue = NULL;
		ALLEGRO_EVENT event;

		display = al_create_display (width, height);

		{//	Bibliotecas

			if (!al_init()) {
				printf ("The allegro5 library is missing.");
				return 1;
			}

			if (!al_init_primitives_addon) {
				printf ("\nThe allegro_primitives library is missing.");
				return 1;
			}

			if (!al_init_image_addon) {
				printf ("\nThe allegro_image library is missing.");
				return 1;
			}

			if (!al_init_acodec_addon) {
				printf ("\nThe allegro_acodec library is missing.");
				return 1;
			}
		}

		{//	Instalações
				
			if (!al_install_audio) {
				printf ("Audio cannot be installed. Check your drivers.");
				return 1;
			}

			if (!al_install_keyboard) {
				printf ("Keyboard cannot be installed. Check your drivers.");
				return 1;
			}

			if (!al_install_mouse) {
				printf ("Mouse cannot be installed. Check your drivers.");
				return 1;
			}
		}

		{// Criação da fila de eventos

			event_queue = al_create_event_queue();

			al_register_event_source(event_queue, al_get_display_event_source(display));
			//al_register_event_source(event_queue, al_get_keyboard_event_source());
			//al_register_event_source(event_queue, al_get_mouse_event_source);
			//al_register_event_source(event_queue, al_get_timer_event_source);
		}

		{//	Funções DEBUG
			#ifdef DEBUG
				if (al_is_keyboard_installed){
					printf ("keyboard is installed\n");
				}
			#endif
		}

	#ifdef DEBUG
		sleep (3);
	#endif

	terminate(display);
	return 0;
}