int ft_strncmp(char *s1, char *s2, size_t n)
{
  int i;
  int j;
  
  i = 0;
  j = 0;
  if (n == 0)
    return (j);
  while (s1[i] == s2[i] && s1[i] && i < (n - 1))
    if (i < (n - 1))
      i++;

  j = (s1[i] - s2[i]);
  return (j);
}
