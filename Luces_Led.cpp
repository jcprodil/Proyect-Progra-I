
#include <stdio.h>
#include <stdlib.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>                       
#define MAXCOLOR 256                                    //Defino constantes
#define WIDE 1000
#define LENGHT 1000 
#define FPS 60
#define LIGHT_AREA 60
#define LIGHT_HIGH 1000
#define LIGHT_CANTIDAD 8



/*
*
*/
int main(void) {
    
    ALLEGRO_DISPLAY * display=NULL; 
    ALLEGRO_EVENT_QUEUE * eventos=NULL;         //Defino punteros a el display, los eventos, el timer y dos bitmaps
    ALLEGRO_TIMER * timer=NULL; 
    
    ALLEGRO_BITMAP * lighton=NULL;
    ALLEGRO_BITMAP * lightoff=NULL; 
    
    
    
    
    if(!al_init()){
        fprintf(stderr,"No se pudo inicializar allegro\n");        //Inicializo el teclado, allegro, el timer,etc     //
        return EOF;
    }
    
    if(!al_install_keyboard()){
        fprintf(stderr,"No se pudo instalar  el teclado");
        return EOF;
    }
    
    
    
    timer=al_create_timer(1.0/FPS); //creo timer
    if(!timer){
        fprintf(stderr,"No se pudo crear timer\n"); 
        return EOF;
    }
    
    
    display=al_create_display(WIDE,LENGHT);                         //Creo el display y los bitmaps de "luz encendida" y "luz apagada"
    if(!display){
        fprintf(stderr,"No se pudo crear el display\n");
        al_destroy_timer(timer); 
        return EOF;
    }
    
    
    
    lighton=al_create_bitmap(LIGHT_AREA,LIGHT_HIGH);
      if(!lighton){
          fprintf(stderr,"No se creo el bitmap. Error.\n"); 
          al_destroy_display(display);
          al_destroy_timer(timer);
          return -1;
      }
    lightoff=al_create_bitmap(LIGHT_AREA,LIGHT_HIGH);
      if(!lightoff){
          fprintf(stderr,"No se creo el segundo bitmap.Error.\n");
          al_destroy_display(display);
          al_destroy_timer(timer);
          al_destroy_bitmap(lighton);
          return -1;
      }
  
      bool KEY[12]={false,false,false,false,false,false,false,false,false,false,false,false};   //Creo variables de tipo "bool" para las teclas del teclado.
    bool DRAW=true;
    bool END=false;
    unsigned int count=0;                                               //Creo los contadores que usare despues
    unsigned int count1=0;
    unsigned int count2=0;
   
    for(count,count1,count2;count<MAXCOLOR;count+=4,count1+=1,count2+=1)//Funcion para pintar el display de un color rosado
    { al_clear_to_color(al_map_rgb(count,count1,count2)); 
        al_flip_display();
        al_rest(0.001);
    }
    
    
      
     count=0; 

    
    al_set_target_bitmap(lighton);                          //Seteo el bitmap de la luz encendida y lo pinto
    al_clear_to_color(al_map_rgb(255,255,255)); 
    al_set_target_bitmap(lightoff);                         //Seteo el bitmap de la luz apagada y lo pinto
    al_clear_to_color(al_map_rgb(0,0,0));                   
      
    al_set_target_bitmap(al_get_backbuffer(display));   //Ahora, seteo para modificar el buffer directamente
    

    
    
    while(count<LIGHT_CANTIDAD){
    
        al_draw_bitmap(lightoff,(LIGHT_AREA/(2.0))+count*(WIDE/LIGHT_CANTIDAD),LENGHT/2-(LIGHT_HIGH/2.0),0);
       
        ++count;
                
    }                                               //Creo que los leds a cierta distancia simetrica entre si, y aplasto el buffer contra el display
    
    al_flip_display();
    
   
    eventos=al_create_event_queue();                  //Creo el puntero a eventos
    if(!eventos){
          fprintf(stderr,"No se pudo  crear el evento\n");
          al_destroy_bitmap(lighton);
          al_destroy_bitmap(lightoff);
          al_destroy_display(display);
          al_destroy_timer(timer);
          return -1;
    } 

    al_register_event_source(eventos,al_get_display_event_source(display));//Seteo el programa para que registre los eventos delteclado, display y el timer
    al_register_event_source(eventos,al_get_keyboard_event_source()); 
    al_register_event_source(eventos,al_get_timer_event_source(timer));
      
    al_start_timer(timer);                                                  //Inicializo el timer
    

    
    bool on[8]={false,false,false,false,false,false,false,false};           //Uso bools para diferenciar entre el led encendido y apagado
    
   
    
    enum KEY{CERO,UNO,DOS,TRES,CUATRO,CINCO,SEIS,SIETE,ESC,C,S,B};          //Le pongo nombre a las teclas
    
    while(!END){
          ALLEGRO_EVENT event; 
          
          
          
          al_wait_for_event(eventos,&event);                //Espero al evento...
          
          
          if(event.type==ALLEGRO_EVENT_TIMER){ 
              if(KEY[ESC]){
                  break;
              }
              if(KEY[B]){                       //Dentro de esta parte, pinto el display mediante un flip de los bimaps y los apago constantemente. Es como si parpadeara
                                
                                        if(on[0]){
                                        al_draw_bitmap(lightoff,(LIGHT_AREA/(2.0))+7*(WIDE/LIGHT_CANTIDAD),LENGHT/2-(LIGHT_HIGH/2.0),0);
                                        on[0]=false;
                                        }
                                        else{
                                        al_draw_bitmap(lighton,(LIGHT_AREA/(2.0))+7*(WIDE/LIGHT_CANTIDAD),LENGHT/2-(LIGHT_HIGH/2.0),0);
                                        on[0]=true;
                                        }
                                        if(on[1]){
                                        al_draw_bitmap(lightoff,(LIGHT_AREA/(2.0))+6*(WIDE/LIGHT_CANTIDAD),LENGHT/2-(LIGHT_HIGH/2.0),0);
                                        on[1]=false;
                                        }
                                        else{
                                        al_draw_bitmap(lighton,(LIGHT_AREA/(2.0))+6*(WIDE/LIGHT_CANTIDAD),LENGHT/2-(LIGHT_HIGH/2.0),0);
                                        on[1]=true;
                                        }
                                        if(on[2]){
                                        al_draw_bitmap(lightoff,(LIGHT_AREA/(2.0))+5*(WIDE/LIGHT_CANTIDAD),LENGHT/2-(LIGHT_HIGH/2.0),0);
                                        on[2]=false;
                                        }
                                        else{
                                        al_draw_bitmap(lighton,(LIGHT_AREA/(2.0))+5*(WIDE/LIGHT_CANTIDAD),LENGHT/2-(LIGHT_HIGH/2.0),0);
                                        on[2]=true;
                                        }
                                        if(on[3]){
                                        al_draw_bitmap(lightoff,(LIGHT_AREA/(2.0))+4*(WIDE/LIGHT_CANTIDAD),LENGHT/2-(LIGHT_HIGH/2.0),0);
                                        on[3]=false;
                                        }
                                        else{
                                        al_draw_bitmap(lighton,(LIGHT_AREA/(2.0))+4*(WIDE/LIGHT_CANTIDAD),LENGHT/2-(LIGHT_HIGH/2.0),0);
                                        on[3]=true;
                                        }
                                        if(on[4]){
                                        al_draw_bitmap(lightoff,(LIGHT_AREA/(2.0))+3*(WIDE/LIGHT_CANTIDAD),LENGHT/2-(LIGHT_HIGH/2.0),0);
                                        on[4]=false;
                                        }
                                        else{
                                        al_draw_bitmap(lighton,(LIGHT_AREA/(2.0))+3*(WIDE/LIGHT_CANTIDAD),LENGHT/2-(LIGHT_HIGH/2.0),0);
                                        on[4]=true;
                                        }
                                        if(on[5]){
                                        al_draw_bitmap(lightoff,(LIGHT_AREA/(2.0))+2*(WIDE/LIGHT_CANTIDAD),LENGHT/2-(LIGHT_HIGH/2.0),0);
                                        on[5]=false;
                                        }
                                        else{
                                        al_draw_bitmap(lighton,(LIGHT_AREA/(2.0))+2*(WIDE/LIGHT_CANTIDAD),LENGHT/2-(LIGHT_HIGH/2.0),0);
                                        on[5]=true;
                                        }
                                        if(on[6]){
                                        al_draw_bitmap(lightoff,(LIGHT_AREA/(2.0))+1*(WIDE/LIGHT_CANTIDAD),LENGHT/2-(LIGHT_HIGH/2.0),0);
                                        on[6]=false;
                                        }
                                        else{
                                        al_draw_bitmap(lighton,(LIGHT_AREA/(2.0))+1*(WIDE/LIGHT_CANTIDAD),LENGHT/2-(LIGHT_HIGH/2.0),0);
                                        on[6]=true;
                                        }
                                        if(on[7]){
                                        al_draw_bitmap(lightoff,(LIGHT_AREA/(2.0)),LENGHT/2-(LIGHT_HIGH/2.0),0);
                                        on[7]=false;
                                        }
                                        else{
                                        al_draw_bitmap(lighton,(LIGHT_AREA/(2.0)),LENGHT/2-(LIGHT_HIGH/2.0),0);
                                        on[7]=true;
                                        }
                                        al_flip_display();
                                        

                  
              }
              
              
          }
          if(event.type==ALLEGRO_EVENT_KEY_DOWN){
              switch(event.keyboard.keycode){                               
                  case ALLEGRO_KEY_0: KEY[CERO]=true; //Tomo las teclas dadas por alegro, y me fijo si el evento me marca que estan apretadas. Deser asi, se prende el led.
                                        if(on[0]){
                                        al_draw_bitmap(lightoff,(LIGHT_AREA/(2.0)),LENGHT/2-(LIGHT_HIGH/2.0),0);
                                        on[0]=false;
                                        }
                                        else{
                                        al_draw_bitmap(lighton,(LIGHT_AREA/(2.0)),LENGHT/2-(LIGHT_HIGH/2.0),0);
                                        on[0]=true;
                                        }
                                        al_flip_display();
                                        break;
                  
                  case ALLEGRO_KEY_1: KEY[UNO]=true;
                                        if(on[1]){
                                        al_draw_bitmap(lightoff,(LIGHT_AREA/(2.0))+1*(WIDE/LIGHT_CANTIDAD),LENGHT/2-(LIGHT_HIGH/2.0),0);
                                        on[1]=false;
                                        }
                                        else{
                                        al_draw_bitmap(lighton,(LIGHT_AREA/(2.0))+1*(WIDE/LIGHT_CANTIDAD),LENGHT/2-(LIGHT_HIGH/2.0),0);
                                        on[1]=true;
                                        }
                                        al_flip_display();
                                        break;
                  case ALLEGRO_KEY_2: KEY[DOS]=true;
                                        if(on[2]){
                                        al_draw_bitmap(lightoff,(LIGHT_AREA/(2.0))+2*(WIDE/LIGHT_CANTIDAD),LENGHT/2-(LIGHT_HIGH/2.0),0);
                                        on[2]=false;
                                        }
                                        else{
                                        al_draw_bitmap(lighton,(LIGHT_AREA/(2.0))+2*(WIDE/LIGHT_CANTIDAD),LENGHT/2-(LIGHT_HIGH/2.0),0);
                                        on[2]=true;
                                        }
                                        al_flip_display();
                                        break;
                                         
                  case ALLEGRO_KEY_3: KEY[TRES]=true;
                                        if(on[3]){
                                        al_draw_bitmap(lightoff,(LIGHT_AREA/(2.0))+3*(WIDE/LIGHT_CANTIDAD),LENGHT/2-(LIGHT_HIGH/2.0),0);
                                        on[3]=false;
                                        }
                                        else{
                                        al_draw_bitmap(lighton,(LIGHT_AREA/(2.0))+3*(WIDE/LIGHT_CANTIDAD),LENGHT/2-(LIGHT_HIGH/2.0),0);
                                        on[3]=true;
                                        }
                                        al_flip_display();
                                        break;
                  case ALLEGRO_KEY_4:  KEY[CUATRO]=true;
                                        if(on[4]){
                                        al_draw_bitmap(lightoff,(LIGHT_AREA/(2.0))+4*(WIDE/LIGHT_CANTIDAD),LENGHT/2-(LIGHT_HIGH/2.0),0);
                                        on[4]=false;
                                        }
                                        else{
                                        al_draw_bitmap(lighton,(LIGHT_AREA/(2.0))+4*(WIDE/LIGHT_CANTIDAD),LENGHT/2-(LIGHT_HIGH/2.0),0);
                                        on[4]=true;
                                        }
                                        al_flip_display();
                                        break;
                  case ALLEGRO_KEY_5: KEY[CINCO]=true;
                                        if(on[5]){
                                        al_draw_bitmap(lightoff,(LIGHT_AREA/(2.0))+5*(WIDE/LIGHT_CANTIDAD),LENGHT/2-(LIGHT_HIGH/2.0),0);
                                        on[5]=false;
                                        }
                                        else{
                                        al_draw_bitmap(lighton,(LIGHT_AREA/(2.0))+5*(WIDE/LIGHT_CANTIDAD),LENGHT/2-(LIGHT_HIGH/2.0),0);
                                        on[5]=true;
                                        }
                                        al_flip_display();
                                        break;
                  case ALLEGRO_KEY_6: KEY[SEIS]=true;
                                        if(on[6]){
                                        al_draw_bitmap(lightoff,(LIGHT_AREA/(2.0))+6*(WIDE/LIGHT_CANTIDAD),LENGHT/2-(LIGHT_HIGH/2.0),0);
                                        on[6]=false;
                                        }
                                        else{
                                        al_draw_bitmap(lighton,(LIGHT_AREA/(2.0))+6*(WIDE/LIGHT_CANTIDAD),LENGHT/2-(LIGHT_HIGH/2.0),0);
                                        on[6]=true;
                                        }
                                        al_flip_display();
                                        break;
                  case ALLEGRO_KEY_7: KEY[SIETE]=true;
                                        if(on[7]){
                                        al_draw_bitmap(lightoff,(LIGHT_AREA/(2.0))+7*(WIDE/LIGHT_CANTIDAD),LENGHT/2-(LIGHT_HIGH/2.0),0);
                                        on[7]=false;
                                        }
                                        else{
                                        al_draw_bitmap(lighton,(LIGHT_AREA/(2.0))+7*(WIDE/LIGHT_CANTIDAD),LENGHT/2-(LIGHT_HIGH/2.0),0);
                                        on[7]=true;
                                        }
                                        al_flip_display();
                                        break;
                  case ALLEGRO_KEY_C: count=0;
                                        while(count<LIGHT_CANTIDAD){
    
                                            al_draw_bitmap(lightoff,(LIGHT_AREA/(2.0))+count*(WIDE/LIGHT_CANTIDAD),LENGHT/2-(LIGHT_HIGH/2.0),0);
       
                                            ++count;
                
                                        }
                                        al_flip_display();
                                        count1=0;
                                        for(count1;count1<8;count1++)
                                        {on[count1]=false;
                                        }
                                        break;
                  case ALLEGRO_KEY_S: count=0;
                                        while(count<LIGHT_CANTIDAD){
    
                                            al_draw_bitmap(lighton,(LIGHT_AREA/(2.0))+count*(WIDE/LIGHT_CANTIDAD),LENGHT/2-(LIGHT_HIGH/2.0),0);
       
                                            ++count;
                
                                        }
                                        al_flip_display();
                                        count2=0;
                                        for(count2;count2<8;count2++)                  
                                        {on[count2]=true;
                                        }
                                        break;
                  case ALLEGRO_KEY_B:  KEY[B]=true;
                                      break;
                                        
                                        
                      
                      
                  default: break; 
              }
          }
          if(event.type==ALLEGRO_EVENT_KEY_UP){         // Si aprieto escape, salgo del programa
              switch(event.keyboard.keycode){
                  case ALLEGRO_KEY_ESCAPE: KEY[ESC]=true; 
                                           break;
                  case ALLEGRO_KEY_B:    KEY[B]=false;
                                           break; 
                                          
                  default:break;
              }
          }
              
                  
        
        
        
        
    } 
        
    
    
    

    return 0;
}

