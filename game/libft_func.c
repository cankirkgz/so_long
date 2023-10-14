/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_func.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkirkgoz <mkirkgoz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 09:51:52 by mkirkgoz          #+#    #+#             */
/*   Updated: 2023/10/14 11:00:02 by mkirkgoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"


char	*ft_strdup(const char *s1)
{
	char	*ret;
	size_t	len;

	len = ft_strlen(s1);
	ret = malloc(sizeof(char) * (len + 1));
	if (!ret)
		return (0);
	ft_strlcpy(ret, s1, len + 1);
	return (ret);
}

char* copy_string(const char* original) 
{
    // Orijinal dizinin uzunluğunu bulma.
    int length = strlen(original);

    // Yeni bir karakter dizisi için bellek ayrıştırma.
    char* copied = (char*)malloc((length + 1) * sizeof(char));

    if (copied == NULL) {
        fprintf(stderr, "Bellek ayrıştırma hatası\n");
        exit(EXIT_FAILURE);
    }

    // Orijinal karakter dizisini kopyalama.
    strcpy(copied, original);

    return copied;
}