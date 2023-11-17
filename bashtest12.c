#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

int main(int ac, char **ap) {
	
 int file_descriptor;
 file_descriptor = open("/sys/class/gpio/export", O_WRONLY);
 write(file_descriptor, "17", 2);
 close(file_descriptor);
 sleep(1);
 
  file_descriptor = open("/sys/class/gpio/export", O_WRONLY);
 write(file_descriptor, "23", 2);
 close(file_descriptor);
 sleep(1);
 
 
  file_descriptor = open("/sys/class/gpio/export", O_WRONLY);
 write(file_descriptor, "27", 2);
 close(file_descriptor);
 sleep(1);
 
 
 file_descriptor = open("/sys/class/gpio/export", O_WRONLY);
 write(file_descriptor, "22", 2);
 close(file_descriptor);
 sleep(1);
 

file_descriptor = open("/sys/class/gpio/export", O_WRONLY);
 write(file_descriptor, "16", 2);
 close(file_descriptor);
 sleep(1);
 
  file_descriptor = open("/sys/class/gpio/export", O_WRONLY);
 write(file_descriptor, "20", 2);
 close(file_descriptor);
 sleep(1);
 
 
 file_descriptor = open("/sys/class/gpio/export", O_WRONLY);
 write(file_descriptor, "21", 2);
 close(file_descriptor);
 sleep(1);


 
 file_descriptor = open("/sys/class/gpio/gpio17/direction", O_WRONLY);
 write(file_descriptor, "out", 3);
 close(file_descriptor);
 
  file_descriptor = open("/sys/class/gpio/gpio23/direction", O_WRONLY);
 write(file_descriptor, "in", 2);
 close(file_descriptor);
 
 
  file_descriptor = open("/sys/class/gpio/gpio27/direction", O_WRONLY);
 write(file_descriptor, "out", 3);
 close(file_descriptor);
 
 
  file_descriptor = open("/sys/class/gpio/gpio22/direction", O_WRONLY);
 write(file_descriptor, "out", 3);
 close(file_descriptor);
 
 
  file_descriptor = open("/sys/class/gpio/gpio16/direction", O_WRONLY);
 write(file_descriptor, "out", 3);
 close(file_descriptor);
 
 
  file_descriptor = open("/sys/class/gpio/gpio20/direction", O_WRONLY);
 write(file_descriptor, "out", 3);
 close(file_descriptor);
 
   file_descriptor = open("/sys/class/gpio/gpio21/direction", O_WRONLY);
 write(file_descriptor, "out", 3);
 close(file_descriptor);
 

 
 
 
 int True = 4;
 while(True == 4){
	 
		
		
	 
	sleep(1);
	file_descriptor = open("/sys/class/gpio/gpio17/value", O_WRONLY);
	write(file_descriptor, "0", 1);
	close(file_descriptor);
	
	file_descriptor = open("/sys/class/gpio/gpio27/value", O_WRONLY);
	write(file_descriptor, "1", 1);
	close(file_descriptor);
	
	file_descriptor = open("/sys/class/gpio/gpio22/value", O_WRONLY);
	write(file_descriptor, "1", 1);
	close(file_descriptor);
	
	file_descriptor = open("/sys/class/gpio/gpio16/value", O_WRONLY);
	write(file_descriptor, "1", 1);
	close(file_descriptor);
	
	file_descriptor = open("/sys/class/gpio/gpio20/value", O_WRONLY);
	write(file_descriptor, "0", 1);
	close(file_descriptor);
	
	file_descriptor = open("/sys/class/gpio/gpio21/value", O_WRONLY);
	write(file_descriptor, "1", 1);
	close(file_descriptor);
	
	sleep(1);
	
	file_descriptor = open("/sys/class/gpio/gpio17/value", O_WRONLY);
	write(file_descriptor, "1", 1);
	close(file_descriptor);
	
	file_descriptor = open("/sys/class/gpio/gpio27/value", O_WRONLY);
	write(file_descriptor, "0", 1);
	close(file_descriptor);
	
	file_descriptor = open("/sys/class/gpio/gpio22/value", O_WRONLY);
	write(file_descriptor, "1", 1);
	close(file_descriptor);
	
	file_descriptor = open("/sys/class/gpio/gpio16/value", O_WRONLY);
	write(file_descriptor, "1", 1);
	close(file_descriptor);
	
	file_descriptor = open("/sys/class/gpio/gpio20/value", O_WRONLY);
	write(file_descriptor, "1", 1);
	close(file_descriptor);
	
	file_descriptor = open("/sys/class/gpio/gpio21/value", O_WRONLY);
	write(file_descriptor, "0", 1);
	close(file_descriptor);
	
	sleep(1);
	
	
	file_descriptor = open("/sys/class/gpio/gpio17/value", O_WRONLY);
	write(file_descriptor, "1", 1);
	close(file_descriptor);
	
	file_descriptor = open("/sys/class/gpio/gpio27/value", O_WRONLY);
	write(file_descriptor, "1", 1);
	close(file_descriptor);
	
	file_descriptor = open("/sys/class/gpio/gpio22/value", O_WRONLY);
	write(file_descriptor, "0", 1);
	close(file_descriptor);
	
	file_descriptor = open("/sys/class/gpio/gpio16/value", O_WRONLY);
	write(file_descriptor, "0", 1);
	close(file_descriptor);
	
	file_descriptor = open("/sys/class/gpio/gpio20/value", O_WRONLY);
	write(file_descriptor, "1", 1);
	close(file_descriptor);
	
	file_descriptor = open("/sys/class/gpio/gpio21/value", O_WRONLY);
	write(file_descriptor, "1", 1);
	close(file_descriptor);

		
 }
 
 
 //file_descriptor = open("/sys/class/gpio/unexport", O_WRONLY);
 //write(file_descriptor, "21", 2);
 //close(file_descriptor);
 return 0;
} 
