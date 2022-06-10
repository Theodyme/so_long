size_t	ft_strlen(const char *str)
{
	char	*i;

	i = (char *)str;
	while (*i)
		i++;
	return (i - str);
}