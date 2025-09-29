/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leo <leo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 14:27:55 by leo               #+#    #+#             */
/*   Updated: 2025/09/15 15:46:22 by leo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cctype>

char toupperChar (char c)
{
    return (static_cast<char>(std::toupper(c)));
}

int main (int argc, char **argv)
{
    if (argc == 1)
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
    else
    {
        for(int i = 1; i < argc; i++)
        {
            for(int j = 0; argv[i][j]; j++)
                std::cout<<toupperChar(argv[i][j]);
        }
    }
    std::cout << std::endl;
    return(0);
}