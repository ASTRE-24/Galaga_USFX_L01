// Fill out your copyright notice in the Description page of Project Settings.


#include "GameControlAdapter.h"

UGameControlAdapter::UGameControlAdapter()
{
    // Constructor
}


void UGameControlAdapter::RecordScore(float Score)
{
    ClaseExternaInstance->AddScore(Score);
}

float UGameControlAdapter::GetScore() 
{
    return ClaseExternaInstance->GetScore();
}

void UGameControlAdapter::LoseLife()
{
    ClaseExternaInstance->LoseLife();
}

float UGameControlAdapter::GetLives() 
{
    return ClaseExternaInstance->GetLives();
}

void UGameControlAdapter::SetHealth(float NewHealth)
{
    ClaseExternaInstance->SetHealth(NewHealth);
}

float UGameControlAdapter::GetHealth()
{
    return ClaseExternaInstance->GetHealth();
}

void UGameControlAdapter::SetLogisticaJuego(ULogisticaJuego* Controller)
{
    ClaseExternaInstance = Controller;
}