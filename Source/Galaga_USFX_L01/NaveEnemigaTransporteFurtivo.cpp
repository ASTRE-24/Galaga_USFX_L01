// Fill out your copyright notice in the Description page of Project Settings.


#include "NaveEnemigaTransporteFurtivo.h"

ANaveEnemigaTransporteFurtivo::ANaveEnemigaTransporteFurtivo()
{
	static ConstructorHelpers::FObjectFinder<UStaticMesh> ShipMesh(TEXT("StaticMesh'/Game/StarterContent/Mehes/NavesEnemigas/Spaceships_3.Spaceships_3'"));
	mallaNaveEnemiga->SetStaticMesh(ShipMesh.Object);
    mallaNaveEnemiga->SetWorldScale3D(FVector(0.5f, 1.0f, 1.0f));
    Timer = 0.0f; //Inicializa el timer en 0    
    TiempoTranscurrido = 0.0f;
}

void ANaveEnemigaTransporteFurtivo:: evitarRadares() {

}

void ANaveEnemigaTransporteFurtivo::Destruirse() {
	//polimorfismo
}

void ANaveEnemigaTransporteFurtivo::Mover(float DeltaTime) {
	//polimorfismo para mover()

    // Obtiene la posición actual del actor
    FVector PosicionActual = GetActorLocation();

    float NewY; //Declara la nueva posición en Y
   
    float Velocidad = 100.0f + GetVelocidad(); //Declara la velocidad de la nave 
    float NewX; //Declara la nueva posición en X  
    

    // Si han pasado más de 5 segundos, cambia la pendiente
    if (Timer <= 1.0f && Timer >= 0)
    {
        NewX = PosicionActual.X - 2*Velocidad*DeltaTime;
        NewY = PosicionActual.Y;
        
    }
    else
    {

        NewX = PosicionActual.X + Velocidad * DeltaTime;
        NewY = PosicionActual.Y - Velocidad * DeltaTime;
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

void ANaveEnemigaTransporteFurtivo::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
    

}