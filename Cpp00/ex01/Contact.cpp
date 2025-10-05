/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leo <leo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 00:00:00 by leo               #+#    #+#             */
/*   Updated: 2025/10/03 00:00:00 by leo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact()
{
    for (int i = 0; i < 5; i++)
        info[i] = "";
}

void Contact::setInfo(int index, const std::string& value)
{
    if (index >= 0 && index < 5)
        info[index] = value;
}

std::string Contact::getInfo(int index) const
{
    if (index >= 0 && index < 5)
        return info[index];
    return "";
}