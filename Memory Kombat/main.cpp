#include <stdio.h>
#include <stdlib.h>
#include <time.h>
// Inclui o cabeçalho da bibilioteca Allegro 5
#include <allegro5/allegro.h> 
// Inclui o cabeçalho do add-on para uso de imagens
#include <allegro5/allegro_image.h>
// Inclui o cabeçalho do add-on para uso de fontes True Type
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>

// Atributos da tela
const int LARGURA_TELA = 1280;
const int ALTURA_TELA = 720;

const int L = 4;
const int C = 5;

ALLEGRO_BITMAP * card[10];
ALLEGRO_BITMAP * aux;
ALLEGRO_BITMAP * TAB[L][C];
ALLEGRO_BITMAP * GAME[L][C];

int pontuacao = 0;
int tentativas = 0;
int change1 = 0;
int change2 = 0;
 
int init_allegro()
{
    // Variável representando a janela principal
    ALLEGRO_DISPLAY *janela = NULL;
    
    ALLEGRO_EVENT_QUEUE *fila_eventos = NULL;
    ALLEGRO_BITMAP *botao_sair = NULL;
    
    // O nosso arquivo de fonte
    ALLEGRO_FONT *fonte = NULL;
    
    // Variáveis representando as imagens
    ALLEGRO_BITMAP *papel_de_parede = NULL;
    ALLEGRO_BITMAP *carta_virada = NULL;
    ALLEGRO_BITMAP *scorpion = NULL;
    ALLEGRO_BITMAP *sub_zero = NULL;
    ALLEGRO_BITMAP *liu_kang = NULL;
    ALLEGRO_BITMAP *kung_lao = NULL;
    ALLEGRO_BITMAP *raiden = NULL;
    ALLEGRO_BITMAP *reptile = NULL;
    ALLEGRO_BITMAP *jhonny_cage = NULL;
    ALLEGRO_BITMAP *kitana = NULL;
    ALLEGRO_BITMAP *jade = NULL;
    ALLEGRO_BITMAP *mileena = NULL;
    
    // Inicializa o add-on para utilização de imagens
    al_init_image_addon();
    
    // Flag que condicionará nosso looping
    int sair = 0;
 
    if (!al_init())
    {
        fprintf(stderr, "Falha ao inicializar a Allegro.\n");
        return -1;
    }
 
    janela = al_create_display(LARGURA_TELA, ALTURA_TELA);
    if (!janela)
    {
        fprintf(stderr, "Falha ao criar janela.\n");
        return -1;
    }
 
    // Configura o título da janela
    al_set_window_title(janela, "Memory Kombat");
 
    // Torna apto o uso de mouse na aplicação
    if (!al_install_mouse())
    {
        fprintf(stderr, "Falha ao inicializar o mouse.\n");
        al_destroy_display(janela);
        return -1;
    }
 
    // Atribui o cursor padrão do sistema para ser usado
    if (!al_set_system_mouse_cursor(janela, ALLEGRO_SYSTEM_MOUSE_CURSOR_DEFAULT))
    {
        fprintf(stderr, "Falha ao atribuir ponteiro do mouse.\n");
        al_destroy_display(janela);
        return -1;
    }
 
    // Alocamos o botão para fechar a aplicação
    botao_sair = al_create_bitmap(100, 50);
    if (!botao_sair)
    {
        fprintf(stderr, "Falha ao criar botão de saída.\n");
        al_destroy_display(janela);
        return -1;
    }
 
    fila_eventos = al_create_event_queue();
    if (!fila_eventos)
    {
        fprintf(stderr, "Falha ao inicializar o fila de eventos.\n");
        al_destroy_display(janela);
        return -1;
    }
    
    // Inicialização do add-on para uso de fontes
    al_init_font_addon();
 
    // Inicialização do add-on para uso de fontes True Type
    if (!al_init_ttf_addon())
    {
        fprintf(stderr, "Falha ao inicializar add-on allegro_ttf.\n");
        return -1;
    }
    
    // Carregando o arquivo de fonte
    fonte = al_load_font("MK4.TTF", 36, 0);
    if (!fonte)
    {
        al_destroy_display(janela);
        fprintf(stderr, "Falha ao carregar fonte.\n");
        return -1;
    }
 
    // Dizemos que vamos tratar os eventos vindos do mouse
    al_register_event_source(fila_eventos, al_get_mouse_event_source());   
        
    papel_de_parede = al_load_bitmap("Papel de Parede.bmp");
    carta_virada = al_load_bitmap("Carta Virada.bmp"); 
    card[0] = al_load_bitmap("Scorpion.bmp");
    card[1] = al_load_bitmap("Sub Zero.bmp");
    card[2] = al_load_bitmap("Liu Kang.bmp");
    card[3] = al_load_bitmap("Kung Lao.bmp");
    card[4] = al_load_bitmap("Raiden.bmp");
    card[5] = al_load_bitmap("Reptile.bmp");
    card[6] = al_load_bitmap("Jhonny Cage.bmp");
    card[7] = al_load_bitmap("Kitana.bmp");
    card[8] = al_load_bitmap("Jade.bmp");
    card[9] = al_load_bitmap("Mileena.bmp");
        
	int i, j, k=0, x, y, a, b, c, d;
	
	for (i=0; i<L; i++)
		for (j=0; j<C; j++){
			TAB[i][j] = card[k];
			GAME[i][j] = carta_virada;
			if (k < 9)
				k++;
			else 
				k = 0;
		}		
	
	srand (time(NULL));
	for (i=0; i<L; i++)
		for (j=0; j<C; j++){
			x = rand()%L;
			y = rand()%C;
			aux = TAB[i][j];
			TAB[i][j] = TAB[x][y];
			TAB[x][y] = aux;
		}         
    
    while (!sair)
    {
        while (pontuacao < 10)
        {
            // Limpamos a tela
            al_clear_to_color(al_map_rgb(0, 0, 0));
     
            // Colorimos o bitmap do botão de sair
            al_set_target_bitmap(botao_sair);
            al_clear_to_color(al_map_rgb(255, 0, 0));        
            
            
            // Desenhamos os retângulos na tela
            al_set_target_bitmap(al_get_backbuffer(janela));
            
            al_draw_bitmap(papel_de_parede, 0, 0, 0);
            
            x = 278;
            y = 38;
    		for (i=0; i<L; i++) {
                for (j=0; j<C; j++) {
                    al_draw_bitmap(GAME[i][j], x, y, 0);
                    x = x + 153;                   
    		    }
                y = y + 166;
                x = 278;
            }
            
            while (change1 < 1)
            {
                // Limpamos a tela
                al_clear_to_color(al_map_rgb(0, 0, 0));
         
                // Colorimos o bitmap do botão de sair
                al_set_target_bitmap(botao_sair);
                al_clear_to_color(al_map_rgb(255, 0, 0));        
                
                
                // Desenhamos os retângulos na tela
                al_set_target_bitmap(al_get_backbuffer(janela));
                
                al_draw_bitmap(papel_de_parede, 0, 0, 0);
                
                x = 278;
                y = 38;
        		for (i=0; i<L; i++) {
                    for (j=0; j<C; j++) {
                        al_draw_bitmap(GAME[i][j], x, y, 0);
                        x = x + 153;                   
        		    }
                    y = y + 166;
                    x = 278;
                }
                        
                // Verificamos se há eventos na fila
                while (!al_is_event_queue_empty(fila_eventos))
                {
                    ALLEGRO_EVENT evento;
                    al_wait_for_event(fila_eventos, &evento); 
                    
                    // Se o evento foi um clique do mouse
                    if (evento.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP)
                    {
                        if (evento.mouse.x >= LARGURA_TELA - al_get_bitmap_width(botao_sair) - 10 &&
                            evento.mouse.x <= LARGURA_TELA - 10 && evento.mouse.y <= ALTURA_TELA - 10 &&
                            evento.mouse.y >= ALTURA_TELA - al_get_bitmap_height(botao_sair) - 10)
                        {
                            sair = 1;
                            break;
                        }                
                    
                        if (evento.mouse.x >= 278 && evento.mouse.x <= 391 &&
                            evento.mouse.y >= 38 && evento.mouse.y <= 188)
                        {                        
                            GAME[0][0] = TAB[0][0];
                            change1++;
                            a = 0;
                            b = 0;                                              
                        }
                        
                        if (evento.mouse.x >= 436 && evento.mouse.x <= 549 &&
                            evento.mouse.y >= 38 && evento.mouse.y <= 188)
                        {
                            GAME[0][1] = TAB[0][1];
                            change1++;
                            a = 0;
                            b = 1;
                        }
                        
                        if (evento.mouse.x >= 589 && evento.mouse.x <= 702 &&
                            evento.mouse.y >= 38 && evento.mouse.y <= 188)
                        {
                            GAME[0][2] = TAB[0][2];
                            change1++;
                            a = 0;
                            b = 2;
                        }
                        
                        if (evento.mouse.x >= 742 && evento.mouse.x <= 855 &&
                            evento.mouse.y >= 38 && evento.mouse.y <= 188)
                        {
                            GAME[0][3] = TAB[0][3];
                            change1++;
                            a = 0;
                            b = 3;
                        }
                        
                        if (evento.mouse.x >= 895 && evento.mouse.x <= 1008 &&
                            evento.mouse.y >= 38 && evento.mouse.y <= 188)
                        {
                            GAME[0][4] = TAB[0][4];
                            change1++;
                            a = 0;
                            b = 4;
                        }
                        
                        if (evento.mouse.x >= 278 && evento.mouse.x <= 391 &&
                            evento.mouse.y >= 204 && evento.mouse.y <= 354)
                        {
                            GAME[1][0] = TAB[1][0];
                            change1++;
                            a = 1;
                            b = 0;
                        }
                        
                        if (evento.mouse.x >= 436 && evento.mouse.x <= 549 &&
                            evento.mouse.y >= 204 && evento.mouse.y <= 354)
                        {
                            GAME[1][1] = TAB[1][1];
                            change1++;
                            a = 1;
                            b = 1;
                        }
                        
                        if (evento.mouse.x >= 589 && evento.mouse.x <= 702 &&
                            evento.mouse.y >= 204 && evento.mouse.y <= 354)
                        {
                            GAME[1][2] = TAB[1][2];
                            change1++;
                            a = 1;
                            b = 2;
                        }
                        
                        if (evento.mouse.x >= 742 && evento.mouse.x <= 855 &&
                            evento.mouse.y >= 204 && evento.mouse.y <= 354)
                        {
                            GAME[1][3] = TAB[1][3];
                            change1++;
                            a = 1;
                            b = 3;
                        }
                        
                        if (evento.mouse.x >= 895 && evento.mouse.x <= 1008 &&
                            evento.mouse.y >= 204 && evento.mouse.y <= 354)
                        {
                            GAME[1][4] = TAB[1][4];
                            change1++;
                            a = 1;
                            b = 4;
                        }
                        
                        if (evento.mouse.x >= 278 && evento.mouse.x <= 391 &&
                            evento.mouse.y >= 370 && evento.mouse.y <= 520)
                        {
                            GAME[2][0] = TAB[2][0];
                            change1++;
                            a = 2;
                            b = 0;
                        }
                        
                        if (evento.mouse.x >= 436 && evento.mouse.x <= 549 &&
                            evento.mouse.y >= 370 && evento.mouse.y <= 520)
                        {
                            GAME[2][1] = TAB[2][1];
                            change1++;
                            a = 2;
                            b = 1;
                        }
                        
                        if (evento.mouse.x >= 589 && evento.mouse.x <= 702 &&
                            evento.mouse.y >= 370 && evento.mouse.y <= 520)
                        {
                            GAME[2][2] = TAB[2][2];
                            change1++;
                            a = 2;
                            b = 2;
                        }
                        
                        if (evento.mouse.x >= 742 && evento.mouse.x <= 855 &&
                            evento.mouse.y >= 370 && evento.mouse.y <= 520)
                        {
                            GAME[2][3] = TAB[2][3];
                            change1++;
                            a = 2;
                            b = 3;                       
                        }
                        
                        if (evento.mouse.x >= 895 && evento.mouse.x <= 1008 &&
                            evento.mouse.y >= 370 && evento.mouse.y <= 520)
                        {
                            GAME[2][4] = TAB[2][4];
                            change1++;
                            a = 2;
                            b = 4;
                        }
                        
                        if (evento.mouse.x >= 278 && evento.mouse.x <= 391 &&
                            evento.mouse.y >= 536 && evento.mouse.y <= 686)
                        {
                            GAME[3][0] = TAB[3][0];
                            change1++;
                            a = 3;
                            b = 0;
                        }
                        
                        if (evento.mouse.x >= 436 && evento.mouse.x <= 549 &&
                            evento.mouse.y >= 536 && evento.mouse.y <= 686)
                        {
                            GAME[3][1] = TAB[3][1];
                            change1++;
                            a = 3;
                            b = 1;
                        }
                        
                        if (evento.mouse.x >= 589 && evento.mouse.x <= 702 &&
                            evento.mouse.y >= 536 && evento.mouse.y <= 686)
                        {
                            GAME[3][2] = TAB[3][2];
                            change1++;
                            a = 3;
                            b = 2;
                        }
                        
                        if (evento.mouse.x >= 742 && evento.mouse.x <= 855 &&
                            evento.mouse.y >= 536 && evento.mouse.y <= 686)
                        {
                            GAME[3][3] = TAB[3][3];
                            change1++;
                            a = 3;
                            b = 3;
                        }
                        
                        if (evento.mouse.x >= 895 && evento.mouse.x <= 1008 &&
                            evento.mouse.y >= 536 && evento.mouse.y <= 686)
                        {
                            GAME[3][4] = TAB[3][4];
                            change1++;
                            a = 3;
                            b = 4;
                        }            
                    }
                }
                
                al_draw_bitmap(botao_sair, LARGURA_TELA - al_get_bitmap_width(botao_sair) - 10,
                               ALTURA_TELA - al_get_bitmap_height(botao_sair) - 10, 0);
                           
                // Texto alinhado à direita
                al_draw_textf(fonte, al_map_rgb(0, 206, 209), 140, 50, ALLEGRO_ALIGN_CENTRE, "Pontuacao: %d", pontuacao);
                al_draw_textf(fonte, al_map_rgb(0, 206, 209), 140, 100, ALLEGRO_ALIGN_CENTRE, "Tentativas: %d", tentativas);
            
                               
                // Atualiza a tela
                al_flip_display();
            } 
            
            while (change2 < 1)
            {
                // Limpamos a tela
                al_clear_to_color(al_map_rgb(0, 0, 0));
         
                // Colorimos o bitmap do botão de sair
                al_set_target_bitmap(botao_sair);
                al_clear_to_color(al_map_rgb(255, 0, 0));        
                
                
                // Desenhamos os retângulos na tela
                al_set_target_bitmap(al_get_backbuffer(janela));
                
                al_draw_bitmap(papel_de_parede, 0, 0, 0);
                
                x = 278;
                y = 38;
        		for (i=0; i<L; i++) {
                    for (j=0; j<C; j++) {
                        al_draw_bitmap(GAME[i][j], x, y, 0);
                        x = x + 153;                   
        		    }
                    y = y + 166;
                    x = 278;
                }
                        
                // Verificamos se há eventos na fila
                while (!al_is_event_queue_empty(fila_eventos))
                {
                    ALLEGRO_EVENT evento;
                    al_wait_for_event(fila_eventos, &evento); 
                    
                    // Se o evento foi um clique do mouse
                    if (evento.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP)
                    {
                        if (evento.mouse.x >= LARGURA_TELA - al_get_bitmap_width(botao_sair) - 10 &&
                            evento.mouse.x <= LARGURA_TELA - 10 && evento.mouse.y <= ALTURA_TELA - 10 &&
                            evento.mouse.y >= ALTURA_TELA - al_get_bitmap_height(botao_sair) - 10)
                        {
                            sair = 1;
                            break;
                        }                
                    
                        if (evento.mouse.x >= 278 && evento.mouse.x <= 391 &&
                            evento.mouse.y >= 38 && evento.mouse.y <= 188)
                        {                        
                            GAME[0][0] = TAB[0][0];
                            change2++;
                            c = 0;
                            d = 0;                                             
                        }
                        
                        if (evento.mouse.x >= 436 && evento.mouse.x <= 549 &&
                            evento.mouse.y >= 38 && evento.mouse.y <= 188)
                        {
                            GAME[0][1] = TAB[0][1];
                            change2++;
                            c = 0;
                            d = 1;
                        }
                        
                        if (evento.mouse.x >= 589 && evento.mouse.x <= 702 &&
                            evento.mouse.y >= 38 && evento.mouse.y <= 188)
                        {
                            GAME[0][2] = TAB[0][2];
                            change2++;
                            c = 0;
                            d = 2;
                        }
                        
                        if (evento.mouse.x >= 742 && evento.mouse.x <= 855 &&
                            evento.mouse.y >= 38 && evento.mouse.y <= 188)
                        {
                            GAME[0][3] = TAB[0][3];
                            change2++;
                            c = 0;
                            d = 3;
                        }
                        
                        if (evento.mouse.x >= 895 && evento.mouse.x <= 1008 &&
                            evento.mouse.y >= 38 && evento.mouse.y <= 188)
                        {
                            GAME[0][4] = TAB[0][4];
                            change2++;
                            c = 0;
                            d = 4;
                        }
                        
                        if (evento.mouse.x >= 278 && evento.mouse.x <= 391 &&
                            evento.mouse.y >= 204 && evento.mouse.y <= 354)
                        {
                            GAME[1][0] = TAB[1][0];
                            change2++;
                            c = 1;
                            d = 0;
                        }
                        
                        if (evento.mouse.x >= 436 && evento.mouse.x <= 549 &&
                            evento.mouse.y >= 204 && evento.mouse.y <= 354)
                        {
                            GAME[1][1] = TAB[1][1];
                            change2++;
                            c = 1;
                            d = 1;
                        }
                        
                        if (evento.mouse.x >= 589 && evento.mouse.x <= 702 &&
                            evento.mouse.y >= 204 && evento.mouse.y <= 354)
                        {
                            GAME[1][2] = TAB[1][2];
                            change2++;
                            c = 1;
                            d = 2;
                        }
                        
                        if (evento.mouse.x >= 742 && evento.mouse.x <= 855 &&
                            evento.mouse.y >= 204 && evento.mouse.y <= 354)
                        {
                            GAME[1][3] = TAB[1][3];
                            change2++;
                            c = 1;
                            d = 3;
                        }
                        
                        if (evento.mouse.x >= 895 && evento.mouse.x <= 1008 &&
                            evento.mouse.y >= 204 && evento.mouse.y <= 354)
                        {
                            GAME[1][4] = TAB[1][4];
                            change2++;
                            c = 1;
                            d = 4;
                        }
                        
                        if (evento.mouse.x >= 278 && evento.mouse.x <= 391 &&
                            evento.mouse.y >= 370 && evento.mouse.y <= 520)
                        {
                            GAME[2][0] = TAB[2][0];
                            change2++;
                            c = 2;
                            d = 0;
                        }
                        
                        if (evento.mouse.x >= 436 && evento.mouse.x <= 549 &&
                            evento.mouse.y >= 370 && evento.mouse.y <= 520)
                        {
                            GAME[2][1] = TAB[2][1];
                            change2++;
                            c = 2;
                            d = 1;
                        }
                        
                        if (evento.mouse.x >= 589 && evento.mouse.x <= 702 &&
                            evento.mouse.y >= 370 && evento.mouse.y <= 520)
                        {
                            GAME[2][2] = TAB[2][2];
                            change2++;
                            c = 2;
                            d = 2;
                        }
                        
                        if (evento.mouse.x >= 742 && evento.mouse.x <= 855 &&
                            evento.mouse.y >= 370 && evento.mouse.y <= 520)
                        {
                            GAME[2][3] = TAB[2][3];
                            change2++;
                            c = 2;
                            d = 3;                       
                        }
                        
                        if (evento.mouse.x >= 895 && evento.mouse.x <= 1008 &&
                            evento.mouse.y >= 370 && evento.mouse.y <= 520)
                        {
                            GAME[2][4] = TAB[2][4];
                            change2++;
                            c = 2;
                            d = 4;
                        }
                        
                        if (evento.mouse.x >= 278 && evento.mouse.x <= 391 &&
                            evento.mouse.y >= 536 && evento.mouse.y <= 686)
                        {
                            GAME[3][0] = TAB[3][0];
                            change2++;
                            c = 3;
                            d = 0;
                        }
                        
                        if (evento.mouse.x >= 436 && evento.mouse.x <= 549 &&
                            evento.mouse.y >= 536 && evento.mouse.y <= 686)
                        {
                            GAME[3][1] = TAB[3][1];
                            change2++;
                            c = 3;
                            d = 1;
                        }
                        
                        if (evento.mouse.x >= 589 && evento.mouse.x <= 702 &&
                            evento.mouse.y >= 536 && evento.mouse.y <= 686)
                        {
                            GAME[3][2] = TAB[3][2];
                            change2++;
                            c = 3;
                            d = 2;
                        }
                        
                        if (evento.mouse.x >= 742 && evento.mouse.x <= 855 &&
                            evento.mouse.y >= 536 && evento.mouse.y <= 686)
                        {
                            GAME[3][3] = TAB[3][3];
                            change2++;
                            c = 3;
                            d = 3;
                        }
                        
                        if (evento.mouse.x >= 895 && evento.mouse.x <= 1008 &&
                            evento.mouse.y >= 536 && evento.mouse.y <= 686)
                        {
                            GAME[3][4] = TAB[3][4];
                            change2++;
                            c = 3;
                            d = 4;
                        }            
                    }
                }
                
                al_draw_bitmap(botao_sair, LARGURA_TELA - al_get_bitmap_width(botao_sair) - 10,
                               ALTURA_TELA - al_get_bitmap_height(botao_sair) - 10, 0);
                           
                // Texto alinhado à direita
                al_draw_textf(fonte, al_map_rgb(0, 206, 209), 140, 50, ALLEGRO_ALIGN_CENTRE, "Pontuacao: %d", pontuacao);
                al_draw_textf(fonte, al_map_rgb(0, 206, 209), 140, 100, ALLEGRO_ALIGN_CENTRE, "Tentativas: %d", tentativas);
            
                               
                // Atualiza a tela
                al_flip_display();
            }
            
            if (change2 > 0){
                    if(GAME[a][b] == GAME[c][d]) 
                    {
                       pontuacao++;
                       tentativas++;
                       change1 = 0;
                       change2 = 0;
                    } else
                    {                  
                        tentativas++;
                        {
                            // Limpamos a tela
                            al_clear_to_color(al_map_rgb(0, 0, 0));
                     
                            // Colorimos o bitmap do botão de sair
                            al_set_target_bitmap(botao_sair);
                            al_clear_to_color(al_map_rgb(255, 0, 0));        
                            
                            
                            // Desenhamos os retângulos na tela
                            al_set_target_bitmap(al_get_backbuffer(janela));
                            
                            al_draw_bitmap(papel_de_parede, 0, 0, 0);
                            
                            x = 278;
                            y = 38;
                    		for (i=0; i<L; i++) {
                                for (j=0; j<C; j++) {
                                    al_draw_bitmap(GAME[i][j], x, y, 0);
                                    x = x + 153;                   
                    		    }
                                y = y + 166;
                                x = 278;
                            }
                            al_draw_bitmap(botao_sair, LARGURA_TELA - al_get_bitmap_width(botao_sair) - 10,
                                           ALTURA_TELA - al_get_bitmap_height(botao_sair) - 10, 0);
                                       
                            // Texto alinhado à direita
                            al_draw_textf(fonte, al_map_rgb(0, 206, 209), 140, 50, ALLEGRO_ALIGN_CENTRE, "Pontuacao: %d", pontuacao);
                            al_draw_textf(fonte, al_map_rgb(0, 206, 209), 140, 100, ALLEGRO_ALIGN_CENTRE, "Tentativas: %d", tentativas);
                        
                                           
                            // Atualiza a tela
                            al_flip_display();           
                        }
                        Sleep (1000);
                        GAME[a][b] = carta_virada;                    
                        GAME[c][d] = carta_virada;
                        change1 = 0;
                        change2 = 0;
                    }
                }
            
            al_draw_bitmap(botao_sair, LARGURA_TELA - al_get_bitmap_width(botao_sair) - 10,
                           ALTURA_TELA - al_get_bitmap_height(botao_sair) - 10, 0);
                       
            // Texto alinhado à direita
            al_draw_textf(fonte, al_map_rgb(0, 206, 209), 140, 50, ALLEGRO_ALIGN_CENTRE, "Pontuacao: %d", pontuacao);
            al_draw_textf(fonte, al_map_rgb(0, 206, 209), 140, 100, ALLEGRO_ALIGN_CENTRE, "Tentativas: %d", tentativas);
        
                           
            // Atualiza a tela
            al_flip_display();
        }
    }   
     
 
    // Desaloca os recursos utilizados na aplicação
    al_destroy_bitmap(botao_sair);
    al_destroy_font(fonte);
    al_destroy_display(janela);
    al_destroy_event_queue(fila_eventos);
 
    return 0;
}

int main(void)
{    
    init_allegro();
    //system("pause");  
}
