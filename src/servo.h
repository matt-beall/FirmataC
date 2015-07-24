
#ifndef		__H_FIRMATA_SERVO__
#define		__H_FIRMATA_SERVO__

#include	"Firmata/src/firmata.h"


#include    <stdlib.h>
#include    <stdio.h>


typedef struct s_servo
{
  t_firmata	*firmata;
  int		pin;
}		t_servo;

t_servo		*servo_attach(t_firmata *firmata, int pin);
int		servo_write(t_servo *servo, int value);


t_servo     *servo_attach(t_firmata *firmata, int pin)
{
  t_servo   *res;

  if (!firmata || !firmata->isReady)
    {
      perror("servo_new::Firmata is not ready");
      return (NULL);
    }
  res = new t_servo;
  if (!res)
    {
      perror("servo_new::new servo failed");
      return (NULL);
    }
  res->firmata = firmata;
  res->pin = pin;
  firmata_pinMode(res->firmata, pin, MODE_SERVO);
  return (res);
}

int     servo_write(t_servo *servo, int value)
{
  return (firmata_analogWrite(servo->firmata, servo->pin, value));
}



#endif
