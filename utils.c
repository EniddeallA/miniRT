/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhalid <akhalid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 02:48:37 by akhalid           #+#    #+#             */
/*   Updated: 2020/10/23 17:04:55 by akhalid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strdup(const char *s1)
{
	char	*s;
	char	*dp;
	int		i;

	s = (char *)s1;
	if ((dp = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1))) == 0)
		return (0);
	if (!s)
	{
		*dp = '\0';
		return (dp);
	}
	i = 0;
	while (*s)
	{
		dp[i] = *s;
		s++;
		i++;
	}
	dp[i] = '\0';
	return (dp);
}

int		ft_strchr(char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
			return (1);
		s++;
	}
	if (*s == (char)c)
		return (1);
	return (0);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned	char	*ss1;
	unsigned	char	*ss2;

	ss1 = (unsigned char *)s1;
	ss2 = (unsigned char *)s2;
	while (n-- > 0)
	{
		if (*ss1 != *ss2)
			return (*ss1 - *ss2);
		if (!*ss1)
			return (0);
		ss1++;
		ss2++;
	}
	return (0);
}

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned	char	*t;

	t = b;
	while (len-- > 0)
		*t++ = c;
	return (b);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	i;
	size_t	j;
	char	*temp;
	size_t	len;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	if (!(temp = (char*)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	while (s1[i] != '\0')
	{
		temp[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
		temp[i++] = s2[j++];
	temp[i] = '\0';
	return (temp);
}

int		ft_atoi(char **str)
{
	long res;
	long sign;

	res = 0;
	sign = 1;
	while (**str == '\t' || **str == '\n' || **str == '\r' || **str == '\v' ||
			**str == '\f' || **str == ' ' || (**str < '0' || **str > '9'))
		*str += 1;
	if (**str == '-')
		sign = -1;
	if (**str == '-' || **str == '+')
		*str += 1;
	while (**str >= '0' && **str <= '9')
	{
		if ((unsigned long)__LONG_MAX__ < ((unsigned long)res * 10 + (**str -
						'0')) && sign == 1)
			return (-1);
		else if ((unsigned long)__LONG_MAX__ < ((unsigned long)res * 10 +
					(**str - '0')) && sign == -1)
			return (0);
		res = res * 10 + (**str - '0');
		*str += 1;
	}
	return (res * sign);
}

float		ft_strtof(char **str)
{
	int sign;
	int res;
    int sig_digs;
    int exponent;
    int saw_point;

	res = 0;
	sign = 1;
	sig_digs = 0;
	exponent = 0;
	saw_point = 0;
	while ((**str == '\t' || **str == '\n' || **str == '\r' || **str == '\v' ||
			**str == '\f' || **str == ' ' || **str < '0' || **str > '9') && **str != '-')
		*str += 1;
	if (**str == '-')
		sign = -1;
	if (**str == '-' || **str == '+')
		*str += 1;
	while ((**str >= '0' && **str <= '9') || **str == '.')
	{
		if (**str == '.')
            if (saw_point)
				break ;
            else
                saw_point = 1;
        else
            if (sig_digs < 8)
			{
                res = (res * 10) + (**str - '0');
				sig_digs += (res) ? 1 : 0;
				exponent -= (saw_point) ? 1 : 0;
            }
			else if (!saw_point)
                exponent++;
        *str += 1;
	}
	return (calculateValue(exponent, res, sig_digs) * sign);
}

float calculateValue(int exponent, int res, int sig_digs)
{
	float value;
	float ten_to_the[] = {1, 10, 100, 1000, 10000};
	float ten_to_the_minus[] = {1, 0.1, 0.01, 0.001, 0.0001};
	
	value = 0;
	if (exponent >= 0)
		value = res * ten_to_the[exponent];
	else
	{
		if (exponent < -37)
		{
            value = res * ten_to_the_minus[sig_digs];
            exponent += sig_digs; 
        }
		else
            value = res;
        value *= ten_to_the_minus[-exponent];
	}
	return (value);
}