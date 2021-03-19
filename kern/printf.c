// Simple implementation of cprintf console output for the kernel,
// based on printfmt() and the kernel console's cputchar().

#include <inc/types.h>
#include <inc/stdio.h>
#include <inc/stdarg.h>

/*
	A helper for vprintfmt().
*/
static void
putch(int ch, int *cnt)
{
	cputchar(ch);
	*cnt++;
}

/*
	Use vprintfmt() as a subroutine. Return successful char counts.
*/
int
vcprintf(const char *fmt, va_list ap) // va_list = var_args_list
{
	int cnt = 0;

	vprintfmt((void*)putch, &cnt, fmt, ap);
	return cnt;
}

int
cprintf(const char *fmt, ...)
{
	va_list ap;
	int cnt;

	va_start(ap, fmt);
	cnt = vcprintf(fmt, ap);
	va_end(ap);

	return cnt;
}

