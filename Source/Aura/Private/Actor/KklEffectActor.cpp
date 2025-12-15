
#include "Actor/KklEffectActor.h"
#include "AbilitySystemInterface.h"
#include "AbilitySystem/KklAttributeSet.h"
AKklEffectActor::AKklEffectActor()
{
	PrimaryActorTick.bCanEverTick = false;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	SetRootComponent(Mesh);

	Sphere = CreateDefaultSubobject<USphereComponent>(TEXT("Sphere"));
	Sphere->SetupAttachment(GetRootComponent());
}

void AKklEffectActor::OnOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	UE_LOG(LogTemp, Warning, TEXT("Overlap with %s"), *OtherActor->GetName());
	if (IAbilitySystemInterface* ASCIntrface = Cast<IAbilitySystemInterface>(OtherActor))
	{
		const UKklAttributeSet* AttributeSet = Cast<UKklAttributeSet>(ASCIntrface->GetAbilitySystemComponent()->GetAttributeSet(UKklAttributeSet::StaticClass()));
		UKklAttributeSet* MutableAttributeSet = const_cast<UKklAttributeSet*>(AttributeSet);
			MutableAttributeSet->SetHealth( MutableAttributeSet->GetHealth() + 25.f);
			MutableAttributeSet->SetMana(MutableAttributeSet->GetMana() + 25.f);
			Destroy();
	}
}

void AKklEffectActor::EndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{

}

void AKklEffectActor::BeginPlay()
{
	AActor::BeginPlay();

	Sphere->OnComponentBeginOverlap.AddDynamic(this, &AKklEffectActor::OnOverlap);
	Sphere->OnComponentEndOverlap.AddDynamic(this, &AKklEffectActor::EndOverlap);
	
}


