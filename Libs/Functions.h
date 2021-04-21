int init_libs (void) {

	if (!al_init()) {
		printf ("The allegro5 library is missing.");
		return 1;
	}

	if (!al_init_primitives_addon()) {
		printf ("\nThe allegro_primitives library is missing.");
		return 1;
	}

	if (!al_init_image_addon()) {
		printf ("\nThe allegro_image library is missing.");
		return 1;
	}

	if (!al_init_acodec_addon()) {
		printf ("\nThe allegro_acodec library is missing.");
		return 1;
	}

	if (!al_init_font_addon()) {
		printf ("\nThe allegro_font library is missing.");
		return 1;
	}

	if (!al_init_ttf_addon()) {
		printf ("\nThe allegro_ttf library is missing.");
		return 1;
	}

	return 0;
}

int install (void) {
	
	if (!al_install_audio()) {
	printf ("Audio cannot be installed. Check your drivers.");
	return 1;
	}

	if (!al_install_keyboard()) {
	printf ("Keyboard cannot be installed. Check your drivers.");
	return 1;
	}

	if (!al_install_mouse()) {
	printf ("Mouse cannot be installed. Check your drivers.");
	return 1;
	}

	return 0;
}

void play_animation (int width, int height, ALLEGRO_BITMAP *choraoirl) {
	al_clear_to_color(al_map_rgb(0, 0, 0));
	int img_width = al_get_bitmap_width(choraoirl);
	int img_height = al_get_bitmap_height(choraoirl);
	for (size_t i = 0; i < width-img_width; i++) {
		al_draw_scaled_bitmap(choraoirl,0,0,img_width,img_height,0+i,height/10,height/4+i/5,height/2+i/2,0);
		al_draw_scaled_bitmap(choraoirl,0,0,img_width,img_height,width-(10*img_width/21)-i,height/10,height/4+i/5,height/2+i/2,ALLEGRO_FLIP_HORIZONTAL);
		al_flip_display();
		if (i >= width) {
			break;
		}
	}
}

void draw_menu_boxes (int width, int height) {

	//	Caixa da logo do jogo
	al_draw_rectangle(width/5,height/10,4*width/5,4*height/10,al_map_rgb(255,0,255),1);

	//	Caixas das opções superiores
	al_draw_rectangle(2*width/10-width/20,5*height/10,5*width/10-width/20,6*height/10,al_map_rgb(255,0,255),1);	//	Play
	al_draw_rectangle(8*width/10+width/20,5*height/10,5*width/10+width/20,6*height/10,al_map_rgb(255,0,255),1);	//	Change Character

	//	Caixa das informações do jogo
	al_draw_rectangle(5,height-5,width/2,height-20,al_map_rgb(255,0,255),1);			//	Info

	//	Caixa da seleção de Som
	al_draw_rectangle(width-width/10,0,width-width/30,height/6,al_map_rgb(255,0,255),1);//	Sound
}

void draw_menu_images (int width, int height, ALLEGRO_BITMAP *background, ALLEGRO_BITMAP *menu_block, ALLEGRO_BITMAP *guita) {
	
	//	Fundo
	al_draw_scaled_bitmap(background,0,0,al_get_bitmap_width(background),al_get_bitmap_height(background),0,0,width,height,ALLEGRO_FLIP_HORIZONTAL);

	//	Título
	al_draw_scaled_bitmap(menu_block,0,0,al_get_bitmap_width(menu_block),al_get_bitmap_height(menu_block),width/5-width/25,height/10+height/25,2*width/3,2*height/9,0);

	//	Opção 1
	al_draw_scaled_bitmap(menu_block,0,0,al_get_bitmap_width(menu_block),al_get_bitmap_height(menu_block),2*width/10-width/16,5*height/10,width/3,height/9,0);
	//	Opção 2
	al_draw_scaled_bitmap(menu_block,0,0,al_get_bitmap_width(menu_block),al_get_bitmap_height(menu_block),6*width/10-width/16,5*height/10,width/3,height/9,0);
	//	Botão Sound
	al_draw_scaled_bitmap(guita,0,0,al_get_bitmap_width(guita),al_get_bitmap_height(guita),width-width/10,0,width/18,height/6,0);
}

void draw_menu_text (int width, int height, ALLEGRO_FONT *menufont, ALLEGRO_FONT *titlefont, float menufontsize, float titlefontsize) {

	//	Título
	al_draw_text(titlefont,al_map_rgb(255,255,255),width/2,2*height/10,ALLEGRO_ALIGN_CENTER,"Chorao Pro Skater");

	//	Opção 1
	al_draw_text(menufont,al_map_rgb(255,255,255),width/3-width/30,5*height/10+height/35,ALLEGRO_ALIGN_CENTER,"Play");
	//	Opção 2
	al_draw_text(menufont,al_map_rgb(255,255,255),2*width/3+width/30,5*height/10+height/35,ALLEGRO_ALIGN_CENTER,"Change Resolution");

	//	Informações
	al_draw_text(menufont,al_map_rgb(0,0,0),5,height-20,ALLEGRO_ALIGN_LEFT,"Made by: Brayan Silveira and Leonardo Bruxel");
	al_draw_text(menufont,al_map_rgb(255,255,255),6,height-21,ALLEGRO_ALIGN_LEFT,"Made by: Brayan Silveira and Leonardo Bruxel");
}