/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riel-fas <riel-fas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 11:56:07 by riel-fas          #+#    #+#             */
/*   Updated: 2025/01/17 11:56:09 by riel-fas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*p1;
	unsigned char	*p2;
	size_t			x;

	p1 = (unsigned char *)s1;
	p2 = (unsigned char *)s2;
	x = 0;
	if (n == 0)
		return (0);
	while (x < n && (s1[x] != '\0' || s2[x] != '\0'))
	{
		if (p1[x] != p2[x])
			return (p1[x] - p2[x]);
		x++;
	}
	return (0);
}
