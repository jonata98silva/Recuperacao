// Fill out your copyright notice in the Description page of Project Settings.

#include "Mina.h"
#include "Components/SphereComponent.h"
#include "PaperFlipbookComponent.h"
#include "Personagem.h"


// Sets default values
AMina::AMina()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	CollisionComp = CreateDefaultSubobject<USphereComponent>
		(TEXT("CollisionComp"));
	CollisionComp->bGenerateOverlapEvents = true;
	CollisionComp->SetCollisionProfileName("OverlapAllDynamic");
	CollisionComp->OnComponentBeginOverlap.AddDynamic(
		this, &AMina::OnOverlapBegin);
	RootComponent = CollisionComp;

	Sprite = CreateDefaultSubobject<UPaperFlipbookComponent>
		(TEXT("Sprite"));
	Sprite->SetupAttachment(CollisionComp);

}

// Called when the game starts or when spawned
void AMina::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMina::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AMina::OnOverlapBegin(UPrimitiveComponent * OverlappedComp, AActor * OtherActor, UPrimitiveComponent * OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult)
{
	if (OtherActor != nullptr &&
		OtherActor->IsA(APersonagem::StaticClass())) {
		APersonagem* Personagem = Cast<APersonagem>(OtherActor);
		Personagem->MatarPersona();
		Destroy();

	}
}



