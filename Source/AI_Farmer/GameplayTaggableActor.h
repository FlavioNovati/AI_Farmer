#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GameplayTagAssetInterface.h"
#include "GameplayTaggableActor.generated.h"

UCLASS()
class AI_FARMER_API AGameplayTaggableActor : public AActor, public IGameplayTagAssetInterface
{
	GENERATED_BODY()
	
public:
	AGameplayTaggableActor() { PrimaryActorTick.bCanEverTick = true; };

protected:
	virtual void BeginPlay() override { Super::BeginPlay(); };

public:	
	virtual void Tick(float DeltaTime) override { Super::Tick(DeltaTime); };

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FGameplayTagContainer GameplayTagContainer;

	// Inherited via IGameplayTagAssetInterface
	void GetOwnedGameplayTags(FGameplayTagContainer& TagContainer) const override { TagContainer = GameplayTagContainer; };
};
