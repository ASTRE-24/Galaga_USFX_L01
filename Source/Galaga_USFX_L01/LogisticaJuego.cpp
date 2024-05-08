// Fill out your copyright notice in the Description page of Project Settings.


#include "LogisticaJuego.h"

ULogisticaJuego::ULogisticaJuego()
    : Score(0), Lives(3), Health(100.f)
{
    // Constructor
}

ULogisticaJuego::~ULogisticaJuego()
{
    // Destructor
}

void ULogisticaJuego::AddScore(int32 ScoreToAdd)
{
    Score += ScoreToAdd;
}

int32 ULogisticaJuego::GetScore() const
{
    return Score;
}

void ULogisticaJuego::LoseLife()
{
    if (Lives > 0)
    {
        Lives--;
    }
}

int32 ULogisticaJuego::GetLives() const
{
    return Lives;
}

void ULogisticaJuego::SetHealth(float NewHealth)
{
    Health = FMath::Clamp(NewHealth, 0.f, 100.f);
}

float ULogisticaJuego::GetHealth() const
{
    return Health;
}