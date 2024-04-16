#pragma once
#ifndef ASPELL_HPP
#define ASPELL_HPP

#include <string>
#include <iostream>
#include "ATarget.hpp"
using namespace std;

class ATarget;

class ASpell {
	protected:
		string name;
		string effects;
	public:
		ASpell(string name, string effects);
		ASpell(const ASpell& obj);
		ASpell& operator=(const ASpell& obj);
		virtual ~ASpell();

		string getName() const;
		string getEffects() const;

		virtual ASpell* clone() const = 0;
		void launch(const ATarget& atarget) const;
};

#endif