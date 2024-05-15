// Fill out your copyright notice in the Description page of Project Settings.


#include "LogisticaJuego.h"

ULogisticaJuego::ULogisticaJuego()
    : Score(0), Lives(3), Health(500.f)
{
    // Constructor
}


void ULogisticaJuego::AddScore(float ScoreToAdd)
{
    Score += ScoreToAdd;
}

float ULogisticaJuego::GetScore()
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

float ULogisticaJuego::GetLives()
{
    return Lives;
}

void ULogisticaJuego::SetHealth(float NewHealth)
{
    Health = FMath::Clamp(NewHealth, 0.f, 500.f);
}

float ULogisticaJuego::GetHealth()
{
    return Health;
}