/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlee <nlee@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/15 13:15:53 by nlee              #+#    #+#             */
/*   Updated: 2020/10/15 14:42:44 by nlee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *str1, char const *str2)
{
	size_t	str1_len;
	size_t	str2_len;
	char	*ret;

	if(!(str1_len = ft_strlen(str1) && !(str2_len = ft_strlen(str2))))
		return (0);
	ret = (char *)malloc((str1_len + str2_len + 1) * sizeof(char));
	ft_memcpy(ret, str1, str1_len);
	ft_memcpy(ret + str1_len, str2, str2_len);
	ret[str1_len + str2_len + 1] = 0;
	return (ret);
}
