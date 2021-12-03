#ifdef _WIN32
#define clearscreen() system("cls")
#else
#define clearscreen() printf("\e[1;1H\e[2J");
#endif