/*
 * Copyright (c) 2016-2018 The strace developers.
 * All rights reserved.
 *
 * SPDX-License-Identifier: GPL-2.0-or-later
 */

#include "tests.h"
#include <asm/unistd.h>

#ifdef __NR_unlink

# include <stdio.h>
# include <unistd.h>

int
main(void)
{
	static const char sample[] = "unlink_sample";

	long rc = syscall(__NR_unlink, sample);
	printf("unlink(\"%s\") = %ld %s (%m)\n",
	       sample, rc, errno2name());

	puts("+++ exited with 0 +++");
	return 0;
}

#else

SKIP_MAIN_UNDEFINED("__NR_unlink")

#endif
