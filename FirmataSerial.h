
 #pragma once


#include <stdint.h>

#include <termios.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/select.h>
#include <termios.h>
#include <unistd.h>
#include <dirent.h>
#include <sys/stat.h>
#include <sys/ioctl.h>
#include <linux/serial.h>

typedef struct s_serial
{
  int			port_is_open;
  char			*port_name;
  int			baud_rate;
  char			*error_msg;

  int			port_fd;
  struct termios	settings_orig;
  struct termios	settings;
  int			tx;
  int			rx;
}			t_serial;


namespace FirmataSerial{
  t_serial* serial_new();
  int       serial_open(t_serial *serial, char *name);
  int		    serial_setBaud(t_serial *serial, int baud);
  int		    serial_read(t_serial *serial, void *ptr, int count);
  int		    serial_write(t_serial *serial, void *ptr, int len);
  int		    serial_waitInput(t_serial *serial, int msec);
  int		    serial_discardInput(t_serial *serial);
  void	    serial_flushOutput(t_serial *serial);
  int		    serial_setControl(t_serial *serial, int dtr, int rts);
}


