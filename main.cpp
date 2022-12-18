/* mbed Microcontroller Library
 * Copyright (c) 2019 ARM Limited
 * SPDX-License-Identifier: Apache-2.0
 */

#include "mbed.h"
#include "Grove_LCD_RGB_Backlight.h"

#define WAIT_TIME_MS 500 
DigitalIn boton(D4);
Grove_LCD_RGB_Backlight rgbLCD(PB_9,PB_8);
Timer timer;
float tiempo;
char tiempo_pantalla[10];

float funcion(){
    timer.reset();
    timer.start();
    while(boton==1||timer.elapsed_time().count()<100){

    }
    timer.stop();
    tiempo=timer.elapsed_time().count()/1000000;
    return tiempo;
}

int main()
{
    while (true)
    {   
        if(boton==1){
            funcion();
        }
        rgbLCD.setRGB(0xff, 0xff, 0xff);                 //set the color 
        rgbLCD.locate(0,0);
        rgbLCD.print("Tiempo pulsado=");
        rgbLCD.locate(0,1);
        sprintf(tiempo_pantalla, "%f" ,tiempo);
        rgbLCD.print(tiempo_pantalla);
        rgbLCD.locate(14,1);
        rgbLCD.print("s");
        thread_sleep_for(WAIT_TIME_MS);
    }
}
