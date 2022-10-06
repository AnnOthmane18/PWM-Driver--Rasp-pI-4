#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "pwm.h"


// choisir le canal pwm0 ou pwm1

int load_pwm(S_PWM *ps_pwm, char id_canal[2]){

FILE *p_pwm; //declaring the file where we gonna write the id

    if ((p_pwm = fopen("/sys/class/pwm/pwmchip0/export", "w")) == NULL)
    {
        printf("Cannot open export file.\n");
        exit(1);
    }
    rewind(p_pwm); //putting the cursor on the first line, first column of the file
    strcpy(ps_pwm->id_canal, id_canal);
    fwrite(&ps_pwm->id_canal, sizeof(char), 1, p_pwm); //storing the id in the declared file
    fclose(p_pwm);
  
    return 0;
}

//Enable Disable Function

int set_pwm_enable(S_PWM *ps_pwm, int i_enable)
{
    FILE *p_pwm_enable;
    char pwm_enable[37];
    char c_enable[2];
        //data formatting into char array
        sprintf(pwm_enable, "/sys/class/pwm/pwmchip0/pwm%s/enable", ps_pwm->id_canal);
        
        if ((p_pwm_enable = fopen(pwm_enable, "w")) == NULL)
        {
            printf("Cannot open enable file.\n");
            exit(1);
        }
        rewind(p_pwm_enable);//putting the cursor on the first line, first column of the file
        sprintf(c_enable, "%d", i_enable);//data formatting into char array
        ps_pwm->enable = i_enable;//storing the value in the pin struct
        fwrite(&c_enable, sizeof(char), 1, p_pwm_enable);//writing the value(ENable 1 || DIsable 0) in the declared file
        fclose(p_pwm_enable);
  
    return 0;
}

//Defifing the pwm Period

int set_pwm_period(S_PWM *ps_pwm, long long int i_period){

    FILE *p_pwm_period;
    char pwm_period[37];
    char c_period[8];
    
    set_pwm_enable(ps_pwm,0); // DISABLING THE PIN BEFORE CHANGING ANY VALUE (Peiod or Duty Cycle)

    //DATA formatting into char array
    sprintf(pwm_period, "/sys/class/pwm/pwmchip0/pwm%s/period", ps_pwm->id_canal);
    if ((p_pwm_period = fopen(pwm_period, "w")) == NULL)
        {
            printf("Cannot open period file.\n");
            exit(1);
        }
        rewind(p_pwm_period); //putting the cursor on the first line, first column of the file
        sprintf(c_period, "%lli", i_period); //DATA formatting into char array

        ps_pwm->period = i_period;//storing the value in the pin struct

        /*vaalue in char*/ /**/ /*nbr of characters(nbrs)*/ /*file to store in the value*/ 
        fwrite(&c_period, sizeof(char), 8, p_pwm_period);//writing the period value in the period file
        fclose(p_pwm_period);
        
        set_pwm_enable(ps_pwm,1);// ENABLING THE PIN AFTER CHANGING the period value
  
    return 0;
}


//définir le rapport cyclique 

int set_pwm_duty_cycle(S_PWM *ps_pwm, long long int i_duty_cycle){

    FILE *p_pwm_duty_cycle;
    char pwm_duty_cycle[50];
    char c_duty_cycle[8];
    
    set_pwm_enable(ps_pwm,0);// DISABLING THE PIN BEFORE CHANGING ANY VALUE (Peiod or Duty Cycle)
    
    //DATA formatting into char array
    sprintf(pwm_duty_cycle, "/sys/class/pwm/pwmchip0/pwm%s/duty_cycle", ps_pwm->id_canal);
    if ((p_pwm_duty_cycle = fopen(pwm_duty_cycle, "w")) == NULL)
        {
            printf("Cannot open duty cycle file.\n");
            exit(1);
        }

        rewind(p_pwm_duty_cycle);//putting the cursor on the first line, first column of the file
 
        sprintf(c_duty_cycle, "%lli", i_duty_cycle); //DATA formatting into char array
        ps_pwm->duty_cycle = i_duty_cycle;//storing the value in the pin struct

        fwrite(&c_duty_cycle, sizeof(char), 8, p_pwm_duty_cycle);//storing the value in the pin struct
        fclose(p_pwm_duty_cycle);

        set_pwm_enable(ps_pwm,1);// ENABLING THE PIN AFTER CHANGING the DC value
  
  
    return 0;
}
