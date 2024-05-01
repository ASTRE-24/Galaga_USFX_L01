// Fill out your copyright notice in the Description page of Project Settings.


#include "NaveEnemigaNodriza.h"
#include "TimerManager.h"
#include "SolicitudDeNavesApoyo.h"
#include "SolicitudDeNavesAtaque.h"
#include "SolicitudDeNavesInformante.h"

ANaveEnemigaNodriza::ANaveEnemigaNodriza()
{
	static ConstructorHelpers::FObjectFinder<UStaticMesh> ShipMesh(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_Cube.Shape_Cube'"));
	mallaNaveEnemiga->SetStaticMesh(ShipMesh.Object);
    Timer = 0.0f; //Inicializa el timer en 0 
    TiempoTranscurrido = 0.0f;
    indicePosicion = 0;
	indiceNave = 0;
    SetVelocidad(600);
}

void ANaveEnemigaNodriza::Mover(float DeltaTime)
{
    // Obtiene la posici�n actual del actor
    FVector PosicionActual = GetActorLocation();
    float NewY; //Declara la nueva posici�n en Y
    float PendienteActual = -100; //Declara la pendiente actual
    float Velocidad = 300.0f; //Declara la velocidad de la nave 
    float NewX; //Declara la nueva posici�n en X    

    // Si han pasado m�s de 5 segundos, cambia la pendiente
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

void ANaveEnemigaNodriza::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
    //Mover(DeltaTime);
	FVector Posicion = FVector(GetActorLocation().X, GetActorLocation().Y, GetActorLocation().Z + 100);
    //movimientoNaveNodriza(DeltaTime);
	arma->ArmaDisparoDoble(this);
	arma->SeguirNave(Posicion, GetActorRotation());

}

void ANaveEnemigaNodriza::BeginPlay()
{
	Super::BeginPlay();
    FVector ubicacionInicioNavesEnemigas = FVector(1850.0f, -1540.7f, 216.0f);
    FRotator rotacionNave = FRotator(0.0f, 180.0f, 0.0f);
    for (int i = 0; i < 6; i++) {
        FVector PosicionNaveActualX = FVector(ubicacionInicioNavesEnemigas.X, ubicacionInicioNavesEnemigas.Y + i * 600.0f, ubicacionInicioNavesEnemigas.Z);

        for (int j = 0; j < 3; j++) {
            FVector PosicionNaveActualY = FVector(PosicionNaveActualX.X - j * 528.5f, PosicionNaveActualX.Y, PosicionNaveActualX.Z);
             PosicionesNaves.Add( PosicionNaveActualY);
        }
    }
	GetWorld()->GetTimerManager().SetTimer(TimerNaves, this, &ANaveEnemigaNodriza::retiroNaveNodriza, 10.0f, false);
    GetWorld()->GetTimerManager().SetTimer(TimerSpawnNaves, this, &ANaveEnemigaNodriza::repartirNaves, 2.0f, false);

}

void ANaveEnemigaNodriza::Disparar()
{

}

void ANaveEnemigaNodriza::movimientoNaveNodriza()
{
    const float ReturnSpeed = GetVelocidad(); // Velocidad de retorno ajustable seg�n sea necesario
    const float DeltaTime = GetWorld()->GetDeltaSeconds();
    if (GetActorLocation().Y >= 0.f && GetActorLocation().X<=1500)
    {
        const FVector ReturnMovement = FVector(0, -1, 0) * ReturnSpeed * DeltaTime;
        SetActorLocation(GetActorLocation() + ReturnMovement);
        GetWorldTimerManager().SetTimerForNextTick([this]() {movimientoNaveNodriza(); });
    }
    else if (GetActorLocation().Y <= 0.f && GetActorLocation().X <= 1500.f)
    {
        const FVector ReturnMovement = FVector(1, 0, 0) * ReturnSpeed * DeltaTime;
        SetActorLocation(GetActorLocation() + ReturnMovement);
        GetWorldTimerManager().SetTimerForNextTick([this]() {movimientoNaveNodriza(); });
        
    }
    else if (GetActorLocation().X >= 1500)
    {
		
		
    }
}
void ANaveEnemigaNodriza::movimientoNavesEnemigas()
{
    //// Calcula la direcci�n desde la posici�n actual hasta la posici�n inicial
    //FVector ReturnDirection = InicialPosicion - GetActorLocation();
    //ReturnDirection.Normalize();

    //// Calcula la rotaci�n necesaria para que la nave apunte hacia la posici�n inicial
    //FRotator TargetRotation = ReturnDirection.Rotation();

    //// Interpola gradualmente la rotaci�n actual de la nave hacia la rotaci�n objetivo
    //const float RotationInterpSpeed = 5.0f; // Velocidad de interpolaci�n de rotaci�n ajustable seg�n sea necesario
    //FRotator NewRotation = FMath::RInterpTo(GetActorRotation(), TargetRotation, GetWorld()->GetDeltaSeconds(), RotationInterpSpeed);

    //// Aplica la nueva rotaci�n a la nave
    //SetActorRotation(NewRotation);

    //// Mueve la nave en la direcci�n de regreso a la posici�n inicial
    //const float ReturnSpeed = 1000.0f; // Velocidad de retorno ajustable seg�n sea necesario
    //const float DeltaTime = GetWorld()->GetDeltaSeconds();
    //const FVector ReturnMovement = ReturnDirection * ReturnSpeed * DeltaTime;

    //// Comprueba si la nave est� lo suficientemente cerca de la posici�n inicial
    //const float ReturnDistanceThreshold = 10.0f; // Umbral de distancia ajustable seg�n sea necesario
    //if (FVector::DistSquared(GetActorLocation(), InicialPosicion) <= FMath::Square(ReturnDistanceThreshold))
    //{
    //    // La nave est� lo suficientemente cerca de la posici�n inicial, as� que establece su posici�n y rotaci�n exactamente en la posici�n inicial
    //    SetActorLocationAndRotation(InicialPosicion, FRotator(0, 0, 0));
    //}
    //else
    //{
    //    // La nave todav�a no est� lo suficientemente cerca de la posici�n inicial, as� que sigue movi�ndola hacia all�
    //    SetActorLocation(GetActorLocation() + ReturnMovement);

    //    // Llama a esta funci�n nuevamente en el siguiente fotograma
    //    GetWorldTimerManager().SetTimerForNextTick([this]() { movimientoNavesEnemigas(); });
    //}
}
void ANaveEnemigaNodriza::tipoDeArma()
{
    arma = GetWorld()->SpawnActor<AArmas>(AArmas::StaticClass(), FVector(GetActorLocation().X, GetActorLocation().Y,
        GetActorLocation().Z ), FRotator(0, 0, 0));

}
void ANaveEnemigaNodriza::tiposNavesEnemigas()
{
    FVector ubicacionInicioNavesEnemigas = FVector(1850.0f, -1540.7f, 216.0f);
    FRotator rotacionNave = FRotator(0.0f, 180.0f, 0.0f);
    //Creacion de las solicitudes de naves
    ASolicitudDeNaves* SolicitudDeNavesAtaque = GetWorld()->SpawnActor<ASolicitudDeNavesAtaque>(ASolicitudDeNavesAtaque::StaticClass());
    ASolicitudDeNaves* SolicitudDeNavesApoyo = GetWorld()->SpawnActor<ASolicitudDeNavesApoyo>(ASolicitudDeNavesApoyo::StaticClass());
    ASolicitudDeNaves* SolicitudDeNavesInformante = GetWorld()->SpawnActor<ASolicitudDeNavesInformante>(ASolicitudDeNavesInformante::StaticClass());
    //Aniadir los nombres al TArray
    NombresNavesAtaque.Add("NaveEnemigaCaza");
    NombresNavesAtaque.Add("NaveEnemigaCazaSigilosa");
    NombresNavesAtaque.Add("NaveEnemigaCazaVeloz");
    NombresNavesApoyo.Add("NaveEnemigaTransporte");
    NombresNavesApoyo.Add("NaveEnemigaTransporteFurtivo");
    NombresNavesApoyo.Add("NaveEnemigaTransporteLogistico");
    NombresNavesInformante.Add("NaveEnemigaEspia");
    NombresNavesInformante.Add("NaveEnemigaEspiaInfiltrada");
    NombresNavesInformante.Add("NaveEnemigaEspiaTactica");
    NombresNavesApoyo.Add("NaveEnemigaReabastecimiento");
    NombresNavesApoyo.Add("NaveReabastecimientoEnergia");
    NombresNavesApoyo.Add("NaveReabastecimientoMunicion");


    UWorld* const World = GetWorld();
    if (World != nullptr)
    {
        //Creacion de las naves enemigas

        for (int i = 0; i < 18; i++) {
            // Selecciona un tipo de nave aleatorio
            int32 CategoriaNave = 0;//FMath::RandRange(0, CategoriasNaves.Num() - 1);//Genera un numero aleatorio entre 0 y el tama�o del TArray - 1
            if (CategoriaNave == 0)
            {
                int32 RandomIndex = FMath::RandRange(0, NombresNavesAtaque.Num() - 1);//Genera un numero aleatorio entre 0 y el tama�o del TArray - 1
                // Spawnea la nave aleatoria
                ANaveEnemiga* NaveEnemigaAtaque = SolicitudDeNavesAtaque->OrdenarNaveEnemiga(NombresNavesAtaque[RandomIndex]);
                
                NavesEnemigas.Add( NaveEnemigaAtaque);
                
            }
            else if (CategoriaNave == 1)
            {
                int32 RandomIndex = FMath::RandRange(0, NombresNavesApoyo.Num() - 1);//Genera un numero aleatorio entre 0 y el tama�o del TArray - 1
                // Spawnea la nave aleatoria
                ANaveEnemiga* NaveEnemigaApoyo = SolicitudDeNavesApoyo->OrdenarNaveEnemiga(NombresNavesApoyo[RandomIndex]);
               
            }
            else if (CategoriaNave == 2)
            {
                int32 RandomIndex = FMath::RandRange(0, NombresNavesInformante.Num() - 1);//Genera un numero aleatorio entre 0 y el tama�o del TArray - 1
                // Spawnea la nave aleatoria
                ANaveEnemiga* NaveEnemigaInformante = SolicitudDeNavesInformante->OrdenarNaveEnemiga(NombresNavesInformante[RandomIndex]);
                
            }  
        }
    }
}

void ANaveEnemigaNodriza::retiroNaveNodriza()
{
    const float ReturnSpeed = GetVelocidad(); // Velocidad de retorno ajustable seg�n sea necesario
    const float DeltaTime = GetWorld()->GetDeltaSeconds();
    const FVector ReturnMovement = FVector(0, 1, 0) * ReturnSpeed * DeltaTime;
    if (GetActorLocation().Y >= 1000)
    {
		Destroy();
		arma->Destroy();
    }
    else 
    {
        SetActorLocation(GetActorLocation() + ReturnMovement);

        // Llama a esta funci�n nuevamente en el siguiente fotograma
        GetWorldTimerManager().SetTimerForNextTick([this]() {retiroNaveNodriza(); });
    }

}

void ANaveEnemigaNodriza::repartirNaves()
{
	for (int i = 0; i < NavesEnemigas.Num(); i++)
    {
		NavesEnemigas[i]->SetActorLocation(GetActorLocation());
		posicionesIniciales(i);
    }
	//GetWorld()->GetTimerManager().SetTimer(TimerInicial, this, &ANaveEnemigaNodriza::posicionesIniciales, 5.0f, false);
}

void ANaveEnemigaNodriza::posicionesIniciales(int g)
{
    int parametroG = g;
    FVector ReturnDirection = PosicionesNaves[g] - NavesEnemigas[g]->GetActorLocation();
    ReturnDirection.Normalize();

    // Calcula la rotaci�n necesaria para que la nave apunte hacia la posici�n inicial
    FRotator TargetRotation = ReturnDirection.Rotation();

    // Interpola gradualmente la rotaci�n actual de la nave hacia la rotaci�n objetivo
    const float RotationInterpSpeed = 5.0f; // Velocidad de interpolaci�n de rotaci�n ajustable seg�n sea necesario
    FRotator NewRotation = FMath::RInterpTo(NavesEnemigas[g]->GetActorRotation(), TargetRotation, GetWorld()->GetDeltaSeconds(), RotationInterpSpeed);

    // Aplica la nueva rotaci�n a la nave
    SetActorRotation(NewRotation);

    // Mueve la nave en la direcci�n de regreso a la posici�n inicial
    const float ReturnSpeed2 = 1000.0f; // Velocidad de retorno ajustable seg�n sea necesario
    const float DeltaTime2 = GetWorld()->GetDeltaSeconds();
    const FVector ReturnMovement2 = ReturnDirection * ReturnSpeed2 * DeltaTime2;

    // Comprueba si la nave est� lo suficientemente cerca de la posici�n inicial
    const float ReturnDistanceThreshold = 10.0f; // Umbral de distancia ajustable seg�n sea necesario
    if (FVector::DistSquared(NavesEnemigas[g]->GetActorLocation(), PosicionesNaves[g]) <= FMath::Square(ReturnDistanceThreshold))
    {
        // La nave est� lo suficientemente cerca de la posici�n inicial, as� que establece su posici�n y rotaci�n exactamente en la posici�n inicial
        NavesEnemigas[g]->SetActorLocationAndRotation(PosicionesNaves[g], FRotator(0, 0, 0));
    }
    else
    {
        // La nave todav�a no est� lo suficientemente cerca de la posici�n inicial, as� que sigue movi�ndola hacia all�
        NavesEnemigas[g]->SetActorLocation(NavesEnemigas[g]->GetActorLocation() + ReturnMovement2);

        // Llama a esta funci�n nuevamente en el siguiente fotograma
        GetWorldTimerManager().SetTimerForNextTick([=]() { posicionesIniciales(parametroG); });
    }
}
