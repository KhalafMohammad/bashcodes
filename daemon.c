#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <syslog.h>
#include <stddef.h>
#include <mariadb/mysql.h>
#include <fcntl.h>


int ledcheck(MYSQL *connection){
	int columnvalue = 0;

		// checks the value of the column LEDstate
	 	if (mysql_query(connection, "select * from LED")) {
      		printf("%s\n", mysql_error(connection));
		}
		MYSQL_ROW row;
	
		//stores the results in the pointer resutl
		MYSQL_RES *result = mysql_store_result(connection);
		if(result == NULL){
			printf("%s\n", mysql_error(connection));
		}

		// fetches the results in row 
		row = mysql_fetch_row(result);

		// saves the value of the row under the LEDstate column in columnvalue and turns it to an integer.
		columnvalue = atoi(row[2]);

		//prints the value of the column to make sure that its working.
		printf("column value is: %d\n", columnvalue);
		mysql_free_result(result);// frees the results

		//strcmp function compares string columnvalue with either 1(true) or 0(false)
		return columnvalue;
}

void ledcontrol(int columnvalue){
	int file_descriptor;
	if(columnvalue == 1){

			//if columnvalue is equal to 1, then sets pin21 to 1.
			file_descriptor = open("/sys/class/gpio/gpio21/value", O_WRONLY);
			write(file_descriptor, "1", 1);
			close(file_descriptor);
			
		
		
		}else
	
			//if columnvalue is other than 1 sets pin21 valuse to 0
			file_descriptor = open("/sys/class/gpio/gpio21/value", O_WRONLY);
			write(file_descriptor, "0", 1);
			close(file_descriptor);
			

}

// static
// void daemoniztionque(){

// 	FILE *fp = NULL;
	
// 	pid_t process_id;
// 	pid_t sid = 0;
	
//     // create Child process
    
//     process_id = fork();
    
		
// 	/* Success: Let the parent terminate */
// 	if(process_id < 0){
		
// 		// exit(EXIT_FAILURE);
// 		printf("fork failed!\n");
// 		exit(1);
// 	}

// 	if(process_id > 0){
// 		printf("process_id : %d\n", process_id);
// 		// exit(EXIT_SUCCESS);
// 		exit(0);
// 	}

// 	umask(0);

		
// 	/* On success: The child process becomes session leader */
// 	sid = setsid();
		
// 	if(sid < 0){
// 		//exit(EXIT_FAILURE);
// 		exit(1);

// 	}

// 	//change to root
	
// 	chdir("/");

// 	close(STDIN_FILENO);
// 	close(STDOUT_FILENO);
// 	close(STDERR_FILENO);
// 	fp = fopen("log.txt", "w+");

// 	// for (int x = sysconf(_SC_OPEN_MAX); x>0; x--)
//     // {
//     //     close (x);
//     // }
		
	
// 	// openlog("secdaemon", LOG_PID, LOG_DAEMON);
	
	
// }


int main(int ac, char **ap){
	MYSQL *connection = mysql_init(NULL);
	mysql_real_connect(connection, "localhost", "pipo", "theclown", "mijndb", 0, NULL, 0);
	if(connection == NULL) {
		printf("Kan geen verbinding met de MariaDB server maken \n");
	exit(-1);
	}
	
	FILE *fp = NULL;
	
	pid_t process_id;
	pid_t sid = 0;
	
    // create Child process
    
    process_id = fork();
    
		
	/* Success: Let the parent terminate */
	if(process_id < 0){
		
		// exit(EXIT_FAILURE);
		printf("fork failed!\n");
		exit(1);
	}

	if(process_id > 0){
		printf("process_id : %d\n", process_id);
		// exit(EXIT_SUCCESS);
		exit(0);
	}

	umask(0);

		
	/* On success: The child process becomes session leader */
	sid = setsid();
		
	if(sid < 0){
		//exit(EXIT_FAILURE);
		exit(1);

	}

	//change to root
	
	chdir("/");

	close(STDIN_FILENO);
	close(STDOUT_FILENO);
	close(STDERR_FILENO);
	fp = fopen("Log.txt", "w+");




	int file_descriptor;
	//exports pin21
	file_descriptor = open("/sys/class/gpio/export", O_WRONLY);
	write(file_descriptor, "21", 2);
	close(file_descriptor);
	sleep(1);

	// sets pin21 as output
	file_descriptor = open("/sys/class/gpio/gpio21/direction", O_WRONLY);
	write(file_descriptor, "out", 3);
	close(file_descriptor);
	// daemoniztionque();
	
	while(1){

		
		fprintf(fp, "logging info...");
		fflush(fp);
		int status = ledcheck(connection);
		printf("cloumnvalue is: %d\n", status);
		ledcontrol(status);

		sleep(10);
		
		
		}
		//logout "sort of", and log that the daemon is terminatid.
		// syslog (LOG_NOTICE, "First daemon terminated.");
		fclose(fp);
		// closelog();
		mysql_close(connection);
	
return 0;
}