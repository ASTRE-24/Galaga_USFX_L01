// Fill out your copyright notice in the Description page of Project Settings.


#include "SpawnFacade.h"
#include "ObstaculoMeteoro.h"
#include "ObstaculoPared.h"
#include "ControladorEventos.h"
#include "Kismet/GameplayStatics.h"
#include "Galaga_USFX_L01Pawn.h"


// Sets default values
ASpawnFacade::ASpawnFacade()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	flag = 0;
}

// Called when the game starts or when spawned
void ASpawnFacade::BeginPlay()
{
	Super::BeginPlay();
	lluviaObstaculos = GetWorld()->SpawnActor<ALluviaDeObstaculos>
        (ALluviaDeObstaculos::StaticClass());
	reduccionVida = GetWorld()->SpawnActor<AReduccionVida>
		(AReduccionVida::StaticClass());
    lluviaObstaculos->Subscribe(this);
	ControladorEventos = GetWorld()->SpawnActor<AControladorEventos>
		(AControladorEventos::StaticClass());
    
	ControladorEventos->SetSpawnFacade(this);

    TArray<AActor*> FoundActors;
    UGameplayStatics::GetAllActorsOfClass(GetWorld(), AGalaga_USFX_L01Pawn::StaticClass(), FoundActors);
	if (FoundActors.Num() > 0)
	{
		AGalaga_USFX_L01Pawn* Jugador = Cast<AGalaga_USFX_L01Pawn>(FoundActors[0]);
		ControladorEventos->SetJugador(Jugador);
		Jugador->EstablecerControlador(ControladorEventos);
	}
    TiempoTranscurrido = 0;
    TiempoCapsulas = 0;
	posiciones();
}

// Called every frame
void ASpawnFacade::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
    // Verifica y elimina naves inválidas
    TArray<AActor*> FoundActors;
    UGameplayStatics::GetAllActorsOfClass(GetWorld(), ANaveEnemiga::StaticClass(), FoundActors);

    bool bAnyNavesEnemigasExist = FoundActors.Num() > 0;
    float promedio = 0;
    for (AActor* Naves : FoundActors)
    {
		ANaveEnemiga* nave = Cast<ANaveEnemiga>(Naves);
        promedio+=nave->GetEnergia();
    }
	if (promedio / navesEnemigas.Num() < 80.0f && flag == 0)
    {
		ControladorEventos->Notificar(this, "RecargaEnemigo");
		flag = 1;
	}
    
    if (!bAnyNavesEnemigasExist)
    {
		navesEnemigas.Empty();
		obstaculos.Empty();
		capsulas.Empty();
		PosicionesNaves.Empty();
		lluviaObstaculos->flags = 0;
        posiciones();
        invocarNaves();
		ControladorEventos->Notificar(this, "LluviaObstaculos");
        invocarObstaculos();
        //invocarCapsula();
    }
    if(VehiculoNeutral)
    {
        TiempoTranscurrido += DeltaTime;
        TiempoCapsulas += DeltaTime;

        VehiculoNeutral->Manejar();
        VehiculoNeutral->Volar();
        VehiculoNeutral->Navegar();
        if (TiempoCapsulas >= 2)
        {
            VehiculoNeutral->SuministrarCapsulas();
            TiempoCapsulas = 0.0f;
        }
        VehiculoNeutral->Disparar();
    }
}

void ASpawnFacade::IniciarJuego()
{
    invocarNaves();
    invocarCapsula();
    invocarObstaculos();
    CrearVehiculoNeutral();
}

void ASpawnFacade::invocarNaves()
{
    navesApoyo = GetWorld()->SpawnActor<ASolicitudDeNavesApoyo>(ASolicitudDeNavesApoyo::StaticClass());
    navesAtaque = GetWorld()->SpawnActor<ASolicitudDeNavesAtaque>(ASolicitudDeNavesAtaque::StaticClass());
    navesInformante = GetWorld()->SpawnActor<ASolicitudDeNavesInformante>(ASolicitudDeNavesInformante::StaticClass());
    //Aniadir los nombres al TArray
    TArray<FString> NombresNavesAtaque;
    TArray<FString> NombresNavesApoyo;
    TArray<FString> NombresNavesInformante;
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
    lluviaObstaculos->contadorNavesEnemigas = 0;

    UWorld* const World = GetWorld();
    if (World != nullptr)
    {
        //Creacion de las naves enemigas

        for (int i = 0; i < PosicionesNaves.Num(); i++) {
            // Selecciona un tipo de nave aleatorio

            int random = FMath::RandRange(0, 2);
            if (random == 0)
            {
                int32 RandomIndex = FMath::RandRange(0, NombresNavesAtaque.Num() - 1);//Genera un numero aleatorio entre 0 y el tamaño del TArray - 1
                ANaveEnemiga* NaveEnemigaAtaque = navesAtaque->OrdenarNaveEnemiga(NombresNavesAtaque[RandomIndex]);
				NaveEnemigaAtaque->SetLluviaObstaculo(lluviaObstaculos);
				NaveEnemigaAtaque->SetReduccionVida(reduccionVida);
                NaveEnemigaAtaque->SetActorLocationAndRotation(PosicionesNaves[i], FRotator(0,180,0));
				ControladorEventos->SetNaveEnemiga(NaveEnemigaAtaque);
				NaveEnemigaAtaque->EstablecerControlador(ControladorEventos);
                navesEnemigas.Add(NaveEnemigaAtaque);
            }
            else if (random == 1)
            {
                int32 RandomIndex = FMath::RandRange(0, NombresNavesApoyo.Num() - 1);//Genera un numero aleatorio entre 0 y el tamaño del TArray - 1
                // Spawnea la nave aleatoria
                ANaveEnemiga* NaveEnemigaApoyo = navesApoyo->OrdenarNaveEnemiga(NombresNavesApoyo[RandomIndex]);
                NaveEnemigaApoyo->SetLluviaObstaculo(lluviaObstaculos);
                NaveEnemigaApoyo->SetReduccionVida(reduccionVida);
                NaveEnemigaApoyo->SetActorLocationAndRotation(PosicionesNaves[i], FRotator(0, 180, 0));
				ControladorEventos->SetNaveEnemiga(NaveEnemigaApoyo);
				NaveEnemigaApoyo->EstablecerControlador(ControladorEventos);
                navesEnemigas.Add(NaveEnemigaApoyo);
            }
            else
            {
                int32 RandomIndex = FMath::RandRange(0, NombresNavesInformante.Num() - 1);//Genera un numero aleatorio entre 0 y el tamaño del TArray - 1
                // Spawnea la nave aleatoria
                ANaveEnemiga* NaveEnemigaInformante = navesInformante->OrdenarNaveEnemiga(NombresNavesInformante[RandomIndex]);
                NaveEnemigaInformante->SetLluviaObstaculo(lluviaObstaculos);
                NaveEnemigaInformante->SetReduccionVida(reduccionVida);
                NaveEnemigaInformante->SetActorLocationAndRotation(PosicionesNaves[i], FRotator(0, 180, 0));
				ControladorEventos->SetNaveEnemiga(NaveEnemigaInformante);
				NaveEnemigaInformante->EstablecerControlador(ControladorEventos);
                navesEnemigas.Add(NaveEnemigaInformante);
            }
        }
    }

}

void ASpawnFacade::invocarObstaculos()
{
	//GetWorld()->GetTimerManager().SetTimer(TimerHandle_LluviaObstaculos, 
        //this, &ASpawnFacade::CrearLluviaObstaculos, 7.0f, false);
   
    FVector ubicacionDeObjetosInventario = FVector(-700.0f, -1300.0f, 215.0f);
    for (int i = 0; i < 12; i++) 
    {
        UWorld* const World = GetWorld();
        if (World != nullptr)
        {
            //Generar un número aleatorio entre 0 y 2
            int RandomNumber = FMath::FRandRange(0, 2);
            if (RandomNumber == 0)
            {
                obstaculoMapa = GetWorld()->SpawnActor<AObstaculo>(AObstaculoMeteoro::StaticClass());
                obstaculoMapa->SetActorLocation(ubicacionDeObjetosInventario);
                //obstaculos.Add(obstaculoMapa);
            }
            else if (RandomNumber == 1)
            {
                obstaculoMapa = GetWorld()->SpawnActor<AObstaculo>(AObstaculoPared::StaticClass());
                obstaculoMapa->SetActorLocation(ubicacionDeObjetosInventario);
                //.Add(obstaculoMapa);
            }
        }
        ubicacionDeObjetosInventario = ubicacionDeObjetosInventario + FVector(0.0f, 300.0f, 0.0f);
    }
}

void ASpawnFacade::invocarCapsula()
{
    FVector ubicacionDeObjetosInventario = FVector(-700.0f, 300.0f, 700.0f);
    //inventarioFactory = GetWorld()->SpawnActor<IInventarioAFactory>(AJugadorCapsula::StaticClass());
    //for (int i = 0; i < 7; i++) {
    //    UbicacionInventario.Add(i, FVector(ubicacionDeObjetosInventario.X, ubicacionDeObjetosInventario.Y + i * 140.0f, ubicacionDeObjetosInventario.Z));
    //    //Generar un número aleatorio entre 0 y 1
    //    int RandomNumber = FMath::FRandRange(0, 3);
    //    if (RandomNumber == 0)
    //    {
    //        capsulas.Add(inventarioFactory->crearCapsulaArma(UbicacionInventario[i]));
    //    }
    //    else if (RandomNumber == 1)
    //    {
    //        capsulas.Add(inventarioFactory->crearCapsulaEnergia(UbicacionInventario[i]));
    //    }
    //    else if (RandomNumber == 2)
    //    {
    //        capsulas.Add(inventarioFactory->crearCapsulaMunicion(UbicacionInventario[i]));
    //    }
    //}

    inventarioFactory = GetWorld()->SpawnActor<IInventarioAFactory>(AEnemigoCapsula::StaticClass());
    for (int i = 0; i < navesEnemigas.Num(); i++) {

        int RandomNumber = FMath::FRandRange(0, 3);
        FVector PosicionNaveActual = PosicionesNaves[i] + FVector(0.0f, 0.0f, 500.0f);
        if (RandomNumber == 0)
        {
            capsulas.Add(inventarioFactory->crearCapsulaArma(PosicionNaveActual));
        }
        else if (RandomNumber == 1)
        {
            capsulas.Add(inventarioFactory->crearCapsulaEnergia(PosicionNaveActual));
        }
        else if (RandomNumber == 2)
        {
            capsulas.Add(inventarioFactory->crearCapsulaMunicion(PosicionNaveActual));
        }

    }
    realizaTareas(navesEnemigas, obstaculos, capsulas);
}

void ASpawnFacade::CrearVehiculoNeutral()
{
    VehiculoNeutral = GetWorld()->SpawnActor<AVehiculo>(AVehiculo::StaticClass());
    VehiculoNeutral->SetActorLocation(FVector(0, 0, 60));
	VehiculoNeutral->EstablecerControlador(ControladorEventos);
	ControladorEventos->SetVehiculo(VehiculoNeutral);
}

void ASpawnFacade::realizaTareas(TArray<class ANaveEnemiga*> _NavesEnemigas, 
    TArray<class AObstaculo*> _Obstaculos, TArray<class AActor*> _Capsulas)
{
	
}

void ASpawnFacade::posiciones()
{
    int formacion = FMath::RandRange(1, 3); //Genera un numero aleatorio entre 1 y 3
    FVector ubicacionInicioNavesEnemigas = FVector(1850.0f, -1540.7f, 216.0f);
    if (formacion == 1)
    {
        for (int i = 0; i < 6; i++) {
            FVector PosicionNaveActualX = FVector(ubicacionInicioNavesEnemigas.X, ubicacionInicioNavesEnemigas.Y + i * 600.0f, ubicacionInicioNavesEnemigas.Z);

            for (int j = 0; j < 3; j++) {
                FVector PosicionNaveActualY = FVector(PosicionNaveActualX.X - j * 528.5f, PosicionNaveActualX.Y, PosicionNaveActualX.Z);
                if ((i == 0 || i == 5) && j == 0)
                    PosicionesNaves.Add(PosicionNaveActualY);
                if ((i == 1 || i == 4) && (j == 0 || j == 1))
                    PosicionesNaves.Add(PosicionNaveActualY);
                if (i == 2 || i == 3)
                    PosicionesNaves.Add(PosicionNaveActualY);
                //GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("Numero de elementos en el array: %d"), PosicionesNaves.Num()));

            }
        };return;
    }
    else if (formacion == 2)
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
    else if (formacion == 3)
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

void ASpawnFacade::CrearLluviaObstaculos()
{
    //lluviaObstaculos->IniciarLluvia();
    FVector ubicacionDeObjetosInventario = FVector(-700.0f, -1300.0f, 215.0f);
    for (int i = 0; i < 12; i++) {
        UWorld* const World = GetWorld();
        if (World != nullptr)
        {
            //Generar un número aleatorio entre 0 y 2
            int RandomNumber = FMath::FRandRange(0, 2);
            if (RandomNumber == 0)
            {
                obstaculoMapa = GetWorld()->SpawnActor<AObstaculo>(AObstaculoMeteoro::StaticClass());
                obstaculoMapa->SetActorLocation(ubicacionDeObjetosInventario);
                obstaculos.Add(obstaculoMapa);
            }
            else if (RandomNumber == 1)
            {
                obstaculoMapa = GetWorld()->SpawnActor<AObstaculo>(AObstaculoPared::StaticClass());
                obstaculoMapa->SetActorLocation(ubicacionDeObjetosInventario);
                obstaculos.Add(obstaculoMapa);
            }
        }
        ubicacionDeObjetosInventario = ubicacionDeObjetosInventario + FVector(0.0f, 300.0f, 0.0f);
		
    }
}

void ASpawnFacade::RetornarPosicion()
{
	for (int i = 0; i < navesEnemigas.Num(); i++)
	{
		if (navesEnemigas[i])
        {
            navesEnemigas[i]->SetActorLocation(PosicionesNaves[i]);
			navesEnemigas[i]->SetMoverse(false);
			navesEnemigas[i]->SetMovimiento(true);
        }
	}
}

void ASpawnFacade::Update()
{
    //invocarObstaculos();
    //GetWorld()->GetTimerManager().SetTimer(TimerHandle_RetornarPosicion, this, &ASpawnFacade::RetornarPosicion, 5.0f, false);
}

void ASpawnFacade::Destroyed()
{
    Super::Destroyed();
    if (!lluviaObstaculos)
    {

        UE_LOG(LogTemp, Error, TEXT("Lluvia de obstaculo no existe")); return;
    }
    lluviaObstaculos->UnSubscribe(this);
}


