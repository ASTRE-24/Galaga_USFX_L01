// Fill out your copyright notice in the Description page of Project Settings.


#include "NaveEnemigaEspiaTactica.h"

ANaveEnemigaEspiaTactica::ANaveEnemigaEspiaTactica()
{
	static ConstructorHelpers::FObjectFinder<UStaticMesh> ShipMesh(TEXT("StaticMesh'/Game/StarterContent/Mehes/NavesEnemigas/Spaceships_5.Spaceships_5'"));
	//// Create the mesh component
	//mallaNaveEnemiga = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ShipMesh"));
	mallaNaveEnemiga->SetStaticMesh(ShipMesh.Object);
    mallaNaveEnemiga->SetWorldScale3D(FVector(0.5f, 1.2f, 1.0f));
	

}

void ANaveEnemigaEspiaTactica::Mover(float DeltaTime)
{
    FVector PosicionActual = GetActorLocation();
    float NewY; //Declara la nueva posición en Y
    float PendienteActual; //Declara la pendiente actual
    float Velocidad = 200.0f + GetVelocidad(); //Declara la velocidad de la nave 

    // Si han pasado más de 5 segundos, cambia la pendiente
    if (Timer <= 1.0f && Timer >= 0)
    {

        PendienteActual = -100;
        NewY = PosicionActual.Y + PendienteActual * DeltaTime;
        // Reinicia el temporizador
    }
    else
    {
        PendienteActual = 100;
        NewY = PosicionActual.Y + PendienteActual * DeltaTime;

    }
    TiempoTrascurrido += PI / 2 * DeltaTime;
    Timer = FMath::Sin(TiempoTrascurrido); //Alternando para que sea positivo y negativo

    // Calcula las nuevas posiciones en X e Y
    float NewX = PosicionActual.X - Velocidad * DeltaTime;


    // Actualiza la posición del actor
    SetActorLocation(FVector(NewX, NewY, PosicionActual.Z));

    if (GetActorLocation().X <= -1800.0f)
    {

        SetActorLocation(FVector(1850.0f, NewY, PosicionActual.Z));


    }
}

void ANaveEnemigaEspiaTactica::Atacar()
{

}

void ANaveEnemigaEspiaTactica::RecopilarInformacion()
{

}