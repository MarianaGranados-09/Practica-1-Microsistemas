//Primera practica Microsistemas: 3 Secuencias con LEDs activadas mediante 3 botones
//28 de Enero del 2022
//Laboratorio de microsistemas

/*
#include <18F4550.h>

#FUSES NOWDT                                      
#FUSES NOBROWNOUT              
#FUSES INTRC //Fuse para cristal interno

#use delay(clock=8M)
#byte PORTB=0xF81
//#byte PORTD=0xF83
#byte PORTC=0xF82

void main()
{
   //Secuencia 1
   int8 vector1[] = {0xFF,0x0,0x1,0x2,0x4,0x8,0x10,0x20,0x40,0x80};
   int8 vector1_2[]={0x1,0x3,0x7,0xF,0x1F,0x3F,0x7F,0xFF};
   
   //Secuencia 2
   int8 vector2[] = {0x81,0xC3, 0xE7,0xFF,0x18,0x3C,0x7E, 0xFF};
   
   //Secuencia 3
   int8 vector3[]={0xCC,0x33,0xCC,0x33,0x55,0xAA,0xFF};
   
   while(TRUE)
   {
      //Sec1
      if(input(PIN_C0) == 1)
      {
         for(int8 j=0;j<3;j++)
         {
         
            for(int8 i=0;i<10;i++)
            {
               output_B(vector1[i]);
               delay_ms(100);
            }
         }
         for(int8 k=0;k<3;k++)
         {
               for(int8 n=0;n<8;n++)
               {
                  output_B(vector1_2[n]);
                  delay_ms(50);
               }
         }
         PORTB = 0;
             
      }
      
      //Sec2
       if(input(PIN_C7) == 1)
      {
      for(int8 i=0;i<5;i++)
      {
         for(int8 j=0;j<8;j++)
         {
            output_D(vector2[j]);
            delay_ms(100);
         }
     
      }
         PORTD = 0;
      }
      
        //Sec3
       if(input(PIN_C6) == 1)
      {
         for(int8 i=0;i<8;i++)
         {
            for(int8 j=0;j<6;j++)
            {
            output_D(vector3[j]);
            delay_ms(150);
            }
         }
         PORTD = 0;
      }
   }
}

*/

#include <18F4550.h>

//Codigo con registros para una secuencia

//FUSES
#FUSES NOWDT  //Fuse No watchdog timer
//Fuse que hace el "switcheo" entre el cristal externo e interno o detiene al microcontrolador 
//en caso de que nuestro cristal externo este dañado
#FUSES NOBROWNOUT 
#FUSES INTRC //Fuse para cristal interno

#use delay(clock=8M)

//Direcciones de memoria de los puertos (Pagina 68 del Datasheet del PIC18)
#byte PORTB=0xF81
#byte TRISB=0xF93
#byte PORTD=0xF83
#byte TRISD=0xF95

void main()
{
   //Declaracion de la secuencia 1
   int8 vector1[] = {0xFF,0x0,0x1,0x2,0x4,0x8,0x10,0x20,0x40,0x80};
   int8 vector1_2[]={0x1,0x3,0x7,0xF,0x1F,0x3F,0x7F,0xFF};
   
   while(TRUE)
   {
      TRISB=0x01; //Primer bit del puerto B como entrada para el boton
      TRISD=0x00; //8 terminales de salida para el puerto D
      
      //Enmascaramiento: Operacion logica a nivel de bits
      //00000001 & 00000001
      if(PORTB & 0x01)
      {
         for(int8 j=0;j<3;j++)
         {
         
            for(int8 i=0;i<10;i++)
            {
               PORTD=vector1[i];
               delay_ms(100);
            }
         }
         for(int8 k=0;k<5;k++)
         {
               for(int8 n=0;n<8;n++)
               {
                  PORTD=vector1_2[n];
                  delay_ms(50);
               }
         }
         PORTD = 0x00;
      
      }
      
   }
}
