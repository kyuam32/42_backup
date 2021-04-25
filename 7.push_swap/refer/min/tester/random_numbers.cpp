/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random_numbers.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minckim <minckim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/07 01:27:52 by minckim           #+#    #+#             */
/*   Updated: 2021/03/07 02:10:52 by minckim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <set>
#include <vector>
#include <random>
#include <iostream>
#include <unistd.h>

int				myrandom(long min, long max)
{
	std::random_device					random_device;
	std::mt19937						generator(random_device());
	std::uniform_int_distribution<int>	distribute(min, max);
	return distribute(generator);
}

int		main(int argc, char** argv)
{
	std::set<int>		s;
	std::vector<int>	v;
	
	int		size;
	int		min;
	int		max;
	if (argc < 2)
	{
		std::cout << "Usage: " << argv[0] << " <size> [min] [max]\n"
		<< "min and max is optional arguments.\n"
		<< "if (max - min) is less than size, max is revised automatically\n"
		<< "if you want to set ARG, just type a cmd line like this:\n"
		<< "export ARG=\"$(" << argv[0] << " <size> [min] [max])\"\n"
		<< "made by minckim\n";
		return 1;
	}
	try
	{
		size = atoi(argv[1]);
		if (argc >= 3)
			min = atoi(argv[2]);
		else
			min = 0;
		if (argc >= 4)
		{
			max = atoi(argv[3]);
			max = max > min + size - 1 ? max : min + size - 1;
		}
		else
			max = min + size - 1;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << '\n';
	}
	for (int i = 0 ; i < size ; ++i)
	{
		auto	result = s.insert(myrandom(min, max));
		while (result.second == false)
		{
			result = s.insert(myrandom(min, max));
		}
		v.push_back(*result.first);
	}
	for (int i : v)
	{
		std::string		num = std::to_string(i);
		write(1, num.c_str(), num.length());
		write(1, " ", 1);
	}
	return 0;
}