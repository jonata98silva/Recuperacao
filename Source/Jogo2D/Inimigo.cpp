// Fill out your copyright notice in the Description page of Project Settings.

#include "Inimigo.h"
#include "PaperFlipbookComponent.h"
#include "Components/SphereComponent.h"
#include "Personagem.h"


// Sets default values
AInimigo::AInimigo()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	CollisionComp = CreateDefaultSubobject<USphereComponent>(TEXT("CollisionComp"));
	CollisionComp->bGenerateOverlapEvents = true;
	CollisionComp->SetCollisionProfileName("OverlapAllDynamic");
	CollisionComp->OnComponentBeginOverlap.AddDynamic(
		this, &AInimigo::OnOverlapBegin);
	RootComponent = CollisionComp;
	
	Multiply = 1.0f;

}

// Called when the game starts or when spawned
void AInimigo::BeginPlay()
{
	Super::BeginPlay();
	Life = 0;
	
}

// Called every frame
void AInimigo::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

int AInimigo::GetLife()
{
	return Life;
}

void AInimigo::SetLife()
{
	Life = Life;
}

void AInimigo::OnOverlapBegin(UPrimitiveComponent * OverlappedComp, AActor * OtherActor, UPrimitiveComponent * OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult)
{
	if (OtherActor != nullptr &&
		OtherActor->IsA(APersonagem::StaticClass())) {
			UE_LOG(LogTemp, Warning, TEXT("ColidiuInimigo"));
			APersonagem* Personagem = Cast<APersonagem>(OtherActor);
			Personagem->SetLife(Personagem->GetLife() - 1);
			Personagem->GetLife();
		
			
	}
	
}

