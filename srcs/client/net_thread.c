#include "jdr.h"


// int net_thread_main(t_my_net *net)
// {
// 	if (done)
// 	{
// 		printf("in thread net !\n");
// 	}
// 	// TCPsocket sock=(TCPsocket)data;
// 	SDLNet_SocketSet set;
// 	int numready;
// 	char *str=NULL;

// 	set=SDLNet_AllocSocketSet(1);
// 	if(!done && !set)
// 	{
// 		printf("SDLNet_AllocSocketSet: %s\n", SDLNet_GetError());
// 		SDLNet_Quit();
// 		SDL_Quit();
// 		done=2;
// 	}

// 	if(!done && SDLNet_TCP_AddSocket(set,net->sock)==-1)
// 	{
// 		printf("SDLNet_TCP_AddSocket: %s\n",SDLNet_GetError());
// 		SDLNet_Quit();
// 		SDL_Quit();
// 		done=3;
// 	}
	
// 	while(!done)
// 	{
// 		numready=SDLNet_CheckSockets(set, (Uint32)-1);
// 		if(numready==-1)
// 		{
// 			printf("SDLNet_CheckSockets: %s\n",SDLNet_GetError());
// 			done=4;
// 			break;
// 		}

// 		/* check to see if the server sent us data */
// 		if(numready && SDLNet_SocketReady(net->sock))
// 		{
// 			/* getMsg is in tcputil.h, it gets a string from the socket */
// 			/* with a bunch of error handling */
// 			if(!getMsg(net->sock,&str))
// 			{
// 				char *errstr=SDLNet_GetError();
// 				printf("getMsg: %s\n",strlen(errstr)?errstr:"Server disconnected");
// 				done=5;
// 				break;
// 			}
// 			/* post it to the screen */
// 			printf("%s\n",str);
// 		}
// 	}
// 	if(!done)
// 		done=1;
// 	SDL_KillThread(local_thread);
// 	return(0);
// }
