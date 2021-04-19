//	Definições
	#include "Libs/AllegroHeader.h"
	#include "Libs/Functions.h"
	#include "Libs/Variables.h"
	#include "Libs/Macros.h"
	//#define DEBUG
	//#define PLACEHOLDER
	#define MUTE

int main () {

	//	Início do programa
	int width[2] = {640,940};
	int height[2] = {480,700};
	int FPS = 240;
	float refresh = 1/FPS;
		
	int dm = 0;									//	Seleção da resolução
	bool menu = true;							//	Inicia o menu
	bool game = false;							//	Inicia o jogo
	bool done = false;							//	Inicia o loop principal
	bool played_animation = false;				//	Inicia a animação

	float menufontsize = 15 * width[dm] / 640;	//	Adaptação do tamanho da fonte pela resolução
	float titlefontsize = 30 * width[dm] / 640;	//	Adaptação do tamanho da fonte pela resolução

	init_libs();	//	Inicia as Bibliotecas
	install();		//	Instalação dos Componentes
	VARIABLES		//	Declaração de Variáveis

	//	Criação dos componentes		
	CREATE_DISPLAY
	//timer = al_create_timer(1/60);	//	Criação do Timer
	EVENTQUEUE							//	Criação da fila de eventos e definição das fontes de eventos
	#ifndef MUTE
		VOICEMIXER					//	Define os parâmetros dos canais de áudio
		MUSIC(OSTFILE)				//	Define o arquivo da música de fundo
		TRACKTOVOICE				//	Faz a transmissão do arquivo para o canal de áudio
	#endif

	//	Loop Principal
	while (!done) {
		al_clear_to_color(al_map_rgb(0, 0, 0));	//	Limpa o Display

		//	Animação
		if (!played_animation) {
			play_animation(width[dm],height[dm],choraoirl);
			played_animation = true;
		}

		//	Loop do Menu
		while (menu == true) {
			al_clear_to_color(al_map_rgb(0, 0, 0));								//	Limpa o Display
			draw_menu_images(width[dm], height[dm],menu_background,menu_block);	//	Cria os gráficos das caixas de opções
			draw_menu_text(width[dm], height[dm], menufont, titlefont);			//	Cria os textos das transmissões
			#ifdef PLACEHOLDER
				draw_menu_boxes(width[dm], height[dm]);	//	Mostra as áreas delimitadoras das opções
			#endif

			al_wait_for_event_timed(event_queue,&ev,refresh);	//	Aguarda evento do mouse

			//	Controle pelo mouse
			al_get_mouse_state(&mouse_state);
			if (ev.type == ALLEGRO_EVENT_MOUSE_AXES) {	//	Checa a posição do mouse
				if ((ev.mouse.x >= 2*width[dm]/10-width[dm]/20) && (ev.mouse.x <= 8*width[dm]/10+width[dm]/20)) {	//	Área dos Botões
					if ((ev.mouse.y >= 5*height[dm]/10) && (ev.mouse.y <= 6*height[dm]/10)) {	//	Botões superiores
						if (al_mouse_button_down(&mouse_state,1)) {				//	Checa se houve clique
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
								sleep(1);
								if (dm == 0) {
									dm++;
									al_resize_display(display,width[1],height[1]);
									RESIZEFONT
									break;
								}
								if (dm == 1) {
									dm--;
									al_resize_display(display,width[0],height[0]);
									RESIZEFONT
									break;
								}
							}
						}
					}
					{//	Botões inferiores (desativados)
					/*if ((ev.mouse.y >= 7*height[dm]/10-height[dm]/20) && (ev.mouse.y <= 8*height[dm]/10-height[dm]/20)) {	//	Botões inferiores
						if (al_mouse_button_down(&mouse_state,1)) {				//	Checa se houve clique
							//	Botão 3
							if (ev.mouse.x <= 5*width[dm]/10-width[dm]/20) {	//	Replay Introduction
								al_clear_to_color(al_map_rgb(0, 0, 0));	//	Limpa o Display
								al_flip_display();
								played_animation = false;
								menu = false;
								break;
							}
							//	Botão 4
							if (ev.mouse.x >= 5*width[dm]/10+width[dm]/20) {	//	Change Character
								menu = true;
								game = false;
							}
						}
					}*/
					}
				}
			}

			//	Fechar com Esc.
			al_get_keyboard_state(&keyboard_state);
			if (ev.type == ALLEGRO_EVENT_KEY_DOWN) {
				if (ev.keyboard.keycode == ALLEGRO_KEY_ESCAPE) {
					done = true;
					break;
				}
			}

			al_flip_display();
		}

		while (game) {
			done = true;
			break;
		}

		al_flip_display();
	}

	#ifdef DEBUG
	   	sleep (3);
	#endif
	TERMINATE
	return 0;
}