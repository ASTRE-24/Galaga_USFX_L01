// Fill out your copyright notice in the Description page of Project Settings.


#include "NaveEnemigaReabastecimiento.h"

ANaveEnemigaReabastecimiento::ANaveEnemigaReabastecimiento()
{
	static ConstructorHelpers::FObjectFinder<UStaticMesh> ShipMesh(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_Wedge_B.Shape_Wedge_B'"));
	mallaNaveEnemiga->SetStaticMesh(ShipMesh.Object);
    Timer = 0.0f; //Inicializa el timer en 0
    TiempoTranscurrido = 0.0f;
    

}

void ANaveEnemigaReabastecimiento::Mover(float DeltaTime)
{
    // Obtiene la posición actual del actor
    FVector PosicionActual = GetActorLocation();
   

    float NewY; //Declara la nueva posición en Y
    //float PendienteActual = 100; //Declara la pendiente actual
    float Velocidad = 300.0f; //Declara la velocidad de la nave 
    float NewX; //Declara la nueva posición en X    

    // Si han pasado más de 5 segundos, cambia la pendiente
    if (Timer <= 1.0f && Timer > 0.5f)
    {
        NewY = PosicionActual.Y + Velocidad * DeltaTime;
		NewX = PosicionActual.X;
        // Reinicia el temporizador
        
    }
    if (Timer <= 0.5f && Timer > 0.0f)
    {
		
        NewX = PosicionActual.X - Velocidad * DeltaTime;
        NewY = PosicionActual.Y;

	}
    if (Timer <= 0.0f && Timer > -0.5f)
    {
		NewX = PosicionActual.X - Velocidad * DeltaTime;
		NewY = PosicionActual.Y;
	}
    if(Timer <= -0.5f && Timer >= -1.0f)
    {
        NewY = PosicionActual.Y - Velocidad * DeltaTime;
        NewX = PosicionActual.X;
    }
    TiempoTranscurrido += PI / 2 * DeltaTime;
    Timer = FMath::Sin(TiempoTranscurrido); //Alternando para que sea positivo y negativo

    // Calcula las nuevas posiciones en X e Y


    // Actualiza la posición del actor
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

void ANaveEnemigaReabastecimiento::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
    Mover(DeltaTime);
}

void ANaveEnemigaReabastecimiento::Disparar()
{
}

void ANaveEnemigaReabastecimiento::Destruirse()
{

}

void ANaveEnemigaReabastecimiento::Escapar()
{

}

void ANaveEnemigaReabastecimiento::Atacar()
{

}