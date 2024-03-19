// Fill out your copyright notice in the Description page of Project Settings.


#include "NaveEnemigaTransporteLogistico.h"

ANaveEnemigaTransporteLogistico::ANaveEnemigaTransporteLogistico()
{
	static ConstructorHelpers::FObjectFinder<UStaticMesh> ShipMesh(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_Tube.Shape_Tube'"));
	mallaNaveEnemiga->SetStaticMesh(ShipMesh.Object);
    mallaNaveEnemiga->SetWorldScale3D(FVector(0.7f, 0.7f, 0.7f));//Para Modificar la escala de la nave
	Timer = 0.0f; //Inicializa el timer en 0    
	TiempoTranscurrido = 0.0f;
}

void ANaveEnemigaTransporteLogistico::Mover(float DeltaTime) {

    // Obtiene la posici�n actual del actor
    FVector PosicionActual = GetActorLocation();

    float NewY; //Declara la nueva posici�n en Y

    float Velocidad = 200.0f; //Declara la velocidad de la nave 
    float NewX; //Declara la nueva posici�n en X  


    // Si han pasado m�s de 5 segundos, cambia la pendiente
    if (Timer <= 1.0f && Timer >= 0)
    {
        NewX = PosicionActual.X - 2 * Velocidad * DeltaTime;
        NewY = PosicionActual.Y;

    }
    else
    {

        NewX = PosicionActual.X + Velocidad * DeltaTime;
        NewY = PosicionActual.Y + Velocidad * DeltaTime;
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

void ANaveEnemigaTransporteLogistico::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
    Mover(DeltaTime);
    
}


void ANaveEnemigaTransporteLogistico::Escapar() {

}

void ANaveEnemigaTransporteLogistico::Atacar() {

}

void ANaveEnemigaTransporteLogistico::Destruirse() {

}

void ANaveEnemigaTransporteLogistico::entregarSuministros() {

}