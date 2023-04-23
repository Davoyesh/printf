/**
 * get_flags - Calculates active flags
 * @format: Formatted string in which to print the arguments
 * @i: Pointer to the current position in the format string
 * Return: Flags:
 */
int get_flags(const char *format, int *i)
{
	int flags = 0;

	while (strchr("-+0# ", format[*i + 1]))
	{
		switch (format[++(*i)])
		{
			case '-':
				flags |= F_MINUS;
				break;
			case '+':
				flags |= F_PLUS;
				break;
			case '0':
				flags |= F_ZERO;
				break;
			case '#':
				flags |= F_HASH;
				break;
			case ' ':
				flags |= F_SPACE;
				break;
		}
	}

	return (flags);
}
