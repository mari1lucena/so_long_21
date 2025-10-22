#include <stdio.h>      // Para comparação com printf real
#include "ft_printf.h"  // Seu ft_printf

	int main(void)
	{
		int len1, len2;
		int n = -42;
		char c = 'A';
		char *str = "Hello, Spark!";
		unsigned int u = 4294967295;
		void *ptr = &n;

		ft_printf("==== Testes com ft_printf ====\n");

		// %c
		len1 = ft_printf("Char: %c\n", c);
		len2 = printf("Char: %c\n", c);
		ft_printf("ft_printf len: %d | printf len: %d\n\n", len1, len2);

		// %s
		len1 = ft_printf("String: %s\n", str);
		len2 = printf("String: %s\n", str);
		ft_printf("ft_printf len: %d | printf len: %d\n\n", len1, len2);

		// %d e %i
		len1 = ft_printf("Decimal (%%d): %d\n", n);
		len2 = printf("Decimal (%%d): %d\n", n);
		ft_printf("ft_printf len: %d | printf len: %d\n\n", len1, len2);

		len1 = ft_printf("Integer (%%i): %i\n", n);
		len2 = printf("Integer (%%i): %i\n", n);
		ft_printf("ft_printf len: %d | printf len: %d\n\n", len1, len2);

		// %u
		len1 = ft_printf("Unsigned: %u\n", u);
		len2 = printf("Unsigned: %u\n", u);
		ft_printf("ft_printf len: %d | printf len: %d\n\n", len1, len2);

		// %x e %X
		len1 = ft_printf("Hex lowercase: %x\n", u);
		len2 = printf("Hex lowercase: %x\n", u);
		ft_printf("ft_printf len: %d | printf len: %d\n\n", len1, len2);

		len1 = ft_printf("Hex uppercase: %X\n", u);
		len2 = printf("Hex uppercase: %X\n", u);
		ft_printf("ft_printf len: %d | printf len: %d\n\n", len1, len2);

		// %p
		len1 = ft_printf("Pointer: %p\n", ptr);
		len2 = printf("Pointer: %p\n", ptr);
		ft_printf("ft_printf len: %d | printf len: %d\n\n", len1, len2);

		// %%
		len1 = ft_printf("Percent: %%\n");
		len2 = printf("Percent: %%\n");
		ft_printf("ft_printf len: %d | printf len: %d\n\n", len1, len2);

		return 0;
	}
