
static int	process(long nb, int base)
{
	int		val;

	val = 0;
	if (nb >= base)
	{
		val += process(nb / base, base);
		val += process(nb % base, base);
	}
	else
		val++;
	return (val);
}

int			ft_nbrlen(long nbr, int base)
{
	char	neg;

	neg = 0;
	if (nbr < 0)
	{
		nbr = -nbr;
		neg++;
	}
	return(process(nbr, base) + neg);
}