//	Definições
	#include "Libs/AllegroHeader.h"
	#include "Libs/Functions.h"
	#include "Libs/Variables.h"
	#include "Libs/Macros.h"
	#define DEBUG
	#define PLACEHOLDER
	//#define MUTE

int main () {

	//	Início do programa
		int width[2] = {640,940};
		int height[2] = {480,700};
		int displaymode = 1;						//	Seleção da resolução
		bool menu = true;							//	Inicia o menu
		bool played_animation = false;
		float menufontsize = 15 * width[displaymode] / 640;	//	Adaptação do tamanho da fonte pela resolução

		init_libs();	//	Inicia as Bibliotecas
		install();		//	Instalação dos Componentes
		VARIABLES		//	Declaração de Variáveis

		//	Criação dos componentes
			display = al_create_display(width[displaymode], height[displaymode]);	//	Criação do Display
			EVENTQUEUE				//	Criação da fila de eventos e definição das fontes de eventos
			#ifndef MUTE
				VOICEMIXER			//	Define os parâmetros dos canais de áudio
				MUSIC(OSTFILE)		//	Define o arquivo da música de fundo
				TRACKTOVOICE		//	Faz a transmissão do arquivo para o canal de áudio
			#endif

	//	Loop do Menu
		while (menu) {
			al_clear_to_color(al_map_rgb(0, 0, 0));	//	Limpa o Display

		//	Animação da introdução
			if (!played_animation) {
				for (size_t i = 0; i < width[displaymode]; i+=1) {
					al_draw_scaled_bitmap(choraoirl,0,0,al_get_bitmap_width(choraoirl),al_get_bitmap_height(choraoirl),0+i,0,height[displaymode]/4+i/10,height[displaymode]/2+i/2,0);
					al_flip_display();
					if (i >= width[displaymode]) {
						break;
					}
				}
				played_animation = true;
			}

			//#ifndef PLACEHOLDER
				draw_menu_images(width[displaymode], height[displaymode],menu_background,menu_block);	//	Cria os gráficos das caixas de opções
			//#endif
			#ifdef PLACEHOLDER
				draw_menu_boxes(width[displaymode], height[displaymode]);	//	Mostra as áreas delimitadoras das opções
			#endif

			draw_menu_text(width[displaymode], height[displaymode], menufont, titlefont);	//	Cria os textos das transmissões

			al_flip_display();
		}

	#ifdef DEBUG
	   	sleep (3);
	#endif
	TERMINATE
	return 0;
}