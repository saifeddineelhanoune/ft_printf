#!/bin/sh
fswatch --exclude ".*" --include "ft_printf.c" --verbose ./ | while read f ; do clear && gcc $f push/libft.a && ./a.out | cat -e; done