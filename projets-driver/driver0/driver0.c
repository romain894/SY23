/*
   driver0.c

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

*/


#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include <asm/uaccess.h>
#include <linux/fs.h>
#include <linux/kdev_t.h>
#include <linux/miscdevice.h>
#include "driverioctl.h"

// decommenter pour l'affichage d'information supplémentaires
#define DEBUG

#define BUFFMAX 100

static bool input; //Port mode, if true input, else output

module_param(input, bool, S_IRUSR | S_IWUSR);
MODULE_PARM_DESC(input, "determine if the port is in output or input mode");


static char buffer[BUFFMAX];
static unsigned int majeur,mineur;
static int nboctets,nblu;


static int driver0_open(struct inode *pinode,struct file *pfile) {
  printk(KERN_DEBUG"input =  %d", input );

   mineur = MINOR(pinode->i_rdev);
   majeur = MAJOR(pinode->i_rdev);
#ifdef DEBUG
   printk(KERN_DEBUG"driver0[open] majeur %u mineur %u\n",majeur,mineur);
   printk(KERN_DEBUG"driverport[open] : flags %04x\n",pfile->f_flags);
#endif
   nblu = 0;
   return 0;
}

static int driver0_release(struct inode *pinode,struct file *pfile) {
#ifdef DEBUG
   printk(KERN_DEBUG"driver0[close]\n");
#endif
   return 0;
}


static ssize_t driver0_write(struct file *pfile, const char *poctets, size_t nb,loff_t *pos) {

  int nc = 0;

  if (nb > BUFFMAX) {
     printk(KERN_ERR"driver0[write] ERREUR ecriture %d octets superieur a %d\n",(int)nb,BUFFMAX);
     return -1;
  }



  nc=copy_from_user(buffer,poctets,nb); //To, from, nomber of bytes to copy
  if (nc == 0) {
   nboctets=nb;
#ifdef DEBUG
   printk(KERN_DEBUG"driver0[write]  %d octets\n",nboctets);
#endif
  }
  else {
	  printk(KERN_ERR"driver0[write] erreur copie %d\n",nc);
  }
  return nb;
}


static ssize_t driver0_read(struct file *pfile, char *poctets, size_t nb,loff_t *pos) {
  int nc;
#ifdef DEBUG
  printk(KERN_DEBUG"driver0[read] demande %ld octets position=%lld\n",nb,*pos);

#endif
  if (nboctets > 0) {
   nc=copy_to_user(poctets,buffer,nboctets);
   printk(KERN_DEBUG"Str_test: %c \n",*(poctets+2));

   if (nc == 0) {
     nblu = nboctets;
     nboctets = 0;
   }
   else {
	   printk(KERN_ERR"driver0[read] erreur copie %d\n",nc);
   }
  }
  else {
    nblu = 0;
  }
  *pos += nblu;
#ifdef DEBUG
  printk(KERN_DEBUG"driver0[read] retourne %d octets pos=%lld\n",nblu,*pos);
#endif
  return nblu;
}


static long driver0_ioctl(struct file *pfile,unsigned int cmd,unsigned long arg) {
#ifdef DEBUG
  printk(KERN_DEBUG"driver0[ioctl] %u\n",cmd);
#endif
  return 0;
}

struct file_operations driver0_fops = {
	owner: THIS_MODULE,
	open:driver0_open,
	write:driver0_write,
	read:driver0_read,
	unlocked_ioctl:driver0_ioctl,
	release:driver0_release,
};

static struct miscdevice driver0_dev = {
	.minor = MISC_DYNAMIC_MINOR,
	.name = "driver0",
	.fops = &driver0_fops,
	.mode = 0666
};


// initialisation
static int __init driver0_init(void) {
  int retour;
  printk(KERN_INFO"driver0[init] \n");
  retour = misc_register(&driver0_dev);
  return retour;
}

// suppression
static void __exit driver0_cleanup(void) {
  int retour=misc_deregister(&driver0_dev);
  if (retour) {
	  printk(KERN_ERR"driver0[cleanup] : erreur suppression\n");
  }

  else {
	  printk(KERN_INFO"driver0[cleanup] : suppression OK\n");
  }
}


// valeurs pour modinfo : description auteur licence
MODULE_DESCRIPTION("driver principe");
MODULE_AUTHOR("Michel Doussot");
MODULE_LICENSE("GPL");


module_init(driver0_init); // assignation de la fonction d'initialisation
module_exit(driver0_cleanup); // assignation de la fonction de destruction
