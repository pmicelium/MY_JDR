#include "jdr.h"
#include "tcputil.h"

void init_client(t_perso *perso, t_my_net *net)
{
	net->name = perso->name;

	net->set = SDLNet_AllocSocketSet(1);
	if (!net->set)
	{
		printf("SDLNet_AllocSocketSet: %s\n", SDLNet_GetError());
		SDLNet_Quit();
		SDL_Quit();
		exit(4); /*most of the time this is a major error, but do what you want. */
	}

	/* get the port from the commandline */
	net->port = (Uint16)strtol(MY_PORT, NULL, 0);
	/* Resolve the argument into an IPaddress type */
	printf("Connecting to %s port %d\n", MY_HOST, net->port);
	if (SDLNet_ResolveHost(&net->ip, MY_HOST, net->port) == -1)
	{
		printf("SDLNet_ResolveHost: %s\n", SDLNet_GetError());
		SDLNet_Quit();
		SDL_Quit();
		exit(5);
	}

	/* open the server socket */
	net->sock = SDLNet_TCP_Open(&net->ip);
	if (!net->sock)
	{
		printf("SDLNet_TCP_Open: %s\n", SDLNet_GetError());
		SDLNet_Quit();
		SDL_Quit();
		exit(6);
	}

	if (SDLNet_TCP_AddSocket(net->set, net->sock) == -1)
	{
		printf("SDLNet_TCP_AddSocket: %s\n", SDLNet_GetError());
		SDLNet_Quit();
		SDL_Quit();
		exit(7);
	}
	/* login with a name */
	if (!putMsg(net->sock, myformat("ssdsdsd", net->name, "$", perso->r, "$", perso->g, "$", perso->b)))
	{
		SDLNet_TCP_Close(net->sock);
		SDLNet_Quit();
		SDL_Quit();
		exit(8);
	}

	printf("Logged in as %s\n", net->name);
}