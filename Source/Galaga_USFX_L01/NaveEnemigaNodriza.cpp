// Fill out your copyright notice in the Description page of Project Settings.


#include "NaveEnemigaNodriza.h"

ANaveEnemigaNodriza::ANaveEnemigaNodriza()
{
	static ConstructorHelpers::FObjectFinder<UStaticMesh> ShipMesh(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_Cube.Shape_Cube'"));
	mallaNaveEnemiga->SetStaticMesh(ShipMesh.Object);
    Timer = 0.0f; //Inicializa el timer en 0 
    TiempoTranscurrido = 0.0f; 
    SetVelocidad(600);
}

void ANaveEnemigaNodriza::Mover(float DeltaTime)
{
    // Obtiene la posición actual del actor
    FVector PosicionActual = GetActorLocation();
    float NewY; //Declara la nueva posición en Y
    float PendienteActual = -100; //Declara la pendiente actual
    float Velocidad = 300.0f; //Declara la velocidad de la nave 
    float NewX; //Declara la nueva posición en X    

    // Si han pasado más de 5 segundos, cambia la pendiente
    if (Timer <= 1.0f && Timer >= 0)
    {
        NewY = PosicionActual.Y + PendienteActual * DeltaTime;
        // Reinicia el temporizador
        NewX = PosicionActual.X - Velocidad * DeltaTime;

    }
    else
    {
        NewY = PosicionActual.Y - PendienteActual * DeltaTime;
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

void ANaveEnemigaNodriza::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
    //Mover(DeltaTime);
    movimientoNaveNodriza(DeltaTime);
    
}



void ANaveEnemigaNodriza::Disparar()
{

}

void ANaveEnemigaNodriza::movimientoNaveNodriza(float DeltaTime)
{
    if (GetActorLocation().Y >= 0.f && GetActorLocation().X<=1500)
    {
        float newY = GetActorLocation().Y - GetVelocidad() * DeltaTime;
        SetActorLocation(FVector(GetActorLocation().X, newY, GetActorLocation().Z));return;
    }
    else if (GetActorLocation().Y <= 0.f && GetActorLocation().X <= 1500.f)
    {
        float newX = GetActorLocation().X + GetVelocidad() * DeltaTime;
        SetActorLocation(FVector(newX, GetActorLocation().Y, GetActorLocation().Z));return;
    }
    else if(GetActorLocation().X >= 1500) retiroNaveNodriza(DeltaTime);
}
void ANaveEnemigaNodriza::movimientoNavesEnemigas()
{

}
void ANaveEnemigaNodriza::tipoDeArma()
{
    arma = GetWorld()->SpawnActor<AArmas>(AArmas::StaticClass(), FVector(0, 0, 215), FRotator(0, 0, 0));

}
void ANaveEnemigaNodriza::tiposNavesEnemigas()
{

}
void ANaveEnemigaNodriza::retiroNaveNodriza(float DeltaTime)
{
    float newY = GetActorLocation().Y + GetVelocidad() * DeltaTime;
    SetActorLocation(FVector(GetActorLocation().X, newY, GetActorLocation().Z));
    if (GetActorLocation().Y >= 1000) Destroy();
}
