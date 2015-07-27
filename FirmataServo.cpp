#include "Firmata/FirmataServo.h"


t_servo* FirmataServo::servo_attach(t_firmata *firmata, int pin)
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
  Firmata::firmata_pinMode(res->firmata, pin, MODE_SERVO);
  return (res);
}

int FirmataServo::servo_write(t_servo *servo, int value)
{
  return (Firmata::firmata_analogWrite(servo->firmata, servo->pin, value));
}

