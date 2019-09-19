/* 
 * File:   lab12_main.c
 * Author: chrysanv & martinz
 *
 * Created on December 6, 2018, 1:04 PM
 */

#include "ece212.h"



/*
 * 
 */
int main(int argc, char** argv) {
    int max_speed, slow_speed, left_sense, right_sense ;
    int threshold; 
    threshold = 0x150; //0x150
    max_speed = 0xEEFF; // EEEE
    slow_speed = 0x2222;  //5566
    
    //inital speed and direction
    RFORWARD = 0x0;
    RBACK = 0x0;
    LFORWARD = 0x0;
    LBACK = 0x0;
    
    ece212_lafbot_setup();
  
    while(1){
        delayms(50); // delay for some amount of time before repeating 
        left_sense = analogRead(LEFT_SENSOR);
        right_sense = analogRead(RIGHT_SENSOR);
        
        if(left_sense < threshold && right_sense <threshold ){
            RFORWARD = 0xFFFF;
            RBACK = 0x0;
            LFORWARD = 0xFFFF;
            LBACK = 0x0;
            
        }
        else if(right_sense >= threshold ){
            RFORWARD = slow_speed;
            RBACK = 0x0;
            LFORWARD = max_speed;
            LBACK = 0x0;
        }
        
        else if(left_sense >= threshold){
            RFORWARD = max_speed;
            RBACK = 0x0;
            LFORWARD = slow_speed;
            LBACK = 0x0;
//        }else
//            RFORWARD = max_speed;
//            RBACK = 0x0;
//            LFORWARD = max_speed;
//            LBACK = 0x0;
//    
    }
    }
    return (EXIT_SUCCESS);
}

