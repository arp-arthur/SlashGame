#pragma once

UENUM(BlueprintType)
enum class ECharacterState : uint8
{
	ECS_Unequipped UMETA(DisplayName = "Unequipped"),
	ECS_EquippedOneHandedWeapon UMETA(DisplayName = "EquippedOneHandedWeapon"),
	ECS_EquippedTwoHandedWeapon UMETA(DisplayName = "EquippedTwoHandedWeapon")
};
UENUM(BlueprintType)
enum class EActionState : uint8
{
	EAS_Unoccupied UMETA(DisplayName = "Unoccupied"),
	EAS_Attacking UMETA(DisplayName = "Attacking"),
	EAS_EquippingWeapon UMETA(DisplayName = "EquippingWeapon")
};
UENUM(BlueprintType)
enum class EDeathPose : uint8
{
	EDP_Dead1 UMETA(DisplayName = "DeadToBack"),
	EDP_Dead2 UMETA(DisplayName = "DeadToFront")
};
UENUM(BlueprintType)
enum class EEnemyState : uint8
{
	EES_Dead UMETA(DisplayName = "Dead"),
	EES_Patrolling UMETA(DisplayName = "Patrolling"),
	EES_Chasing UMETA(DisplayName = "Chasing"),
	EES_Attacking UMETA(DisplayName = "Attacking"),
	EES_Engaged UMETA(DisplayName = "Engaged"),
	EES_NoState UMETA(DisplayName = "NoState")
};