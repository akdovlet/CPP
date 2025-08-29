/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 10:29:32 by akdovlet          #+#    #+#             */
/*   Updated: 2025/08/29 16:47:33 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

// int main()
// {
// 	// DiamondTrap d1("Shiny");
// 	FragTrap	original("Rocky");
// 	original.attack("your mom");
// 	original.beRepaired(20);
// 	FragTrap	YN(original);
// 	std::cout << YN.getName() << std::endl;
// 	std::cout << YN.getHP() << std::endl;
// 	std::cout << YN.getEP() << std::endl;
// 	std::cout << YN.getAD() << std::endl;

	
// 	// d1.getValues();
// 	return (0);
// }

int main() {
    // Test Section 1: Basic ClapTrap (ex00)
    std::cout << "\n=== Test 1: Basic ClapTrap Construction and Destruction ===\n";
    {
        ClapTrap clap("ClapBot");
    }  // Destructor called here

    // Expected Output:
    // ClapTrap ClapBot constructor called
    // ClapTrap ClapBot destructor called

    std::cout << "\n=== Test 2: ClapTrap Actions ===\n";
    {
        ClapTrap clap("ClapBot");
        clap.attack("Enemy1");
        clap.takeDamage(5);
        clap.beRepaired(3);
        clap.takeDamage(15);  // Should deplete hit points
        clap.attack("Enemy2");  // No action if no hit points
        clap.beRepaired(10);    // No action if no hit points
    }

    // Expected Output:
    // ClapTrap ClapBot constructor called
    // ClapTrap ClapBot attacks Enemy1, causing 0 points of damage!
    // ClapTrap ClapBot takes 5 points of damage!
    // ClapTrap ClapBot is repaired for 3 points!
    // ClapTrap ClapBot takes 15 points of damage!
    // ClapTrap ClapBot cannot attack because it has no hit points left!
    // ClapTrap ClapBot cannot be repaired because it has no hit points left!
    // ClapTrap ClapBot destructor called

    std::cout << "\n=== Test 3: ClapTrap Energy Depletion ===\n";
    {
        ClapTrap clap("EnergyBot");
        for (int i = 0; i < 11; ++i) {  // 10 energy points initially
            clap.attack("Target");
        }
        clap.beRepaired(5);  // No energy left
    }

    // Expected Output:
    // ClapTrap EnergyBot constructor called
    // ClapTrap EnergyBot attacks Target, causing 0 points of damage!  (x10)
    // ClapTrap EnergyBot cannot attack because it has no energy points left!
    // ClapTrap EnergyBot cannot be repaired because it has no energy points left!
    // ClapTrap EnergyBot destructor called

    std::cout << "\n=== Test 4: ClapTrap Copy and Assignment ===\n";
    {
        ClapTrap original("OriginalBot");
        original.takeDamage(4);
        original.beRepaired(2);

        ClapTrap copy(original);
        copy.attack("CopyTarget");

        ClapTrap assigned("AssignedBot");
        assigned = original;
        assigned.attack("AssignedTarget");
    }

    // Expected Output:
    // ClapTrap OriginalBot constructor called
    // ClapTrap OriginalBot takes 4 points of damage!
    // ClapTrap OriginalBot is repaired for 2 points!
    // ClapTrap OriginalBot copy constructor called  (for copy)
    // ClapTrap copy attacks CopyTarget, causing 0 points of damage!
    // ClapTrap AssignedBot constructor called
    // ClapTrap OriginalBot copy assignment operator called  (for assigned = original)
    // ClapTrap assigned attacks AssignedTarget, causing 0 points of damage!
    // (Destructors in reverse order)

    // Test Section 2: ScavTrap (ex01)
    std::cout << "\n=== Test 5: ScavTrap Construction and Destruction Chaining ===\n";
    {
        ScavTrap scav("ScavBot");
    }

    // Expected Output:
    // ClapTrap ScavBot constructor called
    // ScavTrap ScavBot constructor called
    // ScavTrap ScavBot destructor called
    // ClapTrap ScavBot destructor called

    std::cout << "\n=== Test 6: ScavTrap Actions and Special Ability ===\n";
    {
        ScavTrap scav("ScavBot");
        scav.attack("Enemy");  // Should use ScavTrap message if overridden
        scav.takeDamage(20);
        scav.beRepaired(15);
        scav.guardGate();
    }

    // Expected Output:
    // ClapTrap ScavBot constructor called
    // ScavTrap ScavBot constructor called
    // ScavTrap ScavBot attacks Enemy, causing 20 points of damage!
    // ScavTrap ScavBot takes 20 points of damage!
    // ScavTrap ScavBot is repaired for 15 points!
    // ScavTrap ScavBot is now in Gate keeper mode!
    // ScavTrap ScavBot destructor called
    // ClapTrap ScavBot destructor called

    std::cout << "\n=== Test 7: ScavTrap Copy and Assignment ===\n";
    {
        ScavTrap original("OriginalScav");
        original.takeDamage(30);
        original.beRepaired(10);

        ScavTrap copy(original);
        copy.attack("CopyEnemy");
        copy.guardGate();

        ScavTrap assigned("AssignedScav");
        assigned = original;
        assigned.attack("AssignedEnemy");
    }

    // Expected Output:
    // (Construction chaining for original)
    // ScavTrap OriginalScav takes 30 points of damage!
    // ScavTrap OriginalScav is repaired for 10 points!
    // (Copy construction chaining)
    // ScavTrap copy attacks CopyEnemy, causing 20 points of damage!
    // ScavTrap copy is now in Gate keeper mode!
    // (Construction for assigned)
    // (Assignment chaining)
    // ScavTrap assigned attacks AssignedEnemy, causing 20 points of damage!
    // (Destructors)

    // Test Section 3: FragTrap (ex02)
    std::cout << "\n=== Test 8: FragTrap Construction and Destruction Chaining ===\n";
    {
        FragTrap frag("FragBot");
    }

    // Expected Output:
    // ClapTrap FragBot constructor called
    // FragTrap FragBot constructor called
    // FragTrap FragBot destructor called
    // ClapTrap FragBot destructor called

    std::cout << "\n=== Test 9: FragTrap Actions and Special Ability ===\n";
    {
        FragTrap frag("FragBot");
        frag.attack("Enemy");
        frag.takeDamage(40);
        frag.beRepaired(25);
        frag.highFivesGuys();
    }

    // Expected Output:
    // ClapTrap FragBot constructor called
    // FragTrap FragBot constructor called
    // FragTrap FragBot attacks Enemy, causing 30 points of damage!
    // FragTrap FragBot takes 40 points of damage!
    // FragTrap FragBot is repaired for 25 points!
    // FragTrap FragBot requests a positive high fives!
    // FragTrap FragBot destructor called
    // ClapTrap FragBot destructor called

    std::cout << "\n=== Test 10: FragTrap Copy and Assignment ===\n";
    {
        FragTrap original("OriginalFrag");
        original.takeDamage(50);
        original.beRepaired(20);

        FragTrap copy(original);
        copy.attack("CopyEnemy");
        copy.highFivesGuys();

        FragTrap assigned("AssignedFrag");
        assigned = original;
        assigned.attack("AssignedEnemy");
    }

    // Expected Output:
    // Similar to ScavTrap, with FragTrap-specific messages and values (e.g., 30 damage)

    // Test Section 4: DiamondTrap (ex03)
    std::cout << "\n=== Test 11: DiamondTrap Construction and Destruction Chaining ===\n";
    {
        DiamondTrap diamond("DiamondBot");
    }

    // Expected Output:
    // ClapTrap DiamondBot_clap_name constructor called
    // ScavTrap DiamondBot constructor called
    // FragTrap DiamondBot constructor called
    // DiamondTrap DiamondBot constructor called
    // DiamondTrap DiamondBot destructor called
    // FragTrap DiamondBot destructor called
    // ScavTrap DiamondBot destructor called
    // ClapTrap DiamondBot_clap_name destructor called
    // (Order of ScavTrap/FragTrap may vary, but ClapTrap once)

    std::cout << "\n=== Test 12: DiamondTrap Actions and Inherited Abilities ===\n";
    {
        DiamondTrap diamond("DiamondBot");
        diamond.whoAmI();
        diamond.attack("Enemy");  // Should use ScavTrap's attack
        diamond.takeDamage(35);
        diamond.beRepaired(20);
        diamond.guardGate();      // From ScavTrap
        diamond.highFivesGuys();  // From FragTrap
    }

    // Expected Output:
    // (Construction chaining as above)
    // DiamondTrap name: DiamondBot, ClapTrap name: DiamondBot_clap_name
    // ScavTrap DiamondBot attacks Enemy, causing 30 points of damage!  (Since using ScavTrap::attack)
    // DiamondTrap DiamondBot takes 35 points of damage!
    // DiamondTrap DiamondBot is repaired for 20 points!
    // ScavTrap DiamondBot is now in Gate keeper mode!
    // FragTrap DiamondBot requests a positive high fives!
    // (Destruction chaining)

    std::cout << "\n=== Test 13: DiamondTrap Attribute Verification ===\n";
    {
        DiamondTrap diamond("DiamondBot");
        // Assuming getValues() or similar prints: name, hitPoints (100 from Frag), energy (50 from Scav), attack (30 from Frag)
        diamond.getValues();  // If implemented; otherwise, use attacks/repairs to infer
    }

    // Expected Output:
    // DiamondBot
    // 100
    // 50
    // 30
    // (Plus construction/destruction)

    std::cout << "\n=== Test 14: DiamondTrap Copy and Assignment ===\n";
    {
        DiamondTrap original("OriginalDiamond");
        original.takeDamage(40);
        original.beRepaired(15);

        DiamondTrap copy(original);
        copy.whoAmI();
        copy.attack("CopyEnemy");

        DiamondTrap assigned("AssignedDiamond");
        assigned = original;
        assigned.whoAmI();
        assigned.attack("AssignedEnemy");
    }

    // Expected Output:
    // (Construction for original)
    // OriginalDiamond takes 40 points of damage!
    // OriginalDiamond is repaired for 15 points!
    // (Copy construction: should preserve modified hit points, etc.)
    // DiamondTrap name: OriginalDiamond, ClapTrap name: OriginalDiamond_clap_name
    // ScavTrap OriginalDiamond attacks CopyEnemy, causing 30 points of damage!
    // (Assignment: similar preservation)
    // DiamondTrap name: OriginalDiamond, ClapTrap name: OriginalDiamond_clap_name  (assigned now has original's state, but name is AssignedDiamond? Wait, if name is copied correctly)
    // Note: Ensure copy/assign handles both _name and ClapTrap::_name correctly via swap or proper impl.
    // ScavTrap OriginalDiamond attacks AssignedEnemy, causing 30 points of damage!
    // (Destructors)

    std::cout << "\n=== Test 15: Mixed Inheritance and Polymorphism ===\n";
    {
        ClapTrap* base = new DiamondTrap("PolyBot");
        base->attack("PolyEnemy");  // Should call ScavTrap's attack via DiamondTrap
        delete base;
    }

    // Expected Output:
    // (Full chaining for DiamondTrap)
    // ScavTrap PolyBot attacks PolyEnemy, causing 30 points of damage!
    // (Full destruction chaining)

    return 0;
}
