//	Definições
	#include "Libs/AllegroHeader.h"
	#include "Libs/Functions.h"
	#include "Libs/Variables.h"
	#include "Libs/Macros.h"
	#define DEBUG
	#define PLACEHOLDER
	#define MUTE
	GLOBALS
	//#define SLOW_MODE

int main () {

	//	Início do programa
	int width[2] = {640,940};					//	Definição dos parâmetros da tela
	int height[2] = {480,700};					//	Definição dos parâmetros da tela
	int dm = 0;									//	Seleção da resolução
	double prop = width[dm] / width[0];			//	Constante de proporcionalidade pela resolução
	int FPS = 30;								//	Quadros por segundo
	double refresh = 1/FPS;						//	Frequência de Atualização

	bool played_animation = true;				//	Inicia a animação
	bool menu = true;							//	Inicia o menu
	bool game = false;							//	Inicia o jogo
	bool tutorial = false;						//	Inicia o tutorial
	bool done = false;							//	Inicia o loop principal
	bool dead = false;							//	Definição do estado do jogo
	bool music_on = true;						//	Seleciona com ou sem música

	float menufontsize = 15 * prop;				//	Adaptação do tamanho da fonte pela resolução
	float titlefontsize = 30 * prop;			//	Adaptação do tamanho da fonte pela resolução
	float debugfontsize = 20 * prop;			//	Adaptação do tamanho da fonte pela resolução

	init_libs();								//	Inicia as Bibliotecas
	install();									//	Instalação dos Componentes
	SYSTEM_VARIABLES							//	Declaração de Variáveis do Sistema
	RESIZEFONT									//	Redefinição das fontes

	//	Criação dos componentes
	timer = al_create_timer(1.0 / 45);			//	Criação do Timer
	srand(time(NULL));							//	Cria a "semente" do gerador RNG
	CREATE_DISPLAY								//	Criação do display e alteração de opções
	EVENTQUEUE									//	Criação da fila de eventos e definição das fontes de eventos
	#ifndef MUTE
		VOICEMIXER								//	Define os parâmetros dos canais de áudio
		MUSIC(OSTFILE)							//	Define o arquivo da música de fundo
		TRACKTOVOICE							//	Faz a transmissão do arquivo para o canal de áudio
	#endif

	//	Loop Principal
	while (!done) {
		//	Loop da Animação
		while (!played_animation) {
			play_animation(width[dm],height[dm],choraoirl);
			played_animation = true;
		}

		al_register_event_source(event_queue,al_get_mouse_event_source());
		//	Loop do Menu
		while (menu == true) {
			al_clear_to_color(al_map_rgb(0,0,0));													//	Limpa o Buffer
			draw_menu_images(width[dm], height[dm],menu_background,menu_block,guita);				//	Cria os gráficos das caixas de opções
			draw_menu_text(width[dm], height[dm], menufont, titlefont);								//	Cria os textos das transmissões
			#ifdef PLACEHOLDER
				draw_menu_boxes(width[dm], height[dm]);												//	Mostra as áreas delimitadoras das opções
			#endif
			al_flip_display();																		//	Atualiza o Display
			al_wait_for_event(event_queue,&ev);														//	Aguarda evento do mouse

			//	Controle pelo mouse
			al_get_mouse_state(&mouse_state);
			if (ev.type == ALLEGRO_EVENT_MOUSE_AXES) {												//	Checa a posição do mouse
				if ((ev.mouse.x >= 2*width[dm]/10-width[dm]/20) && (ev.mouse.x <= 8*width[dm]/10+width[dm]/20)) {	//	Área dos Botões
					if ((ev.mouse.y >= 5*height[dm]/10) && (ev.mouse.y <= 6*height[dm]/10)) {		//	Botões superiores
						if (al_mouse_button_down(&mouse_state,1)) {									//	Checa se houve clique
							//	Botão 1
							if (ev.mouse.x <= 5*width[dm]/10-width[dm]/20) {	//	Play
								menu = false;
								game = true;
								al_clear_to_color(al_map_rgb(0,0,0));
								al_flip_display();
								break;
							}
							//	Botão 2
							if (ev.mouse.x >= 5*width[dm]/10+width[dm]/20) {	//	Change Resolution
								al_clear_to_color(al_map_rgb(0,0,0));
								al_flip_display();
								sleep(0.5);
								switch (dm) {

									case 0: {
									dm++;
									prop = 2;
									al_resize_display(display,width[1],height[1]);
									RESIZEFONT
									al_wait_for_event(event_queue,&ev);
									break;
									}

									case 1: {
									dm--;
									prop = 1;
									al_resize_display(display,width[0],height[0]);
									RESIZEFONT
									al_wait_for_event(event_queue,&ev);
									break;
									}
								}
							}
						}
					}
					if ((ev.mouse.y >= 7*height[dm]/10) && (ev.mouse.y <= 8*height[dm]/10)) {		//	Botões inferiores
						if (al_mouse_button_down(&mouse_state,1)) {									//	Checa se houve clique
							//	Botão 3
							if (ev.mouse.x <= 5*width[dm]/10-width[dm]/20) {	//	Exit
								menu = false;
								game = false;
								done = true;
								al_clear_to_color(al_map_rgb(0,0,0));
								al_flip_display();
								break;
							}
							//	Botão 4
							if (ev.mouse.x >= 5*width[dm]/10+width[dm]/20) {	//	Tutorial
								menu = false;
								tutorial = true;
								game = false;
								al_clear_to_color(al_map_rgb(0,0,0));
								al_flip_display();
								break;
							}
						}
					}
				}
				//	Botão Sound
				if ((ev.mouse.x >= width[dm]-width[dm]/10) && (ev.mouse.x <= width[dm]-width[dm]/30)) {	//	Guitar image
					if ((ev.mouse.y <= height[dm]/6) && (al_mouse_button_down(&mouse_state,1))) {
						switch (music_on) {

							case false: {
							music_on++;
							al_destroy_audio_stream(soundtrack);
							MUSIC(OSTFILE)
							TRACKTOVOICE
							al_wait_for_event(event_queue,&ev);
							al_flush_event_queue(event_queue);
							sleep(1);
							break;
							}

							case true: {
							music_on--;
							al_destroy_audio_stream(soundtrack);
							MUSIC(NOSOUND)
							TRACKTOVOICE
							al_wait_for_event(event_queue,&ev);
							al_flush_event_queue(event_queue);
							sleep(1);
							break;
							}
						}
					}
				}
			}

			//	Fechar com Esc.
			if (ev.type == ALLEGRO_EVENT_KEY_DOWN) {
				if (ev.keyboard.keycode == ALLEGRO_KEY_ESCAPE) {
					menu = false;
					done = true;
					al_flush_event_queue(event_queue);
					break;
				}
			}

			al_flip_display();
			al_clear_to_color(al_map_rgb(0, 0, 0));	//	Limpa o Display
			al_flush_event_queue(event_queue);		//	Limpa a fila de eventos
		}
		al_unregister_event_source(event_queue,al_get_mouse_event_source());

		GAME_VARIABLES			//	Declaração de Variáveis do Jogo
		GAME_IMAGES				//	Definição das imagens do jogo

		//	Loop do Tutorial
		while (tutorial == true) {
			al_clear_to_color(al_map_rgb(0,0,0));

			int img_width = al_get_bitmap_width(choris);
			int img_height = al_get_bitmap_height(choris);

			draw_tutorial_text(width[dm],height[dm],titlefont,menufont);
			al_draw_scaled_bitmap(choris,0,0,img_width,img_height,width[dm]/20,5*height[dm]/10,prop*img_width/4,prop*img_height/4,0);

			al_wait_for_event_timed(event_queue,&ev,refresh);	//	Aguarda evento do teclado

			//	Fechar com Esc.
			if (ev.type == ALLEGRO_EVENT_KEY_DOWN) {
				al_clear_to_color(al_map_rgb(255,0,255));

				if (ev.keyboard.keycode == ALLEGRO_KEY_ESCAPE) {
					tutorial = false;
					menu = true;
					game = false;
					al_flush_event_queue(event_queue);
					break;
				}
				al_flip_display();
			}
			al_flip_display();
		}

		al_start_timer(timer);
		//	Loop do jogo
		while (game) {
			draw_background(width[dm],height[dm],sol);
			al_wait_for_event_timed(event_queue,&ev,refresh);

			player_xpos++;
			enemy_draw_time++;
			cloud_draw_time++;

			if (cloud_draw_time >= 101) {
				switch (cloud_trig) {
					case true:
						cloud_trig = false;
						break;

					case false:
						cloud_trig = true;
						break;
				}
				cloud_trig = 0;
				cldrnd = rand()%3;
			}

			if (enemy_draw_time >= 101) {
				switch (enemy_trig) {
					case true:
						enemy_trig = false;
						break;

					case false:
						enemy_trig = true;
						break;
				}
				enemy_draw_time = 0;
				enemy_count++;
				rnd = rand()%3;
			}

			if (player_ypos == player_init_ypos) {
				if (ev.type == ALLEGRO_EVENT_KEY_DOWN) {
					if (ev.keyboard.keycode == ALLEGRO_KEY_UP) {
						jump = true;
					}
				}
			}

			JUMP_LOGIC
			GAME_MATH_LOGIC

			if (enemy_trig == true) {
				int enemy_xpos = width[dm]-hardness*enemy_draw_time;
				generate_enemy(enemy_1,enemy_2,enemy_3,enemy_xpos,enemy_ypos,width[dm],height[dm],prop,rnd);
			}
			if (cloud_trig == true) {
				int cloud_xpos = width[dm]-hardness*cloud_draw_time;
				int cloud_ypos = height[dm]/4;
				generate_cloud(cloud_1,cloud_2,cloud_3,cloud_xpos,cloud_ypos,width[dm],height[dm],prop,cldrnd);
			}

			draw_score(menu_block,width[dm],height[dm],prop,titlefont,enemy_count);
			draw_player(choris,width,height,dm,player_ypos,prop);
			#ifdef DEBUG
				DEGUB_SHOW_VARS
			#endif

			//	Fechar para o Menu com Esc.
			if (ev.type == ALLEGRO_EVENT_KEY_DOWN) {
				if (ev.keyboard.keycode == ALLEGRO_KEY_ESCAPE) {
					game = false;
					menu = true;
					al_clear_to_color(al_map_rgb(0,0,0));
					break;
				}
			}
			#ifdef DEBUG
				//	Teste de morte
				if (ev.type == ALLEGRO_EVENT_KEY_DOWN) {
					if (ev.keyboard.keycode == ALLEGRO_KEY_BACKSPACE) {
						game = false;
						dead = true;
						menu = false;
						al_clear_to_color(al_map_rgb(0,0,0));
						break;
					}
				}
			#endif

			al_flush_event_queue(event_queue);
			al_flush_event_queue(timer_trig);
			TIMER_FLIP_DISP
		}
		al_stop_timer(timer);

		//	Loop da Morte
		while (dead == true) {
			al_clear_to_color(al_map_rgb(0,0,0));

			int img_width = al_get_bitmap_width(choris);
			int img_height = al_get_bitmap_height(choris);

			draw_dead_text(width[dm],height[dm],titlefont,menufont);
			al_draw_scaled_bitmap(choris,0,0,img_width,img_height,(width[dm]/2)-(img_width/2),5*height[dm]/10,prop*img_width/4,prop*img_height/4,0);
			
			al_wait_for_event_timed(event_queue,&ev,refresh);	//	Aguarda evento do teclado

			//	Fechar com Esc.
			if (ev.type == ALLEGRO_EVENT_KEY_DOWN) {
				al_clear_to_color(al_map_rgb(255,0,255));

				if (ev.keyboard.keycode == ALLEGRO_KEY_ESCAPE) {
					tutorial = false;
					menu = true;
					game = false;
					al_flush_event_queue(event_queue);
					break;
				}
				al_flip_display();
			}
			al_flip_display();
		}
	}

	#ifdef SLOW_MODE
		sleep (1);
	#endif
	#ifdef PLACEHOLDER
		TERMINATE_IMAGES
	#endif
	#ifndef MUTE
		TERMINATE_AUDIO
	#endif
	TERMINATE
	return 0;
}