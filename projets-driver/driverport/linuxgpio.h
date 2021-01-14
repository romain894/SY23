

#ifndef __LINUXGPIO_H
#define __LINUXGPIO_H


/*
export the GPIO to userspace :
  int gpio_export(unsigned gpio, bool direction_may_change);
reverse gpio_export :
  void gpio_unexport();
create a sysfs link to an exported GPIO node :
  int gpio_export_link(struct device *dev, const char *name, unsigned gpio)
change the polarity of a GPIO node in sysfs :
  int gpio_sysfs_set_active_low(unsigned gpio, int value);
 
set as input or output, returning 0 or negative errno 
  int gpio_is_valid(int number);
  int gpio_direction_input(unsigned gpio);
  int gpio_direction_output(unsigned gpio, int value);
*/  


int gpio_export(unsigned , int);
void gpio_unexport(unsigned );
int gpio_direction_input(unsigned );
int gpio_direction_output(unsigned , int);
void gpio_set_value(unsigned , int);
int gpio_get_value(unsigned );
  
#endif  
