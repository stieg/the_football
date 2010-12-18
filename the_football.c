/*
 * the_football.c
 *
 * Copyright (C) 2010 Andrew Stiegmann <andrew.stiegmann@gmail.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <curses.h>
#include <glib.h>
#include <glib/gprintf.h>
#include <usb.h>

/*
 * T:  Bus=03 Lev=01 Prnt=01 Port=04 Cnt=03 Dev#=  7 Spd=1.5 MxCh= 0
 * D:  Ver= 1.10 Cls=00(>ifc ) Sub=00 Prot=00 MxPS= 8 #Cfgs=  1
 * P:  Vendor=0a81 ProdID=ff01 Rev=00.01
 * S:  Manufacturer=Rocket Baby
 * S:  Product=Rocket Baby
 * C:  #Ifs= 1 Cfg#= 1 Atr=a0 MxPwr=100mA
 * I:  If#= 0 Alt= 0 #EPs= 1 Cls=03(HID  ) Sub=00 Prot=00 Driver=usbfs
 */

/**
 * is_rocket_baby_device:
 * @*dev: (IN) USB drvice pointer
 * @Returns: TRUE if it is, FALSE otherwise
 *
 * Tells us if the given device is a Rocket Baby
 *
 **/
static gboolean
is_rocket_baby_device (struct usb_device *dev) /* IN */
{
   g_return_val_if_fail(dev != NULL, FALSE);
   return (dev->descriptor.idVendor == 0x0a81 &&
           dev->descriptor.idProduct == 0xff01);
} /* is_rocket_baby_device */


/**
 * find_rocket_baby:
 * @Returns: A pointer to the Rocket Baby device, or NULL if not found.
 *
 * Finds the Rocket Baby device
 *
 **/
static struct usb_device *
find_rocket_baby ()
{
   struct usb_bus *bus = NULL;
   struct usb_device *dev = NULL;

   usb_find_busses();
   usb_find_devices();

   for(bus = usb_get_busses(); bus != NULL; bus = bus->next)
      for(dev = bus->devices; dev != NULL; dev = dev->next)
         if (is_rocket_baby_device(dev))
            return dev;

   return NULL;
} /* find_rocket_baby */


int
main()
{
   struct usb_device *h;
   WINDOW *win;
   usb_init();

   h = find_rocket_baby();
   /* if (h == NULL) */
   /*    g_error("Rocket Baby device not found\n"); */

   win = initscr();
   cbreak();
   while(1) {
      int c = getch();
      g_printf("Got char %d\n", c);
      fflush(NULL);
   }

   return 0;
}
