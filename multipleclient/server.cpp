#include <stdio.h> // standard input and output library
#include <stdlib.h> // this includes functions regarding memory allocation
#include <string.h> // contains string functions
#include <errno.h> //It defines macros for reporting and retrieving error conditions through error codes
#include <time.h> //contains various functions for manipulating date and time
#include <unistd.h> //contains various constants
#include <sys/types.h> //contains a number of basic derived types that should be used whenever appropriate
#include <arpa/inet.h> // defines in_addr structure
#include <sys/socket.h> // for socket creation
#include <netinet/in.h> //contains constants and structures needed for internet domain addresses
 int send_image(int socket){

   FILE *picture;
   int size, read_size, stat, packet_index;
   char send_buffer[10240], read_buffer[256];
   packet_index = 1;

   picture = fopen("/home/ramu/face_recognition-master/knn_examples/train/sravan/1.jpg", "r");
   printf("Getting Picture Size\n");   

   if(picture == NULL) {
        printf("Error Opening Image File"); } 

   fseek(picture, 0, SEEK_END);
   size = ftell(picture);
   fseek(picture, 0, SEEK_SET);
   printf("Total Picture size: %i\n",size);

   //Send Picture Size
   printf("Sending Picture Size\n");
   write(socket, (void *)&size, sizeof(int));

   //Send Picture as Byte Array
   printf("Sending Picture as Byte Array\n");

   do { //Read while we get errors that are due to signals.
      stat=read(socket, &read_buffer , 255);
      printf("Bytes read: %i\n",stat);
   } while (stat < 0);

   printf("Received data in socket\n");
   printf("Socket data: %c\n", read_buffer);

   while(!feof(picture)) {
   //while(packet_index = 1){
      //Read from the file into our send buffer
      read_size = fread(send_buffer, 1, sizeof(send_buffer)-1, picture);

      //Send data through our socket 
      do{
        stat = write(socket, send_buffer, read_size);  
      }while (stat < 0);

      printf("Packet Number: %i\n",packet_index);
      printf("Packet Size Sent: %i\n",read_size);     
      printf(" \n");
      printf(" \n");


      packet_index++;  

      //Zero out our send buffer
      bzero(send_buffer, sizeof(send_buffer));
     }
    }

//int main()
int mnmain(int x, int y)
{
    time_t clock;
	char dataSending[1025]; // Actually this is called packet in Network Communication, which contain data and send through.
	int clintListn = 0, clintConnt = 0;
	struct sockaddr_in ipOfServer;
	clintListn = socket(AF_INET, SOCK_STREAM, 0); // creating socket
	memset(&ipOfServer, '0', sizeof(ipOfServer));
	memset(dataSending, '0', sizeof(dataSending));
	ipOfServer.sin_family = AF_INET;
	ipOfServer.sin_addr.s_addr = htonl(INADDR_ANY);
	ipOfServer.sin_port = htons(2017); 		// this is the port number of running server
	bind(clintListn, (struct sockaddr*)&ipOfServer , sizeof(ipOfServer));
	listen(clintListn , 20);
 
	while(1)
	{
		printf("\n\nHi,Iam running server.Some Client hit me\n"); // whenever a request from client came. It will be processed here.
		clintConnt = accept(clintListn, (struct sockaddr*)NULL, NULL);
 
		clock = time(NULL);
		//char* sample="Hi";
                //write(clintConnt, sample, strlen(sample));
		//snprintf(dataSending, sizeof(dataSending), "%.24s\r\n", ctime(&clock)); // Printing successful message
		//write(clintConnt, dataSending, strlen(dataSending));
                send_image(clintConnt);
        //close(clintConnt);
        sleep(1);
     }
 
     return 0;
}
   
