#ifndef PWM_H_
#define PWM_H_


#define PWM00 "18"
#define PWM01 "12"

#define ENABLE "1"
#define DISABLE "0"

struct S_PWM {
    char id_canal[2];
    int enable;
    long long int period;
    long long int duty_cycle;
};
typedef struct S_PWM S_PWM;

//exporting the pin to the user layer
int load_pwm(S_PWM *ps_pwm, char id_canal[2]);
//we can't change any value on the pwm pin, until we disable it
int set_pwm_enable(S_PWM *ps_pwm, int i_enable);
//setting up the period value
int set_pwm_period(S_PWM *ps_pwm, long long int period);
//setting up the duty cycle value
int set_pwm_duty_cycle(S_PWM *ps_pwm, long long int duty_cycle);

#endif /*PWM_H_*/
