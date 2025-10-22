/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_fd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlucena- <mlucena-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 14:48:31 by mlucena-          #+#    #+#             */
/*   Updated: 2025/10/22 16:58:48 by mlucena-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// Função para verificar se o arquivo existe e não está vazio
int	check_file_validity(char *filename)
{
	int		fd;
	char	buffer[1];
	int		read_bytes;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		ft_printf("Error\nMap file '%s' does not exist or cannot be opened\n",
			filename);
		return (0);
	}
	read_bytes = read(fd, buffer, 1);
	close(fd);
	if (read_bytes <= 0)
	{
		ft_printf("Error\nMap file '%s' is empty\n", filename);
		return (0);
	}
	return (1);
}

int	check_file_extension(char *filename, char *extension)
{
	int	file_len;
	int	ext_len;

	file_len = ft_strlen(filename);
	ext_len = ft_strlen(extension);
	if (file_len <= ext_len)
		return (0);
	return (ft_strncmp(filename + file_len - ext_len,
			extension, ext_len) == 0);
}

// Função principal para validar o arquivo do mapa antes de processar
int	validate_map_file(char *filename)
{
	if (!check_file_extension(filename, ".ber"))
	{
		ft_printf("Error\nMap file must have .ber extension\n");
		return (0);
	}
	if (!check_file_validity(filename))
		return (0);
	return (1);
}

// Função auxiliar para verificar extensão do arquivo

int	error_message(char *message)
{
	ft_printf("Error\n%s\n", message);
	return (0);
}
