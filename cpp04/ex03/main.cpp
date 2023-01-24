/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smischni <smischni@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 15:41:04 by smischni          #+#    #+#             */
/*   Updated: 2023/01/24 14:32:11 by smischni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"

int main()
{
	{
		std::cout << YELLOW "********* Subject Test ********" DEFAULT << std::endl;
		IMateriaSource* src = new MateriaSource();
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());
		ICharacter* me = new Character("me");
		AMateria* tmp;
		tmp = src->createMateria("ice");
		me->equip(tmp);
		tmp = src->createMateria("cure");
		me->equip(tmp);
		ICharacter* bob = new Character("bob");
		me->use(0, *bob);
		me->use(1, *bob);
		delete bob;
		delete me;
		delete src;
	}
	{
		std::cout << YELLOW "********* Own Tests Materia & Character ********" DEFAULT << std::endl;
		
		std::cout << YELLOW "Create 1 Ice and 1 Cure:" DEFAULT << std::endl;
		// AMateria	*m0 = new AMateria();//doesn't work since abstract
		AMateria	*m1 = new Ice();
		AMateria	*m2 = new Cure();

		std::cout << YELLOW "Use Copy Constructor of Ice:" DEFAULT << std::endl;
		AMateria	*m3 = new Ice(*(Ice*)m1);
		delete m3;
		m3 = new Ice(*(Ice*)m2);//should fail since m2 is Cure
		delete m3;

		std::cout << YELLOW "Assign Materias of one type to another one:" DEFAULT << std::endl;
		*m1 = *m2;//not allowed, since they are different Materia types - no copying of type
		
		std::cout << YELLOW "Create 2 Characters: target and attacker:" DEFAULT << std::endl;
		// ICharacter	*c0 = new ICharacter();//doesn't work since abstract/interface
		ICharacter	*target = new Character("Henne");
		ICharacter	*attacker = new Character("Saskia");

		std::cout << YELLOW "Try to equip 5 Materias (Ice and Cure and their clones) to attacker:" DEFAULT << std::endl;
		attacker->equip(m1);
		attacker->equip(m2);
		attacker->equip(m1->clone());
		attacker->equip(m2->clone());
		AMateria	*m4 = new Ice();//make new Materia for the slot since we need to be able to delete it after equipping fails
		attacker->equip(m4);//shouldn't work since all slots are full
		delete m4;

		std::cout << YELLOW "Use the 4 equipped Materias:" DEFAULT << std::endl;
		attacker->use(0, *target);
		attacker->use(1, *target);
		attacker->use(2, *target);
		attacker->use(3, *target);
		
		std::cout << YELLOW "Unequip Materia at index 1 (twice) + try to unequip index out of bounds:" DEFAULT << std::endl;
		attacker->unequip(1);
		attacker->unequip(1);//shouldn't work since nothing equipped here
		attacker->unequip(5);//shouldn't work since out of bounds
		
		std::cout << YELLOW "Equip different Materia at index 1 and use it:" DEFAULT << std::endl;
		attacker->equip(m1->clone());
		attacker->use(1, *target);
		
		std::cout << YELLOW "Create new Character and use copy assignment operator to copy attacker:" DEFAULT << std::endl;
		Character	newC("Vinny");
		newC = *(Character*)attacker;

		std::cout << YELLOW "Unequip Materia at 3rd index of attacker, try to use it both in attacker and its copy:" DEFAULT << std::endl;
		attacker->unequip(3);
		attacker->use(3, *target);//shouldn't work since unequipped
		newC.use(3, *target);//should work if deep copy
		
		std::cout << YELLOW "Delete attackers, also deletes all equipped and previously equipped Materias:" DEFAULT << std::endl;
		delete target;
		delete attacker;
	}
	{
		std::cout << YELLOW "********* Own Tests MateriaSource ********" DEFAULT << std::endl;

		std::cout << YELLOW "Create MateriaSource and have it learn 4 Materias:" DEFAULT << std::endl;
		IMateriaSource *ms = new MateriaSource();
		ms->learnMateria(new Ice());
		ms->learnMateria(new Ice());
		ms->learnMateria(new Ice());
		ms->learnMateria(new Ice());

		std::cout << YELLOW "Try to have it learn a 5th Materia, delete afterwards:" DEFAULT << std::endl;
		AMateria *m0 = new Ice();
		ms->learnMateria(m0);//shouldn't work since only 4 spots for Materia
		delete m0;

		std::cout << YELLOW "Create Characters to equip it with Materia from the MateriaSource / use it on them:" DEFAULT << std::endl;
		ICharacter	*attacker = new Character("Saskia");
		ICharacter	*target = new Character("Henne");
		
		std::cout << YELLOW "Create Materia from MateriaSource, equip it to attacker Character and use it:" DEFAULT << std::endl;
		AMateria *m1 = ms->createMateria("ice");
		attacker->equip(m1);
		attacker->use(0, *target);//shows that it actually created Ice

		std::cout << YELLOW "Try to create a Materia not known by the Materia Source:" DEFAULT << std::endl;
		m1 = ms->createMateria("cure");//shouldn't since Materia is unknown to Materia Source
		m1 = ms->createMateria("fire");//shouldn't since invalid Materia
		
		std::cout << YELLOW "Delete Characters and MateriaSource, incl. their respective Materias:" DEFAULT << std::endl;
		delete attacker;//also deletes Materia m1 since equipped
		delete target;
		delete ms;//deletes the original Materias
	}
	return 0;
}
