#pragma once
#ifndef ATARGET_HPP
#define ATARGET_HPP

#include <string>
#include "ASpell.hpp"
using namespace std;

class ASpell;

class ATarget {
	protected:
		string type;
	public:
		ATarget(string type);
		const string& getType() const;
		virtual ATarget* clone() const = 0;
		void getHitBySpell(const ASpell& aspell);
};

#endif