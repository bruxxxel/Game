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

void play_animation (int width,int height,ALLEGRO_BITMAP *choraoirl) {
	al_clear_to_color(al_map_rgb(0,0,0));
	int img_width = al_get_bitmap_width(choraoirl);
	int img_height = al_get_bitmap_height(choraoirl);
	for (size_t i = 0; (i < (width-(3*img_width/2))); i++) {
		al_draw_scaled_bitmap(choraoirl,0,0,img_width,img_height,0+i,height/10,height/4+i/5,height/2+i/2,0);
		al_draw_scaled_bitmap(choraoirl,0,0,img_width,img_height,width-(10*img_width/21)-i,height/10,height/4+i/5,height/2+i/2,ALLEGRO_FLIP_HORIZONTAL);
		al_flip_display();
		if (i >= width/2) {
			break;
		}
	}
}

void draw_menu_boxes (int width,int height) {

	//	Caixa da logo do jogo
	al_draw_rectangle(width/5,height/10,4*width/5,4*height/10,al_map_rgb(255,0,255),1);

	//	Caixas das opções superiores
	al_draw_rectangle(2*width/10-width/20,5*height/10,5*width/10-width/20,6*height/10,al_map_rgb(255,0,255),1);	//	Play
	al_draw_rectangle(8*width/10+width/20,5*height/10,5*width/10+width/20,6*height/10,al_map_rgb(255,0,255),1);	//	Change Character

	//	Caixas das opções superiores
	al_draw_rectangle(2*width/10-width/20,7*height/10,5*width/10-width/20,8*height/10,al_map_rgb(255,0,255),1);	//	Play
	al_draw_rectangle(8*width/10+width/20,7*height/10,5*width/10+width/20,8*height/10,al_map_rgb(255,0,255),1);	//	Change Character

	//	Caixa das informações do jogo
	al_draw_rectangle(5,height-5,width/2,height-20,al_map_rgb(255,0,255),1);	//	Info

	#ifndef MUTE
		//	Caixa da seleção de Som
		al_draw_rectangle(width-width/10,0,width-width/30,height/6,al_map_rgb(255,0,255),1);	//	Sound
	#endif
}

void draw_menu_images (int width,int height,ALLEGRO_BITMAP *background,ALLEGRO_BITMAP *menu_block,ALLEGRO_BITMAP *guita) {
	
	//	Fundo
	al_draw_scaled_bitmap(background,0,0,al_get_bitmap_width(background),al_get_bitmap_height(background),0,0,width,height,ALLEGRO_FLIP_HORIZONTAL);

	//	Título
	al_draw_scaled_bitmap(menu_block,0,0,al_get_bitmap_width(menu_block),al_get_bitmap_height(menu_block),width/5-width/25,height/10+height/25,2*width/3,2*height/9,0);

	//	Opção 1
	al_draw_scaled_bitmap(menu_block,0,0,al_get_bitmap_width(menu_block),al_get_bitmap_height(menu_block),2*width/10-width/16,5*height/10,width/3,height/9,0);
	//	Opção 2
	al_draw_scaled_bitmap(menu_block,0,0,al_get_bitmap_width(menu_block),al_get_bitmap_height(menu_block),6*width/10-width/16,5*height/10,width/3,height/9,0);
	//	Opção 3
	al_draw_scaled_bitmap(menu_block,0,0,al_get_bitmap_width(menu_block),al_get_bitmap_height(menu_block),2*width/10-width/16,7*height/10,width/3,height/9,0);
	//	Opção 4
	al_draw_scaled_bitmap(menu_block,0,0,al_get_bitmap_width(menu_block),al_get_bitmap_height(menu_block),6*width/10-width/16,7*height/10,width/3,height/9,0);

	//	Botão Sound
	al_draw_scaled_bitmap(guita,0,0,al_get_bitmap_width(guita),al_get_bitmap_height(guita),width-width/10,0,width/18,height/6,0);
}

void draw_menu_text (int width,int height,ALLEGRO_FONT *menufont,ALLEGRO_FONT *titlefont) {

	//	Título
	al_draw_text(titlefont,al_map_rgb(255,255,255),width/2,2*height/10,ALLEGRO_ALIGN_CENTER,"Chorao Pro Skater");

	//	Opção 1
	al_draw_text(menufont,al_map_rgb(255,255,255),width/3-width/30,5*height/10+height/35,ALLEGRO_ALIGN_CENTER,"Play");
	//	Opção 2
	al_draw_text(menufont,al_map_rgb(255,255,255),2*width/3+width/30,5*height/10+height/35,ALLEGRO_ALIGN_CENTER,"Change Resolution");
	//	Opção 3
	al_draw_text(menufont,al_map_rgb(255,255,255),width/3-width/30,7*height/10+height/35,ALLEGRO_ALIGN_CENTER,"Exit");
	//	Opção 4
	al_draw_text(menufont,al_map_rgb(255,255,255),2*width/3+width/30,7*height/10+height/35,ALLEGRO_ALIGN_CENTER,"Help");

	//	Informações
	al_draw_text(menufont,al_map_rgb(0,0,0),5,height-20,ALLEGRO_ALIGN_LEFT,"Made by: Brayan Silveira and Leonardo Bruxel");
	al_draw_text(menufont,al_map_rgb(255,255,255),6,height-21,ALLEGRO_ALIGN_LEFT,"Made by: Brayan Silveira and Leonardo Bruxel");
}

void draw_tutorial_text (int width, int height, ALLEGRO_FONT *titlefont, ALLEGRO_FONT *menufont) {

	//	Título
	al_draw_text(titlefont,al_map_rgb(255,255,255),width/2,height/10,ALLEGRO_ALIGN_CENTER,"Chorao Pro Skater");
	//	Ajuda
	al_draw_text(menufont,al_map_rgb(255,255,255),width/2,3*height/10,ALLEGRO_ALIGN_CENTER,"Press ^ to jump");
	al_draw_text(menufont,al_map_rgb(255,255,255),width/2,4*height/10,ALLEGRO_ALIGN_CENTER,"Press Esc to exit");
	al_draw_text(menufont,al_map_rgb(255,255,255),width/2,6*height/10,ALLEGRO_ALIGN_CENTER,"You are Chorao, a famous skater and musician.");
	al_draw_text(menufont,al_map_rgb(255,255,255),width/2,6*height/10+height/20,ALLEGRO_ALIGN_CENTER,"You have to jump over yout enemies");
	al_draw_text(menufont,al_map_rgb(255,255,255),width/2,7*height/10,ALLEGRO_ALIGN_CENTER,"or they might kill you.");
}

void draw_background (int width, int height, ALLEGRO_BITMAP *sol) {

	//	Skybox
	al_clear_to_color(al_map_rgb(0,128,255));
	//	Road
	al_draw_filled_rectangle(0,18*height/20,width,height,al_map_rgb(0,0,0));
	//	Sun
	int sun_w = al_get_bitmap_width(sol);
	int sun_h = al_get_bitmap_height(sol);
	al_draw_scaled_bitmap(sol,0,0,sun_w,sun_h,0,0,sun_w/10,sun_h/10,0);
}

void generate_enemy (ALLEGRO_BITMAP *enemy_1,ALLEGRO_BITMAP *enemy_2,ALLEGRO_BITMAP *enemy_3,int x_pos,int y_pos,int width,int height, int prop, int rnd) {
	int x_scale;
	int y_scale;
	int img_width;
	int img_height;

	switch (rnd) {
	case 0:
		x_scale = width/4;
		y_scale = height/4;
		img_width = al_get_bitmap_width(enemy_1);
		img_height = al_get_bitmap_height(enemy_1);
		al_draw_scaled_bitmap(enemy_1,0,0,img_width,img_height,x_pos,y_pos-(prop*img_height/8),x_scale,y_scale,0);
		break;
	
	case 1:
		x_scale = width/4;
		y_scale = height/4;
		img_width = al_get_bitmap_width(enemy_2);
		img_height = al_get_bitmap_height(enemy_2);
		al_draw_scaled_bitmap(enemy_2,0,0,img_width,img_height,x_pos,y_pos-2*(prop*img_height/8),x_scale,y_scale,0);
		break;

	case 2:
		x_scale = width/4;
		y_scale = height/4;
		img_width = al_get_bitmap_width(enemy_3);
		img_height = al_get_bitmap_height(enemy_3);
		al_draw_scaled_bitmap(enemy_3,0,0,img_width,img_height,x_pos,y_pos-2*(prop*img_height/8),x_scale,y_scale,0);
		break;
		
	default:
		break;
	}
}

void generate_cloud (ALLEGRO_BITMAP *cloud_1,ALLEGRO_BITMAP *cloud_2,ALLEGRO_BITMAP *cloud_3,int x_pos,int y_pos,int width,int height, int prop, int rnd) {
	int x_scale;
	int y_scale;
	int img_width;
	int img_height;

	switch (rnd) {
	case 0:
		img_width = al_get_bitmap_width(cloud_1);
		img_height = al_get_bitmap_height(cloud_1);
		x_scale = width/4;
		y_scale = height/4;
		al_draw_scaled_bitmap(cloud_1,0,0,img_width,img_height,x_pos,y_pos,x_scale,y_scale,0);
		break;
	
	case 1:
		img_width = al_get_bitmap_width(cloud_2);
		img_height = al_get_bitmap_height(cloud_2);
		x_scale = width/4;
		y_scale = height/4;
		al_draw_scaled_bitmap(cloud_2,0,0,img_width,img_height,x_pos,y_pos,x_scale,y_scale,0);
		break;

	case 2:
		img_width = al_get_bitmap_width(cloud_3);
		img_height = al_get_bitmap_height(cloud_3);
		x_scale = width/4;
		y_scale = height/4;
		al_draw_scaled_bitmap(cloud_3,0,0,img_width,img_height,x_pos,y_pos,x_scale,y_scale,0);
		break;
		
	default:
		break;
	}
}

void draw_score (ALLEGRO_BITMAP *skate,int width,int height,int prop,ALLEGRO_FONT *titlefont,int points) {
	int img_width = al_get_bitmap_width(skate);
	int img_height = al_get_bitmap_height(skate);
	al_draw_scaled_bitmap(skate,0,height/20,img_width,img_height,2*width/6,height/20,2*width/6,img_height/6,0);

	al_draw_textf(titlefont,al_map_rgb(255,255,255),width/2,height/20,ALLEGRO_ALIGN_CENTER,"%i",points/2);
}

void draw_player (ALLEGRO_BITMAP *choraoirl,int width[],int height[],int dm,value player_ypos, int prop) {
	
	#ifdef PLACEHOLDER
		al_draw_filled_circle(width[dm]/10,player_ypos,height[dm]/20,al_map_rgb(255,0,255));
	#endif
	#ifndef PLACEHOLDER
		int player_w = al_get_bitmap_width(choraoirl);
		int player_h = al_get_bitmap_height(choraoirl);
		al_draw_scaled_bitmap(choraoirl,0,0,player_w,player_h,width[dm]/10,player_ypos-(prop*player_h/6),prop*player_w/6,prop*player_h/6,0);
	#endif
}

void draw_dead_text (int width, int height, ALLEGRO_FONT *titlefont, ALLEGRO_FONT *menufont) {

	//	Aviso
	al_draw_text(titlefont,al_map_rgb(255,255,255),width/2,height/10,ALLEGRO_ALIGN_CENTER,"WASTED");
	//	Ajuda
	al_draw_text(menufont,al_map_rgb(255,255,255),width/2,3*height/10,ALLEGRO_ALIGN_CENTER,"Press Esc to go back to menu");
}

