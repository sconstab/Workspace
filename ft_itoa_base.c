#include "libc.h"

char	*ft_itoa_base(int value, int base) {
	long	tmp;
	long	tmp2;
	char	*link;
	char	*ret;
	int		len;

	len = 0;
	tmp = value;
	link = "0123456789ABCDEF";
	if (value == 0)
		return ("0");
	if (tmp < 0) {
		if (base == 10)
			len++;
		tmp *= -1;
	}
	tmp2 = tmp;
	while (tmp2 > 0) {
		len++;
		tmp2 /= base;
	}
	ret = malloc(sizeof(char) * (len + 1));
	if (value < 0)
		ret[0] = '-';
	ret[len--] = '\0';
	while (tmp > 0) {
		ret[len--] = link[tmp % base];
		tmp /= base;
	}
	return (ret);
}

int		main() {
	int	test = 3;
	int	base = 2;

	printf("%s\n", ft_itoa_base(test, base));
	return (0);
}