// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "InputActionValue.h"//����"MyCharacter.generated.h"����
#include "MyCharacter.generated.h"

UCLASS()
class TPS_API AMyCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AMyCharacter();

	//�����
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly,Category = Camera)
	class UCameraComponent* P_Camera;
	//�����ҡ��
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera)
	class USpringArmComponent* CameraSpring;

	////////////////////��ǿ����///////////////
	//��ɫ���ƶ�����
	UPROPERTY(EditAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"), Category = Input)
	class UInputAction* IA_Move;

	//����ӳ��
	UPROPERTY(EditAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"), Category = Input)
	class UInputMappingContext* InputMapping;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	void Move(const FInputActionValue& Value);

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
