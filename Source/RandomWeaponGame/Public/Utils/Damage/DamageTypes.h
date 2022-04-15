#pragma once

#include "Character/Entity.h"
#include "DamageTypes.generated.h"

UENUM(BlueprintType)
enum class EDamageTypeEnum : uint8
{
	Fixed_Damage UMETA(DisplayName = "FixedDamage"),
	Physic_Damage UMETA(DisplayName = "PhysicDamage"),
    Magic_Damage UMETA(DisplayName = "MagicDamage"),
};

UENUM(BlueprintType)
enum class EAttackTypeEnum : uint8
{
	Melee_Attack UMETA(DisplayName = "MeleeAttack"),
	Skill_Attack UMETA(DisplayName = "SkillAttack"),
    Item_Attack UMETA(DisplayName = "ItemAttack"),
};

USTRUCT(BlueprintType)
struct FDamageSource
{
    GENERATED_BODY()
public:

    AEntity* Attacker;
    AEntity* Target;
    float damage;
    EDamageTypeEnum DamageType;
    EAttackTypeEnum AttackType;
};