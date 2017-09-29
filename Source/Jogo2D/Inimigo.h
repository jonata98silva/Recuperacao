// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Inimigo.generated.h"


UCLASS()
class JOGO2D_API AInimigo : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AInimigo();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	int GetLife();
	UFUNCTION()
	void SetLife();


private:

	UPROPERTY(EditAnywhere)
		class UPaperFlipbook* WalkingInimigo;

	UPROPERTY(EditAnywhere)
		class USphereComponent*CollisionComp;

	UPROPERTY(EditAnywhere, Category = "Properties")
		 FVector InitialLocation;
	
		UPROPERTY(EditAnywhere, Category = "Properties")
		 float Multiply;

		UPROPERTY(EditAnywhere)
		int Life;
	
		UFUNCTION()
		 void OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	
	
};
