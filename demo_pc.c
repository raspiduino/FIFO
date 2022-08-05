/**
   GeekFactory - "INNOVATING TOGETHER"
   Distribucion de materiales para el desarrollo e innovacion tecnologica
   www.geekfactory.mx

   This example shows the basic usage of the FIFO library. We create a FIFO,
   then we fill it with some data and then dump the data to the serial monitor.
*/

#include <stdio.h>
#include "FIFO.h"

// array of test data
char data[] = "Hola Mundo!!!!";
// type to store a FIFO reference
fifo_t myfifo;

int main() {

  // create a FIFO (queue) capable of storing 10 items
  myfifo = fifo_create(10, sizeof(char));

  // check if FIFO was created
  if (myfifo == NULL) {
    printf("Cannot create FIFO... halting!\n");
    for (;;);
  } else {
    printf("FIFO created successfully\n");
  }

  // put some data on the fifo buffer
  printf("\r\nFILLING FIFO WITH DATA...\n");
  for (unsigned int i = 0; i < sizeof(data); i++)
  {
    printf("Add item to FIFO: %u", data[i]);
    if (fifo_add(myfifo, &data[i])) {
      printf(" (OK)\n");
    } else {
      printf(" (FAIL)\n");
    }
  }

  // get data from FIFO
  printf("\r\nGETTING DATA FROM FIFO...");
  // dump data from FIFO to serial monitor
  while (!fifo_is_empty(myfifo)) {
    char c;
    fifo_get(myfifo, &c);
    printf("%c", c);
  }

  // end of test program
  printf("\nDONE");

  return 0;
}
