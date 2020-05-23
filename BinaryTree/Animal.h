#ifndef ANIMAL_H
#define ANIMAL_H

// clase abstracta
struct InterfaceAnimal
{
	virtual void MakeNoise() = 0;
	virtual void Run() = 0;
};

#endif