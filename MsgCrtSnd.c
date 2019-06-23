#include <stdio.h>
 #include <string.h>
 #include <sys/msg.h>
 #define MAX_LINE 80
 int MY_MQ_ID;
 typedef struct {
 long type; // Msg Type (> 0)
 float fval; // User Message
 unsigned int uival; // User Message
 char strval[MAX_LINE+1]; // User Message
 } MY_TYPE_T;
 int main()
 {
	 MY_TYPE_T myObject;
	 int qid, ret;
	 char msg1[20];
	 int msgid;
	/* Create the message queue with the id MY_MQ_ID */
	printf("Enter Message Queue Id: ");
	scanf("%d",&MY_MQ_ID);
	msgid = msgget( MY_MQ_ID, 0666 | IPC_CREAT );

	if (msgid >= 0) {
		printf( "Created a Message Queue %d\n", msgid );

		}

	
	 /* Get the queue ID for the existing queue */
	 //printf();
	 qid = msgget( MY_MQ_ID, 0 );

	 if (qid >= 0) {
		/* Create our message with a message queue type of 1 */
		 myObject.type = 1L;
		 myObject.fval = 128.256;
		 myObject.uival = 512;
		 printf("Enter the Message ");
		 gets(msg1);
		 gets(msg1);
		 strncpy( myObject.strval, msg1, MAX_LINE );

		 /* Send the message to the queue defined by the queue ID */
		 ret = msgsnd( qid, (struct msgbuf *)&myObject,
		 sizeof(MY_TYPE_T), 0 );

		 if (ret != -1) {

			 printf( "Message successfully sent to queue %d\n", qid );

		 }

	 }

 return 0;
}
