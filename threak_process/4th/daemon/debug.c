#ifdef DEBUG
void debug_wait (int debug)
{
	while (1) {
		if (debug == 1)
			sleep (1);
		else
			break;
	}
}
#else
void debug_wait (int debug)
{
}
#endif
