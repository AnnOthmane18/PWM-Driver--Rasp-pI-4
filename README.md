# PWM-Driver--Rasp-pI-4
in this project i tried to create pwm driver for the raspberry pi using main functions:
    * **load_pwm(S_PWM *ps_pwm, char id_canal[2])**: function that has 2 parameters (the chosen pin(since the rasp pi 4 has 4 pwm pins) + its ID)
    * **set_pwm_enable(S_PWM *ps_pwm, int i_enable)**: An Enable/Disable Function in order to be able to make changes to pin(changing period & Ducty Cycle values)
    * **set_pwm_period(S_PWM *ps_pwm, long long int period)**: A dedicated function to set up the Period function
    * **set_pwm_duty_cycle(S_PWM *ps_pwm, long long int duty_cycle)**: A dedicated function to set up the Ducty Cycle function

# Raspberry pi 4
![alt text](https://www.electronicwings.com/storage/PlatformSection/TopicContent/304/description/Raspberry%20pi%203%20PWM%20pins.png)
