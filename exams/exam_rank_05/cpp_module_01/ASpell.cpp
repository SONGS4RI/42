#include "ASpell.hpp"

ASpell::ASpell(string name, string effects) {
	this->name = name;
	this->effects = effects;
}

ASpell::ASpell(const ASpell& obj) {
	*this = obj;
}

ASpell& ASpell::operator=(const ASpell& obj) {
	this->name = obj.getName();
	this->effects = obj.getEffects();
}

ASpell::~ASpell() {

}


string ASpell::getName() const {
	return name;
}

string ASpell::getEffects() const {
	return effects;
}

void ASpell::launch(const ATarget& atarget) const {
	
}
