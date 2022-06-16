size_t	ft_strlen(const char *str)
{
	char	*i;

	if (!str)
		return (0);
	i = (char *)str;
	while (*i)
		i++;
	return (i - str);
}
