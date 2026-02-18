#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GameplayTaggableActor.h"
#include "GenericTeamAgentInterface.h"
#include "GenericTeamAgentActor.generated.h"

UCLASS()
class AI_FARMER_API AGenericTeamAgentActor : public AGameplayTaggableActor, public IGenericTeamAgentInterface
{
	GENERATED_BODY()

public:	
	// Sets default values for this actor's properties
	AGenericTeamAgentActor();
	
	virtual ETeamAttitude::Type GetTeamAttitudeTowards(const AActor& Other) const override
	{
		const IGenericTeamAgentInterface* OtherTeamAgent = Cast<const IGenericTeamAgentInterface>(&Other);
		return OtherTeamAgent ? FGenericTeamId::GetAttitude(GetGenericTeamId(), OtherTeamAgent->GetGenericTeamId())
			: ETeamAttitude::Hostile;
	}
};
