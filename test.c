#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>

//#define test


int main() {
	
 int file_descriptor;
 file_descriptor = open("/sys/class/gpio/export", O_WRONLY);
 write(file_descriptor, "24", 2);
 close(file_descriptor);
 sleep(1);
 
  file_descriptor = open("/sys/class/gpio/export", O_WRONLY);
 write(file_descriptor, "16", 2);
 close(file_descriptor);
 sleep(1);
 


 


 
 file_descriptor = open("/sys/class/gpio/gpio16/direction", O_WRONLY);
 write(file_descriptor, "out", 3);
 close(file_descriptor);
 
 
  file_descriptor = open("/sys/class/gpio/gpio24/direction", O_WRONLY);
 write(file_descriptor, "in", 2);
 close(file_descriptor);
 
 
 
 int button1, buttonLED, button_state, pstate;
 button1 = open("/sys/class/gpio/gpio24/value", O_WRONLY);

buttonLED = open("/sys/class/gpio/gpio16/value", O_WRONLY);

pstate= open("/sys/class/gpio/gpio24/pull", O_WRONLY);
write(pstate, "up", 2);
close(pstate);

 
 //int True = 4;
 while(1){
	 
	 read(button1, &button_state, 1);
#ifdef test
printf("this the button value: %d\n", button_state);
sleep(2);
#endif	 
	//if(button_state != pstate){
			//usleep(10000);
			//read(button1, &button_state, 1);
		//}
		
	if (button_state == 0){
		printf("button was pressed!\n");
		write(buttonLED, "0", 1);
		close(buttonLED);
		
	
	}else{
		write(buttonLED, "1", 1);
		close(buttonLED);
		
		}
	 
 }
 
 
 //file_descriptor = open("/sys/class/gpio/unexport", O_WRONLY);
 //write(file_descriptor, "21", 2);
 //close(file_descriptor);
 return 0;
} 
