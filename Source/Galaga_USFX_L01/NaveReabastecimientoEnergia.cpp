// Fill out your copyright notice in the Description page of Project Settings.


#include "NaveReabastecimientoEnergia.h"

ANaveReabastecimientoEnergia::ANaveReabastecimientoEnergia()
{
	static ConstructorHelpers::FObjectFinder<UStaticMesh> ShipMesh(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_Trim_90_Out.Shape_Trim_90_Out'"));
	mallaNaveEnemiga->SetStaticMesh(ShipMesh.Object);
    mallaNaveEnemiga->SetWorldScale3D(FVector(2.5f, 2.5f, 2.5f));

}

void ANaveReabastecimientoEnergia::Mover(float DeltaTime)
{
    // Obtiene la posici�n actual del actor
    FVector PosicionActual = GetActorLocation();


    float NewY; //Declara la nueva posici�n en Y
    //float PendienteActual = 100; //Declara la pendiente actual
    float Velocidad = 300.0f; //Declara la velocidad de la nave 
    float NewX; //Declara la nueva posici�n en X    

    // Si han pasado m�s de 5 segundos, cambia la pendiente
    if (Timer <= 1.0f && Timer > 0.5f)
    {
        NewY = PosicionActual.Y + Velocidad * DeltaTime;
        NewX = PosicionActual.X;
        // Reinicia el temporizador

    }
    if (Timer <= 0.5f && Timer > 0.0f)
    {

        NewX = PosicionActual.X - 0.5*Velocidad * DeltaTime;
        NewY = PosicionActual.Y;

    }
    if (Timer <= 0.0f && Timer > -0.5f)
    {
        NewX = PosicionActual.X - 2*Velocidad * DeltaTime;
        NewY = PosicionActual.Y;
    }
    if (Timer <= -0.5f && Timer >= -1.0f)
    {
        NewY = PosicionActual.Y - 0.7*Velocidad * DeltaTime;
        NewX = PosicionActual.X;
    }
    TiempoTranscurrido += PI / 2 * DeltaTime;
    Timer = FMath::Sin(TiempoTranscurrido); //Alternando para que sea positivo y negativo

    // Calcula las nuevas posiciones en X e Y


    // Actualiza la posici�n del actor
    SetActorLocation(FVector(NewX, NewY, PosicionActual.Z));

    if (GetActorLocation().X <= -1800.0f)
    {

        SetActorLocation(FVector(1850.0f, NewY, PosicionActual.Z));


    }
    if (GetActorLocation().Y >= 1850)
    {
        SetActorLocation(FVector(NewX, -1850.0f, PosicionActual.Z));
    }

    if (GetActorLocation().Y <= -1850)
    {
        SetActorLocation(FVector(NewX, 1850.0f, PosicionActual.Z));
    }
}

void ANaveReabastecimientoEnergia::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
    Mover(DeltaTime);
}


void ANaveReabastecimientoEnergia::Escapar()
{

}

void ANaveReabastecimientoEnergia::RecargarEnergia()
{

}