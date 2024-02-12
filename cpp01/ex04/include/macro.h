/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   macro.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minakim <minakim@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 21:29:09 by minakim           #+#    #+#             */
/*   Updated: 2024/02/12 14:25:33 by minakim          ###   ########.fr       */
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

/* ************************************************************************** */

/// for the target project
# include <sstream>
# include <fstream>

/// project using
using	std::ifstream;
using	std::ofstream;

#endif
