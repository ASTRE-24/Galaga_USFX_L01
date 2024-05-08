// Fill out your copyright notice in the Description page of Project Settings.


#include "GameControlAdapter.h"

UGameControlAdapter::UGameControlAdapter()
{
    // Constructor
}

UGameControlAdapter::~UGameControlAdapter()
{
    // Destructor
}

void UGameControlAdapter::RecordScore(int32 Score)
{
    ClaseExternaInstance->AddScore(Score);
}

int32 UGameControlAdapter::GetScore() const
{
    return ClaseExternaInstance->GetScore();
}

void UGameControlAdapter::LoseLife()
{
    ClaseExternaInstance->LoseLife();
}

int32 UGameControlAdapter::GetLives() const
{
    return ClaseExternaInstance->GetLives();
}

void UGameControlAdapter::SetHealth(float NewHealth)
{
    ClaseExternaInstance->SetHealth(NewHealth);
}

float UGameControlAdapter::GetHealth() const
{
    return ClaseExternaInstance->GetHealth();
}

void UGameControlAdapter::SetLogisticaJuego(ULogisticaJuego* Controller)
{
    ClaseExternaInstance = Controller;
}