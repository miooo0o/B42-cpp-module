/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   macro.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minakim <minakim@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 21:29:09 by minakim           #+#    #+#             */
/*   Updated: 2024/02/14 19:42:04 by minakim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MACRO_H
#define MACRO_H

/// basic i/o stream
# include <iostream>

/// string
# include <string>

/// exit code
# include <cstdlib>

/// basic using
using	std::cout;
using	std::endl;
using	std::flush;
using	std::string;
using	std::cerr;
using	std::cin;

/// valid
# define INVALID	1
# define VALID		0

/* ************************************************************************** */

/// project using
using	std::ifstream;
using	std::ofstream;

#endif
