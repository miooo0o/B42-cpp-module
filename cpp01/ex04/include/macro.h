/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   macro.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minakim <minakim@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 21:29:09 by minakim           #+#    #+#             */
/*   Updated: 2024/02/12 17:01:34 by minakim          ###   ########.fr       */
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

/// error
#include <errno.h>
# define SYSERROR()  errno

/// valid
# define INVALID	1
# define VALID		0

/* ************************************************************************** */

/// for the target project
# include <sstream>
# include <fstream>

/// project using
using	std::ifstream;
using	std::ofstream;

#endif
