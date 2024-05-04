// Fill out your copyright notice in the Description page of Project Settings.


#include "NaveEnemigaNodriza.h"
#include "TimerManager.h"
#include "SolicitudDeNavesApoyo.h"
#include "SolicitudDeNavesAtaque.h"
#include "SolicitudDeNavesInformante.h"

ANaveEnemigaNodriza::ANaveEnemigaNodriza()
{
	static ConstructorHelpers::FObjectFinder<UStaticMesh> ShipMesh(TEXT("StaticMesh'/Game/StarterContent/Mehes/NavesEnemigas/source.source'"));
	mallaNaveEnemiga->SetStaticMesh(ShipMesh.Object);
    Timer = 0.0f; //Inicializa el timer en 0 
    TiempoTranscurrido = 0.0f;
    indicePosicion = 0;
	indiceNave = 0;
	tipoMovimiento = "";
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
	FVector Posicion = FVector(GetActorLocation().X, GetActorLocation().Y, GetActorLocation().Z + 100);
    //movimientoNaveNodriza(DeltaTime);
	arma->ArmaDisparoDoble(this);
	arma->SeguirNave(Posicion, GetActorRotation());

}

void ANaveEnemigaNodriza::BeginPlay()
{
	Super::BeginPlay();
	
    GetWorld()->GetTimerManager().SetTimer(TimerSpawnNaves, this, &ANaveEnemigaNodriza::repartirNaves, 2.5f, false);

}

void ANaveEnemigaNodriza::Disparar()
{

}

void ANaveEnemigaNodriza::movimientoNaveNodriza()
{
	if (tipoMovimiento == "Movimiento 1")
    {
        const float ReturnSpeed = GetVelocidad(); // Velocidad de retorno ajustable según sea necesario
        const float DeltaTime = GetWorld()->GetDeltaSeconds();
        if (GetActorLocation().Y >= 0.f && GetActorLocation().X <= 1500)
        {
            const FVector ReturnMovement = FVector(0, -1, 0) * ReturnSpeed * DeltaTime;
            SetActorLocationAndRotation(GetActorLocation() + ReturnMovement, FRotator(0, -90, 0));
            GetWorldTimerManager().SetTimerForNextTick([this]() {movimientoNaveNodriza(); });
        }
        else if (GetActorLocation().Y <= 0.f && GetActorLocation().X <= 1500.f)
        {
            const FVector ReturnMovement = FVector(1, 0, 0.13) * ReturnSpeed * DeltaTime;
            SetActorLocationAndRotation(GetActorLocation() + ReturnMovement, FRotator(0, 0, 0));
			if (GetActorLocation().X >= 1500.0f)
			{
				
				GetWorld()->GetTimerManager().SetTimer(TimerNaves, this, &ANaveEnemigaNodriza::retiroNaveNodriza, 2.0f, false);
			}
            GetWorldTimerManager().SetTimerForNextTick([this]() {movimientoNaveNodriza(); });
            
        }
	}
    else if (tipoMovimiento == "Movimiento 2")
    {
        const float Amplitud = 5.0f;
        const float Frecuencia = 4.0f;
        const float ReturnSpeed = GetVelocidad(); // Velocidad de retorno ajustable según sea necesario
        const float DeltaTime = GetWorld()->GetDeltaSeconds();
        if (GetActorLocation().Y >= 0.f && GetActorLocation().X <= 1500)
        {
			Timer += DeltaTime;
            const FVector ReturnMovement = FVector(1, -1, 0) * FVector(Amplitud * FMath::Sin(Frecuencia * Timer), ReturnSpeed * DeltaTime, 0);
            SetActorLocationAndRotation(GetActorLocation() + ReturnMovement, FRotator(0,-90,0));
            GetWorldTimerManager().SetTimerForNextTick([this]() {movimientoNaveNodriza(); });
        }
        else if (GetActorLocation().Y <= 0.f && GetActorLocation().X <= 1500.f)
        {
            Timer += DeltaTime;
            const FVector ReturnMovement = FVector(1, 1, 0.7) * FVector(ReturnSpeed * DeltaTime, Amplitud * FMath::Sin(Frecuencia * Timer), 0.7);
            SetActorLocationAndRotation(GetActorLocation() + ReturnMovement, FRotator(0, 0, 0));
            if (GetActorLocation().X >= 1500.0f)
            {

                GetWorld()->GetTimerManager().SetTimer(TimerNaves, this, &ANaveEnemigaNodriza::retiroNaveNodriza, 2.0f, false);
            }
            GetWorldTimerManager().SetTimerForNextTick([this]() {movimientoNaveNodriza(); });

        }
	}
    else if (tipoMovimiento == "Movimiento 3")
    {
        const float ReturnSpeed = GetVelocidad(); // Velocidad de retorno ajustable según sea necesario
        const float DeltaTime = GetWorld()->GetDeltaSeconds();
        if (GetActorLocation().Y >= 0.f && GetActorLocation().X <= 1500)
        {
            float PendienteActual;
            if (Timer <= 0.5f)
            {

                PendienteActual = -85;

            }
            else if (Timer >0.5f)
            {
                PendienteActual = 85;
            }
            TiempoTranscurrido += PI / 2 * DeltaTime;
            Timer = FMath::Sin(TiempoTranscurrido); //Alternando para que sea positivo y negativo
            Timer += DeltaTime;
            const FVector ReturnMovement = FVector(1, -1, 0) * FVector(PendienteActual * DeltaTime, ReturnSpeed/3 * DeltaTime, 0);
            SetActorLocationAndRotation(GetActorLocation() + ReturnMovement, FRotator(0,-90,0));
            GetWorldTimerManager().SetTimerForNextTick([this]() {movimientoNaveNodriza(); });
        }
        else if (GetActorLocation().Y <= 0.f && GetActorLocation().X <= 1500.f)
        {
            float PendienteActual;
            if (Timer <= 0.5f)
            {

                PendienteActual = -75;

            }
            else if (Timer > 0.5f)
            {
                PendienteActual = 75;
            }
            TiempoTranscurrido += PI / 2 * DeltaTime;
            Timer = FMath::Sin(TiempoTranscurrido); //Alternando para que sea positivo y negativo
            Timer += DeltaTime;
            const FVector ReturnMovement = FVector(1, 1, 0.2) * FVector(ReturnSpeed/3 * DeltaTime ,PendienteActual * DeltaTime , 0.7);
            SetActorLocationAndRotation(GetActorLocation() + ReturnMovement, FRotator(0, 0, 0));
            if (GetActorLocation().X >= 1500.0f)
            {
                
                GetWorld()->GetTimerManager().SetTimer(TimerNaves, this, &ANaveEnemigaNodriza::retiroNaveNodriza, 2.0f, false);
            }
            GetWorldTimerManager().SetTimerForNextTick([this]() {movimientoNaveNodriza(); });

        }
	}
}

void ANaveEnemigaNodriza::formacionNavesEnemigas(FString formacion)
{
    FVector ubicacionInicioNavesEnemigas = FVector(1850.0f, -1540.7f, 216.0f);
    if (formacion == "Posicion 1") 
    {
        for (int i = 0; i < 6; i++) {
            FVector PosicionNaveActualX = FVector(ubicacionInicioNavesEnemigas.X, ubicacionInicioNavesEnemigas.Y + i * 600.0f, ubicacionInicioNavesEnemigas.Z);

            for (int j = 0; j < 3; j++) {
                FVector PosicionNaveActualY = FVector(PosicionNaveActualX.X - j * 528.5f, PosicionNaveActualX.Y, PosicionNaveActualX.Z);
				if ((i == 0 || i==5) && j == 0)
                PosicionesNaves.Add(PosicionNaveActualY);
				if ((i == 1 || i==4) && (j == 0 || j == 1))
					PosicionesNaves.Add(PosicionNaveActualY);
				if (i == 2 || i == 3)
					PosicionesNaves.Add(PosicionNaveActualY);
                //GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("Numero de elementos en el array: %d"), PosicionesNaves.Num()));

            }
        };return;
    }
	else if (formacion == "Posicion 2")
	{
		for (int i = 0; i < 6; i++) {
			FVector PosicionNaveActualX = FVector(ubicacionInicioNavesEnemigas.X, ubicacionInicioNavesEnemigas.Y + i * 600.0f, ubicacionInicioNavesEnemigas.Z);

			for (int j = 0; j < 3; j++) {
				FVector PosicionNaveActualY = FVector(PosicionNaveActualX.X - j * 528.5f, PosicionNaveActualX.Y, PosicionNaveActualX.Z);
				if ((i == 0 || i == 5) && (j == 1 || j == 2))
					PosicionesNaves.Add(PosicionNaveActualY);
				if ((i == 1 || i == 4) && j == 0)
					PosicionesNaves.Add(PosicionNaveActualY);
				if (i == 2 || i == 3)
					PosicionesNaves.Add(PosicionNaveActualY);
			}
		};return;
	}
    else if (formacion == "Posicion 3")
    {
        for (int i = 0; i < 7; i++) {
            FVector PosicionNaveActualX = FVector(ubicacionInicioNavesEnemigas.X, ubicacionInicioNavesEnemigas.Y + i * 550.0f, ubicacionInicioNavesEnemigas.Z);

            for (int j = 0; j < 3; j++) {
                FVector PosicionNaveActualY = FVector(PosicionNaveActualX.X - j * 528.5f, PosicionNaveActualX.Y, PosicionNaveActualX.Z);
				if (i % 2 == 0 && j % 2 == 0)
					PosicionesNaves.Add(PosicionNaveActualY);
				if (i % 2 != 0 && j % 2 != 0)
					PosicionesNaves.Add(PosicionNaveActualY);
            }
		};return;
    }
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

        for (int i = 0; i < PosicionesNaves.Num(); i++) {
            // Selecciona un tipo de nave aleatorio
            int32 CategoriaNave = FMath::RandRange(0, 2);//Genera un numero aleatorio entre 0 y el tamaño del TArray - 1
            if (CategoriaNave == 0)
            {
                int32 RandomIndex = FMath::RandRange(0, NombresNavesAtaque.Num() - 1);//Genera un numero aleatorio entre 0 y el tamaño del TArray - 1
                // Spawnea la nave aleatoria
                ANaveEnemiga* NaveEnemigaAtaque = SolicitudDeNavesAtaque->OrdenarNaveEnemiga(NombresNavesAtaque[RandomIndex]);
                
                NavesEnemigas.Add( NaveEnemigaAtaque);
                
            }
            else if (CategoriaNave == 1)
            {
                int32 RandomIndex = FMath::RandRange(0, NombresNavesApoyo.Num() - 1);//Genera un numero aleatorio entre 0 y el tamaño del TArray - 1
                // Spawnea la nave aleatoria
                ANaveEnemiga* NaveEnemigaApoyo = SolicitudDeNavesApoyo->OrdenarNaveEnemiga(NombresNavesApoyo[RandomIndex]);
                NavesEnemigas.Add(NaveEnemigaApoyo);
               
            }
            else if (CategoriaNave == 2)
            {
                int32 RandomIndex = FMath::RandRange(0, NombresNavesInformante.Num() - 1);//Genera un numero aleatorio entre 0 y el tamaño del TArray - 1
                // Spawnea la nave aleatoria
                ANaveEnemiga* NaveEnemigaInformante = SolicitudDeNavesInformante->OrdenarNaveEnemiga(NombresNavesInformante[RandomIndex]);
                NavesEnemigas.Add(NaveEnemigaInformante);
                
            }  
        }
    }
}

void ANaveEnemigaNodriza::retiroNaveNodriza()
{
    const float Amplitud = 5.0f;
    const float Frecuencia = 4.0f;
    const float ReturnSpeed = GetVelocidad(); // Velocidad de retorno ajustable según sea necesario
    const float DeltaTime = GetWorld()->GetDeltaSeconds();
    if (tipoMovimiento == "Movimiento 1")
    {      
        if (GetActorLocation().Y >= 1000)
        {
            Destroy();
            arma->Destroy();
        }
        else
        {
            Timer += DeltaTime;
            const FVector ReturnMovement = FVector(0, 1, 0) * ReturnSpeed * DeltaTime;
            SetActorLocationAndRotation(GetActorLocation() + ReturnMovement, FRotator(0, 90, 0));

            // Llama a esta función nuevamente en el siguiente fotograma
            GetWorldTimerManager().SetTimerForNextTick([this]() {retiroNaveNodriza(); });
        }
    }
    else if (tipoMovimiento == "Movimiento 2")
    {
        if (GetActorLocation().Y >= 1000)
        {
            Destroy();
            arma->Destroy();
        }
        else
        {
            Timer += DeltaTime;
            const FVector ReturnMovement = FVector(-1, 1, 0) * FVector(Amplitud * FMath::Sin(Frecuencia * Timer), ReturnSpeed * DeltaTime, 0);
            SetActorLocationAndRotation(GetActorLocation() + ReturnMovement, FRotator(0, 90, 0));

            // Llama a esta función nuevamente en el siguiente fotograma
            GetWorldTimerManager().SetTimerForNextTick([this]() {retiroNaveNodriza(); });
        }
    }
	else if (tipoMovimiento == "Movimiento 3")
    {      
        if (GetActorLocation().Y >= 1000)
        {
			Destroy();
			arma->Destroy();
		}
        else
        {
            float PendienteActual;
            if (Timer <= 1.0f && Timer >= 0)
            {

                PendienteActual = -75;
              
            }
            else
            {
                PendienteActual = 75;              
            }
            TiempoTranscurrido += PI / 2 * DeltaTime;
            Timer = FMath::Sin(TiempoTranscurrido); //Alternando para que sea positivo y negativo
            Timer += DeltaTime;
            const FVector ReturnMovement = FVector(1, 1, 0) * FVector(PendienteActual * DeltaTime, ReturnSpeed/3 * DeltaTime, 0);
            // Reinicia el temporizador
            SetActorLocationAndRotation(GetActorLocation() + ReturnMovement, FRotator(0, 90, 0));

			// Llama a esta función nuevamente en el siguiente fotograma
			GetWorldTimerManager().SetTimerForNextTick([this]() {retiroNaveNodriza(); });
        }
    }
}

void ANaveEnemigaNodriza::repartirNaves()
{
	for (int i = 0; i < NavesEnemigas.Num(); i++)
    {
		NavesEnemigas[i]->SetActorLocation(FVector(GetActorLocation().X, GetActorLocation().Y, 215.0f));
		posicionesIniciales(i);
    }
	//GetWorld()->GetTimerManager().SetTimer(TimerInicial, this, &ANaveEnemigaNodriza::posicionesIniciales, 5.0f, false);
}

void ANaveEnemigaNodriza::posicionesIniciales(int g)
{
    int parametroG = g;
    FVector ReturnDirection = PosicionesNaves[g] - NavesEnemigas[g]->GetActorLocation();
    ReturnDirection.Normalize();

    // Calcula la rotación necesaria para que la nave apunte hacia la posición inicial
    FRotator TargetRotation = ReturnDirection.Rotation();

    // Interpola gradualmente la rotación actual de la nave hacia la rotación objetivo
    const float RotationInterpSpeed = 5.0f; // Velocidad de interpolación de rotación ajustable según sea necesario
    FRotator NewRotation = FMath::RInterpTo(NavesEnemigas[g]->GetActorRotation(), TargetRotation, GetWorld()->GetDeltaSeconds(), RotationInterpSpeed);

    // Aplica la nueva rotación a la nave
    NavesEnemigas[g]->SetActorRotation(NewRotation);

    // Mueve la nave en la dirección de regreso a la posición inicial
    const float ReturnSpeed = 1000.0f; // Velocidad de retorno ajustable según sea necesario
    const float DeltaTime = GetWorld()->GetDeltaSeconds();
    const FVector ReturnMovement = ReturnDirection * ReturnSpeed * DeltaTime;

    // Comprueba si la nave está lo suficientemente cerca de la posición inicial
    const float ReturnDistanceThreshold = 50.0f; // Umbral de distancia ajustable según sea necesario
    if (FVector::DistSquared(NavesEnemigas[g]->GetActorLocation(), PosicionesNaves[g]) <= FMath::Square(ReturnDistanceThreshold))
    {
        // La nave está lo suficientemente cerca de la posición inicial, así que establece su posición y rotación exactamente en la posición inicial
        NavesEnemigas[g]->SetActorLocationAndRotation(PosicionesNaves[g], FRotator(0, 180, 0));
		// (g >= 12 && g <= 17)
		//NavesEnemigas[g]->bShoulDispara = true;
		//NavesEnemigas[g]->SetMoverse(true);
    }
    else
    {
        // La nave todavía no está lo suficientemente cerca de la posición inicial, así que sigue moviéndola hacia allí
        NavesEnemigas[g]->SetActorLocation(NavesEnemigas[g]->GetActorLocation() + ReturnMovement);

        // Llama a esta función nuevamente en el siguiente fotograma
        GetWorldTimerManager().SetTimerForNextTick([=]() { posicionesIniciales(parametroG); });
    }
}
