//	Definições
	#include "Libs/AllegroHeader.h"
	#define DEBUG

int main () {

	//	Início do programa
		LIBINITMACRO	//	Inicia as Bibliotecas
		INSTALLMACRO	//	Instalação dos Componentes
		VARIABLES		//	Declaração de Variáveis

		//	Criação dos componentes
			DISPLAY			//	Criação do Display
			EVENTQUEUE		//	Criação da fila de eventos e definição das fontes de eventos
			VOICEMIXER		//	Define os parâmetros dos canais de áudio
			MUSIC(OSTFILE)	//	Define o arquivo da música de fundo
			TRACKTOVOICE	//	Faz a transmissão do arquivo para o canal de áudio

	//	Loop do Menu

    #ifdef DEBUG
       	sleep (3);
	#endif
	TERMINATE
	return 0;
}