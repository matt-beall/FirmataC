

#pragma once

#include	"Firmata.h"


#include    <stdlib.h>
#include    <stdio.h>


typedef struct s_servo
{
  t_firmata *firmata;
  int   pin;
}   t_servo;


namespace FirmataServo{

  t_servo		*servo_attach(t_firmata *firmata, int pin);


  int		servo_write(t_servo *servo, int value);

}
