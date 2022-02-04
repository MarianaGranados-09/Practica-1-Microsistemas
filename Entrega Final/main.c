//Primera practica Microsistemas: 1 Secuencia con LEDs activada mediante un boton (SIN REGISTROS)
//28 de Enero del 2022
//Laboratorio de microsistemas
/*

#include <18F4550.h>

#FUSES NOWDT                                      
#FUSES NOBROWNOUT             
#FUSES INTRC //Fuse para cristal interno

#use delay(clock=8M)

#byte PORTD=0xF83

void main()
{
   //Secuencia 1
   int8 vector1[] = {0xFF,0x0,0x1,0x2,0x4,0x8,0x10,0x20,0x40,0x80};
   int8 vector1_2[]={0x1,0x3,0x7,0xF,0x1F,0x3F,0x7F,0xFF};
   
   while(TRUE)
   {
      //Sec1
      if(input(PIN_B0) == 1)
      {
         for(int8 j=0;j<3;j++)
         {
         
            for(int8 i=0;i<10;i++)
            {
               output_D(vector1[i]);
               delay_ms(100);
            }
         }
         for(int8 k=0;k<3;k++)
         {
               for(int8 n=0;n<8;n++)
               {
                  output_D(vector1_2[n]);
                  delay_ms(50);
               }
         }
         PORTD = 0;
             
      }
   }
}*/
          

/*
#include <18F4550.h>

//Codigo con registros

//FUSES
#FUSES NOWDT  //Fuse No watchdog timer
//Fuse que hace el "switcheo" entre el cristal externo e interno o detiene al microcontrolador 
//en caso de que nuestro cristal externo este dañado
#FUSES NOBROWNOUT 
#FUSES INTRC //Fuse para cristal interno

#use delay(clock=8M)

//Direcciones de memoria de los puertos (Pagina 68 del Datasheet del PIC18F4550)
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
      TRISD=0x00; //8 terminales de salida para el puerto D para salida de secuencia
      
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
*/


/*
//CODIGO UTILIZANDO LAS DIRECTIVAS #USE FIXED_IO, FAST_IO Y STANDARD_IO (DEFINICION DE CADA UNA)
//SIN REGISTROS

#include <18f4550.h>
#fuses INTRC, NOWDT, NOPROTECT
#use delay(clock=8M)
//#byte TRISB=0xF93
//#byte TRISD=0xF95
//#byte PORTD=0xF83
//#byte PORTB=0xF81
//#Use FAST_IO (B)      //Para este tipo de directiva, es necesario utilizar la función "Set_Tris_X(VALOR)". Esta función nos permite escribir directamente en el 
                        //registro TRISX para configurar los puertos como I/O.
//#USE FIXED_IO (D_outputs=PIN_D0, PIN_D1, PIN_D2, PIN_D3, PIN_D4, PIN_D5, PIN_D6, PIN_D7)   
//El registro TRISX se modificará de acuerdo al los puertos indicados en la directiva (solo se indican los terminales de salida), sin tener en
//los demas ya que los configurará como entrada.

#Use STANDARD_IO(B)                  //Se configura como I/O dependiendo de si se utiliza la función "Input_X()" o "Output_X()", es la directiva por defecto.
//Solo funciona si se utilizan las funciones de output o input

void main()
{
   //TRISB=0x00;
   //TRISD=0x01;
   int serie1[]={0x10, 0x18, 0x1C, 0x1E, 0x1F, 0x9F, 0xDF, 0xFF, 0xEF, 0xE7, 0xE3, 0xE1, 0xE0, 0x60, 0x20, 0x00};
   while(TRUE)
   {
      if(input(PIN_B0)==1)
      {
         int i, j;
         for(i=0; i<5; i++)
         {
            for(j=0; j<16; j++)
            {
               output_d(serie1[j]);
               delay_ms(40);
            }
         }
         output_d(0x00);
      }
   }
}
*/
