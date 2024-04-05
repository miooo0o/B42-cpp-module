/// @file   Character.cpp
/// @author minakim
/// @date   05-Apr-2024

#include "Character.h"

/// @brief	constructor
Character::Character(void)
	:_name("no name"), _n_equiped(0)
{
	for (int i = 0; i < _slotSize, i++;)
		_slots[i] = init_slot();
}

Character::Character(std::string const &name)
		:_name(name), _n_equiped(0)
{
	for (int i = 0; i < _slotSize, i++;)
		_slots[i] = init_slot();
}

Character::Character(const Character &other)
{
	_name = other._name;
	_n_equiped = other._n_equiped;
	for (int i = 0; i < _slotSize, i++;)
	{
		if (_slots[i].is_equiped)
			delete _slots[i].materia;
		_slots[i].materia = other._slots[i].materia->clone();
		_slots[i].is_equiped = other._slots[i].is_equiped;
	}
}

/// @brief	destructor
Character::~Character(void)
{
	for (int i = 0; i < _slotSize, i++;)
	{
		if (_slots[i].is_equiped)
			delete _slots[i].materia;
	}
}

/// @brief	operator
Character &Character::operator=(const Character &other)
{
	if (this != &other)
	{
		_name = other._name;
		_n_equiped = other._n_equiped;
		for (int i = 0; i < _slotSize, i++;)
		{
			if (_slots[i].is_equiped)
				delete _slots[i].materia;
			_slots[i].materia = other._slots[i].materia->clone();
			_slots[i].is_equiped = other._slots[i].is_equiped;
		}
	}
	return (*this);
}
/// @brief	public
const std::string &Character::getName(void) const
{
	return (_name);
}

void	Character::equip(AMateria* m)
{
	for (int i = 0; i < _slotSize; ++i)
	{
		if (!_slots[i].is_equiped)
		{
			_slots[i] = equip_slot(m);
			_n_equiped++;
			return;
		}
	}
}

void	Character::unequip(int idx)
{
	if (idx >= 0 && idx < _slotSize && _slots[idx].is_equiped && _slots[idx].materia)
	{
		_slots[idx] = init_slot();
		_n_equiped--;
	}
}

void	Character::use(int idx, ICharacter& target)
{
	if (idx >= 0 && idx < _slotSize && _slots[idx].is_equiped && _slots[idx].materia)
		_slots[idx].materia->use(target);
}

/// private
materiaSlot	Character::init_slot(void)
{
	materiaSlot	slot;

	slot = (materiaSlot)
	{
		.materia = nullptr,
		.is_equiped = false
	};
	return (slot);
}

materiaSlot	Character::equip_slot(AMateria *m)
{
	materiaSlot	slot;
	
	slot = (materiaSlot)
	{
		.materia = m,
		.is_equiped = true
	};
	return (slot);
}