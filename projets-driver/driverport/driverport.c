/*
   driverport.c

#define    KERN_EMERG     «<0>»     system is unusable
#define    KERN_ALERT     «<1>»      action must be taken immediately
#define    KERN_CRIT     «<2>»      critical conditions
#define    KERN_ERR     «<3>»     error conditions
#define    KERN_WARNING  «<4>»     warning conditions
#define    KERN_NOTICE «<5>»     normal but significant condition
#define    KERN_INFO     “<6>”     informational
#define    KERN_DEBUG     «<7>»     debug-level messages

module_param(entier, int, 0644);
module_param_array(tableau, int, NULL, 0644);
module_param_string(chaine, chaine, sizeof(chaine), 0644);

routines gpio

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

GPIO INPUT:  return zero or nonzero :
  int gpio_get_value(unsigned gpio);
GPIO OUTPUT
  void gpio_set_value(unsigned gpio, int value);

*/

/*
The objective is to access the driver with the echo command, so echo something > /dev/driverport with something being the 8bit value written in decimal
or hexadecimal.
The value is written to each of the GPIOs corresponding to the JC port.
For this, we must first initialize the 8 GPIOs making up the JC port, then parse the 8bit
value echoed to each of the GPIOs exported.
The initialization is done with the __init function, the driverport_write will translate 8bit value written in dec/hex
into 8 bit value and write on each corresponding GPIOs.
The reading will be done via the driverport_read function which will return the number of bytes read and display
the value on port via standard console output.
*/

#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include <asm/uaccess.h>
#include <linux/fs.h>
#include <linux/kdev_t.h>
#include <linux/miscdevice.h>
#include "linuxgpio.h" // pour la simulation
#include "driverioctl.h"
#include "pmodhat.h"

#define DEBUG

static char buf_write[4];
static char buf_read[9];
static unsigned int majeur,mineur;
static bool direction;
const int gpio_map[8] = {PI_KID_JC7, PI_KID_JC6, PI_KID_JC5, PI_KID_JC4, PI_KID_JC3, PI_KID_JC2, PI_KID_JC1, PI_KID_JC0};

module_param(direction, bool, S_IRUSR | S_IWUSR);
MODULE_PARM_DESC(direction, "determine if the port is in output or input mode, true for input, else output");

static int driverport_open(struct inode *pinode,struct file *pfile) {
   mineur = MINOR(pinode->i_rdev);
   majeur = MAJOR(pinode->i_rdev);
#ifdef DEBUG
   printk(KERN_DEBUG"driverport[open] majeur %u mineur %u\n",majeur,mineur);
   printk(KERN_DEBUG"driverport[open] : flags %04x\n",pfile->f_flags);
#endif
  return 0;
}

static int driverport_release(struct inode *pinode,struct file *pfile) {
#ifdef DEBUG
   printk(KERN_DEBUG"driverport[release] : close\n");
#endif
   return 0;
}


static ssize_t driverport_write(struct file *pfile, const char *poctets, size_t nb,loff_t *pos) {
  int gpio_values[8];
  int convert_result = 0;
  int init_gpio_loop;
  int binary_exponent = 0;
  int return_code;

  #ifdef DEBUG
    printk(KERN_DEBUG"driverport[write] : ecrit %zu octets position %lld\n",nb,*pos);
    printk(KERN_DEBUG"driverport[write] : buf_write size %ld", sizeof(buf_write) );
  #endif

  //Initializing gpio values table
  for (init_gpio_loop = 0; init_gpio_loop < 8; init_gpio_loop++){
    gpio_values[init_gpio_loop] = 0;
  }

  //check user input for buffer overflow
  if (nb > sizeof(buf_write)){
    printk(KERN_ERR"driverport[write] : Buffer overflow" );
    return -EINVAL;
  }

  //copy user input from userspace into kernel space
  if (copy_from_user(buf_write, poctets, nb )){
    printk(KERN_ERR"driverport[write] : Error copying to kernel space\n");
    return -EFAULT;
  }

  //read integer formatted inside the stored user input , then affect it to convert_result
  return_code = sscanf(buf_write, "%d", &convert_result);
  if (return_code != 1){
    printk(KERN_ERR"driverport[write] : input format invalid\n");
    return -EINVAL;
  }
  #ifdef DEBUG
  printk(KERN_DEBUG"driverport[write] : user input value %d\n", convert_result);
  #endif
  // convert_result = simple_strtol(poctets, &endptr, 10 );

  //Checks now if the user input is valid
  if (convert_result > 255){
    printk(KERN_ERR"out of range: %d", convert_result );
  }
  else{
    //Binary conversion from decimal user input values
    while (convert_result > 0){
      gpio_values[binary_exponent] = convert_result%2;
      convert_result /= 2;
      binary_exponent++;
    }
    //Setting gpio output values based on mapped GPIOs. MSB/Big Endian
    for (init_gpio_loop = 7; init_gpio_loop >= 0; init_gpio_loop--){
      #ifdef DEBUG
      printk(KERN_DEBUG"driverport[write] : gpio%d %d", gpio_map[init_gpio_loop], gpio_values[init_gpio_loop] );
      #endif
      gpio_set_value(gpio_map[init_gpio_loop], gpio_values[init_gpio_loop]);
    }
  }

  #ifdef DEBUG
  if (convert_result == 0){
    printk(KERN_DEBUG"conversion success, %d", convert_result );
  }
  else{
    printk(KERN_DEBUG"conversion failed, %d", convert_result );
  }
  #endif
  return nb;
}


static ssize_t driverport_read(struct file *pfile, char *poctetqs, size_t nb,loff_t *pos) {
  int read_gpio_loop;
  int return_code;
  int gpio_value;

#ifdef DEBUG
  printk(KERN_DEBUG"driverport[read] : demande %zu octets position %lld\n",nb,*pos);
  printk(KERN_DEBUG"driverport[read] : buf_read size %ld\n", sizeof(buf_read));
#endif
// A completer obligatoirement
// lecture sur les GPIOS
  for (read_gpio_loop = 7; read_gpio_loop >= 0; read_gpio_loop--){
    gpio_value = gpio_get_value(gpio_map[read_gpio_loop]);
    /*gpio_get_value returns an integer, cannot be stored in our 9 byte large char type buf_read.
    Hence the simple char conversion. */
    if (gpio_value == 1){
      buf_read[read_gpio_loop] = '1';
    }
    else{
      buf_read[read_gpio_loop] = '0';
    }
    #ifdef DEBUG
    printk(KERN_INFO"driverport[read] : gpio%d %d\n",gpio_map[read_gpio_loop], gpio_value );
    #endif
  }
  buf_read[8] = '\n'; //Newline for printing to terminal

  /*Check if there is still data to be read or not. If position goes past 0, return 0 for nothing left to read.
  The problem is that cat continously calls __read until it reaches EOF. If we never return 0 it keeps copying buf_read to userspace forever
  */
  //If __read has already been called, return 0 directly to signal cat that there's nothing more to read.
  if (*pos > sizeof(buf_read)){
    return 0; //EOF
  }
  // If this is the first call to read, we bring the offset to the beginning of buf_read
  if (nb > sizeof(buf_read)){
    *pos = nb - sizeof(buf_read);
  }
  return_code = copy_to_user(poctetqs, buf_read,sizeof(buf_read));
  if (return_code != 0){
    printk(KERN_ERR"driverport[read] Error copying to userspace\n");
    return -EFAULT;
  }
  return nb;
}


static long driverport_ioctl(struct file *pfile,unsigned int cmd,unsigned long arg) {
#ifdef DEBUG
  printk(KERN_DEBUG"driverport[ioctl] : cmd : %u\n",cmd);
#endif
  return 0;
}

struct file_operations driverport_fops = {
	owner: THIS_MODULE,
	open:driverport_open,
	write:driverport_write,
	read:driverport_read,
	unlocked_ioctl:driverport_ioctl,
	release:driverport_release,
};

static struct miscdevice driverport_dev = {
	.minor = MISC_DYNAMIC_MINOR,
	.name = "driverport",
	.fops = &driverport_fops,
	.mode = 0666
};

// initialisation
static int __init driverport_init(void) {
  int retour;
  int init_gpio_loop;
  int direction_code;
  retour = misc_register(&driverport_dev);
  if (retour) {
	  printk(KERN_ERR"driverport[init] : erreur enregistrement\n");
  }
  else {
	  printk(KERN_INFO"driverport[init] : enregistrement OK\n");
  }

 for (init_gpio_loop = 0; init_gpio_loop < 8; init_gpio_loop++){
   retour = gpio_export(gpio_map[init_gpio_loop], 0);
 }

 if (direction){
   for (init_gpio_loop = 0; init_gpio_loop < 8; init_gpio_loop++){
     direction_code = gpio_direction_input(gpio_map[init_gpio_loop]);
   }
   printk(KERN_INFO"driverport[init] : input mode set\n");
 }
 else{
   for (init_gpio_loop = 0; init_gpio_loop < 8; init_gpio_loop++){
     direction_code = gpio_direction_output(gpio_map[init_gpio_loop], 0);
   }
   printk(KERN_INFO"driverport[init] : output mode set\n");

 }
  return 0;

}
// suppression
static void __exit driverport_cleanup(void) {
  int retour;
  int cleanup_gpio_loop;
// A completer obligatoirement
// liberation GPIOS
for (cleanup_gpio_loop = 0; cleanup_gpio_loop <8; cleanup_gpio_loop++){
  gpio_unexport(gpio_map[cleanup_gpio_loop]);
}
  retour=misc_deregister(&driverport_dev);
  if (retour) {
	  printk(KERN_ERR"driverport[cleanup] : erreur suppression\n");
  }
  else {
	  printk(KERN_INFO"driverport[cleanup] : suppression OK\n");
  }

}


// valeurs pour modinfo : description auteur licence
MODULE_DESCRIPTION("driver 8 leds pour pmodhat JA JB JC");
MODULE_AUTHOR("Viet Phuong DINH");
MODULE_LICENSE("GPL");


module_init(driverport_init); // assignation de la fonction d'initialisation
module_exit(driverport_cleanup); // assignation de la fonction de destruction
