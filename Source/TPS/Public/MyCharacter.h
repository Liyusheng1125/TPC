// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "InputActionValue.h"//放在"MyCharacter.generated.h"上面
#include "MyCharacter.generated.h"

UCLASS()
class TPS_API AMyCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AMyCharacter();

	//摄像机
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly,Category = Camera)
	class UCameraComponent* P_Camera;
	//摄像机摇臂
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera)
	class USpringArmComponent* CameraSpring;

	////////////////////增强输入///////////////
	//角色的移动输入
	UPROPERTY(EditAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"), Category = Input)
	class UInputAction* IA_Move;

	//输入映射
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
