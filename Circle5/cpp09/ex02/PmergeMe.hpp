/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahlee <jahlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 16:25:12 by jahlee            #+#    #+#             */
/*   Updated: 2023/09/01 20:02:35 by jahlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <vector>
#include <deque>

class PmergeMe {
	private:
		static PmergeMe* _ptr;
		std::vector<int> _before;
		std::vector<int> _after;
		std::pair<int,int> _v_time;
		std::pair<int,int> _dq_time;
		PmergeMe(void);
		PmergeMe(char** argv);
		PmergeMe(const PmergeMe& obj);
		PmergeMe& operator=(const PmergeMe& obj);
		static bool compare(const std::pair<int, int>& a, const std::pair<int, int>& b);
	public:
		~PmergeMe(void);
		static PmergeMe* getPmergeMe(char** argv);
		void sortVector(void);
		void sortDeque(void);
		template <typename T>
		void fordJohnsonSort(T& mainChain, T&subChain) {
			(void)mainChain;
			(void)subChain;
		};
};

#endif
