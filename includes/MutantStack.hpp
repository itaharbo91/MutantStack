/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itaharbo <itaharbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 23:16:25 by itaharbo          #+#    #+#             */
/*   Updated: 2025/10/23 23:38:06 by itaharbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <stack>

template <typename T>
class MutantStack : public std::stack<T>
{
public:

	MutantStack() {}
	MutantStack(MutantStack const &cpy) : std::stack<T>(cpy) {}
	~MutantStack() {}

	MutantStack&	operator=(MutantStack const &other)
	{
		std::stack<T>::operator=(other);
		return *this;
	}

	typedef typename std::stack<T>::container_type::iterator		iterator;
	typedef typename std::stack<T>::container_type::const_iterator	const_iterator;

	iterator	begin()
	{
		return this->c.begin();
	}

	iterator	end()
	{
		return this->c.end();
	}

	const_iterator	begin() const
	{
		return this->c.begin();
	}

	const_iterator	end() const
	{
		return this->c.end();
	}

};

#endif
