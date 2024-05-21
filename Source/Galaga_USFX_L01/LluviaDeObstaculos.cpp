// Fill out your copyright notice in the Description page of Project Settings.


#include "LluviaDeObstaculos.h"

ALluviaDeObstaculos::ALluviaDeObstaculos()
{
	PrimaryActorTick.bCanEverTick = true;
}

void ALluviaDeObstaculos::BeginPlay()
{
	Super::BeginPlay();
}

void ALluviaDeObstaculos::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ALluviaDeObstaculos::IniciarLluvia()
{
	NotifySubscribers();
}

void ALluviaDeObstaculos::SetTimeObstaculo(float NewTimeObstaculo)
{
	TimeObstaculo = NewTimeObstaculo;
	if (TimeObstaculo > 1.0f)
	IniciarLluvia();
}