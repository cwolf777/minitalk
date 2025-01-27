/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwolf <cwolf@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 10:29:31 by cwolf             #+#    #+#             */
/*   Updated: 2025/01/27 11:19:50 by cwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	signal1(int signo, void *handler)
{
	sa.sa_handler = handler;
	sigaaddset(&sa.sa_mask, SIGUSR1);
	sigaaddset(&sa.sa_mask, SIGUSR2);
	
	if (sigaction(signo, &sa, NULL) < 0)
	{
		perror("Sigaction failed");
		exit(EXIT_FAILURE);
	}
}