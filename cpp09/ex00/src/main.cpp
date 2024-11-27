/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minakim <minakim@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 20:24:00 by minakim           #+#    #+#             */
/*   Updated: 2024/11/26 20:42:36 by minakim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

Data	createDateBase(const std::string& filename)
{
    FileHandler fileHandler(filename);
    if (fileHandler.getExtension() != "csv")
        throw std::runtime_error("invalid database file, `" 
                                + fileHandler.getExtension() 
                                + "` (expected .csv)");
    const std::vector<std::string> content = fileHandler.readFile();
    return (Data(content));
}

int	main(const int argc, const char **argv)
{
	if (argc != 2)
	{
        std::cerr << "Usage: " << argv[0] << " <bitcoin file>" << std::endl;
        return (1);
    }

    const std::string   bitcoinFilename = argv[1];
    try
    {
        const Data      db = createDateBase("data/data.csv");
        BitcoinExchange bitcoinExchange(db, bitcoinFilename);
        bitcoinExchange.run();       
    }
    catch(const std::exception& e)
    {
        std::cerr << "Error: runtime error => " << e.what() << '\n';
        return (1);
    }

    return (0);
}
